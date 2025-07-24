//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the C Automated Fortune Teller!\n\n");
    printf("Think of a question and I will give you an answer...\n");
    
    srand(time(NULL)); // Seed the random number generator with current time
    
    int randomAnswer = rand() % 10; // Generate a random number between 0 and 9
    
    switch (randomAnswer) {
        case 0:
            printf("It is certain.\n"); 
            break;
        case 1:
            printf("It is decidedly so.\n");
            break;
        case 2:
            printf("Without a doubt.\n");
            break;
        case 3:
            printf("Yes, definitely.\n");
            break;
        case 4:
            printf("You may rely on it.\n");
            break;
        case 5:
            printf("As I see it, yes.\n");
            break;
        case 6:
            printf("Most likely.\n");
            break;
        case 7:
            printf("Outlook good.\n");
            break;
        case 8:
            printf("Yes.\n");
            break;
        case 9:
            printf("Signs point to yes.\n");
            break;
        default:
            printf("Error: Invalid fortune.\n");
            break;
    }
    
    return 0;
}