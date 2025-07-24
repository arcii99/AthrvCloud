//FormAI DATASET v1.0 Category: Compression algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to compress a given string using our custom algorithm
char* custom_compress(char* str) {
    if(str == NULL) return NULL;
    
    // First, we create an integer array to represent the frequencies of each character
    int freq[128] = {0}; // 128 is the maximum number of ASCII characters
    
    for(int i=0; i<strlen(str); i++)
        freq[str[i]]++;
    
    // Next, we create a character array to represent our compressed string
    char* compressed = (char*)malloc(sizeof(char)*strlen(str)*2); // twice the length since it is compressed
    
    int index = 0;
    for(int i=0; i<strlen(str); i++) {
        if(freq[str[i]] == 0) continue; // skip if frequency is zero
        
        char freq_str[5];
        sprintf(freq_str, "%d", freq[str[i]]); // convert frequency to string
        
        compressed[index++] = str[i];
        strcat(compressed, freq_str);
        
        freq[str[i]] = 0; // set frequency to zero to avoid duplicates
    }
    
    return compressed;
}

// Function to decompress a given string using our custom algorithm
char* custom_decompress(char* str) {
    if(str == NULL) return NULL;
    
    // First, we create an integer array to represent the frequencies of each character
    int freq[128] = {0}; // 128 is the maximum number of ASCII characters
    
    for(int i=0; i<strlen(str); i++) {
        char c = str[i];
        if(c >= '0' && c <= '9') continue; // skip digit
        
        freq[c]++;
    }
    
    // Next, we create a character array to represent our decompressed string
    char* decompressed = (char*)malloc(sizeof(char)*strlen(str)); // same length as original
    
    int index = 0;
    for(int i=0; i<strlen(str); i++) {
        char c = str[i];
        if(c >= '0' && c <= '9') continue; // skip digit
        
        char freq_str[5];
        int j = i+1;
        while(str[j] >= '0' && str[j] <= '9') {
            freq_str[j-i-1] = str[j];
            j++;
        }
        freq_str[j-i-1] = '\0';
        
        int frequency = atoi(freq_str); // convert frequency string to integer
        
        for(int k=0; k<frequency; k++)
            decompressed[index++] = c;
    }
    
    return decompressed;
}

int main() {
    char input[] = "aaabbbccccddddeeee";
    char* compressed = custom_compress(input);
    printf("Compressed string: %s\n", compressed);
    
    char* decompressed = custom_decompress(compressed);
    printf("Decompressed string: %s\n", decompressed);
    
    free(compressed);
    free(decompressed);
    
    return 0;
}