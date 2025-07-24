//FormAI DATASET v1.0 Category: Text processing ; Style: medieval
#include <stdio.h>
#include <string.h>

int main() {
    char string[100];
    int string_length, i, vowels = 0, consonants = 0, spaces = 0;

    printf("Enter any text in medieval style: ");
    fgets(string, sizeof(string), stdin); // To input the string in medieval style

    string_length = strlen(string); // To calculate the length of the string

    for(i = 0; i < string_length; i++) {
        if(string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u' || string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U') {
            vowels++; // To count the number of vowels in the string
        }
        else if((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z')) {
            consonants++; // To count the number of consonants in the string
        }
        else if(string[i] == ' ') {
            spaces++; // To count the number of spaces in the string
        }
    }

    printf("\nText in pigeon English: %s\n\n", string); // To output the string in pigeon english

    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
    printf("Number of spaces: %d\n", spaces);

    return 0;
}