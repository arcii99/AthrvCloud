//FormAI DATASET v1.0 Category: Recursive ; Style: synchronous
#include <stdio.h>

// recursive function to add numbers from start to end
int sum(int start, int end)
{
    if(start > end)
        return 0;
    return start + sum(start + 1, end);
}

int main()
{
    int start_num, end_num, total_sum;

    printf("Enter the starting number: ");
    scanf("%d", &start_num);

    printf("Enter the ending number: ");
    scanf("%d", &end_num);

    total_sum = sum(start_num, end_num);
    printf("The sum of numbers between %d and %d is %d\n", start_num, end_num, total_sum);

    return 0;
}