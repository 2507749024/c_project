#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

typedef struct {
    char data[MAX_N];
    int front;
    int rear;
} Queue;

typedef struct {
    char data[MAX_N];
    int top;
} Stack;

void initializeQueue(Queue *queue) {
    queue->front = 0;
    queue->rear = -1;
}

void enqueue(Queue *queue, char item) {
    queue->data[++queue->rear] = item;
}

char dequeue(Queue *queue) {
    return queue->data[queue->front++];
}

int isQueueEmpty(Queue *queue) {
    return (queue->front > queue->rear);
}

void initializeStack(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack, char item) {
    stack->data[++stack->top] = item;
}

char pop(Stack *stack) {
    return stack->data[stack->top--];
}

int isStackEmpty(Stack *stack) {
    return (stack->top == -1);
}

int main() {
    // 读取 n、m、smax 的值
    int n, m, smax;
    scanf("%d %d %d", &n, &m, &smax); 

    // 定义一个包含 n+1 个队列的数组
    Queue a[MAX_N + 1]; 
    for (int i = 1; i <= n; i++) {
        // 初始化第 i 个队列
        initializeQueue(&a[i]); 
        for (int j = 0; j < m; j++) {
            char tem;
            // 读取元素并将其添加到第 i 个队列中
            scanf(" %c", &tem); 
            enqueue(&a[i], tem);
        }
    }

    Stack b; // 定义一个栈 b
    initializeStack(&b); // 初始化栈 b

    while (1) {
        int x;
        // 读取 x 的值
        scanf("%d", &x); 
         // 如果 x 为 -1，则正常退出循环
        if (x == -1)
            break;
        // 如果 x 为 0 且栈 b 非空，则将栈顶元素弹出并输出
        if (x == 0 && !isStackEmpty(&b)) {
            printf("%c", pop(&b)); 
        }
        // 如果 x 大于 0 且栈 b 的大小小于 smax 且第 x 个队列非空，则将第 x 个队列的队首元素出队并入栈 b
        if (x > 0 && b.top < smax && !isQueueEmpty(&a[x])) {
            push(&b, dequeue(&a[x])); 
        } else if (x > 0 && b.top >= smax && !isQueueEmpty(&a[x])) {
            // 如果 x 大于 0 且栈 b 的大小大于等于 smax 且第 x 个队列非空，则将栈顶元素弹出并输出
            printf("%c", pop(&b)); 
            // 然后将第 x 个队列的队首元素出队并入栈 b
            push(&b, dequeue(&a[x])); 
        }
    }

    return 0;
}
