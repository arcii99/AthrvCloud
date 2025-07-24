//FormAI DATASET v1.0 Category: Word Count Tool ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    int i, count = 0, flag = 0;

    printf("Welcome to the C Word Count Tool!\n");
    printf("Enter your sentence: ");
    fgets(input, sizeof(input), stdin);

    for (i = 0; i < strlen(input); i++) {
        if (input[i] == ' ' || input[i] == '\n' || input[i] == '\t') {
            flag = 0;
        }
        else if (flag == 0) {
            flag = 1;
            count++;
        }
    }
    printf("The total number of words in your sentence is: %d\n", count);
    printf("Thank you for using our tool, have a great day!\n");
    return 0;
}