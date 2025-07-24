//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the CyberFortune Teller!\n");
    printf("Please enter your name: \n");

    char name[20];
    scanf("%s", &name);

    printf("Hello, %s! Please concentrate on your question and press enter to shake the magic eight ball...\n", name);
    getchar();

    srand(time(NULL));
    int random = rand() % 20;
    char fortune[20][100] = {"It is certain.", 
                             "Without a doubt.", 
                             "You may rely on it.", 
                             "Yes, definitely.", 
                             "It is decidedly so.", 
                             "As I see it, yes.", 
                             "Most likely.", 
                             "Yes.", 
                             "Outlook good.", 
                             "Signs point to yes.", 
                             "Reply hazy, try again.", 
                             "Better not tell you now.", 
                             "Ask again later.", 
                             "Cannot predict now.", 
                             "Concentrate and ask again.", 
                             "Don't count on it.", 
                             "Outlook not so good.", 
                             "My sources say no.", 
                             "Very doubtful.", 
                             "My reply is no."};
    printf("The CyberFortune Teller says: %s\n", fortune[random]);
    return 0;
}