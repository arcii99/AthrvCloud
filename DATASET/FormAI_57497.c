//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a JSON value
#define MAX_STRING_LEN 50

// Define the JSON structure
typedef struct {
    char key[MAX_STRING_LEN];
    char value[MAX_STRING_LEN];
} json;

// Define the JSON parser
void parse_json(const char* input_json) {
    // Initialize the variables
    json json_array[MAX_STRING_LEN];
    char temp_key[MAX_STRING_LEN];
    char temp_value[MAX_STRING_LEN];
    int index = 0;
    int i, j;

    // Loop through the input JSON string
    for (i = 0; i < strlen(input_json); i++) {
        // If a key is detected
        if (input_json[i] == '\"') {
            // Get the key
            for (j = i + 1; input_json[j] != '\"'; j++) {
                temp_key[j - i - 1] = input_json[j];
            }
            temp_key[j - i - 1] = '\0';

            // Skip the colon
            i = j + 1;

            // If a value is detected
            if (input_json[i] == '\"') {
                // Get the value
                for (j = i + 1; input_json[j] != '\"'; j++) {
                    temp_value[j - i - 1] = input_json[j];
                }
                temp_value[j - i - 1] = '\0';

                // Add the key-value pair to the JSON array
                strcpy(json_array[index].key, temp_key);
                strcpy(json_array[index].value, temp_value);
                index++;
            }
        }
    }

    // Print the parsed JSON
    printf("Parsed JSON:\n");
    for (i = 0; i < index; i++) {
        printf("%s: %s\n", json_array[i].key, json_array[i].value);
    }
}

int main(void) {
    char input_json[] = "{\"name\": \"John\", \"age\": \"30\", \"city\": \"New York\"}";
    parse_json(input_json);
    return 0;
}