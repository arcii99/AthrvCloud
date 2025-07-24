//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1000

bool isVowel(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
       c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
    {
        return true;
    }
    
    return false;
}

void summarize(char input[], int summary_size)
{
    // Check if the input is empty
    if(strlen(input) == 0)
    {
        printf("\nThe input text is empty!");
        return;
    }
    
    // Initialize variables
    int i = 0;
    int j = 0;
    int num_sentences = 1;
    int num_vowels = 0;
    char current_sentence[MAX_SIZE];
    char summary[MAX_SIZE] = "";
    
    // Loop through the input text
    while(input[i] != '\0')
    {
        // Check if the current character is a vowel
        if(isVowel(input[i]))
        {
            num_vowels++;
        }
        
        // Check if the current character is a sentence-ending punctuation
        if(input[i] == '.' || input[i] == '?' || input[i] == '!')
        {
            num_sentences++;
            strncat(current_sentence, &input[j], (i-j+1));
            
            // Check if the current sentence is longer than the summary size
            if(strlen(summary) + strlen(current_sentence) <= summary_size)
            {
                strcat(summary, current_sentence);
            }
            else
            {
                break;
            }
            
            // Reset the current sentence buffer
            memset(current_sentence, 0, sizeof(current_sentence));
            
            // Update the index variables for the next sentence
            j = i + 1;
            num_vowels = 0;
        }
        
        // Check if the number of vowels exceeds the summary size
        if(num_vowels > summary_size / 3)
        {
            break;
        }
        
        i++;
    }
    
    // Print the summary
    printf("\n --- SUMMARY --- \n\n");
    printf("%s\n", summary);
    printf("\n---------------------\n");
}

int main()
{
    char input_text[MAX_SIZE] = "Mr. Sherlock Holmes, who was usually very late in the mornings, save upon those not infrequent occasions when he was up all night, was seated at the breakfast table. I stood upon the hearth-rug and picked up the stick which our visitor had left behind him the night before. It was a fine, thick piece of wood, bulbous-headed, of the sort which is known as a \"Penang lawyer.\" Just under the head was a broad silver band nearly an inch across. \"To James Mortimer, M.R.C.S., from his friends of the C.C.H.,\" was engraved upon it, with the date \"1884.\"";
    
    summarize(input_text, 50);
    
    return 0;
}