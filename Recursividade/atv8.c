#include <stdio.h>

int minArr(int arr[], int size)
{
    if (size == 1)
        return arr[0];

    int before = minArr(arr, size - 1);

    return (arr[size - 1] < before) ? arr[size - 1] : before;
}

int main()
{
    int array[] = {64, 25, 12, 22, 11};
    int size = sizeof(array) / sizeof(array[0]);

    int minValue = minArr(array, size);

    printf("O menor valor no vetor: %d\n", minValue);

    return 1;
}
