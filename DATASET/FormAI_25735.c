//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Ada Lovelace
#include <stdio.h>

void fibonacci(int n) {
    int first_num = 0, second_num = 1, next_num;

    printf("%d, %d, ", first_num, second_num);

    for(int i = 2; i < n; i++) {
        next_num = first_num + second_num;
        printf("%d, ", next_num);

        first_num = second_num;
        second_num = next_num;
    }
}

int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("The first %d terms of the Fibonacci sequence are: \n", n);
    fibonacci(n);

    return 0;
}