//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: ephemeral
// Unique C Alien Language Translator example program
#include<stdio.h>
#include<string.h>
int main(){
    char alien_language[100]; // define alien_language as a character array with size 100
    printf("Welcome to the Alien Language Translator Program! \n");
    printf("Please enter the sentence in the alien language: ");
    fgets(alien_language, 100, stdin); // get input from user
    
    // Translation rules
    // Rule 1: Replace all vowels with the letter 'u'
    // Rule 2: Replace all consonants with the next consonant in the alphabet
    for(int i=0;i<strlen(alien_language);i++){
        if(alien_language[i]=='a' || alien_language[i]=='e' || alien_language[i]=='i' || alien_language[i]=='o' || alien_language[i]=='u'){
            alien_language[i]='u';
        } else if(alien_language[i]>='b' && alien_language[i]<='d' || alien_language[i]>='f' && alien_language[i]<='t' || alien_language[i]>='v' && alien_language[i]<='z'){
            alien_language[i]+=1;
        }
    }
    printf("The translation of the given sentence is: %s \n", alien_language);
    return 0; // end program
}