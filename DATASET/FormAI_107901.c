//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>

#define MAX_MSG_SIZE 100 // Maximum message size 

int main()
{
    char msg[MAX_MSG_SIZE]; // Array to store the message
    
    int lower_case_count = 0; // Count of lowercase alphabets
    int upper_case_count = 0; // Count of uppercase alphabets
    int digit_count = 0; // Count of digits
    int special_char_count = 0; // Count of special characters
    
    printf("Enter a message: ");
    fgets(msg, MAX_MSG_SIZE, stdin); // Get user input
    
    int i;
    for(i = 0; i < strlen(msg); i++)
    {
        char c = msg[i]; // Get the current character
        
        if(c >= 'a' && c <= 'z')
        {
            lower_case_count++;
        }
        else if(c >= 'A' && c <= 'Z')
        {
            upper_case_count++;
        }
        else if(c >= '0' && c <= '9')
        {
            digit_count++;
        }
        else
        {
            special_char_count++;
        }
    }
    
    if(lower_case_count < 2 || lower_case_count > 5)
    {
        printf("Message is spam.\n"); // If the message contains less than 2 or more than 5 lowercase alphabets, it is considered spam.
    }
    else if(upper_case_count > 3)
    {
        printf("Message is spam.\n"); // If the message contains more than 3 uppercase alphabets, it is considered spam.
    }
    else if(digit_count == 0)
    {
        printf("Message is spam.\n"); // If the message contains no digits, it is considered spam.
    }
    else if(special_char_count > 5)
    {
        printf("Message is spam.\n"); // If the message contains more than 5 special characters, it is considered spam.
    }
    else
    {
        printf("Message is not spam.\n"); // If the message passes all checks, it is not considered spam.
    }

    return 0;
}