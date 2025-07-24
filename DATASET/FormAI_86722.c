//FormAI DATASET v1.0 Category: modern Encryption ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* input_str, int shift) {
    int len = strlen(input_str);
    char* output_str = (char*) malloc(len+1);
    
    for(int i=0; i<len; i++) {
        char c = input_str[i];
        if(isalpha(c)) {
            char base_char = islower(c) ? 'a' : 'A';
            c = (c - base_char + shift) % 26 + base_char;
        }
        output_str[i] = c;
    }
    output_str[len] = '\0';
    return output_str;
}

int main() {
    char input_str[100];
    printf("Enter a string to encrypt: ");
    fgets(input_str, sizeof(input_str), stdin);
    input_str[strcspn(input_str, "\n")] = 0; // Removing the trailing newline character
    
    int shift;
    printf("Enter the shift value: ");
    scanf("%d", &shift);
    
    char* encrypted_str = encrypt(input_str, shift);
    printf("The encrypted string is: %s\n", encrypted_str);
    
    free(encrypted_str);
    return 0;
}