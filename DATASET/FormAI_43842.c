//FormAI DATASET v1.0 Category: Spam Detection System ; Style: thoughtful
#include <stdio.h>
#include <string.h>

int main() {
    char input[100]; // to store user input
    int vowels = 0, consonants = 0, digits = 0, spaces = 0, special_characters = 0;
    int spam_score = 0;
    
    printf("Enter a message:\n");
    fgets(input, sizeof(input), stdin); // read user input
    
    for(int i = 0; i < strlen(input); i++) {
        if(input[i] >= 'a' && input[i] <= 'z' || input[i] >= 'A' && input[i] <= 'Z') { // check for alphabets
            if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' || // check for vowels
               input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U') {
                vowels++;
            } else {
                consonants++;
            }
        } else if (input[i] >= '0' && input[i] <= '9') { // check for digits
            digits++;
        } else if (input[i] == ' ') { // check for spaces
            spaces++;
        } else { // check for special characters
            special_characters++;
        }
    }
    
    spam_score += vowels >= 3 ? 0 : 1; // add 1 to spam score if there are less than 3 vowels
    spam_score += consonants >= 7 ? 0 : 1; // add 1 to spam score if there are less than 7 consonants
    spam_score += digits >= 2 ? 0 : 1; // add 1 to spam score if there are less than 2 digits
    spam_score += spaces >= 2 ? 0 : 1; // add 1 to spam score if there are less than 2 spaces
    spam_score += special_characters >= 1 ? 0 : 1; // add 1 to spam score if there are no special characters
    
    if(spam_score <= 2) {
        printf("The message seems genuine.");
    } else if (spam_score <= 4) {
        printf("The message might be spam.");
    } else {
        printf("The message is most likely spam.");
    }
    
    return 0;
}