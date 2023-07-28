#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int row;        // 元素的行索引
    int col;        // 元素的列索引
    int value;      // 元素的值
} Element;

typedef struct {
    int rows;       // 矩阵的行数
    int cols;       // 矩阵的列数
    int numElements;    // 非零元素的个数
    Element data[MAX_SIZE]; // 存储非零元素的数组
} SparseMatrix;

int getElement(SparseMatrix* matrix, int row, int col);

// 初始化稀疏矩阵
void initSparseMatrix(SparseMatrix* matrix, int rows, int cols) {
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->numElements = 0;
}

// 设置稀疏矩阵中指定位置的元素
void setElement(SparseMatrix* matrix, int row, int col, int value) {
    //判断行、列是否合法
    if (row < 0 || row >= matrix->rows || col < 0 || col >= matrix->cols) {
        printf("Invalid matrix index\n");
        return;
    }

    if (value != 0) {
        //判断
        if (matrix->numElements >= MAX_SIZE) {
            printf("Sparse matrix overflow\n");
            return;
        }

        //赋值
        //要先判断原来的值是否不为0，不为0的话直接改值就好了，序列数不用加1（不然后面相加和相乘会出问题）
        if(getElement(matrix,row,col)!=0){
            //只知道行和列，只能从data数组里面遍历找到对应的值，然后改掉
            for(int i=0;i<matrix->numElements;i++){
                Element* element = &(matrix->data[i]);
                if(element->row == row&&element->col==col){
                    element->value = value;
                }
            }
        }else{
            //不为0的话就直接往data数组里加值就好
            Element* element = &(matrix->data[matrix->numElements]);
            element->row = row;
            element->col = col;
            element->value = value;
            matrix->numElements++;
        }

        //这里是一开始错误的改法，从第一步element这里就不对了

        //Element* element = &(matrix->data[matrix->numElements]);
        //element->row = row;
        //element->col = col;
        //如果原来的值不等于零，那直接赋值就好，序列数不变（不然后面矩阵相加和相乘会出问题）
        // if(element->value != 0){
        //     element->value = value;
        // }else{//否则赋值且序列数加1
        //     element->value = value;
        //     matrix->numElements++;
        // }
               
    }
}

// 获取稀疏矩阵中指定位置的元素值
int getElement(SparseMatrix* matrix, int row, int col) {
    //判断行、列是否合法
    if (row < 0 || row >= matrix->rows || col < 0 || col >= matrix->cols) {
        printf("Invalid matrix index\n");
        return 0;
    }

    for (int i = 0; i < matrix->numElements; i++) {
        Element* element = &(matrix->data[i]);
        if (element->row == row && element->col == col) {
            return element->value;
        }
    }

    return 0;
}

// 稀疏矩阵相加
SparseMatrix addSparseMatrices(SparseMatrix* matrix1, SparseMatrix* matrix2) {
    //判断行列是否相等
    if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
        printf("Matrix dimensions mismatch\n");
        SparseMatrix emptyMatrix;
        initSparseMatrix(&emptyMatrix, 0, 0);
        return emptyMatrix;
    }

    SparseMatrix resultMatrix;
    initSparseMatrix(&resultMatrix, matrix1->rows, matrix1->cols);

    // 将矩阵1的非零元素复制到结果矩阵
    for (int i = 0; i < matrix1->numElements; i++) {
        Element* element = &(matrix1->data[i]);
        setElement(&resultMatrix, element->row, element->col, element->value);
    }

    // 将矩阵2的非零元素加到结果矩阵上
    for (int i = 0; i < matrix2->numElements; i++) {
        Element* element = &(matrix2->data[i]);
        int currentValue = getElement(&resultMatrix, element->row, element->col);
        setElement(&resultMatrix, element->row, element->col, currentValue + element->value);
    }

    return resultMatrix;
}

// 稀疏矩阵相乘
SparseMatrix multiplySparseMatrices(SparseMatrix* matrix1, SparseMatrix* matrix2) {
    if (matrix1->cols != matrix2->rows) {
        printf("Matrix dimensions mismatch\n");
        SparseMatrix emptyMatrix;
        initSparseMatrix(&emptyMatrix, 0, 0);
        return emptyMatrix;
    }

    SparseMatrix resultMatrix;
    initSparseMatrix(&resultMatrix, matrix1->rows, matrix2->cols);

    for (int i = 0; i < matrix1->numElements; i++) {
        Element* element1 = &(matrix1->data[i]);
        for (int j = 0; j < matrix2->numElements; j++) {
            Element* element2 = &(matrix2->data[j]);
            if (element1->col == element2->row) {
                int currentValue = getElement(&resultMatrix, element1->row, element2->col);
                setElement(&resultMatrix, element1->row, element2->col, currentValue + element1->value * element2->value);
            }
        }
    }

    return resultMatrix;
}

// 稀疏矩阵转置
SparseMatrix transposeSparseMatrix(SparseMatrix* matrix) {
    SparseMatrix resultMatrix;
    initSparseMatrix(&resultMatrix, matrix->cols, matrix->rows);

    for (int i = 0; i < matrix->numElements; i++) {
        Element* element = &(matrix->data[i]);
        setElement(&resultMatrix, element->col, element->row, element->value);
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

int main() {
    SparseMatrix matrix1;
    initSparseMatrix(&matrix1, 3, 3);

    setElement(&matrix1, 0, 0, 3);
    setElement(&matrix1, 1, 1, 3);
    setElement(&matrix1, 2, 2, 3);
    setElement(&matrix1, 1, 2, 5);

    SparseMatrix matrix2;
    initSparseMatrix(&matrix2, 3, 3);

    setElement(&matrix2, 0, 0, 4);
    setElement(&matrix2, 1, 1, 5);
    setElement(&matrix2, 2, 2, 6);
    setElement(&matrix2, 1, 2, 7);

    printf("Matrix 1:\n");
    printSparseMatrix(&matrix1);

    printf("Matrix 2:\n");
    printSparseMatrix(&matrix2);

    SparseMatrix matrixSum = addSparseMatrices(&matrix1, &matrix2);
    printf("Matrix Sum:\n");
    printSparseMatrix(&matrixSum);

    SparseMatrix matrixProduct = multiplySparseMatrices(&matrix1, &matrix2);
    printf("Matrix Product:\n");
    printSparseMatrix(&matrixProduct);

    SparseMatrix matrixTranspose = transposeSparseMatrix(&matrix1);
    printf("Matrix Transpose:\n");
    printSparseMatrix(&matrixTranspose);

    return 0;
}
