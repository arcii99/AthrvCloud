//FormAI DATASET v1.0 Category: Compression algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_DICT_SIZE 128

int main() {
    char input[MAX_INPUT_LENGTH];
    char dict[MAX_DICT_SIZE][MAX_INPUT_LENGTH];
    int dict_size = 0;
    int next_code = 128;

    // Get input string from user
    printf("Enter input string:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0; // Remove trailing newline

    // Initialize dictionary
    for (int i = 0; i < 128; i++) {
        dict[i][0] = i;
        dict[i][1] = '\0';
    }
    dict_size = 128;

    // Compress input string
    char output[MAX_INPUT_LENGTH * 2]; // Output buffer
    strcpy(output, ""); // Clear output buffer
    int i = 0; // Current index in input string
    while (input[i] != '\0') {
        // Check if substring exists in dictionary
        int j = i+1;
        char sub[MAX_INPUT_LENGTH] = { input[i] }; // Start with single character
        while (input[j] != '\0' && strlen(sub) < MAX_INPUT_LENGTH) {
            strncat(sub, &input[j], 1); // Append next character
            if (strlen(sub) == MAX_INPUT_LENGTH) break; // Prevent buffer overflow
            int found = 0;
            for (int k = 0; k < dict_size; k++) {
                if (strcmp(sub, dict[k]) == 0) { // Substring found in dictionary
                    found = 1;
                    break;
                }
            }
            if (!found) break; // Substring not found in dictionary
            j++;
        }
        // Add substring to dictionary if not already present
        if (j-i > 1) {
            dict[dict_size][0] = sub[0];
            dict[dict_size][1] = sub[1];
            dict[dict_size][2] = '\0';
            dict_size++;
            if (dict_size == MAX_DICT_SIZE) break; // Prevent dictionary overflow
        }
        // Output code for current substring
        for (int k = 0; k < dict_size; k++) {
            if (strcmp(sub, dict[k]) == 0) { // Substring found in dictionary
                char code[4];
                sprintf(code, "%d ", k);
                strcat(output, code);
                break;
            }
        }
        i = j-1; // Move to next substring
    }

    // Print compressed output
    printf("Compressed output:\n%s\n", output);

    // Decompress output string
    char decompressed[MAX_INPUT_LENGTH];
    strcpy(decompressed, ""); // Clear decompressed buffer
    char *token = strtok(output, " ");
    while (token != NULL) {
        int code = atoi(token);
        strcpy(decompressed + strlen(decompressed), dict[code]);
        if (next_code < MAX_DICT_SIZE) { // Add new entry to dictionary
            char new_entry[MAX_INPUT_LENGTH];
            strcpy(new_entry, dict[code]);
            strcat(new_entry, dict[code+1]);
            strcpy(dict[next_code], new_entry);
            next_code++;
        }
        token = strtok(NULL, " ");
    }

    // Print decompressed output
    printf("Decompressed output:\n%s\n", decompressed);
    
    return 0;
}