//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Dennis Ritchie
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main() 
{ 
    int num, guess, tries = 0; 
    
    srand(time(0)); 
    num = rand() % 100; 

    printf("Welcome to the Guessing Game!\n"); 

    do 
    { 
        printf("Guess the number (between 0 and 99): "); 
        scanf("%d", &guess); 

        if (guess < num) 
            printf("Too low, try again!\n"); 
        else if (guess > num) 
            printf("Too high, try again!\n"); 
        else 
            printf("Congratulations, you won in %d tries!\n", tries); 

        tries++; 

    } while (guess != num); 

    return 0; 
}