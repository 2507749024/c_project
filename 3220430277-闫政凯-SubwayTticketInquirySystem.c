#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//定义地铁站路信息
char* subway_lines[] = {"1号线", "2号线", "4号线", "5号线"};
char* subway_stations[][50] = {
    {"湘湖","滨康路","西兴","滨和路","江陵路","近江","婺江路","城站","定安路","龙翔桥","凤起路","武林广场","西湖文化广场","打铁关","闸弄口","火车东站","彭埠","七堡","九和路","九堡","客运中心","下沙西","金沙湖","高沙路","文泽路","文海南路","云水","下沙江滨","杭州大会展中心","港城大道","南阳","向阳路","萧山国际机场"},
    {"朝阳", "曹家桥", "潘水", "人民路", "杭发厂",
    "人民广场", "建设一路", "建设三路", "振宁路", "飞虹路",
    "盈丰路", "钱江世纪城", "钱江路", "庆春广场", "庆菱路",
    "建国北路", "中河北路", "凤起路", "武林门", "沈塘桥",
    "下宁桥", "学院路", "古翠路", "丰潭路", "文新",
    "三坝", "虾龙圩", "三墩", "墩祥街", "金家渡",
    "白洋", "杜甫村", "良渚"},
    {"池华街", "金家渡", "好运街", "杭行路", "储运路",
    "独城生态公园", "吴家角港", "桃源街", "皋亭坝", "新天地街",
    "华中南路", "笕桥老街", "黎明", "明石路", "彭埠",
    "火车东站", "新风", "新塘", "景芳", "钱江路",
    "江锦路", "市民中心", "城星路", "近江", "甬江路",
    "南星桥", "复兴路", "水澄桥", "联庄", "中医药大学",
    "杨家墩", "浦沿"},
    {"姑娘桥", "双桥", "火车南站", "通惠中路", "育才北路",
    "人民广场", "金鸡路", "博奥路", "滨康路", "江晖路",
    "聚才路", "长河", "南星桥", "候潮门", "江城路",
    "城站", "万安桥", "建国北路", "宝善桥", "打铁关",
    "杭氧", "东新园", "西文街", "善贤", "拱宸桥东",
    "大运河", "和睦", "萍水街", "三坝", "浙大紫金港",
    "蒋村", "五常", "永福", "杭师大仓前", "良睦路",
    "创景路", "葛巷", "绿汀路", "金星"}
};
int subway_station_count[] = {33, 33, 32, 39};


//获取站点所在的地铁线路
int get_line_index(char* station){
    int i,j;
    for(int i=0;i<4;i++){
        for(int j=0;j<subway_station_count[i];j++){
            if(strcmp(station, subway_stations[i][j])==0){
                return i;
            }
        }
    }
    return -1;
}

//获取乘坐地铁的站点数量
int get_station_count(char* start_station,char* end_station,int line_index){
    int i,j;
    int start_index=-1,end_index=-1;
    for(i=0;i<subway_station_count[line_index];i++){
        if(strcmp(start_station,subway_stations[line_index][i])==0){
            start_index = i;
        }
        if(strcmp(end_station,subway_stations[line_index][i])==0){
            end_index = i;
        }
    }
    //未收到
    if(start_index == -1||end_index == -1){
        return -1;
    }
    return abs(end_index-start_index)+1;
}

// 计算费用
int calculate_fare(int station_count) {
    if (station_count <= 3) {
        return 2;
    } else if (station_count <= 6) {
        return 3;
    } else if (station_count <= 11) {
        return 4;
    } else if (station_count <= 16) {
        return 5;
    } else {
        int extra_stations = station_count - 16;
        return 5 + extra_stations / 5;
    }
}




int main(){
    char start_station[30];
    char end_station[30];

    printf("请输入起点站：");
    scanf("%s",start_station);
    printf("请输入终点站：");
    scanf("%s",end_station);

    //获取起点和终点所在的线路
    int start_line_index = get_line_index(start_station);
    int end_line_index = get_line_index(end_station);

    //判断站点输入是否正确
    if(start_line_index == -1||end_line_index == -1){
        printf("未找到起点或终点站，请检查输入是否正确。\n");
        return 0;
    }

    //定义最小费用和最优路线
    int min_fare = 9999;
    int min_line_index = -1;

    //在同一条线路上
    if(start_line_index == end_line_index){
        int station_count = get_station_count(start_station, end_station, start_line_index);
        if (station_count == -1) {
            printf("未找到起点或终点站，请检查输入是否正确。\n");
            return 0;
        }
        min_fare = calculate_fare(station_count);
        min_line_index = start_line_index;
        printf("乘车路线为：从%s站坐%s可直达%s站。\n",start_station,subway_lines[min_line_index],end_station);
        printf("最低费用为：%d\n",min_fare);
        return 0;
    } else {//需要换乘
        //定义换乘路线变量和乘坐的站点数
        int i, j, k;
        int transfer_line_index = -1;
        int transfer_station_count = -1;
        int total_fare = -1;
        char final_transfer_station[50];

        //遍历两条线路
        for(i=0;i<subway_station_count[start_line_index];i++){
            for(j=0;j<subway_station_count[end_line_index];j++){
                //找到中转站
                if(strcmp(subway_stations[start_line_index][i],subway_stations[end_line_index][j])==0){
                    //定义中转站变量
                    char transfer_station[50];
                    strcpy(transfer_station,subway_stations[start_line_index][i]);
                    //分别计算经过的站数和费用
                    int transfer_station_count1 = get_station_count(start_station, transfer_station, start_line_index);
                    int fare1 = calculate_fare(transfer_station_count1);
                    int transfer_station_count2 = get_station_count(transfer_station, end_station, end_line_index);
                    int fare2 = calculate_fare(transfer_station_count2);
                    //计算总站数和总费用
                    transfer_station_count = transfer_station_count1 + transfer_station_count2;
                    total_fare = fare1 + fare2;
                    
                    //判断是否是最少费用
                    if(min_fare>total_fare){
                        min_fare = total_fare;
                        strcpy(final_transfer_station,transfer_station);
                    }

                }
            }
        }
        //打印输出结果
        if(min_fare!=-1&&transfer_station_count!=-1){
            printf("乘车路线为：从%s站乘坐%s到%s站中转%s可到达%s站。\n",start_station,subway_lines[start_line_index],
                                final_transfer_station,subway_lines[end_line_index],end_station);
            printf("最低费用为：%d\n",min_fare);
        } else {
            printf("无法从起点站到达终点站，请检查输入是否正确。\n");
        }
    }

    return 0;


}



