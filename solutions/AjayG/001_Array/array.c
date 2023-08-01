#include <stdio.h>

int main(int argc, char **argv)
{
    int arr[5];
    printf("\nEnter array elements: ");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nArray elements: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nArray elements with there addresses: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t= %d\n", &arr[i], arr[i]);
    }

    int *ptr = arr;
    int ptrVal = (int)arr;
    printf("Base address pointer = %d\n", ptr);
    printf("Base address to integer: %d\n", ptrVal);

    printf("\nArray elements using index formula (pointer): \n");
    for (int i = 0; i < 5; i++)
    {
        printf("BAP + I = \t%d + %d = \t%d", ptr, i, ptr + i);
        printf("\t --> %d\n", *(ptr + i));
    }
    printf("\nArray elements using index formula (integer as pointer): \n");
    for (int i = 0; i < 5; i++)
    {
        printf("BA + (DT * I) = \t%d + ( %d * %d ) = \t%d", ptrVal, sizeof(int), i, ptrVal + (sizeof(int) * i));
        printf("\t --> %d\n", *(int *)(ptrVal + (sizeof(int) * i)));
    }
    return 0;
}