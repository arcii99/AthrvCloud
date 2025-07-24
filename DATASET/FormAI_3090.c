//FormAI DATASET v1.0 Category: Text processing ; Style: accurate
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter a sentence: ");
    fgets(input, 100, stdin); // Read input sentence from user
    
    // Convert sentence to lowercase
    int i;
    for(i = 0; i < strlen(input); i++) {
        if(input[i] >= 'A' && input[i] <= 'Z') {
            input[i] = input[i] + 32;
        }
    }
    
    // Count number of vowels and consonants
    int vowelCount = 0;
    int consonantCount = 0;
    for(i = 0; i < strlen(input); i++) {
        if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u') {
            vowelCount++;
        }
        else if(input[i] >= 'a' && input[i] <= 'z') {
            consonantCount++;
        }
    }
    
    printf("Lowercase sentence: %s\n", input);
    printf("Number of vowels: %d\n", vowelCount);
    printf("Number of consonants: %d\n", consonantCount);
    
    // Reverse the sentence
    char reversed[100];
    int j = 0;
    for(i = strlen(input)-1; i >= 0; i--) {
        reversed[j] = input[i];
        j++;
    }
    reversed[j] = '\0';
    printf("Reversed sentence: %s\n", reversed);
    
    return 0;
}