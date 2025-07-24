//FormAI DATASET v1.0 Category: Word Count Tool ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main() {
    char string[1000];
    int count = 0, flag;

    printf("Enter a string:\n");
    fgets(string, 1000, stdin);

    for(int i = 0; string[i] != '\0'; i++) {
        if(string[i] == ' ' || string[i] == '\n' || string[i] == '\t') {
            flag = 0;
        }
        else if(flag == 0) {
            flag = 1;
            count++;
        }
    }

    printf("Word count: %d\n", count);

    return 0;
}