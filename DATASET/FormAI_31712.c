//FormAI DATASET v1.0 Category: File Encyptor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

char* encrypt(char* text, int key) {
    char* result = (char*)malloc((sizeof(text) / sizeof(text[0])) * sizeof(char));
    for(int i = 0; i < sizeof(text) / sizeof(text[0]); i++) {
        if(text[i] >= 'a' && text[i] <= 'z') {
            result[i] = (((text[i] - 'a') + key) % 26) + 'a';
        }
        else if(text[i] >= 'A' && text[i] <= 'Z') {
            result[i] = (((text[i] - 'A') + key) % 26) + 'A';
        }
        else {
            result[i] = text[i];
        }
    }

    return result;
}

int main() {
    char str[100], *s;
    int key;

    printf("Enter the text to encrypt: ");
    fgets(str, sizeof(str), stdin);
    printf("Enter the key: ");
    scanf("%d", &key);

    s = encrypt(str, key);
    printf("Encrypted Text: %s", s);

    free(s);
    
    return 0;
}