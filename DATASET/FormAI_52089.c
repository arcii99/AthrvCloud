//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_SIZE 1024
#define MAX_STRING_SIZE 256

// Sample JSON string to parse
char example_json[MAX_JSON_SIZE] = "{ \"name\": \"John Doe\", \"age\": 25, \"isStudent\": true }";

// JSON object structure
typedef struct JsonObject {
    char name[MAX_STRING_SIZE];
    char value[MAX_STRING_SIZE];
} JsonObject;

// JSON parser function
void parseJson(char* json) {
    int i, j, len;
    char token;
    len = strlen(json);
    i = 0;
    JsonObject objects[10];
    int num_objects = 0;
    while(i < len) {
        token = json[i];
        if(token == '{' || token == ',') {
            i++; // Move past the { or ,
            j = 0;
            char name[MAX_STRING_SIZE];
            char value[MAX_STRING_SIZE];
            while(json[i] != ':') {
                name[j] = json[i];
                i++;
                j++;
            }
            name[j] = '\0';
            i++; // Move past the :
            j = 0;
            while(json[i] != ',' && json[i] != '}') {
                value[j] = json[i];
                i++;
                j++;
            }
            value[j] = '\0';
            // Trim whitespace
            char trimmedName[MAX_STRING_SIZE];
            char trimmedValue[MAX_STRING_SIZE];
            int k, l;
            k = 0;
            l = 0;
            for(k = 0; k < strlen(name); k++) {
                if(isspace(name[k])) {
                    continue;
                }
                trimmedName[l++] = name[k];
            }
            trimmedName[l] = '\0';
            k = 0;
            l = 0;
            for(k = 0; k < strlen(value); k++) {
                if(isspace(value[k])) {
                    continue;
                }
                trimmedValue[l++] = value[k];
            }
            trimmedValue[l] = '\0';
            // Create the JSON object
            JsonObject object;
            strcpy(object.name, trimmedName);
            strcpy(object.value, trimmedValue);
            objects[num_objects] = object;
            num_objects++;
        }
        i++;
    }
    // Print the JSON objects
    printf("Parsed JSON:\n");
    for(i = 0; i < num_objects; i++) {
        printf("%s: %s\n", objects[i].name, objects[i].value);
    }
}   

int main() {
    parseJson(example_json);
    return 0;
}