//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: energetic
#include <stdio.h> 

#define MAX_NUM 1000

int main() {
    int even_sum = 0;
    int odd_sum = 0;

    for (int i = 1; i <= MAX_NUM; i++) {
        if (i % 2 == 0) {
            even_sum += i;
        } else {
            odd_sum += i;   
        }
    }

    printf("The sum of even numbers between 1 and %d is: %d\n", MAX_NUM, even_sum);
    printf("The sum of odd numbers between 1 and %d is: %d\n", MAX_NUM, odd_sum);

    return 0;
}