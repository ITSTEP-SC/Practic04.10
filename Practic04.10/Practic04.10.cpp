
#include <iostream>

using namespace std;


void Print(int** arr, int s) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < s; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

/*
. Написать программу, которая удаляет из
двухмерного массива, заполненного случайными числами
строки, содержащие нулевые элементы.
*/
int** f1(int** arr,int size1, int size2) {   
    int counter = 0;
    int** newArr = new int* [size1];
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr[i][j] == 0)
                counter++;
        }
        *(newArr+i) = new int[size2 - counter];
        counter = 0;
    }

    for (int i = 0, g = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr[i][j] != 0) {
                newArr[i][g] = arr[i][j];
                g++;
            }
        } 
        Print(newArr,g);
        g = 0;
    }
   
    return newArr;
}

/*
Задание 2. Написать программу, которая поэлементно
суммирует два динамических двумерных массива, заполненных случайными 
числами и сохраняет результат
в третьем массиве. Размеры исходных массивов задаются пользователем.
*/

int** f2(int** arr, int** arr2) {
    int size1 = 3;
    int** arr4 = new int* [size1];
    for (int i = 0; i < 3; i++) {
        *(arr4 + i) = new int[5];
        for (int j = 0; j < 5; j++) {
            arr4[i][j] = arr[i][j] + arr2[i][j];
            
    }
        
    }
    return arr4;
}

/*Напишите функцию умножения матриц. 
Матрица представляет собой таблицу чисел. Произведением
матрицы A размером M×N (M строк, N столбцов) на
матрицу B размером N×K является матрица C размером
N×K такая, что
cij= ai1b1j + ai2b2j + … + aiNbNj, для
1 <= i <= M и 1 <= j <= K, где
■ axy — элемент, находящийся на пересечении строки
x и столбца y матрицы A;
■ bxy — элемент, находящийся на пересечении строки
x и столбца y матрицы B;
■ cxy — элемент, находящийся на пересечении строки
x и столбца y матрицы C.*/

int** f3(int** arr, int** arr1, int M, int N, int K) {
    int** arr3 = new int* [M];
    int T = 0;
    for (int i = 0; i < M; i++) {
        *(arr3 + i) = new int[K];
        for (int j = 0; j < K; j++) {
            for (int h = 0; h < N; h++) {
                T += arr[i][h] * arr1[h][j];
            }
            arr3[i][j] = T;
            T = 0;
        }
    }
    return arr3;
}

/*
Написать программу, которая дает пользователю ввести 5 фамилий студентов, 
а затем находит среди
них самую длинную фамилию.
*/

void f4() {
    char** arr = new char* [5];
    for (int i = 0; i < 5; i++) {
        *(arr + i) = new char[256];
        cin >> *(arr + i);
    }
    int a = 0;
    int b = 0;
    for (int j = 0; j < 5; j++) {
        if (b < strlen(*(arr + j))) {
            b = strlen(*(arr + j));
            a = j;
        }
    }
    cout << *(arr + a);
    //for (int i = 0; i < 5; i++) {
    //    cout << *(arr + i) << endl;
    //}
 }
int main()
{
    int size1 = 3;
    int size2 = 5;
    int** arr = new int* [2];
    *arr = new int[3] {3, 2, 1};
    *(arr+1) = new int[3] {4, 5, 1};
    //Print(f1(arr, size1, size2));
   // f1(arr, size1, size2);
    int** arr1 = new int* [3];
    *arr1 = new int[2] {1, 4};
    *(arr1 + 1) = new int[2] {5, 7};
    *(arr1 + 2) = new int[2] {8, 1};
    //Print(f2(arr, arr1), 5);
    //Print(f3(arr, arr1, 2, 3, 2), 2);
    f4();

}
