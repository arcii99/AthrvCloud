//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("Welcome to the Checksum Calculator! Let's get started.\n");
    int n;
    printf("Enter the number of integers you want to calculate checksum of: ");
    scanf("%d", &n);
    if(n < 1)
    {
        printf("Invalid input!\n");
        return 0;
    }
    int* arr = (int*)malloc(sizeof(int)*n);
    printf("Enter the integers:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int checksum = 0;
    for(int i=0; i<n; i++)
    {
        checksum += arr[i];
    }
    printf("The sum of the integers is %d\n", checksum);
    return 0;
}