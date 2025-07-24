//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator with the current time

    int fortune_number = rand() % 5; // generate a random number from 0 to 4

    printf("Greetings, fellow human. I am the Automated Fortune Teller. Are you ready to receive your fortune?\n"); // start of conversation

    char response[4];
    scanf("%s", response); // get user response
    if (response[0] == 'y' || response[0] == 'Y') {
        printf("Excellent. Your fortune awaits...\n");
        switch (fortune_number) {
            case 0:
                printf("You will discover a hidden talent in the near future. Embrace it.\n");
                break;
            case 1:
                printf("A great love will enter your life soon. Be open to it.\n");
                break;
            case 2:
                printf("You will experience a windfall of money in the coming weeks. Use it wisely.\n");
                break;
            case 3:
                printf("Your health will improve dramatically in the next month. Take advantage of it.\n");
                break;
            case 4:
                printf("A long-standing problem will finally be resolved in the near future. You'll feel a weight lifted off your shoulders.\n");
                break;
        }
    } else {
        printf("I understand. Perhaps another time. Goodbye.\n"); // end of conversation
    }

    return 0;
}