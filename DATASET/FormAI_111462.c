//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: shocked
#include<stdio.h>
#include<string.h>

int main() {
    char input[100];
    int hash = 0;
    
    printf("Enter input to hash: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0; // to remove the newline character
    
    for(int i=0; i<strlen(input); i++){
        hash = (hash << 3) + input[i]; // shift left and add the character's ASCII value
    }
    
    printf("The hash of %s is %d", input, hash);
    
    return 0;
}