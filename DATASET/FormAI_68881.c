//FormAI DATASET v1.0 Category: Game ; Style: beginner-friendly
#include <stdio.h>

int main() {

    int choice = 0;

    printf("Welcome to Adventureland!\n");
    printf("You are standing in a forest. There are three paths in front of you.\n");
    printf("Which path will you take?\n");

    while(choice != 3) {
        printf("1. Left path\n");
        printf("2. Middle path\n");
        printf("3. Right path\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("You take the left path and find a treasure chest. You win!\n");
                break;
            case 2:
                printf("You take the middle path and encounter a giant spider. Game over!\n");
                break;
            case 3:
                printf("You take the right path and fall into a pit. Game over!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    printf("Thanks for playing!\n");

    return 0;
}