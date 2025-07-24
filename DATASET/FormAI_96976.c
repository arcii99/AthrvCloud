//FormAI DATASET v1.0 Category: Modern Encryption ; Style: introspective
#include<stdio.h>
#include<string.h>

void encrypt(char* message, int key);

int main()
{
    char message[1000];
    int key;
    
    //getting input from the user
    printf("Enter a message to encrypt: ");
    fgets(message, 1000, stdin);
    
    printf("Enter key: ");
    scanf("%d", &key);

    encrypt(message, key);  //calling encryption function
    
    printf("Encrypted message: %s", message);
    
    return 0;
}

void encrypt(char* message, int key)
{
    int i;
    char ch;
    
    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        
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