//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: calm
#include <stdio.h>
#include <stdbool.h>

void printMenu() {
    printf("\nMain Menu:\n");
    printf("1. Record workout\n");
    printf("2. View workout history\n");
    printf("3. Edit workout\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    bool repeat = true;

    while (repeat) {
        printMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nRecording workout...\n");
                // implementation of recording workout
                break;
            case 2:
                printf("\nViewing workout history...\n");
                // implementation of viewing workout history
                break;
            case 3:
                printf("\nEditing workout...\n");
                // implementation of editing workout
                break;
            case 4:
                printf("\nExiting program...\n");
                repeat = false;
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}