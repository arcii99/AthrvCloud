//FormAI DATASET v1.0 Category: Word Count Tool ; Style: sophisticated
#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    int count = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for(int i = 0; i < strlen(str); i++) {
        if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            count++;
        }
    }

    printf("The total number of words in the string is: %d", count + 1);

    return 0;
}