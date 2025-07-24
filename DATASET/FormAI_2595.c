//FormAI DATASET v1.0 Category: Arithmetic ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main() {

    int* ptr;
    int num, sum = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &num);

    ptr = (int*) malloc(num * sizeof(int));

    if(ptr == NULL)                     
    {
        printf("Error! memory not allocated!");
        exit(0);
    }

    printf("Enter the elements: ");
    for(int i = 0; i < num; i++)
    {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }

    printf("The elements you entered are: ");
    for(int i = 0; i < num; i++)
    {
        printf("%d ", *(ptr + i));
    }

    printf("\n\nThe sum of the elements is: %d", sum);

    free(ptr);
    return 0;
}