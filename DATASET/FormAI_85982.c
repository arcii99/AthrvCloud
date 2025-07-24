//FormAI DATASET v1.0 Category: Pattern printing ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Welcome to the surreal world of C Pattern printing!\n");

    for (int i = 1; i <= 10; i++) {

        for (int j = 1; j <= 10; j++) {

            int random_number = rand() % 100;
            char character = ' ';

            if (random_number % 5 == 0) {
                character = 'C';
            } else if (random_number % 7 == 0) {
                character = 'O';
            } else if (random_number % 11 == 0) {
                character = 'D';
            } else if (random_number % 13 == 0) {
                character = 'E';
            } else if (random_number % 17 == 0) {
                character = 'S';
            } else if (random_number % 19 == 0) {
                character = 'A';
            } else if (random_number % 23 == 0) {
                character = 'R';
            } else if (random_number % 29 == 0) {
                character = 'Y';
            }

            printf("%c ", character);

        }

        printf("\n");

    }

    printf("Thank you for experiencing the surreal world of C Pattern printing!\n");

    return 0;

}