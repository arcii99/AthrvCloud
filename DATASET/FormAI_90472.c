//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random number generator
    
    printf("Welcome to the Automated Fortune Teller Program!\n\n");
    printf("Think of a question and ask it out loud.\n");
    printf("(Press Enter to reveal your fortune...)\n");
    getchar(); // wait for user to press Enter
    
    int random_num = rand() % 10 + 1; // generate random number between 1 and 10
    
    switch(random_num) {
        case 1:
            printf("The answer is unclear. Try again later.\n");
            break;
        case 2:
            printf("Yes, definitely!\n");
            break;
        case 3:
            printf("It is decidedly so.\n");
            break;
        case 4:
            printf("Without a doubt.\n");
            break;
        case 5:
            printf("You may rely on it.\n");
            break;
        case 6:
            printf("As I see it, yes.\n");
            break;
        case 7:
            printf("Most likely.\n");
            break;
        case 8:
            printf("Outlook good.\n");
            break;
        case 9:
            printf("Signs point to yes.\n");
            break;
        case 10:
            printf("My sources say no.\n");
            break;
    }
    
    return 0;
}