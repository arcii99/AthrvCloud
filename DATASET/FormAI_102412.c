//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int randomNumber = rand() % 5;

    char* responses[5] = {
        "It is certain.", 
        "Without a doubt.", 
        "You may rely on it.", 
        "Reply hazy, try again.", 
        "Outlook not so good."
    };

    printf("Welcome to the Retro Automated Fortune Teller!\n");
    printf("Think of a yes or no question and I will tell you your fortune.\n");
    printf("Press any key to continue.");
    getchar();
    
    printf("\nGenerating fortune...\n");
    printf("%s\n", responses[randomNumber]);

    printf("Would you like to ask another question? (y/n)\n");
    char answer = getchar();

    while(answer == 'y' || answer == 'Y') {
        randomNumber = rand() % 5;
        printf("\nGenerating fortune...\n");
        printf("%s\n", responses[randomNumber]);

        printf("Would you like to ask another question? (y/n)\n");
        answer = getchar();
    }

    printf("Thank you for visiting the Retro Automated Fortune Teller!\n");
    return 0;
}