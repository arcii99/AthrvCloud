//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: romantic
#include <stdio.h>
#include <string.h>

int main()
{
    char symbol[10];
    int atomic_number, choice;
    printf("Hello my love! Let's play a game to test your knowledge of the periodic table.\n");
    printf("Enter '1' to test your knowledge of symbols or '2' to test your knowledge of atomic numbers: ");
    scanf("%d", &choice);

    if(choice == 1)
    {
        printf("Alright, let's start with the symbol quiz.\n");
        printf("What element has the symbol 'Fe'?: ");
        scanf("%s", &symbol);
        if(strcmp(symbol, "Iron") == 0 || strcmp(symbol, "Fe") == 0)
        {
            printf("You got it right! Iron is such a strong and sturdy element, just like our love.\n");
        }
        else
        {
            printf("Oh no, you got it wrong. The correct answer is Iron. Don't worry, even Iron can rust, but our love is forever.\n");
        }
    }
    else if(choice == 2)
    {
        printf("Okay, let's test your knowledge of atomic numbers.\n");
        printf("What is the atomic number of Helium?: ");
        scanf("%d", &atomic_number);
        if(atomic_number == 2)
        {
            printf("You got it right! Helium is a noble gas, just like you are a noble person.\n");
        }
        else
        {
            printf("Oh no, you got it wrong. The correct answer is 2. But it's okay, you're still the light of my life.\n");
        }
    }
    else
    {
        printf("Oops, that was an invalid choice. Please select '1' for the symbol quiz or '2' for the atomic number quiz.\n");
    }

    printf("Thanks for playing my love. Let's continue exploring the wonderful world of chemistry together.\n");
    return 0;
}