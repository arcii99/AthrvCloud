//FormAI DATASET v1.0 Category: Text processing ; Style: paranoid
#include <stdio.h>
#include <string.h>

#define MAX_CHARS 1000
#define MIN_PASSWORD_LENGTH 8

int main(void) {
    char password[MAX_CHARS];
    
    printf("Please enter your password:\n");
    fgets(password, MAX_CHARS, stdin);
    
    // Check password length
    if (strlen(password) < MIN_PASSWORD_LENGTH) {
        printf("Error: Your password must be at least %d characters long.\n", MIN_PASSWORD_LENGTH);
        return 1;
    }
    
    // Check for common words and patterns
    char *common_words[] = {"password", "123456", "qwerty", "monkey", "letmein", "football", "iloveyou"};
    int num_common_words = 7;
    for (int i = 0; i < num_common_words; i++) {
        if (strstr(password, common_words[i])) {
            printf("Error: Your password contains the common word '%s'. Please choose a more unique password.\n", common_words[i]);
            return 1;
        }
    }
    
    char *sequence_patterns[] = {"0123456789", "1234567890", "qwertyuiop", "asdfghjkl", "zxcvbnm"};
    int sequence_lengths[] = {10, 10, 10, 9, 6};
    int num_sequence_patterns = 5;
    for (int i = 0; i < num_sequence_patterns; i++) {
        int seq_len = sequence_lengths[i];
        for (int j = 0; j < strlen(password) - seq_len + 1; j++) {
            char *substr = strndup(password + j, seq_len);
            if (strstr(sequence_patterns[i], substr)) {
                printf("Error: Your password contains the sequence '%s'. Please choose a more unique password.\n", substr);
                return 1;
            }
            free(substr);
        }
    }
    
    // Check for repeated characters
    for (int i = 0; i < strlen(password)-1; i++) {
        if (password[i] == password[i+1]) {
            printf("Error: Your password contains repeated characters. Please choose a more unique password.\n");
            return 1;
        }
    }
    
    printf("Your password meets our standards. Congratulations!\n");
    return 0;
}