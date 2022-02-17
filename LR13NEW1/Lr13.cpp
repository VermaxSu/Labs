#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

void Input (int &n)
{
    cout<< "Введите количество элементов массива";
    do
    {
        cin>> n;
    }
    while (n < 1 || n > 101);
}

void Array1 (int *a, int &n)
{
    Input(n);

    for (int i = 0;i < n;i ++)
    {
        cout<< "a["<< i<< "]= ";
        cin>> &array[i];
    }
    cout<< endl;
}

void Array2 (int *array, int &n)
{
    srand ( time (NULL));

    Input(n);

    int a, b, c = 0;
    cout<< "Введите границы диапазона"<< endl;
    cout<< "a= "; cin>> a;
    cout<< "b= "; cin>> b;

    if (a > b)
    {
        c = a;
        a = b;
        b = c;
    }
    cout<< "Массив из случайных чисел"<< endl;
    for (int i = 0;i < n;i ++)
    {
        array[i] = rand() % (b - a + 1) + a;
        cout<< "a["<< i<< "]= "<< array[i];
    }
    cout<< endl;
}

void Array3 (int *array, int &n)
{
    n = 0;
    FILE *file1;
    file1 = fopen("C:/Users/Матвей/Desktop/LR13new\file1.txt", "rt");
    while (!feof (file1))
    {
        fscanf(file1, "%d", &array[n]);
        n += 1;
    }
    cout<<endl;
}

void Min9 (int *array, int &n)
{
    int arr = array[2], min = array[0], count = 0, pozition = 0;

    for (int i = 0;i < n;i ++)
        if (array[i] < min)
        {
            min = array[i];
            pozition = i;
        }
    cout<< "Минимальное число в массиве равно "<< min;

    for (int i = 0;i < n;i ++)
        if (array[i] - min == 9)
            count += 1;
    cout<< "Количество элементов в заданном массиве, отличающихся от минимального на 9 равно ", count;
    array[3] = arr;
    cout<< "Массив со вставленным на 3 позицию минимальным элементом массива:"<< endl;
}

void MaxNegative (int *array, int &n)
{
    int negative = array[0], pozition = 0, pozition2 = 0;

    for (int i = 0;i < n;i ++)
        if (array[i] < 0)
            negative = array[i];
    for (int i = 0;i < n; i++)
        if (array[i] > negative && array[i] < 0)
            negative = array[i];
    for (int i = 0;i < n;i ++)
        if (array[i] == negative)
            pozition = i;
    pozition2 = array[pozition];
    array[pozition] = array[n - 1];
    array[n - 1] = pozition2;
    cout<< "Массив с измененными местами максимального отрицательного элемента с последним"<< endl;
}

void ShiftRight (int *array, int &n)
{
    int a = array[n - 1];
    for (int i = n-1;i > 0;i --)
        array[i] = array[i - 1];
    array[0] = a;
    cout<< "Массив после циклического сдвига всех элементов на 1 вправо:"<< endl;
}

void Output (int *array, int &n)
{
    for (int i = 0;i < n;i ++)
        cout<< "a["<< i<< ']= '<< array[i];
    cout<< endl;
}

int main()
{
    int array[100], n = 0, var;
    cout<< "Выберете вариант ввода массива:"<< endl;
    cout<< "1 - ввод с клавиатуры"<< endl;
    cout<< "2 - ввод случайных чисел из диапазона от А до В"<< endl;
    cout<< "3 - ввод из файла"<< endl;

    do {
        cout<< "Выбран вариант "; cin>>var;
        if (var < 1 || var > 3)
            cout<< "Введите число от 1 до 3"<< endl;
    }
    while (var < 1 || var > 3);

    if (var == 1)
        Array1(array, n);
    if (var == 2)
        Array2(array, n);
    if (var == 3)
    {
        Array3(array, n);
        int selection;
        cout<< "Вывести массив, находящийся в файле?"<< endl;
        cout << "Если да, то введите 1. В противном случае введите 2."<< endl;
        do
        {
            cin>> selection; cout<< endl;
            if (selection < 1 || selection > 2)
                cout<< "Введите 1 или 2."<< endl;
        } while (selection < 1 || selection > 2);

        if (selection == 1)
        {
            cout<< "Массив в файле:"<< endl;
            Output(array, n);
        }
    }

    Min9(array, n);
    Output(array, n);
    MaxNegative(array, n);
    Output(array, n);
    ShiftRight(array, n);
    Output(array, n);

    int record;
    cout<< "Записать полученный массив в файл?"<< endl;
    cout<< "Если да, то введите 1. В противном случае введите 2."<< endl;
    do
    {
        cin>> record; cout<< endl;
        if (record < 1 || record > 2)
            cout<< "Введите 1 или 2"<< endl;
    } while (record < 1 || record > 2);

    if (record == 1)
    {
        FILE *file2;
        file2 = fopen("C:/Users/Матвей/Desktop/LR13new/file2.txt", "w");
        for (int i = 0, i < n; i ++)
            fprintf(file2, "%d\n", array[i]);
        fclose(file2);
    }

    return 1;
}