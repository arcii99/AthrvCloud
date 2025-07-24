//FormAI DATASET v1.0 Category: Error handling ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a = 10, b = 0, c;
    char name[20];

    printf("Welcome to the puzzling error handling example!\n\n");
    printf("Please enter your name: ");
    fgets(name, 20, stdin);
    
    if (name[strlen(name) - 1] == '\n')
        name[strlen(name) - 1] = '\0';

    printf("Hi %s! Let's divide 10 by a number.\n", name);
    printf("Please enter a number: ");
    scanf("%d", &b);

    if (b == 0) {
        printf("I am not a fan of infinite loops. Let's try that again...\n");
        while (1)
            scanf("%d", &b);
    }

    c = a / b;
    printf("10 divided by %d is %d.\n", b, c);
    printf("Thanks for playing with my program. Goodbye!\n");

    return 0;
}