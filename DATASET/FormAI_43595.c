//FormAI DATASET v1.0 Category: Math exercise ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generate_random_number(int lower, int upper) {
    srand(time(NULL));
    int random_number = (rand() % (upper - lower + 1)) + lower;
    return random_number;
}

int main() {
    int num1, num2, num3, num4, num5, result;
    num1 = generate_random_number(1, 10);
    num2 = generate_random_number(1, 10);
    num3 = generate_random_number(1, 10);
    num4 = generate_random_number(1, 10);
    num5 = generate_random_number(1, 10);

    printf("Find the sum of the following numbers:\n");
    printf("%d + %d + %d + %d + %d = ", num1, num2, num3, num4, num5);

    scanf("%d", &result);

    int correct_answer = num1 + num2 + num3 + num4 + num5;

    if (result == correct_answer) {
        printf("Congratulations! That is correct.");
    } else {
        printf("Incorrect. The correct answer is %d.", correct_answer);
    }

    return 0;
}