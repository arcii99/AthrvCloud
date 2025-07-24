//FormAI DATASET v1.0 Category: Memory management ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int *ptr;

    printf("Enter the number of integers you want to store: ");
    scanf("%d", &num);

    ptr = (int*) malloc(num * sizeof(int));

    if(ptr == NULL)                     
    {
        printf("Memory allocation failed!\n");
        exit(0);
    }

    printf("Enter %d integers: ", num);
    for(int i = 0; i < num; i++) 
    {
        scanf("%d", &ptr[i]);
    }

    printf("Your stored integers are: ");
    for(int i = 0; i < num; i++)
    {
        printf("%d ", ptr[i]);
    }

    free(ptr);
    ptr = NULL;

    return 0;
}