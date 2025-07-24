//FormAI DATASET v1.0 Category: Word Count Tool ; Style: light-weight
#include <stdio.h>
#include <ctype.h>

int main() {
    char input[1000];

    printf("Enter a sentence: ");
    fgets(input, 1000, stdin);

    int count = 0;
    int flag = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (!isspace(input[i])) {
            if (flag == 0) {
                count++;
                flag = 1;
            }
        } else {
            flag = 0;
        }
    }

    printf("The total number of words in the sentence is: %d\n", count);

    return 0;
}