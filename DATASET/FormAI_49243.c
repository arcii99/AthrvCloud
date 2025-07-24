//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main()
{
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    char name[50];
    scanf("%s", name);
    printf("\nHello %s, what would you like to know?\n", name);
 
    srand(time(NULL));
    int fortune = rand() % 5;
 
    switch (fortune) {
        case 0:
            printf("The future is looking bright, %s!\n", name);
            break;
        case 1:
            printf("Be cautious in your decisions, %s. They could have unexpected consequences.\n", name);
            break;
        case 2:
            printf("Your hard work will pay off in the end, %s.\n", name);
            break;
        case 3:
            printf("You will face a challenge in the near future, but you will overcome it, %s.\n", name);
            break;
        case 4:
            printf("Your future is uncertain, %s. But whatever happens, you must remain strong.\n", name);
            break;
    }
 
    return 0;
}