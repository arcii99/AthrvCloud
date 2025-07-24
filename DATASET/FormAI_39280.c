//FormAI DATASET v1.0 Category: Text processing ; Style: lively
#include <stdio.h> //header file to include standard input and output functions
#include <string.h> //header file to include string handling functions

int main() {
    char str[1000]; //declare a character array to store input string
    int vowels = 0, consonants = 0; //initialize variables to count number of vowels and consonants
    
    printf("Enter a sentence: "); //prompt user to input a sentence
    fgets(str, sizeof(str), stdin); //read input string from user
    
    //using a for loop to traverse through each character of the input string
    for(int i = 0; i < strlen(str); i++) {
        char ch = str[i]; //store each character in a temporary variable
        
        //check if the character is a vowel
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
           ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            vowels++; //if character is a vowel, increment vowel count
        }
        //check if the character is a letter (excluding vowels)
        else if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            consonants++; //if character is a letter (but not a vowel), increment consonant count
        }
    }
    
    //output the results to the user
    printf("\n\nInput string: %s", str); //print the original input string
    printf("\nNumber of vowels: %d", vowels); //print number of vowels in the input string
    printf("\nNumber of consonants: %d", consonants); //print number of consonants in the input string
    
    return 0; //exit the program
}