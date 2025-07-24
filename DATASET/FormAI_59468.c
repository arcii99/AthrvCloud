//FormAI DATASET v1.0 Category: modern Encryption ; Style: lively
#include<stdio.h>
#include<string.h>
 
void encrypt(char *message, int key);
 
int main()
{
    char message[100];
    int key;
 
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);
 
    printf("Enter key: ");
    scanf("%d", &key);
 
    encrypt(message, key);
 
    printf("Encrypted message: %s", message);
 
    return 0;
}
 
void encrypt(char *message, int key)
{
    int i;
 
    for(i = 0; i < strlen(message); ++i){
        char ch = message[i];
 
        if(ch >= 'a' && ch <= 'z'){
            ch = ch + key;
            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key;
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }
    }
}