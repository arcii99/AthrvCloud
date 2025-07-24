//FormAI DATASET v1.0 Category: Recursive ; Style: portable
#include <stdio.h>

int recursive_sum(int num);

int main() {
    int num, sum;
    printf("Enter the number: ");
    scanf("%d", &num);
    sum = recursive_sum(num);
    printf("The sum of first %d natural numbers is %d\n", num, sum);
    return 0;
}

int recursive_sum(int num) {
    if (num == 0) {
        return 0;
    }
    else {
        return num + recursive_sum(num - 1);
    }
}