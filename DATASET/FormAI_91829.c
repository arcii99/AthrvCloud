//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[20];
    int age, favorite_num;
    srand(time(0)); // Seed random generator with current time

    printf("Hello! I am the automated fortune teller. What is your name?\n");
    scanf("%s", name);
    printf("Nice to meet you, %s! How old are you?\n", name);
    scanf("%d", &age);

    if (age < 18) {
        printf("I'm sorry, you must be 18 or older to receive a fortune from me.\n");
        return 0;
    }

    printf("Great! Now, what is your favorite number between 1 and 10?\n");
    scanf("%d", &favorite_num);

    if (favorite_num < 1 || favorite_num > 10) {
        printf("That number is not between 1 and 10. Please try again.\n");
        return 0;
    }

    printf("OK, %s. Here is your fortune:\n", name);

    switch (rand() % 3) {
        case 0:
            printf("You will come into a great fortune soon!\n");
            break;
        case 1:
            printf("You will meet someone special in the near future.\n");
            break;
        case 2:
            printf("Beware of strangers bearing gifts. They may not have your best interests at heart.\n");
            break;
    }

    printf("Also, your lucky number is %d!\n", rand() % 10);

    if (favorite_num == rand() % 10) {
        printf("Your favorite number matches your lucky number! This is a sign of good things to come.\n");
    }

    return 0;
}