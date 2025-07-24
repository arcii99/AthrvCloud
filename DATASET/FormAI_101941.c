//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //initialize the random number generator with a seed value
    srand(time(NULL));
    printf("Welcome to the Automated Fortune Teller! \n");

    //array to hold possible fortune messages
    char *fortunes[] = {
        "You will encounter great success in the near future.",
        "A new opportunity will present itself to you soon.",
        "Your hard work will pay off in unexpected ways.",
        "Your greatest achievement is yet to come.",
        "You will soon make a valuable connection in your field.",
        "An unexpected financial gain is coming your way."
    };

    //generate random number between 0 and the number of messages in the array
    int random_num = rand() % (sizeof(fortunes)/sizeof(fortunes[0]));

    //print the fortune message
    printf("\nYour Fortune: %s\n", fortunes[random_num]);

    return 0;
}