//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char play_again = 'y';
    srand(time(0)); // initialize random seed

    // array of different fortunes
    char *fortunes[] = {
        "You will have good luck in your future endeavors.",
        "Beware of those who appear friendly, they may not have your best interests at heart.",
        "The path to success will be a difficult one, but the rewards will be worth it.",
        "You will meet someone special in the near future.",
        "Good news is on the horizon.",
        "Be cautious of making impulsive decisions, they may lead to regret.",
        "Your persistence will pay off in the end.",
        "Your kindness towards others will open new doors for you.",
        "An unexpected event will bring great joy to your life.",
        "Be open to new experiences, they may lead to great opportunities."
    };

    while(play_again == 'y') { // loop until user chooses not to play again
        int index = rand() % 10; // generate random index between 0-9
        printf("The fortune teller says: %s\n", fortunes[index]);

        // prompt user to play again
        printf("Would you like another fortune? (y/n): ");
        scanf(" %c", &play_again);

        // clear input buffer
        while(getchar() != '\n');
        printf("\n");
    }

    return 0;
}