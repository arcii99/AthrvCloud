//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: retro
#include <stdio.h>

int check_prime(int num);

int main()
{
    int num, i;
    printf("Welcome to the Retro Style Prime Number Generator!\n");
    printf("Enter a positive integer greater than 1: ");
    scanf("%d", &num);
    
    if(num <= 1)
    {
        printf("Invalid input! Please enter a positive integer greater than 1.\n");
        return 0;
    }
    
    printf("Prime numbers between %d and %d are: ", 2, num);
    
    for(i = 2; i <= num; i++)
    {
        if(check_prime(i) == 1)
        {
            printf("%d ",i);
        }
    }
    
    printf("\n");
    printf("Thanks for using the Retro Style Prime Number Generator!\n");
    
    return 0;
}

int check_prime(int num)
{
    int i;
    for(i = 2; i <= num/2; i++)
    {
        if(num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}