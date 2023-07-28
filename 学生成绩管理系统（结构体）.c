#include <stdio.h>
#include <stdlib.h>
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_SCORES_NUM 20
//题目描述
// 设计一个菜单驱动的学生成绩管理程序，管理n个学生的m门考试科目成绩，实现以下基本功能：

// ① 能够新增学生信息，并计算总分和平均分；

// ② 能够根据学号修改和删除某学生信息；

// ③ 能够显示所有学生的成绩信息；

// ④ 能够分别按总分和学号进行排序；

// ⑤ 能够根据学号查询该学生的基本信息；

// ⑥ 学生成绩数据最终保存在文件中，能够对文件读、写学生数据。
//-----------------------------------------------------
//使用结构体存储学生信息,包括姓名，学号，总分，平均分，m门科目成绩（用数组）
struct Students {
    char name[MAX_NAME_LENGTH];
    int stu_id;
    int num_scores;
    double scores[MAX_SCORES_NUM];
    double average_score;
    double total_score;
} student[MAX_STUDENTS];

//基本要构建8（不确定，随时更改）个函数，
//写完了，最后是16个

//打印菜单信息
void displayMenu() {
    printf("Management for Students' scores:\n");
    printf("1. Append record\n");
    printf("2. List record\n");
    printf("3. Delete record\n");
    printf("4. Modify record\n");
    printf("5. Search record\n");
    printf("6. Sort in descending order by sum\n");
    printf("7. Sort in ascending order by sum\n");
    printf("8. Sort in descending order by num\n");
    printf("9. Sort in ascending order by num\n");
    printf("W. Write to a File\n");
    printf("R. Read from a File\n");
    printf("0. Exit\n");

    printf("Please Enter Your Choice:\n");
}

//定义一个统计学生数量的变量
int num_students = 0;
//添加学生信息
void appendInfo() {
    printf("添加学生信息\n");
    while (1) {
        //判断添加的学生数量是否达上限
        if (num_students >= MAX_STUDENTS) {
            printf("The number of students added has reached its maximum.\n");
            return;
        }

        //基本思路：1.定义一个新的学生对象 2.输入基本信息赋给该对象 3.将该对象存入数组

        //定义一个新的学生对象
        struct Students new_student;

        //输入学号
        printf("Please enter your ID:\n");
        scanf("%d", &new_student.stu_id);
        //输入姓名
        printf("Please enter your name:\n");
        scanf("%s", new_student.name);
        //输入科目成绩的数量
        printf("Please enter the scores num:\n");
        scanf("%d", &new_student.num_scores);
        //用一个循环来输入成绩
        printf("Please enter the score:\n");
        for (int i = 0; i < new_student.num_scores; i++) {
            printf("score %d:", i + 1);
            scanf("%lf", &new_student.scores[i]);
        }
        //计算总分和平均分
        new_student.total_score = 0;
        for (int i = 0; i < new_student.num_scores; i++) {
            new_student.total_score =
                new_student.total_score + new_student.scores[i];
        }
        new_student.average_score =
            new_student.total_score / new_student.num_scores;
        //将该学生信息存入数组
        student[num_students++] = new_student;

        printf("This student information appended successfully!\n");
        //选择接下来的操作
        printf("Please enter your choice: 1.Continue  2.Break\n");
        int flag;
        scanf("%d", &flag);
        if (flag == 2)
            break;
    }
}

