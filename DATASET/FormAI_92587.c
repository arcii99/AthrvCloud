//FormAI DATASET v1.0 Category: Compression algorithms ; Style: cheerful
#include <stdio.h>
#include <string.h>

void compress(char* str) {
    int len = strlen(str); //get length of input string
    //create a new compressed string array 
    char compressed[len];
    int count = 1; //initialize counter for consecutive characters
    int j = 0; //initialize index for compressed string array

    for (int i = 0; i < len; i++) {
        //if current character is the same as next character, increment counter
        if (str[i] == str[i+1]) {
            count++;
        }
        //otherwise, add the count and current character to the compressed string array
        else {
            compressed[j++] = str[i];
            compressed[j++] = count + '0'; //convert integer count to character
            count = 1; //reset counter for next set of characters
        }
    }
    //print the compressed string
    printf("Compressed string: %s\n", compressed);
}

int main() {
    printf("Welcome to the cheerful compression algorithm!\n");
    printf("Enter a string to compress: ");
    char str[50];
    fgets(str, 50, stdin); //get input string
    str[strcspn(str, "\n")] = 0; //remove newline character from input string

    compress(str); //call compress function
    
    printf("Thank you for using the cheerful compression algorithm! Have a great day!\n");
    return 0;
}