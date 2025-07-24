//FormAI DATASET v1.0 Category: Modern Encryption ; Style: grateful
#include<stdio.h>
#include<string.h>

/* Grateful style encryption program */
/* Encrypted message will be grateful phrases */

char* encrypt(char* message, int key) {
    int length = strlen(message);
    char* grateful[] = {"Thanks for everything!", "You're amazing!", "You've been a real help!", "I appreciate you!", "You're a lifesaver!", "I owe you one!", "You rock!", "Thank you so much!", "You're the best!", "You're a star!"};
    int numGrateful = sizeof(grateful) / sizeof(grateful[0]);
    char* result = (char*) malloc(length * (sizeof(char) + 20));
    
    int i, j = 0;
    for (i = 0; i < length; i++) {
        char c = message[i];
        int shift = key * (i+1);
        
        // Shift the character
        if (c >= 'a' && c <= 'z') {
            c = (((c - 'a') + shift) % 26) + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            c = (((c - 'A') + shift) % 26) + 'A';
        }
        
        // Add grateful phrase
        if (i % 4 == 0) {
            strcat(result, grateful[j]);
            strcat(result, " ");
            j = (j + 1) % numGrateful;
        }
        
        // Add encrypted character
        char temp[2] = {c, '\0'};
        strcat(result, temp);
    }
    
    strcat(result, "\0");
    return result;
}

int main(int argc, char* argv[]) {
    char* message = "I am grateful for this opportunity.";
    char* encrypted = encrypt(message, 2);
    
    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", encrypted);
    
    return 0;
}