//FormAI DATASET v1.0 Category: Text processing ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, 100, stdin);
    
    int length = strlen(input);
    char vowels[length];
    int vowel_count = 0;
    
    for(int i = 0; input[i] != '\0'; i++) {
        if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u') {
            vowels[vowel_count] = input[i];
            vowel_count++;
        }
    }
    
    printf("Vowels in the input string: ");
    for(int i = 0; i < vowel_count; i++) {
        printf("%c ", vowels[i]);
    }
    printf("\n");
    
    return 0;
}