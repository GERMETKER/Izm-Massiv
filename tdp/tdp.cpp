#include <random>
#include <Windows.h>
#include <iostream>
void DynArr(int*& arr, int& size);
void DelDynArr(int*& arr);
void InDynArr(int*& arr, int& size);
void PrDynArr(int*& arr, int& size);
void AddElToEnDynArr(int*& arr, int& size, int element);
void AddElByIn(int*& arr, int& size, int element, int index);
void ErElByIn(int*& arr, int& size, int index);
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size;
    int* arr;
    int element;
    int index;
    std::cout << "Введите кол-во элементов\n";
    std::cin >> size;
    std::cout << "Введите элемент\n";
    std::cin >> element;
    std::cout << "Введите индекс\n";
    std::cin >> index;
    DynArr(arr, size);
    InDynArr(arr, size);
    PrDynArr(arr, size);
    ErElByIn(arr, size, index);
    PrDynArr(arr, size);
    DelDynArr(arr);
    return 0;
}
void DynArr(int*& arr, int& size)
{
    arr = new int[size];

}
void DelDynArr(int*& arr)
{
    delete[]arr;
}
void InDynArr(int*& arr, int& size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = i;
    }
}
void PrDynArr(int*& arr, int& size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
void AddElToEnDynArr(int*& arr, int& size, int element)
{
    int* arr2 = new int [size];
    for (int i = 0; i < size; i++)
    {
        arr2[i] = arr[i];
    }
    DelDynArr(arr);
    size++;
    DynArr(arr, size);
    for (int i = 0; i < size; i++)
    {
        arr[i] = arr2[i];
    }
    arr[size - 1] = element;
    DelDynArr(arr2);
}
void AddElByIn(int*& arr, int& size, int element, int index)
{
    int* arr2 = new int [size];
    for (int i = 0; i < size; i++)
    {
        arr2[i] = arr[i];
    }
    DelDynArr(arr);
    size++;
    DynArr(arr, size);
    for (int i = 0, j = 0; i < size; i++, j++)
    {
        if (i != index-1)
        {
            arr[i] = arr2[j];
        }
        else
        {
            arr[i] = element;
            j = j - 1;
        }
    }
    DelDynArr(arr2);
}
void ErElByIn(int*& arr, int& size, int index)
{
    int* arr2 = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr2[i] = arr[i];
    }
    DelDynArr(arr);
    size--;
    DynArr(arr, size);
    for (int i = 0, j = 0; i < size; i++, j++)
    {
        if (i != index - 1)
        {
            arr[i] = arr2[j];
        }
        else
        {
            j++;
            arr[i] = arr2[j];
        }
    }
    DelDynArr(arr2);
}