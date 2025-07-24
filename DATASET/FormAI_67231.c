//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random numbers
int random_number(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

// main function
int main()
{
    // initialize random seed
    srand(time(0));

    // array of fortunes
    char *fortunes[] = {"It is certain", "It is decidedly so", "Without a doubt", "Yes, definitely", "You may rely on it",
                         "As I see it, yes", "Most likely", "Outlook good", "Yes", "Signs point to yes", "Reply hazy try again",
                         "Better not tell you now", "Cannot predict now", "Concentrate and ask again", "Don't count on it",
                         "Outlook not so good", "My sources say no", "Very doubtful"};

    printf("Welcome to the Automated Fortune Teller!\n");

    // loop to ask user for their question
    while(1) 
    {
        printf("What is your question? (type 'quit' to exit)\n");
        char question[50];
        scanf("%s", question);

        // check if user wants to quit
        if (strcmp(question, "quit") == 0)
            break;

        // generate random fortune
        int index = random_number(0, 17);
        char *fortune = fortunes[index];

        // print fortune
        printf("%s\n", fortune);
    }

    printf("Thanks for using the Automated Fortune Teller!\n");

    return 0;
}