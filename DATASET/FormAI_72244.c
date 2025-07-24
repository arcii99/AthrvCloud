//FormAI DATASET v1.0 Category: Compression algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining a struct for storing encoded data
struct EncodedData {
    char* encoding;
    int length;
};

// defining a function for compressing data using a unique algorithm
struct EncodedData compressData(char* data, int length) {
    
    // initializing variables
    char* result = (char*) malloc(2 * length * sizeof(char));
    int resultLength = 0;
    int count = 1;
    
    // iterating over the data array to apply compression
    for(int i = 0; i < length; i++) {
        
        // if two consecutive characters are the same, increment count
        if(i < length - 1 && data[i] == data[i+1]) {
            count++;
        } else {
            // otherwise, append the character and its corresponding count to the result array
            result[resultLength++] = data[i];
            char* countStr = (char*) malloc(10 * sizeof(char));
            sprintf(countStr, "%d", count);
            for(int j = 0; j < strlen(countStr); j++) {
                result[resultLength++] = countStr[j];
            }
            free(countStr);
            count = 1;
        }
    }
    
    // creating the struct that will be returned with the encoding and its length
    struct EncodedData encodedData;
    encodedData.encoding = result;
    encodedData.length = resultLength;
    
    return encodedData;
}

// example usage of the compressData function
int main() {
    
    // initializing data array
    char data[] = "abbbccccddddddddddddddeeeeffgggghhhh";
    int dataLength = strlen(data);
    
    // compressing data using our unique algorithm
    struct EncodedData encodedData = compressData(data, dataLength);
    
    // printing out the encoded data
    printf("Encoded data: %s\n", encodedData.encoding);
    printf("Length of encoded data: %d\n", encodedData.length);
    
    // freeing memory
    free(encodedData.encoding);
    
    return 0;
}