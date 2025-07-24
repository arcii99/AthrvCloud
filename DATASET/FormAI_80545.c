//FormAI DATASET v1.0 Category: Text processing ; Style: bold
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_STR_LEN 100

int main() {
    char user_input[MAX_STR_LEN], processed_str[MAX_STR_LEN];
    
    printf("Enter a string: ");
    fgets(user_input, MAX_STR_LEN, stdin);
    
    int user_input_len = strlen(user_input);

    int uppercase_letters = 0, lowercase_letters = 0, digits = 0, punctuations = 0;
    int j = 0;
    for (int i = 0; i < user_input_len; i++) {
        char current_char = user_input[i];

        if (isupper(current_char)) {
            uppercase_letters++;
            processed_str[j] = toupper(current_char);
            j++;
        }
        else if (islower(current_char)) {
            lowercase_letters++;
            processed_str[j] = tolower(current_char);
            j++;
        }
        else if (isdigit(current_char)) {
            digits++;
            processed_str[j] = current_char;
            j++;
        }
        else if (ispunct(current_char)) {
            punctuations++;
        }
    }
    
    processed_str[j] = '\0';
    
    int processed_str_len = strlen(processed_str);
    
    printf("\nProcessed String: %s\n", processed_str);
    printf("Uppercase Letters: %d\n", uppercase_letters);
    printf("Lowercase Letters: %d\n", lowercase_letters);
    printf("Digits: %d\n", digits);
    printf("Punctuations: %d\n", punctuations);

    return 0;
}