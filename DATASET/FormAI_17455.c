//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int main() {
    char play_again = 'y';
    int fortune_num;

    while (play_again == 'y' || play_again == 'Y') {
        printf("\nWelcome to the Automated Fortune Teller!\n");
        printf("Choose a number between 1 and 5 to receive your fortune: ");
        scanf("%d", &fortune_num);

        switch (fortune_num) {
            case 1:
                printf("\nYour future is bright! You will achieve great success.\n");
                break;
            case 2:
                printf("\nBe cautious in the coming days. You may face challenges ahead.\n");
                break;
            case 3:
                printf("\nLove and romance are in your future. Enjoy the journey!\n");
                break;
            case 4:
                printf("\nFinancial success is on the horizon. Stay focused and stay the course.\n");
                break;
            case 5:
                printf("\nYour dreams will come true, but not without hard work and dedication.\n");
                break;
            default:
                printf("\nInvalid choice. Please choose a number between 1 and 5.\n");
                break;
        }

        printf("\nWould you like another fortune? (y/n): ");
        scanf(" %c", &play_again);
        if (play_again != 'y' && play_again != 'Y') {
            printf("\nThanks for playing. Goodbye!\n");
        }
    }

    return 0;
}