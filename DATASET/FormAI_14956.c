//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Automated Fortune Teller Program!\n\n");

    char options[5][100] = {
        "You will be very successful in your career.",
        "A new romantic relationship is on the horizon.",
        "You will be blessed with good health and long life.",
        "You will experience financial abundance.",
        "You will go on an exciting adventure soon."
    };

    char response;

    do {
        printf("Do you want your fortune read? (y/n)\n");
        scanf(" %c", &response);

        if (response == 'y') {
            printf("\nConsulting the oracle...\n\n");

            srand(time(NULL));
            int index = rand() % 5;

            printf("Your fortune is: %s\n\n", options[index]);

        } else if (response == 'n') {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid option. Please try again.\n");
        }
    } while (response != 'n');

    return 0;
}