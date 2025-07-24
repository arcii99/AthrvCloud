//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure to hold key/value pair */
struct KeyValue {
    char *key;
    char *value;
};

/* Structure to hold JSON object */
struct JsonObject {
    int num_keys;
    struct KeyValue *key_values;
};

/* Function prototypes */
int is_whitespace(char c);
int is_digit(char c);

/* Parse JSON string and return JsonObject */
struct JsonObject parse_json(char *json) {
    struct JsonObject obj;
    obj.num_keys = 0;
    
    /* Count number of key/value pairs in JSON */
    char *cursor = json;
    while (*cursor) {
        if (*cursor == ':') {
            obj.num_keys++;
        }
        cursor++;
    }
    obj.key_values = malloc(obj.num_keys * sizeof(struct KeyValue));
    
    /* Parse key/value pairs */
    int index = 0;
    char *key_start, *key_end, *value_start, *value_end;
    cursor = json;
    while (*cursor) {
        /* Find start of key */
        while (is_whitespace(*cursor)) {
            cursor++;
        }
        key_start = cursor;
        while (*cursor != ':') {
            cursor++;
        }
        key_end = cursor;
        cursor++;
        
        /* Find start of value */
        while (is_whitespace(*cursor)) {
            cursor++;
        }
        value_start = cursor;
        if (*cursor == '\"') {
            /* Handle string value */
            cursor++;
            while (*cursor && *cursor != '\"') {
                cursor++;
            }
            if (*cursor) {
                value_end = cursor;
                cursor++;
            } else {
                /* Error: Unterminated string */
                printf("Error: Unterminated string\n");
                exit(1);
            }
        } else if (is_digit(*cursor)) {
            /* Handle number value */
            while (is_digit(*cursor)) {
                cursor++;
            }
            value_end = cursor;
        } else {
            /* Error: Unexpected value type */
            printf("Error: Unexpected value type\n");
            exit(1);
        }
        
        /* Store key/value pair in JsonObject */
        obj.key_values[index].key = strndup(key_start, key_end - key_start);
        obj.key_values[index].value = strndup(value_start, value_end - value_start);
        index++;
    }
    
    return obj;
}

/* Check if character is whitespace */
int is_whitespace(char c) {
    return (c == ' ' || c == '\n' || c == '\r' || c == '\t');
}

/* Check if character is digit */
int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

/* Sample usage */
int main() {
    char *json = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
    struct JsonObject obj = parse_json(json);
    for (int i = 0; i < obj.num_keys; i++) {
        printf("%s: %s\n", obj.key_values[i].key, obj.key_values[i].value);
    }
    
    /* Free memory allocated for JsonObject */
    for (int i = 0; i < obj.num_keys; i++) {
        free(obj.key_values[i].key);
        free(obj.key_values[i].value);
    }
    free(obj.key_values);
    
    return 0;
}