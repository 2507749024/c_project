#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 建立某班某学期学生信息的单向链表。学生信息包括学号、姓名、四门课程（微积分、线性代数、物理、C语言）的成绩。学生记录按照学号从小到大顺序排列。要求实现如下功能：
// 1）手动增加学生的信息；
// 2）根据学号或姓名查询学生的信息；
// 3）修改学生的信息；
// 4）删除学生的信息（如休学或退学的学生）
// 5）查询该学期不及格人次不及格门数。
// 6）查询每门课程的平均成绩，并求出平均成绩最高和最低的课程。
// 7）查询平均成绩排名班级前5名学生。
// 8）把录入的学生信息保存成文件；
// 9）将学生信息保存在文件中，并通过读取文件建立初始链表。

// 要求用带头结点的单链表实现。

//创建一个链表存储学生信息
typedef struct Student {
    int id;
    char name[50];
    int calculus;
    int linear_algebra;
    int physics;
    int c_language;
    struct Student* next;
} Student;

//创建空链表的头节点
Student* head;
Student *createHeadNode(){
    Student *head = (Student*)malloc(sizeof(Student));
    head->next=NULL;
    return head;
}

//添加学生
void addStudent(int id, char* name, int calculus, int linear_algebra,
                          int physics, int c_language) {
    //创建学生新节点
    Student* stu = (Student*)malloc(sizeof(Student));

    stu->id = id;
    strcpy(stu->name, name);
    stu->calculus = calculus;
    stu->linear_algebra = linear_algebra;
    stu->physics = physics;
    stu->c_language = c_language;

    stu->next = NULL;

    //找到插入的位置
    Student *current = head;
    while(current->next!=NULL&&current->next->id<id){
        current=current->next;
    }

    //将新节点插入
    stu->next=current->next;
    current->next=stu;


    //return stu;
}

//添加学生信息
void addStudentInfo() {

    //基本思路：1.定义学生信息变量 2.键盘录入 3.创建新节点存入 4.将新节点插入链表（按学号从小到大）

    // 1.定义学生信息变量
    int id, calculus, linear_algebra, physics, c_language;
    char name[50];
    // 2.键盘录入
    printf("请输入学生学号：");
    scanf("%d", &id);
    printf("请输入学生姓名：");
    scanf("%s", name);
    printf("请输入学生微积分成绩：");
    scanf("%d", &calculus);
    printf("请输入学生线性代数成绩：");
    scanf("%d", &linear_algebra);
    printf("请输入学生物理成绩：");
    scanf("%d", &physics);
    printf("请输入学生c语言成绩：");
    scanf("%d", &c_language);
    //getchar();

    // 3.节点插入
    addStudent(id, name, calculus, linear_algebra, physics, c_language);

    
    printf("学生信息添加成功！\n");

}
//删除学生信息
void deleteStudentInfo(){

    //基本思路：

    //1.键盘录入学号
    int id;
    printf("请输入要删除的学生学号：");
    scanf("%d",&id);

    //2.遍历链表，找到对应学号
    Student *prev = head;
    Student *current = head->next;
    while(current!=NULL){
        if(current->id==id){
            prev->next=current->next;
            //不用的节点可以free
            free(current);
            //current->next=NULL;
            printf("删除成功！\n");

            return;
            
        }
        prev=current;
        current=current->next;
    }

    //运行到这一步，说明没有对应的学号,进行提示
    printf("没有找到你输入的学号信息。\n");
}

void modifyStudentInfo(){
    printf("修改学生信息\n");

    //1.输入学生学号
    int id;
    printf("请输入要修改的学生学号：");
    scanf("%d",&id);

    //2.遍历链表，找到该学号
    Student *current = head->next;
    while(current!=NULL){
        if(current->id==id){
            int ch,score;
            printf("请选择你要修改的科目：1.微积分 2.线性代数 3.物理 4.c语言\n");
            scanf("%d",&ch);
            printf("请输入新的分数：");
            scanf("%d",&score);
            switch (ch) {
                case 1: current->calculus=score;break;
                case 2: current->linear_algebra=score;break;
                case 3: current->physics=score;break;
                case 4: current->c_language=score;break;
                default:printf("选项不存在!\n");
            }
            printf("修改成功！\n");
            return;
        }
        current=current->next;
    }

    //3.没找到，进行提示
    printf("您输入的学号不存在!\n");

}

void showStudentInfo(){

    Student *current = head->next;

    if(current==NULL){
        printf("没有学生信息！\n");
        return;
    }

    printf("\n学生信息:\n");

    while(current!=NULL){
        printf("学号：%d\n",current->id);
        printf("姓名：%s\n",current->name);
        printf("微积分成绩：%d\n",current->calculus);
        printf("线性代数成绩：%d\n",current->linear_algebra);
        printf("物理成绩：%d\n",current->physics);
        printf("c语言成绩：%d\n\n",current->c_language);
        

        current=current->next;
    }

}

