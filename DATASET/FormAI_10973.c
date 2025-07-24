//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum size for a JSON object
#define MAX_JSON_SIZE 1000

// Declaration of the JSON_parsing function
int JSON_parsing(char* json_string);

// Main function
int main() {
    // Create a sample JSON object in string format
    char sample_json[MAX_JSON_SIZE];
    strcpy(sample_json, "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}");

    // Call the JSON_parsing function and print the return value
    if (JSON_parsing(sample_json)) {
        printf("JSON parsing successful!\n");
    } else {
        printf("JSON parsing failed!\n");
    }
    return 0;
}

// Implementation of the JSON_parsing function
int JSON_parsing(char* json_string) {
    // Check if the input JSON object is valid or not
    if (json_string == NULL || strlen(json_string) == 0) {
        return 0;
    }

    // Iterate through the JSON object character by character
    int i = 0;
    while (json_string[i] != '\0') {
        // Check if the current character is a valid JSON key-value pair
        if (json_string[i] == '\"' && json_string[i+2] == '\"' && json_string[i+3] == ':' && json_string[i+4] == '\"') {
            // Print the JSON key
            printf("JSON key: ");
            int j = i+1;
            while (json_string[j] != '\"') {
                printf("%c", json_string[j]);
                j++;
            }
            printf(" ");

            // Print the JSON value
            printf("JSON value: ");
            j = i+5;
            while (json_string[j] != '\"') {
                printf("%c", json_string[j]);
                j++;
            }
            printf("\n");

            // Increment the index to skip the current key-value pair
            i = j+1;
        } else {
            // Increment the index to the next character in the JSON object
            i++;
        }
    }
    return 1;
}