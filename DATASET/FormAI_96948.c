//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Cryptic
#include <stdio.h>

int main(void)
{
    printf("Welcome to the cryptic periodic table quiz!\n\n");

    // Initializing arrays for questions and answers
    char questions[10][50] = {"32.O-16.Z?", "28.Ni-58.7Cu-93.Tc-?", "75.Ta-?", "80.Hg-?", "51.Sb-121?", "2.He-?", "29.Cu-?", "7.N-?", "16.S-?", "12.Mg-?"};
    char answers[10][10] = {"S", "Co", "Re", "At", "Te", "B", "Cu", "N", "P", "Ca"};

    // Looping through the questions and asking the user for their guess
    for(int i=0; i<10; i++)
    {
        printf("What element is represented by the code %s\n", questions[i]);

        char guess[10];
        scanf("%s", guess);

        // Checking if the user's guess is correct
        if(strcmp(guess, answers[i]) == 0)
        {
            printf("Congratulations, your guess is correct!\n\n");
        }
        else
        {
            printf("Sorry, that's incorrect. The correct answer is %s.\n\n", answers[i]);
        }
    }

    printf("Thanks for playing!\n");

    return 0;
}