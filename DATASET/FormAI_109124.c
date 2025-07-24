//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* fortunes[] = {
    "You will have a great day today!",
    "Your fortunes will improve in the next few days.",
    "You will meet a new friend soon.",
    "Don't worry, things will work out in the end.",
    "Expect some good news in the near future.",
    "Be careful, danger may lurk ahead.",
    "Success is just around the corner!",
    "A little effort will go a long way.",
    "You will find happiness in unexpected places.",
    "Be careful with your words, they have power.",
    "Your hard work will be rewarded.",
    "Don't give up, success is within reach.",
    "You will make a big change in your life soon.",
    "Be prepared for a pleasant surprise.",
    "You will have a long and happy life.",
    "Look for the silver lining in every cloud.",
    "Be the change you wish to see in the world.",
    "Take a chance, it will pay off in the end.",
    "You will find love when you least expect it.",
    "The future is bright, keep moving forward.",
};

int main()
{
    srand(time(0));
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");

    char name[100];
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = 0; // remove trailing newline

    printf("\nHello, %s! Here is your fortune for today:\n\n", name);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

    int index = rand() % 20;
    printf("%s\n", fortunes[index]);

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\nThank you for visiting the Automated Fortune Teller!\n");

    return 0;
}