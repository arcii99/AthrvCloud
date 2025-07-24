//FormAI DATASET v1.0 Category: String manipulation ; Style: optimized
#include <stdio.h>
#include <string.h>

int main() {
    // Declare the string
    char str[100];
    
    // Get input string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove trailing newline character
    str[strcspn(str, "\n")] = '\0';
    
    // Initialize variables
    int length = strlen(str);
    int vowels = 0;
    int consonants = 0;
    
    // Iterate through each character in the string
    for(int i=0; i<length; i++) {
        char c = tolower(str[i]);
        if(c >= 'a' && c <= 'z') {
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    
    // Output the results
    printf("\nString: %s\n", str);
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
    
    // Reverse the string
    for(int i=0; i<length/2; i++) {
        char temp = str[i];
        str[i] = str[length-i-1];
        str[length-i-1] = temp;
    }
    
    // Output the reversed string
    printf("\nReversed string: %s\n", str);
    
    return 0;
}