void searchStudentInfo(){
    //printf("查找学生信息\n");

    //1.键盘录入学号
    int id;
    printf("请输入你要查找的学生学号：");
    scanf("%d",&id);

    //2.遍历链表，打印输出
    Student *current = head->next;
    while (current!=NULL) {
        if(current->id==id){
            printf("\n学号：%d\n",current->id);
            printf("姓名：%s\n",current->name);
            printf("微积分成绩：%d\n",current->calculus);
            printf("线性代数成绩：%d\n",current->linear_algebra);
            printf("物理成绩：%d\n",current->physics);
            printf("c语言成绩：%d\n\n",current->c_language);

            printf("查找成功！\n");
            return;
        }
        current=current->next;
    }

    //3.找不到进行提示
    printf("您输入的学号不存在！\n");
}

void countFailures(){
    //printf("统计不及格人数\n");
    int count = 0;  // 不及格人次
    int numFailures = 0;  // 不及格门数

    Student* current = head->next;
    while (current != NULL) {
        if (current->calculus < 60) {
            count++;
            numFailures++;
        }
        if (current->linear_algebra < 60) {
            count++;
            numFailures++;
        }
        if (current->physics < 60) {
            count++;
            numFailures++;
        }
        if (current->c_language < 60) {
            count++;
            numFailures++;
        }

        current = current->next;
    }

    printf("该学期不及格人次：%d\n", count);
    printf("该学期不及格门数：%d\n", numFailures);

}

void calculateAverageScores(){
    //printf("计算机平均分\n");

    //1.定义所需变量
    int numStudents=0;
    int sumCalculus=0,sumLinearAlgebra=0,sumPhysics=0,sumCLanguage=0;
    double avgCalculus=0.0,avgLinearAlgebra=0.0,avgPhysics=0.0,avgCLanguage=0.0;
    double minAvg=100.0,maxAvg=0.0;
    int minAvgIndex=-1,maxAvgIndex=-1;

    Student* current=head->next;

    //2.遍历累加
    while(current!=NULL){
        numStudents++;
        sumCalculus=sumCalculus+current->calculus;
        sumLinearAlgebra=sumLinearAlgebra+current->linear_algebra;
        sumPhysics=sumPhysics+current->physics;
        sumCLanguage=sumCLanguage+current->c_language;

        current=current->next;
    }

    //3.计算平均成绩
    avgCalculus=(double)sumCalculus/numStudents;
    avgLinearAlgebra=(double)sumLinearAlgebra/numStudents;
    avgPhysics=(double)sumPhysics/numStudents;
    avgCLanguage=(double)sumCLanguage/numStudents;

    //4.找平均成绩最高和最低的课程
    if (avgCalculus < minAvg) {
        minAvg = avgCalculus;
        minAvgIndex = 0;
    }
    if (avgCalculus > maxAvg) {
        maxAvg = avgCalculus;
        maxAvgIndex = 0;
    }
    if (avgLinearAlgebra < minAvg) {
        minAvg = avgLinearAlgebra;
        minAvgIndex = 1;
    }
    if (avgLinearAlgebra > maxAvg) {
        maxAvg = avgLinearAlgebra;
        maxAvgIndex = 1;
    }
    if (avgPhysics < minAvg) {
        minAvg = avgPhysics;
        minAvgIndex = 2;
    }
    if (avgPhysics > maxAvg) {
        maxAvg = avgPhysics;
        maxAvgIndex = 2;
    }
    if (avgCLanguage < minAvg) {
        minAvg = avgCLanguage;
        minAvgIndex = 3;
    }
    if (avgCLanguage > maxAvg) {
        maxAvg = avgCLanguage;
        maxAvgIndex = 3;
    }

    //5.打印输出
    //平均成绩
    printf("微积分平均成绩：%.1lf\n",avgCalculus);
    printf("线性代数平均成绩：%.1lf\n",avgLinearAlgebra);
    printf("物理平均成绩：%.1lf\n",avgPhysics);
    printf("c语言平均成绩：%.1lf\n",avgCLanguage);
    //最低
    switch (minAvgIndex) {
        case 0: printf("平均成绩最低的课程是微积分。\n");break;
        case 1: printf("平均成绩最低的课程是线性代数。\n");break;
        case 2: printf("平均成绩最低的课程是物理。\n");break;
        case 3: printf("平均成绩最低的课程是c语言。\n");break;
    }
    //最高
    switch (maxAvgIndex) {
        case 0: printf("平均成绩最高的课程是微积分。\n");break;
        case 1: printf("平均成绩最高的课程是线性代数。\n");break;
        case 2: printf("平均成绩最高的课程是物理。\n");break;
        case 3: printf("平均成绩最高的课程是c语言。\n");break;
    }


}

