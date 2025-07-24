//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rand_num;
    char input;
    srand(time(NULL)); // Initialize random number generator with current time
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please ask your question and press enter to receive your answer.\n");
    do {
        printf("Your question: ");
        scanf("%c", &input);
        rand_num = rand() % 10; // Generate random number from 0-9
        switch (rand_num) {
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
                printf("Yes - definitely.\n");
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
        }
        printf("Ask another question? (y/n): ");
        scanf(" %c", &input); // Get input, avoid scanning newline character
    } while (input == 'y' || input == 'Y');
    printf("Thank you for using the Automated Fortune Teller!\n");
    return 0;
}