//FormAI DATASET v1.0 Category: Math exercise ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator
    
    int num1 = (rand() % 51) + 50; // generate a random number between 50 and 100
    int num2 = (rand() % 11) + 10; // generate a random number between 10 and 20
        
    printf("Welcome to the futuristic math exercise program!\n");
    printf("Solve the following equation: %d * %d + %d = ?\n", num1, num2, num1 * num2);
        
    int answer;
    scanf("%d", &answer); // get user input for the answer
        
    if (answer == num1 * num2 + num2) {
        printf("Congratulations, you have solved the equation!\n");
    } else {
        printf("Sorry, that answer is incorrect. The correct answer is %d.\n", num1 * num2 + num2);
    }
        
    return 0;
}