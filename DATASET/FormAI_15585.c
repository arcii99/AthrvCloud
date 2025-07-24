//FormAI DATASET v1.0 Category: Recursive ; Style: protected
#include <stdio.h>  
#include <stdlib.h>

void print_num(int num, int limit, int count);

int main()
{
    int num, limit;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter a limit: ");
    scanf("%d", &limit);

    if (num < limit) {
        printf("Printing numbers from %d to %d:\n", num, limit);
        print_num(num, limit, 0);
    } else {
        printf("The limit must be greater than the number.\n");
    }

    return 0;
}

void print_num(int num, int limit, int count)
{
    if (count == 10) { // limit how many numbers are printed on one line
        printf("\n");
        count = 0;
    }

    printf("%d ", num);
    count++;

    if (num == limit) {
        return;
    } else if (num < limit) {
        print_num(num + 1, limit, count);
    } else {
        print_num(num - 1, limit, count);
    }
}