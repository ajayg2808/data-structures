#include <stdio.h>

int main(int argc, char **argv)
{
    int arr[3][3];
    printf("\nEnter array elements: ");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\nArray elements: ");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
    }
    printf("\nArray elements with there addresses: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t= %d\n", &arr[i][j], arr[i][j]);
        }
    }

    int *ptr = arr;
    int ptrVal = (int)arr;
    printf("\nBase address pointer = %d\n", ptr);
    printf("Base address to integer: %d\n", ptrVal);

    printf("\nArray elements using 1D pointer: \n");
    for (int i = 0; i < 9; i++)
    {
        printf("%d + %d = %d -> %d\n", ptr, i, ptr + i, ptr[i]);
    }

    printf("\nArray elements using index formula (2D pointer): \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("BAP + (I * N + J) =\t%d + ( %d * %d + %d ) =\t%d + %d =\t%d", ptr, i, 3, j, ptr, i * 3 + j, ptr + (i * 3 + j));
            printf("\t --> %d\n", *(int *)(ptr + (i * 3 + j)));
        }
    }

    printf("\nArray elements using index formula (integer as 2D pointer): \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("BA + (DT * (I * N + J)) = \t%d + ( %d * ( %d * %d + %d )) = \t%d", ptrVal, sizeof(int), i, 3, j, ptrVal + (sizeof(int) * (i * 3 + j)));
            printf("\t --> %d\n", *(int *)(ptrVal + (sizeof(int) * (i * 3 + j))));
        }
    }
    return 0;
}