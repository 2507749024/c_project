#include<stdio.h>

//将数组a中的n个元素全部清零
void zeros(int a[],int n){
    for(int i=0;i<n;i++){
        *a = 0;
        a=a+1;
    }
}

//输入数组a中n个元素
void input(int a[],int n){
    
    for(int i=0;i<n;i++){
        scanf("%d",a);
        a=a+1;
    }
}

// 输出数组 a 中 n 个元素
void print(int a[], int n){
    for(int i=0;i<n;i++){
        printf("%d",*a);
        a++;
    }
}

// 交换指针 a、b 指向的两个元素的值
void swap(int *a, int *b){
    int *temp;
    *temp = *a;
    *a = *b;
    *b = *temp;
}


// 找出数组 a[n] 中的最大元素和最小元素，并分别保存到指针 max 和 min 指向的变量中
void max_min(int a[], int n, int *max, int *min){
    *max = *a;
    *min = *a;
    for(int i=0;i<n;i++){
        if(*max<*a){
            *max=*a;
        }
        if(*min>*a){
            *min=*a;
        }
        a++;
    }
}

// 求两个数中的最大值
int *max(int *a, int *b){
    int *max;
    if(*a>*b){
        *max=*a;
    }else if(*a<*b){
        *max=*b;
    }else{
        return 0;
    }
    return max;
}
// 求两个数中的最小值
int *min(int *a, int *b){
    int *min;
    if(*a<*b){
        *min=*a;
    }else if(*a>*b){
        *min=*b;
    }else{
        return 0;
    }
    return min;
}

// 求字符串 s 的长度
int mystrlen(const char *s){
    int length=0;
    while(*s!='\0'){
        length++;
        s=s+1;
    }
    return length;
}
// 将字符串 s 复制到字符数组 t 中，返回复制后的字符串
char *mystrcpy(char *t, const char *s){
    while(*s!='\0'){
        *t=*s;
        t++;
        s++;
    }
    return t;
}
// 将字符串 s 连接到字符串 t 之后，返回连接后的字符串
char *mystrcat(char *t, const char *s){
    char *p=t;

    while(*p!='\0'){
        p++;
    }

    while(*s!='\0'){
        *p++ = *s++;
    }

    *p = '\0';

    return t;
}
// 比较字符串 s 和 t，返回正、负和零分别表示串 s>t、s<t 和 s==t
int mystrcmp(const char *s, const char *t){
    while(*s&&*t&&*s==*t){
        s++;
        t++;
    }

    return *s - *t;
}