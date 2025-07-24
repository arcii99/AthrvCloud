//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;

    srand(time(NULL)); // initialize the random seed using the current time

    printf("Welcome to the Automated Fortune Teller! \n");

    do {
        printf("Please choose a number between 1 and 5: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 5) {
            printf("Invalid choice. Please choose a number between 1 and 5.\n");
        }

    } while (choice < 1 || choice > 5);

    switch(choice) {
        case 1:
            printf("Your fortune for today is: You will have a pleasant surprise.\n");
            break;
        case 2:
            printf("Your fortune for today is: You will receive some great news.\n");
            break;
        case 3:
            printf("Your fortune for today is: Your hard work will pay off.\n");
            break;
        case 4:
            printf("Your fortune for today is: You will meet someone new who will have a big impact on your life.\n");
            break;
        case 5:
            printf("Your fortune for today is: You will need to make a difficult decision, but trust your instincts.\n");
            break;
    }

    printf("Your lucky number for today is: %d\n", (rand() % 100) + 1);

    return 0;
}