int compareByAvg(const void *a,const void *b){
    Student *stu_a = (Student *)a;
    Student *stu_b = (Student *)b;
    double avg1,avg2;
    avg1=(stu_a->calculus+stu_a->linear_algebra+stu_a->physics+stu_a->c_language)/4.0;
    avg2=(stu_b->calculus+stu_b->linear_algebra+stu_b->physics+stu_b->c_language)/4.0;
    return (int)(avg1-avg2);
}

void findTop5Students(){
    //printf("找到前5名\n");

    //1.统计学生数量
    int numStudents=0;
    Student *current = head->next;
    while(current!=NULL){
        numStudents++;
        current=current->next;
    }

    //2.将链表学生信息存入数组
    Student **stu = (Student**)malloc(numStudents*sizeof(Student*));
    current=head->next;
    for(int i=0;i<numStudents;i++){
        stu[i]=current;
        current=current->next;
    }

    //3.使用快速排序
    qsort(stu, numStudents, sizeof(Student*), compareByAvg);

    // 输出前5名学生信息
    printf("班级前5名学生信息：\n");
    for (int i = 0; i < 5 && i < numStudents; i++) {
        printf("学号：%d\n", stu[i]->id);
        printf("姓名：%s\n", stu[i]->name);
        printf("微积分成绩：%d\n", stu[i]->calculus);
        printf("线性代数成绩：%d\n", stu[i]->linear_algebra);
        printf("物理成绩：%d\n", stu[i]->physics);
        printf("C语言成绩：%d\n", stu[i]->c_language);
        printf("\n");
    }

    free(stu);

}
void saveToFile(){
    //printf("保存进文件\n");

    //输入文件名
    char filename[50];
    printf("请输入要保存的文件名（包括后缀）：");
    scanf("%s",filename);

    //创建文件
    FILE *file = fopen(filename,"w");
    if(file==NULL){
        printf("文件保存失败！\n");
        return;
    }

    //写入文件
    Student *current = head->next;
    fprintf(file,"学号 姓名 微积分 线性代数 物理 c语言\n");
    while(current!=NULL){
        fprintf(file, "%d %s %d %d %d %d\n", current->id,current->name,current->calculus,
                        current->linear_algebra,current->physics,current->c_language);
        current=current->next;
    }

    //关闭文件
    fclose(file);
    printf("文件保存成功！\n");

}
void readFromFile(){
    //printf("从文件读取\n");

    //输入文件名
    char filename[50];
    printf("请输入要读取的文件名：");
    scanf("%s",filename);

    //打开该文件
    FILE *file = fopen(filename, "r");
    if(file==NULL){
        printf("文件打开失败！\n");
        return;
    }

    //定义信息变量
    int id,calculus,linear_algebra,physics,c_language;
    char name[50];

    //读取到链表
    while(fscanf(file,"%d %s %d %d %d %d",&id,name,&calculus,&linear_algebra,&physics,&c_language)!=EOF){
        addStudent(id, name, calculus, linear_algebra, physics, c_language);
    }

    //关闭文件
    fclose(file);
    printf("文件读取成功！\n");
}

//释放链表内存
void freeMemory(){
    Student *current = head;
    while(current!=NULL){
        Student* temp=current;
        current=current->next;
        free(temp);
    }
}


int main() {

    head = createHeadNode();
    char choice;
    do {
        printf("-----学生信息管理系统-----\n\n");
        printf("1.添加学生信息\n");
        printf("2.删除学生信息\n");
        printf("3.修改学生信息\n");
        printf("4.展示学生信息\n");
        printf("5.查询学生信息\n");
        printf("6.查询该学期不及格人次及不及格门数\n");
        printf("7.查询每门课程的平均成绩，并求出平均成绩最高和最低的课程\n");
        printf("8.查询平均成绩排名班级前5名学生\n");
        printf("9.把录入的学生信息保存成文件\n");
        printf("0.将学生信息保存在文件中，并通过读取文件建立初始链表\n");
        printf("E.结束程序\n\n");
        printf("请输入您的选项：");
        
        scanf(" %c",&choice);
        printf("\n");
        //getchar();


        switch (choice) {
            case '1':
                addStudentInfo();
                break;
            case '2':
                deleteStudentInfo();
                break;
            case '3':
                modifyStudentInfo();
                break;
            case '4':
                showStudentInfo();
                break;
            case '5':
                searchStudentInfo();
                break;
            case '6':
                countFailures();
                break;
            case '7':
                calculateAverageScores();
                break;
            case '8':
                findTop5Students();
                break;
            case '9':
                saveToFile();
                break;
            case '0':
                readFromFile();
                break;
            case 'e':
            case 'E':
                freeMemory();
                printf("结束程序！\n");
                break;
            default:
                printf("选项输入错误！\n");
                break;
        }

        printf("\n");
    }while(choice!='e'&&choice!='E');

    return 0;
}
