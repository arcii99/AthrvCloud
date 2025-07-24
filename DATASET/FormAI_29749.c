//FormAI DATASET v1.0 Category: Error handling ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int input;
    printf("Enter a number between 1 and 10: ");
    scanf("%d", &input);

    if(input < 1 || input > 10) {
        printf("Invalid input! Please enter a number between 1 and 10.\n");
        exit(1);
    } else {
        printf("Congratulations, you entered a valid input: %d\n", input);
    }

    return 0;
}