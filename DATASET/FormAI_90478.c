//FormAI DATASET v1.0 Category: Encryption ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char message[100], encrypted[100] = "", decrypted[100] = "";
    int shift, length, i;

    printf("Enter a message:\n");
    fgets(message, 100, stdin);

    printf("Enter a shift value:\n");
    scanf("%d", &shift);

    length = strlen(message);

    for(i = 0; i < length; i++){
        if(message[i] >= 'A' && message[i] <= 'Z'){
            encrypted[i] = ((message[i] - 'A') + shift) % 26 + 'A';
        }
        else if(message[i] >= 'a' && message[i] <= 'z'){
            encrypted[i] = ((message[i] - 'a') + shift) % 26 + 'a';
        }
        else{
            encrypted[i] = message[i];
        }
    }
    encrypted[length] = '\0';

    printf("The encrypted message is: %s\n", encrypted);

    for(i = 0; i < length; i++){
        if(encrypted[i] >= 'A' && encrypted[i] <= 'Z'){
            decrypted[i] = ((encrypted[i] - 'A') - shift + 26) % 26 + 'A';
        }
        else if(encrypted[i] >= 'a' && encrypted[i] <= 'z'){
            decrypted[i] = ((encrypted[i] - 'a') - shift + 26) % 26 + 'a';
        }
        else{
            decrypted[i] = encrypted[i];
        }
    }
    decrypted[length] = '\0';

    printf("The decrypted message is: %s\n", decrypted);

    return 0;
}