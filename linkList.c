#include <stdio.h>
#include <stdlib.h>

// 结点定义
typedef struct Node {
    int row;            // 行索引
    int col;            // 列索引
    int value;          // 元素值
    struct Node* next;  // 下一个结点的指针
} Node;

// 稀疏矩阵定义
typedef struct {
    int rows;           // 行数
    int cols;           // 列数
    Node* head;         // 链表的头结点指针
} SparseMatrix;

int getElement(SparseMatrix* matrix, int row, int col);

// 初始化稀疏矩阵
void initSparseMatrix(SparseMatrix* matrix, int rows, int cols) {
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->head = NULL;
}

// 设置稀疏矩阵的元素
void setElement(SparseMatrix* matrix, int row, int col, int value) {
    if (row < 0 || row >= matrix->rows || col < 0 || col >= matrix->cols) {
        printf("Invalid matrix index\n");
        return;
    }

    if (value != 0) {

        //要先判断原来的值是否不为0，不为0的话直接改值就好了
        if(getElement(matrix, row, col)!= 0){
            for(Node* current = matrix->head; current != NULL; current = current->next){
                if(current->row == row&&current->col == col){
                    current->value = value;
                }
            }
        }else{
            // 创建新结点
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->row = row;
            newNode->col = col;
            newNode->value = value;
            newNode->next = NULL;

            if (matrix->head == NULL) {
                // 如果链表为空，将新结点设为头结点
                matrix->head = newNode;
            } else {
                // 如果链表不为空，找到链表尾部，将新结点加入链表尾部
                Node* current = matrix->head;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = newNode;
            }
        }
        
    }
}

// 获取稀疏矩阵的元素
int getElement(SparseMatrix* matrix, int row, int col) {
    if (row < 0 || row >= matrix->rows || col < 0 || col >= matrix->cols) {
        printf("Invalid matrix index\n");
        return 0;
    }

    Node* current = matrix->head;
    while (current != NULL) {
        if (current->row == row && current->col == col) {
            return current->value;
        }
        current = current->next;
    }

    return 0;
}

// 稀疏矩阵的加法
SparseMatrix addSparseMatrices(SparseMatrix* matrix1, SparseMatrix* matrix2) {
    if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
        printf("Matrix dimensions mismatch\n");
        SparseMatrix emptyMatrix;
        initSparseMatrix(&emptyMatrix, 0, 0);
        return emptyMatrix;
    }

    SparseMatrix resultMatrix;
    initSparseMatrix(&resultMatrix, matrix1->rows, matrix1->cols);

    // 将 matrix1 的元素加入结果矩阵
    for (Node* current = matrix1->head; current != NULL; current = current->next) {
        setElement(&resultMatrix, current->row, current->col, current->value);
    }

    // 将 matrix2 的元素加入结果矩阵
    for (Node* current = matrix2->head; current != NULL; current = current->next) {
        int currentValue = getElement(&resultMatrix, current->row, current->col);
        setElement(&resultMatrix, current->row, current->col, currentValue + current->value);
    }

    return resultMatrix;
}

// 稀疏矩阵的乘法
SparseMatrix multiplySparseMatrices(SparseMatrix* matrix1, SparseMatrix* matrix2) {
    if (matrix1->cols != matrix2->rows) {
        printf("Matrix dimensions mismatch\n");
        SparseMatrix emptyMatrix;
        initSparseMatrix(&emptyMatrix, 0, 0);
        return emptyMatrix;
    }

    SparseMatrix resultMatrix;
    initSparseMatrix(&resultMatrix, matrix1->rows, matrix2->cols);

    // 使用两重循环计算矩阵乘法
    for (Node* current1 = matrix1->head; current1 != NULL; current1 = current1->next) {
        for (Node* current2 = matrix2->head; current2 != NULL; current2 = current2->next) {
            if (current1->col == current2->row) {
                int currentValue = getElement(&resultMatrix, current1->row, current2->col);
                setElement(&resultMatrix, current1->row, current2->col, currentValue + current1->value * current2->value);
            }
        }
    }

    return resultMatrix;
}

// 稀疏矩阵的转置
SparseMatrix transposeSparseMatrix(SparseMatrix* matrix) {
    SparseMatrix resultMatrix;
    initSparseMatrix(&resultMatrix, matrix->cols, matrix->rows);

    // 遍历原矩阵的链表，将元素加入转置矩阵
    for (Node* current = matrix->head; current != NULL; current = current->next) {
        setElement(&resultMatrix, current->col, current->row, current->value);
    }

    return resultMatrix;
}

// 打印稀疏矩阵
void printSparseMatrix(SparseMatrix* matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            int value = getElement(matrix, i, j);
            printf("%d\t", value);
        }
        printf("\n");
    }
}

// 释放稀疏矩阵的内存
void freeSparseMatrix(SparseMatrix* matrix) {
    Node* current = matrix->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    matrix->head = NULL;
}

int main() {
    // 创建稀疏矩阵 matrix1
    SparseMatrix matrix1;
    initSparseMatrix(&matrix1, 3, 3);

    setElement(&matrix1, 0, 0, 1);
    setElement(&matrix1, 1, 1, 2);
    setElement(&matrix1, 2, 2, 3);
    setElement(&matrix1, 1, 0, 9);

    // 创建稀疏矩阵 matrix2
    SparseMatrix matrix2;
    initSparseMatrix(&matrix2, 3, 3);

    setElement(&matrix2, 0, 0, 4);
    setElement(&matrix2, 1, 1, 5);
    setElement(&matrix2, 2, 2, 6);
    setElement(&matrix2, 2, 0, 8);

    // 打印 matrix1
    printf("Matrix 1:\n");
    printSparseMatrix(&matrix1);

    // 打印 matrix2
    printf("Matrix 2:\n");
    printSparseMatrix(&matrix2);

    // 计算 matrix1 和 matrix2 的和
    SparseMatrix matrixSum = addSparseMatrices(&matrix1, &matrix2);
    printf("Matrix Sum:\n");
    printSparseMatrix(&matrixSum);

    // 计算 matrix1 和 matrix2 的乘积
    SparseMatrix matrixProduct = multiplySparseMatrices(&matrix1, &matrix2);
    printf("Matrix Product:\n");
    printSparseMatrix(&matrixProduct);

    // 计算 matrix1 的转置
    SparseMatrix matrixTranspose = transposeSparseMatrix(&matrix1);
    printf("Matrix Transpose:\n");
    printSparseMatrix(&matrixTranspose);

    // 释放稀疏矩阵的内存
    freeSparseMatrix(&matrix1);
    freeSparseMatrix(&matrix2);
    freeSparseMatrix(&matrixSum);
    freeSparseMatrix(&matrixProduct);
    freeSparseMatrix(&matrixTranspose);

    return 0;
}
