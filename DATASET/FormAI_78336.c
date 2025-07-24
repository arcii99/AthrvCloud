//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to calculate the cryptographic hash value
void hash(char *str, int len){
    int i, j;
    char c;
    char *hash_val;

    // allocate memory to store hash value
    hash_val = (char*)malloc(16*sizeof(char));

    // initialize the hash value to 0
    for(i = 0; i < 16; i++)
        hash_val[i] = 0;

    // loop through the input string and update the hash value
    for(i = 0; i < len; i++){
        c = str[i];
        for(j = 0; j < 8; j++){
            if((hash_val[j%16] ^ c) & 0x01)
                hash_val[j%16] = (hash_val[j%16] >> 1) ^ 0xa001;
            else
                hash_val[j%16] >>= 1;
            c >>= 1;
        }
    }

    // print the hash value
    printf("\nThe hash value of \"%s\" is: ", str);
    for(i = 0; i < 16; i++)
        printf("%02x", (unsigned char)hash_val[i]);

    free(hash_val);
}

int main(){
    char str[100];

    // read input string from user
    printf("Enter a string: ");
    scanf("%[^\n]%*c", str);

    // calculate the hash value and print it
    hash(str, strlen(str));

    return 0;
}