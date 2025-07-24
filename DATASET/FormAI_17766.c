//FormAI DATASET v1.0 Category: Educational ; Style: enthusiastic
// Welcome to the world of C programming!
// This is a program that allows you to input your name and age
// and displays a personalized message to greet you.

#include <stdio.h>

int main()
{
    char name[20];
    int age;

    printf("What is your name? ");
    scanf("%s", name);

    printf("How old are you? ");
    scanf("%d", &age);

    printf("\nHello, %s!\n", name);
    printf("You are %d years old.\n", age);

    if(age % 2 == 0) {
        printf("You're %d years young.\n", age*365);
    } else {
        printf("You're %d days wise.\n", age*365);
    }

    printf("Did you know that the ASCII code for the first letter of your name, '%c', is %d?\n", name[0], name[0]);

    int i;
    for(i = 0; i < age; i++) {
        printf("Happy birthday %d time%s!\n", i+1, i == 0 ? "" : "s");
    }

    printf("\nThank you for using this program. Goodbye!\n");

    return 0;
}