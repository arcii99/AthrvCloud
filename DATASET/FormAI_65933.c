//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[50];
    int birth_month, birth_day, birth_year;
    int lucky_number, random_number;
    char fortune[4][50] = {
        "You will receive good news soon.",
        "A big financial gain is on the horizon.",
        "You will meet someone special within the next month.",
        "A major life change is coming."
    };

    // getting user's name and birthdate
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Please enter your birth month (1-12): ");
    scanf("%d", &birth_month);
    printf("Please enter your birth day (1-31): ");
    scanf("%d", &birth_day);
    printf("Please enter your birth year (1900-2021): ");
    scanf("%d", &birth_year);
    printf("\n");

    // calculating user's lucky number
    lucky_number = ((birth_month + birth_day + birth_year) % 10) + 1;
    printf("Your lucky number is %d.\n", lucky_number);

    // generating a random fortune
    srand(time(NULL));
    random_number = rand() % 4;
    printf("Your fortune is: %s\n", fortune[random_number]);

    return 0;
}