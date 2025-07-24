//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: scalable
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//Function for generating random numbers
int generateRandom(int n)
{
    srand(time(NULL));
    return rand()%n;
}

int main()
{
    int number, guess, nguesses=1;
    number = generateRandom(100);
    printf("Guess the number between 1 and 100\n");
    //Loop for receiving guesses from user
    do
    {
        scanf("%d",&guess);
        if(guess < number)
        {
            printf("Enter a higher number!\n");
            nguesses++;
        }
        else if(guess > number)
        {
            printf("Enter a lower number!\n");
            nguesses++;
        }
        else
        {
            printf("Congratulations! You guessed the number in %d attempts!\n",nguesses);
        }
    } while (guess!=number);

    return 0;
}