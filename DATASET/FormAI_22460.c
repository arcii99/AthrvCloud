//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_SIZE 1000 // maximum size of JSON string

// Function to check if a given character is a white space character
int isWhiteSpace(char c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

// Function to parse a JSON object stored in a string
void parseJSON(char* json) {
    char* key = NULL; // pointer to store key name
    char* value = NULL; // pointer to store value

    // iterate through each character in the JSON string
    for(int i=0; i<strlen(json); i++) {
        if(json[i] == '{') {
            printf("Object: { \n");
        }
        else if(json[i] == '}') {
            printf("} \n");
        }
        else if(json[i] == ':') {
            printf("Key: %s, ", key);
            key = NULL;
        }
        else if(json[i] == ',') {
            printf("Value: %s \n", value);
            value = NULL;
        }
        else if(isWhiteSpace(json[i])) {
            // skip whitespace characters
            continue;
        }
        else {
            // add char to key or value string
            if(key == NULL) {
                key = malloc(sizeof(char) * 100); //set max length of key = 100
                int j = 0;
                while(json[i] != ':') {
                    key[j] = json[i];
                    i++; j++;
                }
                key[j] = '\0';
            }
            else {
                value = malloc(sizeof(char) * 100);
                int j = 0;
                while(json[i] != ',' && json[i] != '}') {
                    value[j] = json[i];
                    i++; j++;
                }
                value[j] = '\0';
            }
        }
    }

    free(key); free(value); // free memory
}

int main() {
    char json[MAX_JSON_SIZE] = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\" }";

    parseJSON(json); // parse the JSON string

    return 0;
}