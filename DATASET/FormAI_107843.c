//FormAI DATASET v1.0 Category: String manipulation ; Style: Ada Lovelace
//This program takes a sentence as an input and capitalizes the first letter of each word

#include <stdio.h>

int main() {
    char sentence[100];
    int i;
    
    printf("Enter a sentence:\n");
    fgets(sentence, 100, stdin); //reads input from the user
    
    for (i = 0; sentence[i] != '\0'; i++) {
        if (i == 0 || sentence[i-1] == ' ') { 
            //if the current character is the first letter or the letter follows a space
            if(sentence[i] >= 'a' && sentence[i] <= 'z') { 
                sentence[i] -= 32; //converts lowercase letter to uppercase
            }
        }
        else {
            if(sentence[i] >= 'A' && sentence[i] <= 'Z') { 
                sentence[i] += 32; //converts uppercase letter to lowercase
            }
        }
    }
    
    printf("Capitalized sentence: %s", sentence); //prints the modified sentence
    
    return 0;
}