//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: futuristic
#include <stdio.h>  
#include <string.h>  
#include <math.h>  

// Define our hash function
int hashFunction(char* inputString) {
    int hash = 0;
    int length = strlen(inputString);
    for(int i = 0; i < length; i++){
        hash += (int)pow((int)inputString[i], i + 1);
    }
    return hash;
}  


// Example usage of our hash function
int main() {
    char inputString[50];
    printf("Enter a string to hash: ");
    scanf("%s", inputString);
    int hashedValue = hashFunction(inputString);
    printf("The hash of %s is %d.", inputString, hashedValue);
    return 0;
}