//FormAI DATASET v1.0 Category: Compression algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100000
#define MAX_DICT_ENTRIES 1000

int main() {
    printf("Welcome to the C Compression Puzzler!\n");
    printf("Enter a string to compress: ");

    char input[MAX_INPUT_SIZE];
    fgets(input, MAX_INPUT_SIZE, stdin);
    input[strlen(input) - 1] = '\0';
    
    int compressed_size = 0;
    char compressed[MAX_INPUT_SIZE];
    memset(compressed, 0, sizeof(compressed));
    
    char dictionary[MAX_DICT_ENTRIES][MAX_INPUT_SIZE];
    int dictionary_size = 0;
    
    printf("Compressing...\n");
    
    for (int i = 0; i < strlen(input); i++) {
        int dict_index = -1;
        
        // Find the longest matching dictionary entry
        for (int j = 0; j < dictionary_size; j++) {
            int k = i;
            while (k < strlen(input) && input[k] == dictionary[j][k-i]) {
                k++;
            }
            
            if (k-i > 1 && k-i > strlen(dictionary[dict_index]) && k < strlen(input)) {
                dict_index = j;
            }
        }
        
        // If a match is found, replace with dictionary index
        if (dict_index != -1) {
            char index_string[MAX_INPUT_SIZE];
            sprintf(index_string, "%d", dict_index);
            strcat(compressed, index_string);
            compressed_size += strlen(index_string);
            i += strlen(dictionary[dict_index])-1;
        } 
        // Otherwise, add to dictionary and write to compressed string
        else {
            char new_entry[MAX_INPUT_SIZE];
            strncpy(new_entry, &input[i], 1);
            new_entry[1] = '\0';
            strcpy(dictionary[dictionary_size], new_entry);
            strcat(compressed, new_entry);
            compressed_size += strlen(new_entry);
            dictionary_size++;
        }
    }
    
    printf("Original size: %d bytes\n", strlen(input));
    printf("Compressed size: %d bytes\n", compressed_size);
    printf("Compression ratio: %.2f%%\n", ((float) compressed_size / (float) strlen(input)) * 100);
    
    printf("Compressed string: %s\n", compressed);
    
    printf("Decompressing...\n");
    
    char original[MAX_INPUT_SIZE];
    memset(original, 0, sizeof(original));
    int j = 0;
    
    for (int i = 0; i < strlen(compressed); i++) {
        if (isdigit(compressed[i])) {
            char index_string[MAX_INPUT_SIZE];
            int k = i;
            while (isdigit(compressed[k])) {
                index_string[k-i] = compressed[k];
                k++;
            }
            index_string[k-i] = '\0';
            
            int index = atoi(index_string);
            
            if (index < dictionary_size) {
                strcat(original, dictionary[index]);
            }
            
            i += strlen(index_string)-1;
        } else {
            strncat(original, &compressed[i], 1);
        }
    }
    
    printf("Decompressed string: %s\n", original);
    
    if (strcmp(input, original) == 0) {
        printf("Puzzle solved!\n");
        return 0;
    } else {
        printf("Puzzle unsolved...\n");
        return 1;
    }
}