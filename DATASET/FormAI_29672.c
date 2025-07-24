//FormAI DATASET v1.0 Category: Recursive ; Style: Sherlock Holmes
#include <stdio.h>

int recursive_sum(int num)
{
    if(num == 0) // base case
        return 0;
    else
        return num + recursive_sum(num - 1); // recursive case
}

int main()
{
    int num = 10;
    int sum = recursive_sum(num);
    printf("The sum of natural numbers up to %d is: %d\n", num, sum);
    return 0;
}