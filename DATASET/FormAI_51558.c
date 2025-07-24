//FormAI DATASET v1.0 Category: Encryption ; Style: unmistakable
#include<stdio.h>
#include<string.h>

//Function implementing encryption
void encrypt(char *input, char *output, int key){
    int length = strlen(input);

    for(int i=0; i<length; i++){
        if(input[i] >= 'a' && input[i] <= 'z'){
            output[i] = 'a' + ((input[i] - 'a' + key) % 26);
        }
        else if(input[i] >= 'A' && input[i] <= 'Z'){
            output[i] = 'A' + ((input[i] - 'A' + key) % 26);
        }
        else{
            output[i] = input[i];
        }
    }
    output[length] = '\0';
}

int main(){
    char input[100];
    char output[100];
    int key;

    printf("Enter string to encrypt: ");
    fgets(input, 100, stdin);

    printf("Enter key (0-25): ");
    scanf("%d", &key);

    encrypt(input, output, key);

    printf("\nOriginal string: %s", input);
    printf("\nEncrypted string: %s", output);
    return 0;
}