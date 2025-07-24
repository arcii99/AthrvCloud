//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed for random function
    int num1 = rand() % 10 + 1;
    int num2 = rand() % 10 + 1;
    int correct_answer = num1 + num2;
    int user_answer;
    int lives = 3;
    
    printf("You woke up in a mysterious room, and you can't find the exit.\n");
    printf("You see a glowing button with a number pad next to it.\n");
    printf("The screen displays two numbers: %d + %d\n", num1, num2);
    
    while (lives > 0) {
        printf("You have %d lives left. What's the answer? ", lives);
        scanf("%d", &user_answer);
        
        if (user_answer == correct_answer) {
            printf("The door to the next room opens.\n");
            num1 = rand() % 10 + 1;
            num2 = rand() % 10 + 1;
            correct_answer = num1 + num2;
            printf("The next room has two numbers: %d + %d\n", num1, num2);
        } else {
            printf("That's incorrect! You lost a life.\n");
            lives--;
        }
    }
    
    printf("You ran out of lives... Game over.\n");
    return 0;
}