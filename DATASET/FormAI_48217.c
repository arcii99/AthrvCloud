//FormAI DATASET v1.0 Category: Math exercise ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //Seeding the random number generator
    
    int num1 = rand() % 21; //Generating a random number between 0 and 20
    int num2 = rand() % 21; //Generating another random number between 0 and 20
    int answer = num1 + num2; //Getting the correct answer
    
    //Printing the math problem to the console
    printf("What is %d + %d?\n", num1, num2);
    
    //Taking the user's input
    int guess;
    scanf("%d", &guess);
    
    //Checking if the answer is correct
    if (guess == answer) {
        printf("Congratulations! You got the correct answer!\n");
    } else {
        printf("Sorry, the correct answer is %d.\n", answer);
    }
    
    return 0;
}