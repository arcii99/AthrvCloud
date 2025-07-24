//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: energetic
#include<stdio.h>

int main()
{
    printf("Welcome to the unique C Checksum Calculator program!\n");
    printf("Please enter the number of integers that you would like to calculate the checksum for: ");
    int n;
    scanf("%d", &n);
    int checksum = 0;
    printf("\nPlease enter the integers:\n");
    for(int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        checksum += num;
    }
    printf("\nThe checksum is: %d\n", checksum);
    printf("Thank you for using the unique C Checksum Calculator!\n");
    return 0;
}