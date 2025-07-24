//FormAI DATASET v1.0 Category: File Encyptor ; Style: intelligent
#include<stdio.h>
#include<string.h>

void encrypt(char message[], int key){
    int i;
    char c;
    for(i = 0; message[i] != '\0'; i++){
        c = message[i];
        if(c >= 'a' && c <= 'z'){
            c = c + key;
            if(c > 'z'){
                c = c - 'z' + 'a' - 1;
            }
            message[i] = c;
        }
        else if(c >= 'A' && c <= 'Z'){
            c = c + key;
            if(c > 'Z'){
                c = c - 'Z' + 'A' - 1;
            }
            message[i] = c;
        }
    }
}

void decrypt(char message[], int key){
    int i;
    char c;
    for(i = 0; message[i] != '\0'; i++){
        c = message[i];
        if(c >= 'a' && c <= 'z'){
            c = c - key;
            if(c < 'a'){
                c = c + 'z' - 'a' + 1;
            }
            message[i] = c;
        }
        else if(c >= 'A' && c <= 'Z'){
            c = c - key;
            if(c < 'A'){
                c = c + 'Z' - 'A' + 1;
            }
            message[i] = c;
        }
    }
}

int main(){
    char message[100];
    int key, choice;

    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin);

    printf("\nEnter a key (1-25): ");
    scanf("%d", &key);

    printf("\nEnter your choice: \n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            encrypt(message, key);
            printf("\nEncrypted message: %s", message);
            break;
        case 2:
            decrypt(message, key);
            printf("\nDecrypted message: %s", message);
            break;
        default:
            printf("\nInvalid choice.");
    }
    return 0;
}