//FormAI DATASET v1.0 Category: Modern Encryption ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

void encrypt(char str[], int key) {
    int len = strlen(str);

    for(int i=0; i<len; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = (((str[i] + key) - 'a') % 26) + 'a'; 
        } else if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = (((str[i] + key) - 'A') % 26) + 'A';
        }
    }
}

int main() {
    char str[100];
    int key;

    printf("Enter a string to encrypt: ");
    fgets(str, 100, stdin);

    printf("Enter a key (1-25) for encryption: ");
    scanf("%d", &key);

    encrypt(str, key);

    printf("Encrypted string: %s\n", str);

    return 0;
}