//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Welcome message
    printf("Welcome to the Automated Fortune Teller Program!\n");

    // Seed the random number generator
    srand(time(NULL));

    // Ask for the user's name and store it in a variable
    char name[50];
    printf("What is your name?\n");
    fgets(name, sizeof(name), stdin);

    // Generate a random number between 1 and 5
    int fortune_num = rand() % 5 + 1;

    // Use a switch statement to generate a unique fortune for each number
    switch (fortune_num) {
        case 1:
            printf("%s, your future looks bright!\n", name);
            break;
        case 2:
            printf("%s, be on the lookout for new opportunities.\n", name);
            break;
        case 3:
            printf("%s, take time to focus on your health and well-being.\n", name);
            break;
        case 4:
            printf("%s, be careful with money in the coming weeks.\n", name);
            break;
        case 5:
            printf("%s, a long-awaited goal will soon be achieved.\n", name);
            break;
        default:
            printf("Error: Invalid fortune number.\n");
            break;
    }

    // Goodbye message
    printf("Thanks for using the Automated Fortune Teller Program!\n");

    return 0;
}