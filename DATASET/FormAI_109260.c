//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: funny
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* secret_key = "HashbrownPotato";

char* my_hash_function(char* input){
    int i, length = strlen(input);
    char* hashed_str = (char*) malloc(sizeof(char)*(length+1));
    strcpy(hashed_str, input);

    // Adding some spice to the hash function
    for(i=0;i<length;i++){
        hashed_str[i] = hashed_str[i] ^ secret_key[i%strlen(secret_key)];
    }

    // Now, let's apply some salt
    char salt[10] = "NaCl";
    strcat(hashed_str, salt);
    return hashed_str;
}

int main(){
    char input_str[100];
    printf("Welcome to my funny hash function program!\n");
    printf("Enter the string you want to hash: ");
    scanf("%s", input_str);

    // Hashing the input string
    char* hashed_str = my_hash_function(input_str);

    printf("Your hashed string is: %s\n", hashed_str);

    // Freeing the memory
    free(hashed_str);
    return 0;
}