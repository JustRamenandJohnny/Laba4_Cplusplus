#include "h.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << n_ << "------VECTOR------" << endl;

   
    Vec<int> vector1(5);  
    vector1[0] = 1;  
    vector1[3] = 4;
    cout << n_ << "vector 1: ";
    vector1.print();

    Vec<int> vector2(5); 
    vector2[2] = 3;
    vector2[3] = 5;

    cout << n_ << "vector 2: ";
    vector2.print();

    Vec<int> vectorSum = vector1 + vector2; 
    cout << n_ << "Сумма векторов: ";
    vectorSum.print();

    int scalarProduct = vector1.dot(vector2);  
    cout << n_ << "Скалярное произведение: " << scalarProduct << endl;


    cout << n_ << "------MATRIX------" << endl;

   
    Matr<int> matrix1(3, 3); 
    matrix1(0, 0) = 1; 
    matrix1(1, 0) = 1;
    matrix1(2, 0) = 1;
    matrix1(0, 1) = 1;
    matrix1(1, 1) = 2;
    matrix1(2, 1) = 1;
    matrix1(0, 2) = 1;
    matrix1(1, 2) = 1;
    matrix1(2, 2) = 2;
    cout << n_ << "Матрица 1" << n_;
    matrix1.print();

    Matr<int> matrix2(3, 3); 
    matrix2(0, 1) = 2;
    matrix2(0, 0) = 2;
    matrix2(2, 2) = 2;
    cout << n_ << "Матрица 2" << n_;
    matrix2.print();

    Matr result_st = matrix1.st(2);  
    cout << n_ << "Степень матрицы:" << endl;
    result_st.print(); 

    Matr<int> matrixSum = matrix1 + matrix2; 
    cout << n_ << "Сумма матриц" << n_;
    matrixSum.print();

    Matr result = matrix1.dot(matrix2); 
    cout << n_ << "Произведение матриц:" << endl;
    result.print(); 

    Matr<int> transposedMatrix = matrix1.transpose(); 
    cout << n_ << "Транспонированная матрица" << n_;
    transposedMatrix.print();

    return 0;
}
