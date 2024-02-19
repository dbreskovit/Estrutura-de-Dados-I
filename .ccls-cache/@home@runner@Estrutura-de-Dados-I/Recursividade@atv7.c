#include <stdio.h>

void printArr(int arr[], int size, int i)
{

    if (i >= size)
        return;

    printf("%d ", arr[i]);

    printArr(arr, size, i + 1);
}

int main()
{
    int array[] = {1, 1, 2, 3, 5};
    int tamanho = sizeof(array) / sizeof(array[0]);

    printf("Array:\n");
    printArr(array, tamanho, 0);

    return 1;
}
