//FormAI DATASET v1.0 Category: Compression algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

char* compress(char* string) {
    int len = strlen(string);
    char* compString = (char*)malloc(sizeof(char) * MAX_SIZE); // allocate memory for compressed string
    int count = 1; // initialize the count for consecutive characters
    int j = 0; // initialize variable for tracking index of compressed string
    
    for(int i = 0; i < len; i++) {
        if(string[i] == string[i+1]) { // if consecutive characters are same
            count++;
        } else {
            // store the character and its count in compressed string
            compString[j++] = string[i];
            compString[j++] = count + '0';
            count = 1; // reset count
        }
    }
    
    compString[j] = '\0'; // add null character at the end of compressed string
    return compString;
}

int main() {
    char* string = "aabbbcccccdddddd";
    char* compString = compress(string);
    
    printf("Original string: %s\n", string);
    printf("Compressed string: %s\n", compString);
    
    free(compString); // free the memory allocated for compressed string
    
    return 0;
}