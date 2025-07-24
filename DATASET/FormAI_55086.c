//FormAI DATASET v1.0 Category: Word Count Tool ; Style: future-proof
#include <stdio.h>
#include <string.h>

int main() {
    char string[1000];
    int count = 0;

    printf("Enter a string: ");
    fgets(string, 1000, stdin);

    for(int i=0; string[i]!='\0'; i++) {
        if(string[i] == ' ') {
            count++;
        }
    }

    printf("\nWord count: %d\n", count+1);

    return 0;
}