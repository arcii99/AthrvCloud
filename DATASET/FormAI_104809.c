//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    char name[50];
    int age;
    char question[100];
    char answers[7][50] = {
        "Yes definitely.", 
        "It is decidedly so.",
        "Without a doubt.",
        "Reply hazy, try again.",
        "Cannot predict now.",
        "Don't count on it.",
        "My sources say no."
    };

    printf("Welcome to the Automated Fortune Teller. Please enter your name:\n");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Hello %s! What's your age?\n", name);
    scanf("%d", &age);

    if (age < 18)
    {
        printf("Sorry %s, you need to be 18 years and above to use this automated fortune teller.\n", name);
        return 0;
    }

    printf("Please ask your question:\n");
    getchar(); // to consume the extra new line character after age input
    fgets(question, sizeof(question), stdin);
    question[strcspn(question, "\n")] = '\0';

    srand(time(0));
    int answer_index = rand() % 7;
    printf("%s, your answer to '%s' is: %s\n", name, question, answers[answer_index]);

    return 0;
}