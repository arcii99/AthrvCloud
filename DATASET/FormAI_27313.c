//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Declare variables
    int num;
    char ans[20];

    // Seed random number generator
    srand(time(NULL));

    // Prompt user for their question
    printf("Welcome to the Automated Fortune Teller! Please ask your question.\n");
    printf("Question: ");
    scanf("%s", ans);

    // Generate random number and output corresponding fortune
    num = rand() % 10 + 1;

    if (num == 1) {
        printf("It is certain.\n");
    } else if (num == 2) {
        printf("It is decidedly so.\n");
    } else if (num == 3) {
        printf("Without a doubt.\n");
    } else if (num == 4) {
        printf("Yes - definitely.\n");
    } else if (num == 5) {
        printf("You may rely on it.\n");
    } else if (num == 6) {
        printf("As I see it, yes.\n");
    } else if (num == 7) {
        printf("Most likely.\n");
    } else if (num == 8) {
        printf("Outlook good.\n");
    } else if (num == 9) {
        printf("Signs point to yes.\n");
    } else {
        printf("Reply hazy, try again.\n");
    }

    return 0;
}