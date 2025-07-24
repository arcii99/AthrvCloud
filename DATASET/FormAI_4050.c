//FormAI DATASET v1.0 Category: Word Count Tool ; Style: minimalist
#include <stdio.h>
#include <string.h>
#define MAX_INPUT_SIZE 1000

int main() {
    printf("Enter a string: ");
    char input[MAX_INPUT_SIZE];
    scanf("%[^\n]", input);

    int count = 0;
    for (int i = 0; i < strlen(input); i++) {
        if ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z')) {
            count++;
            while ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z')) {
                i++;
            }
        }
    }

    printf("\nNumber of words in entered string: %d\n", count);
    return 0;
}