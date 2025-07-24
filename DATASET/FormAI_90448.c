//FormAI DATASET v1.0 Category: Recursive ; Style: surrealist
#include <stdio.h>

int recursive_function(int num) {
    if(num % 2 == 0) {
        printf("The number %d is even. Entering recursive loop...\n", num);
        recursive_function(num - 1);
    } else {
        printf("The number %d is odd. Entering recursive loop...\n", num);
        recursive_function(num + 1);
    }

    return 0;
}

int main() {
    printf("Welcome to the surrealist world of recursive functions!\n");
    printf("Please enter an integer number to start the madness: ");

    int user_input;
    scanf("%d", &user_input);

    printf("Let the games begin...\n");

    recursive_function(user_input);

    printf("Congratulations, you made it out alive!\n");
    printf("Exiting the program. Surrealism is overrated anyway.\n");

    return 0;
}