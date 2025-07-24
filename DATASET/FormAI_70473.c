//FormAI DATASET v1.0 Category: Compression algorithms ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1000

// Function to compress a given string
char* compress(char* str) {
    static char compressed[MAX_LEN] = {'\0'};  // static char buffer to store compressed string
    int len = 0, count = 1, i = 0;
    char current = str[0];
    
    // iterate through the string
    while(str[i] != '\0') {
        if(str[i] == current) {     // if the current character is same as previous character, increase the count
            count++;
        }
        else {                      // if the current character is different, add the previous character and its count to the compressed string
            compressed[len++] = current;
            compressed[len++] = count + '0';
            count = 1;
            current = str[i];
        }
        i++;
    }
    // add the last character and its count to the compressed string
    compressed[len++] = current;
    compressed[len++] = count + '0';
    compressed[len] = '\0';         // add null terminator to the compressed string
    return compressed;
}

int main() {
    char str[MAX_LEN], *compressed;
    printf("Enter a string to compress: ");
    fgets(str, MAX_LEN, stdin);

    compressed = compress(str);     // call the compress function to get the compressed string
    
    printf("Compressed string: %s\n", compressed);
    
    return 0;
}