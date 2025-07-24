//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    char name[20];
    int age;
    int lucky_number;
    char outcome[4][25] = {"great success", "unexpected challenges", "mediocre results", "a major breakthrough"};

    printf("Welcome to the Automated Fortune Teller! \n");
    printf("What is your name? ");
    scanf("%s", name);
    printf("How old are you? ");
    scanf("%d", &age);
    printf("What is your lucky number? ");
    scanf("%d", &lucky_number);

    printf("\n\nGenerating your fortune...\n\n");

    srand(time(0));
    int random_num = rand() % 4;

    printf("Dear %s, your future looks like %s. \n", name, outcome[random_num]);
    printf("Your lucky number, %d, will play a big role in achieving your %s. \n", lucky_number, outcome[random_num]);

    int i;
    printf("\nHere are some other lucky numbers for you, %s: ", name);
    for(i=0; i<5; i++) {
        printf("%d ", (rand() % 100) + 1);
    }
    printf("\n\n");

    printf("Thank you for using the Automated Fortune Teller! Good luck and may your future be bright!");
    return 0;
}