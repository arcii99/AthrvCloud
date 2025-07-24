//FormAI DATASET v1.0 Category: Text processing ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input_str[100];
    printf("Enter a string: ");
    fgets(input_str, 100, stdin);
    
    int len = strlen(input_str);
    
    printf("The length of the input string is: %d\n", len);
    
    char new_str[100];
    int index = 0;
    for (int i = 0; i < len; i++) {
        if (input_str[i] == ' ') {
            continue;
        }
        new_str[index] = input_str[i];
        index++;
    }
    
    len = strlen(new_str);
    
    printf("The modified string is: %s\n", new_str);
    printf("The length of the modified string is: %d\n", len);
    
    int vowel_count = 0;
    int consonant_count = 0;
    
    for (int i = 0; i < len; i++) {
        char c = new_str[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowel_count++;
        } else {
            consonant_count++;
        }
    }
    
    printf("Number of vowels in the modified string: %d\n", vowel_count);
    printf("Number of consonants in the modified string: %d\n", consonant_count);
    
    return 0;
}