//FormAI DATASET v1.0 Category: Encryption ; Style: inquisitive
#include <stdio.h>
#include <string.h>
 
void encrypt(char *message, int shift)
{
    int i;
    char ch;
 
    for (i = 0; message[i] != '\0'; ++i) {
        ch = message[i];
 
        if (ch >= 'a' && ch <= 'z') {
            ch = ch + shift;
 
            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
 
            message[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + shift;
 
            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
 
            message[i] = ch;
        }
    }
}
 
int main()
{
    char message[100];
    int shift;
 
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
 
    printf("Enter shift value: ");
    scanf("%d", &shift);
 
    encrypt(message, shift);
 
    printf("Encrypted message: %s", message);
 
    return 0;
}