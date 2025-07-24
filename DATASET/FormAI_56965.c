//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the hilarious Checksum Calculator!\n");
    printf("Please enter the string that you'd like to calculate the checksum for:\n");
    char input[100];
    scanf("%s", input);

    int sum = 0;
    for (int i = 0; i < strlen(input); i++) {
        sum += input[i];
        if (i % 2 == 0) {
            printf("Ha!");
        } else {
            printf("Ho!");
        }
    }
    printf("\n");

    printf("The checksum for '%s' is: %d\n", input, sum);

    printf("Thank you for using the hilarious Checksum Calculator, have a great day!\n");

    return 0;
}