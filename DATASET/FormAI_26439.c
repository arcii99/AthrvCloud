//FormAI DATASET v1.0 Category: String manipulation ; Style: inquisitive
#include<stdio.h>
#include<string.h>

int main() {
    char str[100], vowels[100], consonants[100]; // Initialize the required variables
    int i, j = 0, k = 0; // Initialize counters for vowels and consonants
    
    printf("Enter a string: "); 
    fgets(str, sizeof(str), stdin); // Reads the input string from user
    str[strcspn(str, "\n")] = '\0'; // Remove the new line character from the input string
    
    for(i=0; str[i] != '\0'; i++) { // Loop through each character in the input string
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
           str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            vowels[j++] = str[i]; // Add the character to the vowels array and increment the count
        } else if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            consonants[k++] = str[i]; // Add the character to the consonants array and increment the count
        }
    }
    
    vowels[j] = '\0'; // Add null character at the end of vowels array 
    consonants[k] = '\0'; // Add null character at the end of consonants array
    
    printf("Vowels: %s\n", vowels); // Display the vowels array
    printf("Consonants: %s\n", consonants); // Display the consonants array
    
    return 0; // End the program
}