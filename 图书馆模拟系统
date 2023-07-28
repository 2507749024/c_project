#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_BOOKS 50
#define MAX_BOOKS_NAME 100

//定义二维数组
char bookList[MAX_BOOKS][MAX_BOOKS_NAME];
int books_num = 0;

//添加图书
void addBook(){

    //先判断是否能添加图书
    if(books_num>=MAX_BOOKS){
        printf("可增加的图书数量已达最大！\n");
        return;
    }

    //开始添加
    printf("请输入你要添加的图书名称（英文）：");
    scanf("%s",bookList[books_num]);
    books_num++;

    //添加成功
    printf("添加成功！\n");
}

//输出图书
void listBook(){

    //判断是否有图书
    if(books_num==0){
        printf("没有查找到图书信息！\n");
        return;
    }

    //遍历输出
    for(int i=0;i<books_num;i++){
        printf("图书列表：\n");
        printf("%d.%s\n",i+1,bookList[i]);
    }


}

//写一个比较函数，用于排序
int compare(const void *a,const void *b){
    return strcmp((char *)a, (char *)b);
}

//按字母排序
void sortBookList(){

    //使用快速排序
    qsort(bookList,books_num,sizeof(bookList[0]),compare);
    printf("图书已排序成功！\n");

}

//图书查找功能
void searchBook(){

    //判断数组中是否有图书信息
    if(books_num==0){
        printf("无图书信息。\n");
        return;
    }

    //输入图书名进行查找
    printf("请输入你要找的图书名称：");
    char name[MAX_BOOKS_NAME];
    scanf("%s",name);
    for(int i=0;i<books_num;i++){
        if(strcmp(bookList[i],name)==0){
            printf("该书是图书列表中的第%d位。\n", i+1);
            return;
        }
    }

    //没找到，进行提示
    printf("未找到该图书信息。\n");
}


void fuzzySearchBook(){

    //判断数组中是否有图书信息
    if(books_num==0){
        printf("无图书信息。\n");
        return;
    }

    //输入图书的一部分信息
    printf("请输入图书名称的信息：");
    char partName[MAX_BOOKS_NAME];
    scanf("%s",partName);

    //进行查找
    for(int i=0;i<books_num;i++){
        if(strstr(bookList[i],partName)!=NULL){
            printf("已找到匹配的图书：%s \n",bookList[i]);
            return;
        }
    }

    //没有进行提示
    printf("没有找到与%s匹配的图书。\n",partName);
}


int main(void) {

    int choice;

    do{
        printf("\n图书馆模拟系统菜单：\n");
        printf("1.添加图书\n");
        printf("2.展示图书\n");
        printf("3.图书排序\n");
        printf("4.查找图书\n");
        printf("5.模糊查找图书\n");
        printf("0.结束\n");
        printf("请输入你的选项：\n");
        scanf("%d",&choice);

        switch(choice){
            case 1: addBook();break;
            case 2: listBook();break;
            case 3: sortBookList();break;
            case 4: searchBook();break;
            case 5:fuzzySearchBook();break;
            case 0: printf("程序结束！\n");break;
            default: printf("选项有误！\n");break;
        }
    }while(choice!=0);
    return 0;
}
