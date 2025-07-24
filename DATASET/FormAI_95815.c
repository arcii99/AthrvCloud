//FormAI DATASET v1.0 Category: Text processing ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input_str[100]; // creating a char array to store user input
    printf("Please enter a sentence:"); // prompting user to input a sentence
    fgets(input_str, 100, stdin); // reading input from user

    int length_of_input = strlen(input_str); // finding length of the user input
    char updated_string[length_of_input+1]; // creating an empty array to store updated string
    int index_counter = 0; // initializing index_counter
    int character_count = 1; // initializing count of characters

    for(int i=0; i<length_of_input; i++)
    {
        if(isspace(input_str[i])) // checking if the current character is a space
        {
            if(character_count%2 == 0) // if the number of characters in the word is even
            {
                for(int j=i-character_count; j<i; j++) // loop through the word and save it in updated string
                {
                    updated_string[index_counter] = input_str[j];
                    index_counter++;
                }
            }
            else // if the number of characters in the word is odd
            {
                char temp_char = input_str[i-character_count]; // store the first character of the word in a temporary variable
                for(int j=i-character_count+1; j<i; j++) // loop through the remaining characters of the word and save in updated string
                {
                    updated_string[index_counter] = input_str[j];
                    index_counter++;
                }
                updated_string[index_counter] = temp_char; // add the first character of the word at the end of the updated word
                index_counter++;
            }
            character_count = 1; // resetting character counter
        }
        else
        {
            character_count++; // if the current character is not a space, increment character count
        }
    }
    printf("The updated sentence is: %s", updated_string); // display the updated sentence

    return 0; // end of program
}