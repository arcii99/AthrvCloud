//FormAI DATASET v1.0 Category: Memory management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *ptr, sum = 0;
    printf("Enter number of elements: ");
    scanf("%d", &num);
    ptr = (int*)malloc(num * sizeof(int));
    if(ptr == NULL)                     
    {
        printf("Memory allocation failed."); 
        exit(0);                            
    }
    printf("Enter elements of the array: ");
    for(int i=0;i<num;i++)
    {
        scanf("%d",ptr+i);
        sum += *(ptr+i);
    }
    printf("The array elements are: ");
    for(int i=0;i<num;i++)
    {
        printf("%d ",*(ptr+i));
    }
    printf("\nSum of array elements = %d",sum);
    free(ptr);                               
    return 0;
}