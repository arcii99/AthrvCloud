//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[64];
    int age;
    int lucky_number;
    char question[256];

    // Ask for user's name and age
    printf("Hello, I am the Automated Fortune Teller. What is your name?\n");
    scanf("%s", name);
    printf("Nice to meet you, %s. How old are you?\n", name);
    scanf("%d", &age);

    // Generate a lucky number based on the user's age
    srand(time(NULL));
    lucky_number = rand() % age + 1;

    // Ask the user to ask a question
    printf("%s, please ask me a question and I will provide you with a fortune.\n", name);
    scanf(" %[^\n]s", question);

    // Generate a random number to determine the fortune
    int fortune_number = rand() % 5 + 1;
    switch (fortune_number) {
        case 1:
            printf("%s, your lucky number is %d, and the universe is on your side. Anything is possible.\n", name, lucky_number);
            break;
        case 2:
            printf("%s, be careful of who you trust, for they may betray you when you least expect it.\n", name);
            break;
        case 3:
            printf("%s, you will soon be presented with an exciting opportunity. Seize it and it will lead to great success!\n", name);
            break;
        case 4:
            printf("%s, it is time to let go of the past and focus on the present. The future is bright for you.\n", name);
            break;
        case 5:
            printf("%s, you will face a challenge in the near future, but with perseverance and determination, you will emerge victorious.\n", name);
            break;
    }

    return 0;
}