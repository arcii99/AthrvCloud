//FormAI DATASET v1.0 Category: Text processing ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char sentence[100]; 
    int count = 0; 
    
    printf("Please enter a sentence: ");
    fgets(sentence, 100, stdin); // Input sentence from user
    
    for(int i=0; i<strlen(sentence)-1; i++) // Loop through each character in the sentence
    {
        if(sentence[i] == ' ') // If there is a space
        {
            count++; // Increase the count of words       
        }
    }
    
    printf("\nNumber of words in the sentence: %d\n", count+1); // Output the number of words
    
    return 0;
}