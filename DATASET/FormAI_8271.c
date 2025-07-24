//FormAI DATASET v1.0 Category: Text processing ; Style: futuristic
#include <stdio.h>
#include <string.h>

int main() {
    char input[1000], output[1000];
    int i, j, key = 5;
    
    printf("Enter text to encrypt: ");
   fgets(input, sizeof(input), stdin);

    for(i = 0; i < strlen(input); i++){
        if(input[i] >= 'a' && input[i] <= 'z') {
            output[i] = 'A' + (input[i] - 'a' + key) % 26;
        } else if(input[i] >= 'A' && input[i] <= 'Z') {
            output[i] = 'a' + (input[i] - 'A' + key) % 26;
        } else if(input[i] >= '0' && input[i] <= '9') {
            output[i] = '0' + (input[i] - '0' + key) % 10;
        } else {
            output[i] = input[i];
        }
    }
    
    printf("Encrypted text: %s\n", output);

    for(j = 0; j < strlen(output); j++){
        if(output[j] >= 'a' && output[j] <= 'z') {
            input[j] = 'A' + (output[j] - 'a' - key + 26) % 26;
        } else if(output[j] >= 'A' && output[j] <= 'Z') {
            input[j] = 'a' + (output[j] - 'A' - key + 26) % 26;
        } else if(output[j] >= '0' && output[j] <= '9') {
            input[j] = '0' + (output[j] - '0' - key + 10) % 10;
        } else {
            input[j] = output[j];
        }
    }
    
    printf("Decrypted text: %s\n", input); 

    return 0;
}