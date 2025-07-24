//FormAI DATASET v1.0 Category: String manipulation ; Style: recursive
#include <stdio.h>
#include <string.h>

void reverseString(char* str, int start, int end) {

    if(start >= end) {
        // Base case: If start index is greater than or equal to end index, return
        return;
    }
    
    // Recursive step 1: Swap characters at start and end index
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    
    // Recursive step 2: Recursively call reverseString for rest of the string
    reverseString(str, start+1, end-1);
}

int countVowels(char* str, int len) {
    
    if(len == 0) {
        // Base case: If length of string is 0, return 0
        return 0;
    }
    
    // Recursive step: Check if first character is a vowel, add 1 if it is and call countVowels recursively for rest of the string
    return ((str[0] == 'a' || str[0] == 'e' || str[0] == 'i' || str[0] == 'o' || str[0] == 'u') ? 1 : 0) + countVowels(str+1, len-1);
}

int main() {

    char str[50];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    int len = strlen(str)-1; // Exclude the null terminator
    
    printf("\nOriginal string: %s\n", str);
    
    // Reverse the string recursively
    reverseString(str, 0, len-1);

    printf("Reversed string: %s\n", str);
    
    // Count the number of vowels in the string recursively
    int numVowels = countVowels(str, len);
    
    printf("Total number of vowels in the string: %d\n", numVowels);

    return 0;
}