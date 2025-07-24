//FormAI DATASET v1.0 Category: Spam Detection System ; Style: safe
#include <stdio.h>
#include <string.h>

#define SPAM_KEYWORDS {"money", "free", "earn", "guaranteed", "act now"}

// Function to check if a word is present in a sentence
int is_present(char *word, char *sentence) {
    char *pos = strstr(sentence, word); // Find position of word in sentence
    if (pos != NULL) { // Word found in sentence
        return 1;
    } else { // Word not found in sentence
        return 0;
    }
}

// Function to check if an email is spam
int is_spam(char *email) {
    char *keywords[] = SPAM_KEYWORDS; // Get spam keywords
    int num_keywords = sizeof(keywords) / sizeof(keywords[0]); // Calculate number of keywords
    char sentence[1000]; // Buffer to hold sentence for each keyword
    
    // Check each keyword in email
    for (int i = 0; i < num_keywords; i++) {
        strcpy(sentence, email); // Copy email to sentence buffer
        // Remove non-alphanumeric characters from sentence
        for (int j = 0, k = 0; j < strlen(sentence); j++) {
            if (isalnum(sentence[j])) {
                sentence[k++] = sentence[j];
            }
        }
        if (is_present(keywords[i], sentence)) { // Keyword present in sentence
            return 1; // Email is spam
        }
    }
    
    // None of the spam keywords found in email
    return 0; // Email is not spam
}

int main() {
    char email1[1000] = "Get free money now!"; // Spam email
    char email2[1000] = "Hello, how are you doing?"; // Legitimate email
    
    if (is_spam(email1)) {
        printf("Email 1 is spam\n");
    } else {
        printf("Email 1 is legitimate\n");
    }
    
    if (is_spam(email2)) {
        printf("Email 2 is spam\n");
    } else {
        printf("Email 2 is legitimate\n");
    }
    
    return 0;
}