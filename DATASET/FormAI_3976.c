//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char key[50];
    char value[200];
} JsonKeyValue;

typedef struct {
    int size;
    JsonKeyValue* data;
} Json;

JsonKeyValue parse_key_value(char* line); // Prototype

Json parse(char* json_str) {
    Json result;
    result.size = 0; // Initialize size
    
    char* line = strtok(json_str, "\n"); // Split the string by new line
    
    while(line != NULL) {
        JsonKeyValue kv = parse_key_value(line); // Get Key-Value pair
        result.data = (JsonKeyValue*)realloc(result.data, sizeof(JsonKeyValue)*(result.size+1)); // Increase array size
        result.data[result.size] = kv; // Add new K-V to array
        result.size++; // Increase size
        line = strtok(NULL, "\n"); // Move to next line
    }
    
    return result;
}

JsonKeyValue parse_key_value(char* line) {
    JsonKeyValue result;
    char* key = strtok(line, ":"); // Split by ":"
    char* value = strtok(NULL, ":"); // Get value
    
    // Remove spaces from key
    int i=0, j=0;
    while(key[i] != '\0') {
        if(key[i] != ' ') {
            result.key[j] = key[i];
            j++;
        }
        i++;
    }
    result.key[j] = '\0';
    
    // Remove spaces from value
    i=0; j=0;
    while(value[i] != '\0') {
        if(value[i] != ' ') {
            result.value[j] = value[i];
            j++;
        }
        i++;
    }
    result.value[j] = '\0';
    
    return result;
}

int main() {
    char json_str[] = "name: John\nage: 30\nemail: john@example.com\n";
    
    Json json = parse(json_str);
    
    int i;
    for(i=0; i<json.size; i++) {
        printf("%s: %s\n", json.data[i].key, json.data[i].value);
    }
    
    return 0;
}