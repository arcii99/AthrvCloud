//FormAI DATASET v1.0 Category: Compression algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Statistical Compression Algorithm
// Adopted from Burrows-Wheeler Transform
// Only support 8-bit characters

// Structure to hold Burrows-Wheeler Transform Intermediate Results
typedef struct {
    unsigned char* transformed; // Transformed string
    int* indexes; // List of indices of original string
    int length; // Length of string
} bwt_inter;

// Helper function to compare strings (for qsort)
int cmp_str(const void * a, const void * b) {
   return strcmp(*(const char**)a, *(const char**)b);
}

// Helper function for Burrows-Wheeler Transform
// Transforms given string into Burrows-Wheeler form
bwt_inter bwt(char* str) {
    int len = strlen(str);
    
    // Create a list of cyclic shifts
    char** shifts = malloc(len * sizeof(char*));
    for (int i=0; i<len; i++) {
        shifts[i] = malloc((len+1) * sizeof(char));
        int shift = i;
        for (int j=0; j<len; j++) {
            shifts[i][j] = str[shift];
            shift = (shift+1) % len;
        }
        shifts[i][len] = '\0';
    }
    
    // Sort the cyclic shifts and get list of their indices in original list
    qsort(shifts, len, sizeof(char*), cmp_str);
    int* indexes = malloc(len * sizeof(int));
    for (int i=0; i<len; i++) {
        if (strcmp(str, shifts[i]) == 0) {
            indexes[i] = 0;
        } else {
            indexes[i] = i+1;
        }
    }
    
    // Extract last column of sorted list of cyclic shifts
    unsigned char* transformed = malloc(len * sizeof(unsigned char));
    for (int i=0; i<len; i++) {
        transformed[i] = shifts[i][len-1];
    }
    
    // Free dynamically allocated memory
    for (int i=0; i<len; i++) {
        free(shifts[i]);
    }
    free(shifts);
    
    // Create and return intermediate result structure
    bwt_inter res = { transformed, indexes, len };
    return res;
}

// Encoder function using Statistical Encoding
// Uses Burrows-Wheeler Transform and Move-to-Front Encoding
// Returns compressed data
unsigned char* encode_stat(char* str, int* out_len) {
    // Apply Burrows-Wheeler Transform on input string
    bwt_inter inter = bwt(str);
    
    // Free memory from input string
    free(str);
    
    // Apply Move-to-Front Encoding on transformed string
    unsigned char* transformed = inter.transformed;
    int len = inter.length;
    int* indexes = inter.indexes;
    unsigned char* encoded = malloc(len * sizeof(unsigned char));
    int freq[256] = {0};
    for (int i=0; i<len; i++) {
        int idx = transformed[i];
        encoded[i] = freq[idx];
        memmove(&freq[1], &freq[0], 255 * sizeof(int));
        freq[idx] = 0;
    }
    
    // Free dynamically allocated memory
    free(inter.indexes);
    free(inter.transformed);
    
    // Set output length and return encoded data
    *out_len = len;
    return encoded;
}

// Decoder function using Statistical Encoding
// Performs reverse Move-to-Front Encoding and reverse Burrows-Wheeler Transform
// Returns original data (uncompressed)
char* decode_stat(unsigned char* data, int len) {
    // Reverse Move-to-Front Encoding
    char* transformed = malloc(len * sizeof(char));
    int freq[256] = {0};
    for (int i=0; i<len; i++) {
        int val = data[i];
        int idx = 0;
        for (int j=0; j<256; j++) {
            if (j == val) {
                break;
            } else if (freq[j] == freq[val]) {
                idx++;
            }
        }
        transformed[i] = idx;
        memmove(&freq[1], &freq[0], 255 * sizeof(int));
        freq[val] = 0;
    }
    
    // Apply reverse Burrows-Wheeler Transform
    int* indexes = malloc(len * sizeof(int));
    for (int i=0; i<len; i++) {
        indexes[i] = i;
    }
    qsort(indexes, len, sizeof(int), cmp_str);
    char* original = malloc((len+1) * sizeof(char));
    int curr = indexes[0];
    for (int i=0; i<len; i++) {
        original[i] = transformed[curr];
        curr = indexes[curr];
    }
    original[len] = '\0';
    
    // Free dynamically allocated memory
    free(transformed);
    free(indexes);
    free(data);
    
    // Return original string
    return original;
}

// Example usage
int main() {
    // Input string
    char str[] = "hello world!";
    int len = strlen(str) + 1;
    
    // Compress input string using Statistical Encoding
    int comp_len;
    unsigned char* comp_data = encode_stat(str, &comp_len);
    
    // Print compressed data
    printf("Compressed data: ");
    for (int i=0; i<comp_len; i++) {
        printf("%d ", comp_data[i]);
    }
    printf("\n");
    
    // Decompress compressed data using Statistical Encoding
    char* decomp_str = decode_stat(comp_data, comp_len);
    
    // Print original string
    printf("Original string: %s\n", decomp_str);
    
    // Free dynamically allocated memory
    free(decomp_str);
    
    // Program complete
    return 0;
}