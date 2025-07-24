//FormAI DATASET v1.0 Category: Text processing ; Style: interoperable
#include <stdio.h>
#include <string.h>

int main() {
    char input[100]; //declare input array
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin); //get user input
    
    int vowels = 0, consonants = 0, digits = 0, spaces = 0; //initialize counters
    int length = strlen(input); //get length of input
    
    for(int i = 0; i < length; i++) { //iterate through input array
        if(input[i] == ' ') { //check for spaces
            spaces++;
        } else if(isdigit(input[i])) { //check for digits
            digits++;
        } else if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' || input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U') { //check for vowels
            vowels++;
        } else if((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')) { //check for consonants
            consonants++;
        }
    }
    
    printf("Vowels: %d\nConsonants: %d\nDigits: %d\nSpaces: %d\n", vowels, consonants, digits, spaces); //print results
    
    return 0; //exit program
}