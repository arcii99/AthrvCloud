//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1024 // Maximum size of the input JSON string.

// Structure to hold JSON object key-value pairs.
struct JSON {
    char key[50];
    char value[50];
};

// Function to parse a JSON object.
void parseJSON(char* jsonString) {
    struct JSON jsonData[50];
    int len = strlen(jsonString), i = 0, j = 0;
    char key[50], value[50];

    // Loop through the input string character by character.
    while (i < len) {
        if (jsonString[i] == '\"') {
            // Found a key, read until the closing quote.
            j = 0;
            i++;
            while (jsonString[i] != '\"') {
                key[j++] = jsonString[i++];
            }
            key[j] = '\0';
        } else if (jsonString[i] == ':') {
            // Found a value, read until the next comma or end of object.
            j = 0;
            i++;
            while (jsonString[i] != '\0' && jsonString[i] != ',' && jsonString[i] != '}') {
                if (jsonString[i] != '\"' && jsonString[i] != '\\') {
                    value[j++] = jsonString[i];
                }
                i++;
            }
            value[j] = '\0';
            // Add the key-value pair to the JSON object array.
            strcpy(jsonData[(int)strlen((const char*)jsonData)].key, key);
            strcpy(jsonData[(int)strlen((const char*)jsonData)].value, value);
        }
        i++; // Move to the next character.
    }

    // Print the parsed JSON object.
    printf("{\n");
    for (i = 0; i < strlen((const char*)jsonData); i++) {
        printf("\t\"%s\": \"%s\",\n", jsonData[i].key, jsonData[i].value);
    }
    printf("}\n");
}

int main() {
    char jsonString[MAX_SIZE];

    // Get the input JSON string from the user.
    printf("Enter a JSON string: ");
    fgets(jsonString, MAX_SIZE, stdin);

    // Parse the input JSON string.
    printf("Parsed JSON object:\n");
    parseJSON(jsonString);

    return 0;
}