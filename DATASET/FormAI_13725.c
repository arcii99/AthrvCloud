//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char answers[10][100] = {
        "It is certain.",
        "Without a doubt.",
        "You may rely on it.",
        "Yes, definitely.",
        "It is decidedly so.",
        "As I see it, yes.",
        "Most likely.",
        "Yes.",
        "Outlook good.",
        "Signs point to yes."};
    char question[100];
    int choice;
    srand(time(NULL)); //Seed the random number generator

    printf("Enter your question: ");
    scanf("%[^\n]s", question); //Read question from user input
    getchar(); //To remove \n from the buffer

    //Generate random number
    choice = rand() % 10;
    
    printf("\nQuestion: %s\n", question);
    printf("Answer: %s\n", answers[choice]);
    return 0;
}