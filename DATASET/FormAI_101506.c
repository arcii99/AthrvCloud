//FormAI DATASET v1.0 Category: Word Count Tool ; Style: light-weight
#include <stdio.h>

int main() {
    char input[1000];
    int count = 0;

    printf("Enter a sentence: ");
    fgets(input, 1000, stdin);

    for(int i = 0; input[i] != '\0'; i++) {
        if(input[i] == ' ' && input[i+1] != ' ') {
            count++;
        }
    }

    if(input[0] == ' ') {
        count--;
    }

    printf("The word count is: %d\n", count+1);

    return 0;
}