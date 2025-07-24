//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void pause(int sec) {
  int ms = 1000 * sec;
  clock_t start_time = clock();
  while (clock() < start_time + ms);
}

int main() {
    char name[30];
    int age, lucky, sum = 0;
    srand(time(NULL));
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Hello, %s!\n", name);
    printf("How old are you? ");
    scanf("%d", &age);
    printf("What is your lucky number? ");
    scanf("%d", &lucky);

    printf("\nCalculating your fortune...\n");
    pause(2);

    int num1 = rand() % 9 + 1;
    int num2 = rand() % 9 + 1;
    int num3 = rand() % 9 + 1;
    int num4 = rand() % 9 + 1;
    int num5 = rand() % 9 + 1;

    printf("\nYour lucky numbers are: %d, %d, %d, %d, %d\n", num1, num2, num3, num4, num5);
    sum = num1 + num2 + num3 + num4 + num5;

    if (sum % lucky == 0) {
        printf("\nCongratulations, %s, you have won the lottery!\n", name);
    } else if (age % sum == 0) {
        printf("\n%s, your age is divisible by the sum of your lucky numbers!\n", name);
    } else {
        printf("\n%s, your future looks uncertain. Be careful!\n", name);
    }

    return 0;
}