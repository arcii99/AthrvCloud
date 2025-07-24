//FormAI DATASET v1.0 Category: Educational ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, sum=0;
    float average;
    printf("Enter the number of elements you want to calculate the average for: ");
    scanf("%d",&num);
    int *ptr = (int*)calloc(num,sizeof(int)); // allocate memory using calloc

    for(int i=0;i<num;i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", (ptr+i));
        sum += *(ptr+i);
    }

    average = (float)sum/num;

    printf("The elements you entered are: ");
    for(int i=0;i<num;i++){
        printf("%d ", *(ptr+i));
    }

    printf("\nThe sum of elements is %d", sum);
    printf("\nThe average of elements is %.2f", average);

    free(ptr); // free memory
    return 0;
}