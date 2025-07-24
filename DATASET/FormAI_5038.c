//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t t;
    srand((unsigned)time(&t));

    char fortunes[7][50] = {"You will win the lottery tomorrow.",
                            "You will have a great day today.",
                            "Your future is very bright.",
                            "You will meet someone special soon.",
                            "You will get a promotion at work.",
                            "You will go on a fun adventure soon.",
                            "You will receive unexpected good news."};

    int random = rand() % 7;

    printf("Welcome to the Automated Fortune Teller! \n");
    printf("Your fortune for today is: %s \n", fortunes[random]);
    printf("Would you like another fortune? (y/n) ");

    char choice;
    scanf("%c", &choice);

    while (choice == 'y') {
        random = rand() % 7;
        printf("Your fortune is: %s \n", fortunes[random]);
        printf("Would you like another fortune? (y/n) ");
        scanf(" %c", &choice);  // added space before %c to clear the input buffer
    }

    printf("Thank you for visiting the Automated Fortune Teller!\n");

    return 0;
}