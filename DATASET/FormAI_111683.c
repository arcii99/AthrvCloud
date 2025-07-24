//FormAI DATASET v1.0 Category: Recursive ; Style: futuristic
#include<stdio.h>

void recursive_function(int n, int sum)
{
    if(n == 0)
    {
        printf("The sum of the numbers is: %d\n", sum);
        return;
    }
    sum += n;
    recursive_function(n-1, sum);
}

int main()
{
    int n;
    printf("Enter a natural number: ");
    scanf("%d", &n);

    // input validation
    if(n <= 0)
    {
        printf("Invalid input!\n");
        return 0;
    }

    printf("Calculating the sum of the numbers from %d to 1 recursively...\n", n);
    recursive_function(n, 0);

    return 0;
}