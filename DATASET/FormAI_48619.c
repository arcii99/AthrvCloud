//FormAI DATASET v1.0 Category: Text processing ; Style: lively
#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin); // reads the input sentence upto 100 characters
    
    int length = strlen(sentence); // length of the sentence
    int words = 1; // count of words in the sentence
    int vowels = 0; // count of vowels in the sentence
    int consonants = 0; // count of consonants in the sentence
    
    for(int i=0; i<length; i++)
    {
        if(sentence[i] == '\n') // end of the sentence
            break;
        
        // checking for vowels
        if(sentence[i] == 'a' || sentence[i] == 'e' || sentence[i] == 'i' || sentence[i] == 'o' || sentence[i] == 'u' ||
           sentence[i] == 'A' || sentence[i] == 'E' || sentence[i] == 'I' || sentence[i] == 'O' || sentence[i] == 'U')
        {
            vowels++;
        }
        
        // checking for consonants
        if((sentence[i] >= 'a' && sentence[i] <= 'z') || (sentence[i] >= 'A' && sentence[i] <= 'Z'))
        {
            consonants++;
        }
        
        // checking for end of word
        if(sentence[i] == ' ' || sentence[i] == '\t')
        {
            words++;
        }
    }
    
    // printing the results
    printf("\nYour sentence: %s", sentence);
    printf("\nWord count: %d", words);
    printf("\nVowel count: %d", vowels);
    printf("\nConsonant count: %d", consonants-vowels); // subtracting vowels from consonants to get the count
    
    return 0; // end of program
}