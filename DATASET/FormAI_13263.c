//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON 2048

int main(void) {

    char json_str[MAX_JSON] = "{\"name\": \"John\",\"age\": 30,\"city\": \"New York\"}";

    char *ptr = json_str;
    int len = strlen(json_str);

    printf("Parsing JSON: %s\n", json_str);

    // Finding first occurrence of '{' character
    char *open_brace = strchr(ptr, '{');
    if (open_brace == NULL) {
        printf("Invalid JSON format!\n");
        exit(1);
    }
    ptr = open_brace + 1;

    // Loop until we reach end of JSON string
    while (*ptr != '}' && ptr - json_str < len) {

        // Finding key
        char *key_start = strchr(ptr, '"');
        if (key_start == NULL) {
            printf("Invalid JSON format!\n");
            exit(1);
        }
        char *key_end = strchr(key_start + 1, '"');
        if (key_end == NULL) {
            printf("Invalid JSON format!\n");
            exit(1);
        }
        int key_len = key_end - key_start - 1;
        char key[key_len + 1];
        strncpy(key, key_start + 1, key_len);
        key[key_len] = '\0';

        // Finding value
        char *value_start = strchr(key_end, ':');
        if (value_start == NULL) {
            printf("Invalid JSON format!\n");
            exit(1);
        }
        char *value_end = strchr(value_start + 1, ',');
        if (value_end == NULL) {
            value_end = strchr(value_start + 1, '}');
        }
        if (value_end == NULL) {
            printf("Invalid JSON format!\n");
            exit(1);
        }
        int value_len = value_end - value_start - 1;
        char value[value_len + 1];
        strncpy(value, value_start + 1, value_len);
        value[value_len] = '\0';

        // Printing result
        printf("%s: %s\n", key, value);

        // Moving on to next key-value pair
        ptr = value_end + 1;
    }

    return 0;
}