//删除学生信息
void deleteInfo() {
    printf("删除学生信息\n");

    while (1) {
        //判断数组中是否有学生信息
        if (num_students == 0) {
            printf("No student information found!");
            return;
        }

        //基本思路：1.输入学号 2.遍历学生数组查找学号 3.从该数据开始循环遍历，用后面的数据覆盖前一个数据

        // 1.输入学号
        int stu_id;
        printf("Enter the student ID to delete:\n");
        scanf("%d", &stu_id);

        int found = 0;
        // 2.遍历数组查找
        for (int i = 0; i < num_students; i++) {
            //拿输入的学号与数组中存储的数据比较
            if (student[i].stu_id == stu_id) {
                // 3.从该数据开始循环遍历覆盖
                for (int j = i; j < num_students - 1; j++) {
                    student[j] = student[j + 1];
                }
                found = 1;
                //学生数量进行相应改变
                num_students--;
                //删除成功，进行提示
                printf("Student information deleted successfully!\n");
                // break即可，无需进行外层循环
                break;
            }
        }

        //根据flag进行判断,如果没有找到该学生，进行提示
        if (!found) {
            printf("Student ID not found!");
        }
        //选择接下来的操作
        printf("Please enter your choice: 1.Continue  2.Break\n");
        int flag;
        scanf("%d", &flag);
        if (flag == 2)
            break;
    }
}
//修改学生信息
void changeInfo() {
    printf("修改学生信息\n");

    //基本思路：1.输入学号查找信息
    //        2.还是循环遍历的方法完成分数的修改（姓名和学号不可改）
    //        3.总分和平均分也相应修改

    while (1) {

        if (num_students == 0) {
            printf("No student information found!\n");
            return;
        }

        //输入学号
        printf("Enter the student ID to change:\n");
        int stu_id;
        scanf("%d", &stu_id);

        //循环遍历查找
        for (int i = 0; i < num_students; i++) {
            if (student[i].stu_id == stu_id) {
                //展示分数信息
                for (int j = 0; j < student[i].num_scores; j++) {
                    printf("score %d: %.1lf\n", j + 1, student[i].scores[j]);
                }
                printf("Please enter the number of score to change:\n");
                int num;
                scanf("%d", &num);
                //遍历找到该分数
                int found = 0;
                for (int k = 0; k < student[i].num_scores; k++) {
                    if (num == k + 1) {
                        printf("Please enter the new score:\n");

                        double new_score;
                        scanf("%lf", &new_score);
                        //释放该地址存储的数据
                        // free(&student[i].scores[k]);

                        //修改总分
                        student[i].total_score = student[i].total_score -
                                                 student[i].scores[k] +
                                                 new_score;
                        //修改平均分
                        student[i].average_score =
                            student[i].total_score / student[i].num_scores;

                        //用新的分数覆盖原分数
                        student[i].scores[k] = new_score;

                        found = 1;
                        //提示修改成功
                        printf(
                            "This score information changed successfully!\n");
                        break;
                    }
                }
                //判断num是否输入有误
                if (!found) {
                    printf("No found score %d information.\n", num);
                }
            }
        }
        printf("Please enter your choice: 1.Continue 2.Break \n");
        int flag;
        scanf("%d", &flag);
        if (flag == 2) {
            break;
        }
    }
}
//查找学生信息
void searchInfo() {
    printf("查找学生信息\n");

    while (1) {
        if (num_students == 0) {
            printf("No student information found!\n");
            return;
        }

        //基本思路：输入学号，循环遍历，找到后打印就行了

        int stu_id;
        printf("Enter the student ID to find:\n");
        scanf("%d", &stu_id);

        //遍历
        int found = 0;
        for (int i = 0; i < num_students; i++) {
            if (student[i].stu_id == stu_id) {
                printf("Student ID: %d\n", student[i].stu_id);
                printf("Name: %s\n", student[i].name);
                //打印各科成绩
                for (int j = 0; j < student[i].num_scores; j++) {
                    printf("Scores %d: %.1lf\n", j + 1, student[i].scores[j]);
                }
                printf("Total score: %.1lf\n", student[i].total_score);
                printf("Average score: %.1lf\n\n", student[i].average_score);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Student ID not found!\n");
        }

        //选择接下来的操作
        printf("Please enter your choice: 1.Continue 2.Break \n");
        int flag;
        scanf("%d", &flag);
        if (flag == 2) {
            break;
        }
        
    }
}
//打印学生信息
void displayInfo() {
    printf("打印学生信息\n");
    //判断是否有学生信息
    if (num_students == 0) {
        printf("No student information found!\n");
    }

    //基本思路：直接一个循环遍历输出打印

    printf("Student information:\n\n");
    for (int i = 0; i < num_students; i++) {

        printf("Student ID: %d\n", student[i].stu_id);
        printf("Name: %s\n", student[i].name);
        //打印各科成绩
        for (int j = 0; j < student[i].num_scores; j++) {
            printf("Scores %d: %.1lf\n", j + 1, student[i].scores[j]);
        }
        printf("Total score: %.1lf\n", student[i].total_score);
        printf("Average score: %.1lf\n\n", student[i].average_score);
    }
}

//分数比较函数（升序）
int compareByTotalScoreUp(const void *a,const void *b){
    struct Students *stu_a = (struct Students *)a; 
    struct Students *stu_b = (struct Students *)b; 
    return (int)(stu_a->total_score - stu_b->total_score);
}
//分数比较函数（降序）
int compareByTotalScoreDown(const void *a,const void *b){
    struct Students *stu_a = (struct Students *)a; 
    struct Students *stu_b = (struct Students *)b; 
    return (int)(stu_b->total_score - stu_a->total_score);
}

//学号比较函数（升序）
int compareByStudentIDUp(const void *a,const void *b){
    struct Students* stu_a=(struct Students *)a;
    struct Students* stu_b=(struct Students *)b;
    return (int)(stu_a->stu_id-stu_b->stu_id);
}
//学号比较函数（降序）
int compareByStudentIDDown(const void *a,const void *b){
    struct Students* stu_a=(struct Students *)a;
    struct Students* stu_b=(struct Students *)b;
    return (int)(stu_b->stu_id-stu_a->stu_id);
}

//按总分升序排序
void sortAscendingByTotalScore() { 
    printf("按总分升序排序\n"); 

    if(num_students==0){
        printf("No student information found!\n");
        return;
    }

    //使用快速排序
    qsort(student,num_students,sizeof(struct Students),compareByTotalScoreUp);

    printf("Student information sorted in ascending order by total score.\n");
}
//按总分降序排序
void sortDescendingByTotalScore() {
    printf("按总分降序排序\n"); 

    if(num_students==0){
        printf("No student information found!\n");
        return;
    }

    //使用快速排序
    qsort(student,num_students,sizeof(struct Students),compareByTotalScoreDown);

    printf("Student information sorted in descending order by total score.\n");
}
//按学号升序排序
void sortAscendingByStuId() {
    printf("按学号升序排序\n"); 

    if(num_students==0){
        printf("No student information found!\n");
        return;
    }

    //使用快速排序
    qsort(student,num_students,sizeof(struct Students),compareByStudentIDUp);

    printf("Student information sorted in ascending order by student ID.\n");
}
//按学号降序排序
void sortDescendingByStuId() { 
    printf("学号降序排序\n");

    if(num_students==0){
        printf("No student information found!\n");
        return;
    }

    //使用快速排序
    qsort(student,num_students,sizeof(struct Students),compareByStudentIDDown);

    printf("Student information sorted in descending order by student ID.\n");
}
//写入文件
void writeToFile() { 
    printf("写入文件\n"); 

    //打开文件
    FILE *file = fopen("stu_info.txt","w");

    if(file==NULL){
        printf("Failed to open file to writing.\n");
        return;
    }

    fwrite(&num_students,sizeof(int),1,file);
    fwrite(student,sizeof(struct Students),num_students,file);

    fclose(file);

    printf("Student information written to file successfully!\n");

}
//读取文件
void readToFile() { 
    printf("读取文件\n");

    FILE *file=fopen("stu_info.txt","r");

    if(num_students==0){
        printf("No student information Found!\n");
        return;
    }

    fread(&num_students,sizeof(int),1,file);
    fread(student,sizeof(struct Students),num_students,file);

    fclose(file);

    printf("Student information read from file successfully!\n");
}

int main() {
    char choice;
    //循环操作，可重复执行
    do {
        //每次执行程序前，先打印菜单信息
        displayMenu();
        //输入你的选项
        scanf(" %c", &choice);
        //用switch函数来跟序号一一对应
        switch (choice) {
        case '1':
            appendInfo();
            break;
        case '2':
            displayInfo();
            break;
        case '3':
            deleteInfo();
            break;
        case '4':
            changeInfo();
            break;
        case '5':
            searchInfo();
            break;
        case '6':
            sortDescendingByTotalScore();
            break;
        case '7':
            sortAscendingByTotalScore();
            break;
        case '8':
            sortDescendingByStuId();
            break;
        case '9':
            sortAscendingByStuId();
            break;
        case 'w':
        case 'W': //大写小写都可以
            writeToFile();
            break;
        case 'r':
        case 'R': //同上
            readToFile();
            break;
        case '0':
            printf("Exiting the Programming.\n");
            break;
        default:
            printf("Invalid choice. Please enter again.\n");
            break;
        }
        printf("\n");
    } while (choice != '0');
    return 0;
}