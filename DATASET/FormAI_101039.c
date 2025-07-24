//FormAI DATASET v1.0 Category: Math exercise ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); //seed random number generator with current time 
    int a = rand() % 100; //generate a random number between 0 and 99
    int b = rand() % 100; //generate another random number between 0 and 99
    float c = (float)a/b; //calculate the quotient of a divided by b
    printf("What is %d divided by %d?\n", a, b); //ask the user for their answer
    float userInput;
    scanf("%f", &userInput);
    if(userInput == c){ //check if the user's answer is correct
        printf("Congratulations, you got it right!\n");
    }
    else{ //if the answer is wrong, help the user out by giving them a hint
        printf("Sorry, that is incorrect. Here is a hint: the quotient of %d divided by %d is %.2f\n", a, b, c);
    }

    return 0;
}