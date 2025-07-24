//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the JSON structure
typedef struct {
    char* key;
    char* value;
} KeyValue;

typedef struct {
    KeyValue* data;
    int count;
} JSONObject;

// Define the JSON parser function
JSONObject parseJSON(char* JSONString) {
    JSONObject object;
    object.data = (KeyValue*)malloc(sizeof(KeyValue));
    object.count = 0;
    char* token;
    char* key;
    char* value;
    token = strtok(JSONString, "{,:\"}");
    while(token != NULL)
    {
        switch(object.count % 2)
        {
            case 0:
                key = token;
                break;
            case 1:
                value = token;
                object.data = (KeyValue*)realloc(object.data, (object.count + 1) * sizeof(KeyValue));
                object.data[object.count - 1].key = (char*)malloc(strlen(key) * sizeof(char));
                object.data[object.count - 1].value = (char*)malloc(strlen(value) * sizeof(char));
                strcpy(object.data[object.count - 1].key, key);
                strcpy(object.data[object.count - 1].value, value);
                break;
        }
        object.count++;
        token = strtok(NULL, "{,:\"}");
    }
    return object;
}

int main() {
    char* jsonString = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
    JSONObject object = parseJSON(jsonString);

    // Print the parsed JSON
    for(int i=0; i<object.count/2; i++) {
        printf("%s : %s\n", object.data[i].key, object.data[i].value);
    }

    // Free the allocated memory
    for(int i=0; i<object.count/2; i++) {
        free(object.data[i].key);
        free(object.data[i].value);
    }
    free(object.data);
    
    return 0;
}