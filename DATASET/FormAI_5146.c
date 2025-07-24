//FormAI DATASET v1.0 Category: Modern Encryption ; Style: multivariable
#include <stdio.h>
#include <string.h>

void encrypt(char *data, int key1, int key2, int key3){ // Function to encrypt the data using the keys
    int len = strlen(data);
    for(int i=0; i<len; i++){
        data[i] = (data[i]*key1 + key2) % key3;
    }
}

void decrypt(char *data, int key1, int key2, int key3){ // Function to decrypt the data using the keys
    int len = strlen(data);
    for(int i=0; i<len; i++){
        data[i] = ((data[i]-key2+key3)*key1) % key3;
    }
}

int main(){
    char data[100];
    printf("Enter the Data to be Encrypted: ");
    scanf("%[^\n]", data);

    int key1, key2, key3;
    printf("\nEnter the 3 Keys(Key 1, Key2, Key3): ");
    scanf("%d %d %d", &key1, &key2, &key3);
    getchar();

    encrypt(data, key1, key2, key3);
    printf("\nEncrypted Data: %s", data);

    decrypt(data, key1, key2, key3);
    printf("\nDecrypted Data: %s", data);

    return 0;
}