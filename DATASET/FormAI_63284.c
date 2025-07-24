//FormAI DATASET v1.0 Category: Text processing ; Style: Claude Shannon
#include<stdio.h>
#include<ctype.h>

int main(){
    char text[100];
    int vowels = 0, consonants = 0, digits = 0, spaces = 0, punctuation = 0;
    
    printf("Enter some text: ");
    fgets(text, 100, stdin);
    
    for(int i = 0; text[i] != '\0'; i++){
        if(isalpha(text[i])){
            if(text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u' || text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U'){
                vowels++;
            }
            else{
                consonants++;
            }
        }
        else if(isdigit(text[i])){
            digits++;
        }
        else if(isspace(text[i])){
            spaces++;
        }
        else{
            punctuation++;
        }
    }
    
    printf("\n********** TEXT PROCESSING RESULTS **********");
    printf("\nTotal Vowels: %d", vowels);
    printf("\nTotal Consonants: %d", consonants);
    printf("\nTotal Digits: %d", digits);
    printf("\nTotal Spaces: %d", spaces);
    printf("\nTotal Punctuation: %d", punctuation);
    
    return 0;
}