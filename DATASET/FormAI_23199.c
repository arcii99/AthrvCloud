//FormAI DATASET v1.0 Category: Math exercise ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// function to generate a random number between two values
int random_num(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    srand(time(NULL)); // seeding the random number generator
    int a, b, c, d;
    float result;
    char operator;

    while(1) {
        // generating random numbers and operator
        a = random_num(1, 10);
        b = random_num(1, 10);
        c = random_num(1, 10);
        d = random_num(1, 10);
        operator = random_num(0, 1) ? '+' : '-'; // randomly choosing between addition and subtraction

        // calculating the result
        if(operator == '+') {
            result = (float) (a + b) / (c + d);
        } else {
            result = (float) (a - b) / (c - d);
            result = roundf(result * 10) / 10; // rounding off to 1 decimal place
        }

        // printing the equation and asking user to solve
        printf("%d %c %d %c %d = ", a, operator, b, operator, c, operator, d);
        float user_answer;
        scanf("%f", &user_answer);

        // comparing user's answer with correct answer
        if(abs(user_answer - result) <= 0.1) {
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is %.1f\n", result);
        }
    }

    return 0;
}