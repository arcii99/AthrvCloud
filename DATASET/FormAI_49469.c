//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_SIZE 1024
#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 100

typedef enum { false, true } bool;

/* Validate key format to prevent injection attacks */
bool is_valid_key(char *str) {
    int len = strlen(str);
    if (len > MAX_KEY_LENGTH) return false;
    for (int i = 0; i < len; i++) {
        if (!isalnum(str[i]) && str[i] != '_' && str[i] != '-') {
            return false;
        }
    }
    return true;
}

/* Validate value format to prevent injection attacks */
bool is_valid_value(char *str) {
    int len = strlen(str);
    if (len > MAX_VALUE_LENGTH) return false;
    for (int i = 0; i < len; i++) {
        if (!isalnum(str[i]) && str[i] != '_' && str[i] != '-'
            && str[i] != ' ' && str[i] != '.' && str[i] != ':' 
            && str[i] != '{' && str[i] != '}' && str[i] != '[' && str[i] != ']') {
            return false;
        }
    }
    return true;
}

/* Parse JSON string and populate key-value pairs */
bool parse_json(char *json_str, char **keys, char **values) {
    int len = strlen(json_str);
    if (len > MAX_JSON_SIZE) return false;
    if (json_str[0] != '{' || json_str[len-1] != '}') return false;

    char *token = strtok(json_str, ",");
    while (token != NULL) {

        /* Extract key */
        char *key = strtok(token, ":");
        if (!key || !is_valid_key(key)) return false;
        *keys++ = key;

        /* Extract value */
        char *value = strtok(NULL, ":");
        value++;
        if (!value || !is_valid_value(value)) return false;
        *values++ = value;

        token = strtok(NULL, ",");
    }

    return true;
}

/* Example usage */
int main() {
    char *json_str = "{\"name\":\"John Doe\",\"age\":25,\"city\":\"New York\"}";
    char *keys[3], *values[3];

    if (parse_json(json_str, keys, values)) {
        printf("Key-Value Pairs:\n");
        for (int i = 0; i < 3; i++) {
            printf("%s : %s\n", keys[i], values[i]);
        }
    } else {
        printf("Invalid JSON format\n");
    }

    return 0;
}