#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *elem1, const void *elem2)
{
    int left = *((int*)elem1);
    int right = *((int*)elem2);

    if (left % 2 != 0 && right % 2 == 0)
    {
        return -1;
    }
    
    if (left % 2 == 0 && right != 0)
    {
        return 1;
    }

    return (left - right);
}

int main()
{
    int size;

    printf("What is the size of the array?: ");
    scanf("%d", &size);

    int input[size];

    printf("\nEnter the %d values for the array.", size);

    for (int i = 0; i < size; i++)
    {
        printf("\n%d.", i + 1);
        scanf("%d", &input[i]);
    }

    printf("\nHere is the array before sorting.\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ,", input[i]);
    }

    qsort(input, size, sizeof(int), compare_int);

    printf("\nHere is the array after sorting.\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ,", input[i]);
    }

    return 0;
}

