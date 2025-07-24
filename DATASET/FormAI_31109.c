//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: curious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void encrypt(char * message, char * key)
{
    srand(time(NULL)); // seed the random number generator

    // generate random numbers between 0 and 25 inclusive for the key
    char random_nums[26] = {'\0'};
    int index, num;
    for(int i = 0; i < 26; i++){
        do{
            num = rand() % 26;
            index = strchr(random_nums, num + 'A') - random_nums;
        }while(index >= 0 && index < 26); // check if the number already exists in the array
        random_nums[i] = num + 'A';
    }

    // substitute each character in the message according to the key
    for(int i = 0; i < strlen(message); i++){
        if(message[i] >= 'A' && message[i] <= 'Z'){
            message[i] = random_nums[message[i] - 'A'];
        }
    }

    strcpy(key, random_nums); // copy the key into the key variable
}

void decrypt(char * message, char * key)
{
    // substitute each character in the message according to the key
    for(int i = 0; i < strlen(message); i++){
        if(message[i] >= 'A' && message[i] <= 'Z'){
            message[i] = key[message[i] - 'A'];
        }
    }
}

int main()
{
    char message[100] = {'\0'}, key[26] = {'\0'};

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0'; // remove the newline character

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    printf("Key: %s\n", key);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}