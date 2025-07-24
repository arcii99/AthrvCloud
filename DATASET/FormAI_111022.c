//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t t;
    srand((unsigned) time(&t));

    char *fortuneList[] = {
        "You will find success in your career soon.",
        "A great opportunity will present itself to you.",
        "Good things come to those who wait, be patient.",
        "Your hard work will pay off in the end.",
        "Be open to new possibilities, they may lead to great things.",
        "You will soon meet someone who will change your life.",
        "Your financial situation will improve in the near future.",
        "Take risks and you will achieve great things.",
        "Never give up on your dreams, they will come true.",
        "Your health will improve in the coming months."
    };
    int numberOfFortunes = sizeof(fortuneList)/sizeof(fortuneList[0]);
    int randomIndex = rand() % numberOfFortunes;

    printf("Welcome to the Automated Fortune Teller!\n\n");
    printf("Your fortune for today is: %s\n", fortuneList[randomIndex]);
    printf("\nThank you for using the Automated Fortune Teller! Have a great day!\n");

    return 0;
}