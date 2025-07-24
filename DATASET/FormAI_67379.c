//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: intelligent
#include <stdio.h> 
#include <string.h> 

// Function to convert the alien language to English 
void alienLanguageTranslator(char alienLanguage[]) 
{ 
    int len = strlen(alienLanguage); 
    int i, j; 
    
    // Loop through each character in the alien language string 
    for(i=0; i<len; ) 
    { 
        // Check if the current character is 'O' and the next character is 'I' 
        if(alienLanguage[i] == 'O' && alienLanguage[i+1] == 'I') 
        { 
            printf("h"); // Print 'h' as it is equivalent to 'OI' in English 
            i += 2; // Move ahead by 2 characters
        } 
        else 
        { 
            printf("%c", alienLanguage[i]); // Print the current character 
            i++; // Move ahead by 1 character
        } 
    } 
} 

int main() 
{ 
    char alienLanguage[100]; 
    printf("Enter an alien language string: "); 
    scanf("%s", alienLanguage); // Read the alien language string from the user 
    
    printf("The English translation is: "); 
    alienLanguageTranslator(alienLanguage); // Call the function to convert the alien language to English
    
    return 0; 
}