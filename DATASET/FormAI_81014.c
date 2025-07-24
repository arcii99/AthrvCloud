//FormAI DATASET v1.0 Category: Word Count Tool ; Style: futuristic
#include <stdio.h>
#include <ctype.h>

int main() {
    char input[1000];
    printf("Enter text: ");
    fgets(input, 1000, stdin);
    int count = 0;
    for(int i = 0; input[i] != '\0'; i++) {
        if(isalpha(input[i]) && !isalpha(input[i+1]))
            count++;
    }
    printf("Word count: %d\n", count);
    return 0;
}