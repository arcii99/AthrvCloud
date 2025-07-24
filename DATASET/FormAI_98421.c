//FormAI DATASET v1.0 Category: Text processing ; Style: curious
#include<stdio.h>
#include<string.h>

int main(){
    char sentence[1000];
    int upperCount = 0, lowerCount = 0, spaceCount = 0;
    
    printf("Enter some text: ");
    fgets(sentence, 1000, stdin); // Get the input string from user
    
    for(int i = 0; i < strlen(sentence); i++){
        if(sentence[i] >= 'A' && sentence[i] <= 'Z'){
            upperCount++;  // Count the number of upper case letters
        }
        else if(sentence[i] >= 'a' && sentence[i] <= 'z'){
            lowerCount++;  // Count the number of lower case letters
        }
        else if(sentence[i] == ' '){
            spaceCount++;   // Count the number of spaces
        }
    }
    
    printf("Your text: %s", sentence);
    printf("Number of uppercase letters: %d\n", upperCount);
    printf("Number of lowercase letters: %d\n", lowerCount);
    printf("Number of spaces: %d\n", spaceCount);
    
    return 0;
}