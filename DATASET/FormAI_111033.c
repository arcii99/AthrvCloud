//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: minimalist
#include <stdio.h>

int main() {
    char C_alien_language[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char English_language[] = {'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};
    char input[1000];
    printf("Enter a sentence in C Alien Language : ");
    fgets(input, 1000, stdin);
    printf("Translation in English : ");
    for(int i=0; input[i]!='\0'; i++) {
        if(input[i] == ' ' || input[i] == '\n') {
            printf("%c", input[i]);
            continue;
        }
        for(int j=0; j<26; j++) {
            if(C_alien_language[j] == input[i]) {
                printf("%c", English_language[j]);
                break;
            }
        }
    }
    return 0;
}