//FormAI DATASET v1.0 Category: Modern Encryption ; Style: systematic
#include<stdio.h>
#include<stdlib.h>

#define KEY 3 // Key for encryption

// Function to encrypt the given string
void encrypt(char* s)
{
    int i = 0;
    while (s[i] != '\0') {
        // Applying Caesar cipher to each character
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = (s[i] + KEY - 'a') % 26 + 'a';
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = (s[i] + KEY - 'A') % 26 + 'A';
        }
        i++;
    }
}

int main()
{
    char s[100];
    printf("Enter a string: ");
    scanf("%[^\n]s", s);
    encrypt(s);
    printf("Encrypted string: %s\n", s);
    return 0;
}