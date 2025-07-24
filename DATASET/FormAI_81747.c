//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a JSON string
#define MAX_JSON_STR_LENGTH 1024

/**
 * This function takes a JSON string as input and returns a pointer to the beginning of the first JSON value.
 * It assumes that the JSON string is well-formed (i.e., all opening brackets are followed by a closing bracket,
 * and all opening quotes are followed by a closing quote). If the JSON string is not well-formed, this function
 * may return a NULL pointer or a pointer to the wrong location.
 */
char* json_parse(const char* json_string) {
    // Define a counter for the current depth of brackets
    int depth = 0;

    // Define a flag for whether we are inside a quoted string
    int inside_string = 0;

    // Loop over each character in the JSON string
    for (int i = 0; i < strlen(json_string); i++) {
        char c = json_string[i];

        // If we are inside a quoted string, ignore all characters except for the closing quote
        if (inside_string) {
            if (c == '\"') {
                // If we have reached the end of the quoted string, toggle the inside_string flag
                inside_string = 0;
            }
        } else {
            if (c == '\"') {
                // If we have encountered an opening quote, toggle the inside_string flag
                inside_string = 1;
            } else if (c == '{' || c == '[') {
                // If we have encountered an opening bracket, increment the depth counter
                depth++;
            } else if (c == '}' || c == ']') {
                // If we have encountered a closing bracket, decrement the depth counter
                depth--;
            }

            if (depth == 0 && (c == ',' || i == strlen(json_string) - 1)) {
                // If we have reached a comma or the end of the JSON string at the top level of brackets,
                // return a pointer to the beginning of the next JSON value
                return (char*) &json_string[i + 1];
            }
        }
    }

    // If we reach the end of the JSON string without finding the end of a JSON value, return NULL
    return NULL;
}

int main() {
    // Define a JSON string to be parsed
    const char* json_string = "{\"name\": \"John Smith\", \"age\": 30, \"isAlive\": true, \"hobbies\": [\"reading\", \"swimming\"]}";

    // Define a buffer for holding the resulting JSON values
    char json_value[MAX_JSON_STR_LENGTH];

    // Define a counter for the number of JSON values found
    int num_json_values = 0;

    // Parse and print each JSON value in the JSON string
    char* json_ptr = json_string;
    while (json_ptr != NULL) {
        // Copy the current JSON value into the result buffer
        int len = (json_parse(json_ptr + 1) - (json_ptr + 1));
        strncpy(json_value, json_ptr + 1, len);
        json_value[len] = '\0';

        // Print the JSON value
        printf("JSON value %d: %s\n", num_json_values++, json_value);

        // Move the pointer to the next JSON value
        json_ptr = json_parse(json_ptr + 1);
    }

    return 0;
}