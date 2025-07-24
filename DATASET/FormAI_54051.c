//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define MAX_CHAR constant
#define MAX_CHAR 100

// define Boolean data type
typedef int bool;
enum { false, true };

// define JSON object structure
typedef struct {
    char key[MAX_CHAR];
    char value[MAX_CHAR];
} JSONObject;

// define function to parse JSON object
void parseJSON(char *jsonString, JSONObject *jsonObject) {
    // split JSON string based on colon ':'
    char *key = strtok(jsonString, ":");
    char *value = strtok(NULL, "");

    // remove leading and trailing quotes from key
    int index = 0;
    while(key[index] != '\0') {
        if(key[index] == '\"') {
            memmove(&key[index], &key[index+1], strlen(key)-index);
            break;
        }
        index++;
    }

    // remove leading and trailing quotes from value
    index = 0;
    while(value[index] != '\0') {
        if(value[index] == '\"') {
            memmove(&value[index], &value[index+1], strlen(value)-index);
            break;
        }
        index++;
    }

    // copy key and value to the JSON object
    strcpy(jsonObject->key, key);
    strcpy(jsonObject->value, value);
}

// define main function
int main() {
    // declare JSON string
    char jsonString[MAX_CHAR] = "{\"name\": \"John\", \"age\": \"25\", \"city\": \"New York\"}";

    // declare array of JSON objects
    JSONObject jsonArray[3];

    // split JSON string into individual JSON objects
    char *jsonObjectString = strtok(jsonString, ",");
    int index = 0;
    while(jsonObjectString != NULL) {
        parseJSON(jsonObjectString, &jsonArray[index]);
        jsonObjectString = strtok(NULL, ",");
        index++;
    }

    // print the contents of the JSON array
    printf("JSON Array:\n");
    for(int i=0; i<3; i++) {
        printf("Key: %s, Value: %s\n", jsonArray[i].key, jsonArray[i].value);
    }

    return 0;
}