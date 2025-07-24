//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 1024

// function prototypes
int parse_json(char* json, char* key, char* value);
int get_string(char* json, char* buffer, int* index);

// main function
int main() {
    // sample JSON string
    char* json = "{\"name\":\"John Doe\", \"age\":30, \"city\":\"New York\"}";

    // parse JSON for the "name" key
    char key[] = "name";
    char value[128];
    int status = parse_json(json, key, value);

    // print result
    if(status == 1) {
        printf("%s: %s\n", key, value);
    } else {
        printf("Error: could not find key\n");
    }

    return 0;
}

// function to parse JSON
int parse_json(char* json, char* key, char* value) {
    // initialize variables
    int index = 0;
    int length = strlen(json);
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    // loop through JSON string
    while(index < length) {
        // check for start of key
        if(json[index] == '\"') {
            // get key
            get_string(json, buffer, &index);

            // check if key matches
            if(strcmp(key, buffer) == 0) {
                // move to value part
                index++;

                // get value
                get_string(json, buffer, &index);
                strcpy(value, buffer);

                // return success
                return 1;
            }
        }

        // move to next character
        index++;
    }

    // return failure if key not found
    return 0;
}

// function to get string from JSON
int get_string(char* json, char* buffer, int* index) {
    // initialize variables
    int start_index = *index;
    int end_index = start_index;
    int length = strlen(json);

    // loop through JSON string
    while(end_index < length) {
        // check for end of string
        if(json[end_index] == '\"') {
            // copy string to buffer
            strncpy(buffer, &json[start_index + 1], end_index - start_index - 1);
            buffer[end_index - start_index - 1] = '\0';

            // update index and return success
            *index = end_index + 1;
            return 1;
        }

        // move to next character
        end_index++;
    }

    // return failure if string not found
    return 0;
}