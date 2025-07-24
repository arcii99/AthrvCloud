//FormAI DATASET v1.0 Category: Word Count Tool ; Style: rigorous
#include <stdio.h>
#include <ctype.h>

int main() {
    char input[1000];
    int count = 0, flag = 0;

    printf("Enter a sentence: ");
    fgets(input, 1000, stdin);

    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            if (flag == 0) {
                flag = 1;
                count++;
            }
        } 
        else if (isspace(input[i])) {
            flag = 0;
        }
    }

    printf("The number of words in the sentence is: %d\n", count);

    return 0;
}