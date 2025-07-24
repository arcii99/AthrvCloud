//FormAI DATASET v1.0 Category: Memory management ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr, sum=0, n;
    printf("Enter size of array: ");
    scanf("%d",&n);

    ptr = (int*)malloc(n*sizeof(int)); // allocate memory dynamically

    if(ptr==NULL)
    {
        printf("Memory not allocated.\n"); // check if memory is allocated or not
        return 0;
    }
    else
    {
        printf("Memory successfully allocated using malloc.\n"); 

        for(int i=0; i<n; i++)
        {
            *(ptr+i) = i+1; // store values in the allocated memory
        }

        printf("The elements of the array are: ");
        for(int i=0; i<n; i++)
        {
            printf("%d ",*(ptr+i)); // print values stored in the allocated memory
            sum += *(ptr+i); // calculate the sum of all elements
        }

        printf("\nThe sum of the elements of the array is: %d\n",sum); // print the sum of all elements

        free(ptr); // free the dynamically allocated memory
        printf("Memory successfully freed using free.\n");
    }

    return 0;
}