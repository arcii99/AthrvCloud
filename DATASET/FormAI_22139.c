//FormAI DATASET v1.0 Category: Modern Encryption ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void encrypt(char s[MAX_SIZE], int key){
    int n = strlen(s);

    for(int i = 0; i < n; i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            s[i] = ((s[i] - 'a' + key) % 26) + 'a';
        }
        else if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = ((s[i] - 'A' + key) % 26) + 'A';
        }
    }
}

int main(){
    char message[MAX_SIZE];
    int key;

    printf("Enter your message: ");
    fgets(message, MAX_SIZE, stdin);

    printf("Enter the key: ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("Encrypted message: %s", message);

    return 0;
}