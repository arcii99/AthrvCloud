//FormAI DATASET v1.0 Category: modern Encryption ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 256
#define MAX_TEXT 1024

// Generate a random key
void generate_key(char *key){
    int i;
    char c;
    srand(time(NULL));
    for(i=0; i<KEY_SIZE; i++){
        c = rand()%256;
        key[i] = c;
    }
    key[i] = '\0';
}

// Encrypt the text using the key
void encrypt(char *text, char *key){
    int i;
    int len = strlen(text);
    for(i=0; i<len; i++){
        text[i] = text[i] ^ key[i%KEY_SIZE];
    }
}

int main(){
    char text[MAX_TEXT];
    char key[KEY_SIZE+1];

    printf("Enter the text to be encrypted: ");
    fgets(text, MAX_TEXT, stdin);
    printf("Text before encryption: %s", text);

    generate_key(key);
    printf("Generated key: %s\n", key);

    encrypt(text, key);
    printf("Text after encryption: %s", text);

    return 0;
}