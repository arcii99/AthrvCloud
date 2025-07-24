//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_json(char* json_string) {

    char* key = NULL;
    char* value = NULL;

    for(int i = 0; i < strlen(json_string); i++) {
        char current_char = json_string[i];

        if(current_char == '{') {
            printf("Begin JSON Object\n");
        } else if(current_char == '}') {
            printf("End JSON Object\n");
        } else if(current_char == '\"') {
            char* string_start = &json_string[i+1];
            char* string_end = strchr(string_start, '\"');
            int string_length = string_end - string_start;
            key = (char*) malloc(string_length+1);
            strncpy(key, string_start, string_length);
            key[string_length] = '\0';
            i = i + string_length + 1;
            printf("Found key: %s\n", key);
        } else if(current_char == ':') {
            i++;
            char* string_start = &json_string[i];
            char* string_end = strchr(string_start, ',');
            if(string_end == NULL) {
                string_end = strchr(string_start, '}');
            }
            
            int string_length = string_end - string_start;
            value = (char*) malloc(string_length+1);
            strncpy(value, string_start, string_length);
            value[string_length] = '\0';
            i = i + string_length;
            printf("Found value: %s\n", value);
        }
    }
}

int main() {

    char* json_string = "{\"name\": \"John Smith\", \"age\": 30, \"city\": \"New York\"}";
    parse_json(json_string);

    return 0;
}