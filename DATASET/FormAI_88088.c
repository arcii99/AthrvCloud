//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_SIZE 1024

typedef struct json_object {
    char key[50];
    char value[100];
} json_object;

json_object parse_json(char *json_str, int len) {
    json_object obj;
    memset(&obj, 0, sizeof(json_object));

    char *token = strtok(json_str, ":");
    if (token != NULL) {
        strcpy(obj.key, token);
        token = strtok(NULL, ":");
        if (token != NULL) {
            strcpy(obj.value, token);
        }
    }

    return obj;
}

int main(void) {
    char json_str[MAX_JSON_SIZE] = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
    int len = strlen(json_str);

    json_object obj = parse_json(json_str, len);
    printf("Key: %s\n", obj.key);
    printf("Value: %s\n", obj.value);

    return 0;
}