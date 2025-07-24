//FormAI DATASET v1.0 Category: System administration ; Style: funny
#include <stdio.h>

int main() {
    printf("Welcome to the Program!\n");

    int menuOption;
    do {
        printf("\nPlease select an option:\n");
        printf("1. Clean up your computer\n");
        printf("2. Install useless software\n");
        printf("3. Shutdown the computer\n");
        printf("4. Exit the program\n");

        scanf("%d", &menuOption);

        switch (menuOption) {
            case 1:
                printf("Cleaning up computer....\n");
                printf("Done! Your computer is now sparkling clean!\n");
                break;
            case 2:
                printf("Installing useless software....\n");
                printf("Done! You now have more garbage on your computer than ever before!\n");
                break;
            case 3:
                printf("Are you sure you want to shutdown your computer? [y/n]\n");
                char answer;
                scanf(" %c", &answer);

                if (answer == 'y') {
                    printf("Shutting down computer....\n");
                    printf("Goodbye!\n");
                    return 0;
                } else {
                    printf("Phew, that was a close one!\n");
                }
                break;
            case 4:
                printf("Exiting the program....\n");
                printf("Thanks for using our program! We hope you enjoyed it.\n");
                return 0;
            default:
                printf("Invalid option selected. Please try again.\n");
                break;
        }
    } while (menuOption != 4);

    return 0;
}