//Для решения задачи согласно варианту предоставить пользователю возможность выбора варианта ввода ( с клавиатуры, случайные числа из диапазона от А до В, из файла). Результат выводить на экран. Предлагать пользователю выводить массив в файл. При заполнении массива случайными числами и чтении его из файла, выводить массив на экран.  Все операции над массивом выполняются в пользовательских функциях. Каждое задание выполнять в отдельной функции.
//24.Определить количество элементов в заданном массиве, отличающихся от минимального на 9. Найти максимальный из отрицательных элементов и поменять его местами с последним элементом массива. Вставить на 3-ю позицию значение минимального элемента. Циклически сдвинуть массив вправо на 1 элемент.
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
using namespace std;

void vvodn(int &n)
{
    printf("Введите количество элементов массива: ");
    do{
        scanf("%d",&n);
    }
    while(n<1||n>101);
}

//ввод массива с клавиатуры
void array1(int *array, int &n)
{
    vvodn(n);
    for (int i=0;i<n;i++)
    {
        printf("a[%d]=",i);
        scanf("%d",&array[i]);
    }
    printf("\n");
}

//ввод массива из диапазона от А до В(случайные числа)
void array2(int *array, int &n)
{
    srand(time(NULL));

    vvodn(n);
    int a,b,c=0;
    printf("Введите границы диапазона\n");
    printf("A= ");
    scanf("%d",&a);
    printf("B= ");
    scanf("%d",&b);
    //меняем А и В местами, если ввод не верный
    if(a>b)
    {
        printf("Ввод границ диапазона некорректный, но сейчас мы это исправим\n");
        c=a;
        a=b;
        b=c;
        printf("Теперь А= %d, а В= %d\n",a,b);
    }
    printf("\n");
    printf("Массив из случайных чисел:\n");
    for (int i=0;i<n;i++)
    {
        array[i]=rand()%(b-a+1)+a;
        printf("a[%d]=%d\n",i,array[i]);
    }
    printf("\n");
}

//ввод массива из файла
void array3(int *array, int &n)
{
    n=0;
    FILE *file1;
    file1=fopen("/Users/daria/учёба/program13/file1.txt","rt");
    while(!feof(file1))
    {
        fscanf(file1,"%d",&array[n]);
        n+=1;
    }
    printf("\n");
}

//кол-во элементов отличающихся от минимального на 9. Вставить на 3-ю позицию значение минимального элемента
void min9(int *array, int &n)
{
    int arr=0;
    arr=array[2];
    int min=array[0],count=0;
    for (int i=0;i<n;i++)
    {
        if (array[i]<min)
            min=array[i];
    }
    printf("Минимальное число в массиве равно %d\n\n",min);
    
    for (int i=0;i<n;i++)
     {
      if (array[i]-min==9)
          count+=1;
     }
    printf("Количество элементов в заданном массиве, отличающихся от минимального на 9 равно %d\n", count);
    array[2]=min;
    n+=1;
    for (int i=(n-1);i>3;i--)
    {
        array[i]=array[i-1];
    }
    array[3]=arr;
    printf("Массив со вставленным на 3 позицию минимальним элементом массива:\n");
}

//Найти максимальный из отрицательных элементов и поменять его местами с последним элементом массива
void maxotric(int *array, int &n)
{
    int otric=array[0],poz=0,poz1=0;
    for (int i=0;i<n;i++)
    {
        if (array[i]<0)
            otric=array[i];
    }
    for (int i=0;i<n;i++)
    {
        if ((array[i]>otric)&&(array[i]<0))
            otric=array[i];
    }
    for (int i=0;i<n;i++)
    {
        if (array[i]==otric)
            poz=i;
    }
    poz1=array[poz];
    array[poz]=array[n-1];
    array[n-1]=poz1;
    printf("Массив с поменянными местами максимального отрицательного элемента с последним:\n");
}


//сдвиг всех элементов массива на 1 вправо
void sdvig(int *array, int &n)
{
    int a;
    a=array[n-1];
    for (int i=(n-1);i>0;i--)
    {
        array[i]=array[i-1];
    }
    array[0]=a;
    printf("Массив после циклического сдвига всех элементов на 1 вправо:\n");
}

//вывод массива
void vivod(int *array,int &n)
{
    for (int i=0;i<n;i++)
        printf("a[%d]=%d\n",i,array[i]);
    printf("\n");
}

int main()
{
    int array[100],n=0,var;
    
    printf("Выберите вaриант ввода:\n");
    printf("1 - ввод с клавиатуры\n");
    printf("2 - ввод случайных чисел из диапазона от A до B\n");
    printf("3 - ввод из файла\n");
    do
    {
        printf("Вы выбрали вариант №");
        scanf("%d",&var);
        if (var<1 || var>3)
            printf("Введите число от 1 до 3\n");
    }
    while (var<1 || var>3);
    
    if (var==1)
        array1(array,n);
        
    if (var==2)
        array2(array,n);
    
    if (var==3)
    {
        array3(array,n);
        int vibor;
        printf("Хотите увидеть массив, находящийся в файле?\n");
        printf("Введите 1, если да\n");
        printf("Введите 2, если нет\n");
        do
        {
            scanf("%d",&vibor);
            printf("\n");
            if (vibor<1 || vibor>2)
                printf("Введите 1 или 2\n");
        }
        while(vibor<1 || vibor>2);
        if (vibor==1)
        {
            printf("Массив в файле:\n");
            vivod(array,n);
        }
    }
    min9(array,n);
    vivod(array,n);
    maxotric(array,n);
    vivod(array,n);
    sdvig(array,n);
    vivod(array,n);
    
    int zapis;
    printf("Хотите записать новый массив в файл?\n");
    printf("Введите 1, если да\n");
    printf("Введите 2, если нет\n");
    do
    {
        scanf("%d",&zapis);
        printf("\n");
        if (zapis<1 || zapis>2)
            printf("Введите 1 или 2\n");
    }
    while(zapis<1 || zapis>2);
    if (zapis==1)
    {
        FILE *file2;
        file2=fopen("/Users/daria/учёба/program13/array2.txt","w");
        for (int i=0;i<n;i++)
        {
            fprintf(file2,"%d\n",array[i]);
        }
        fclose(file2);
    }
    
    return 0;
}
