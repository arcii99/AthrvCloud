//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    char *value;
} json_item;

int parse_json(char *json_string, json_item **result) {
    if (json_string == NULL || strlen(json_string) == 0 || result == NULL) {
        return -1;
    }

    char *buf = (char *)malloc(strlen(json_string) + 1);
    strcpy(buf, json_string);

    char *ptr = buf;

    while (*ptr == ' ' || *ptr == '\t' || *ptr == '\n' || *ptr == '\r') {
        ptr++;
    }

    if (*ptr != '{') {
        return -1;
    }

    ptr++;

    *result = (json_item *)malloc(sizeof(json_item));
    memset(*result, 0, sizeof(json_item));
    int count = 0;

    while (*ptr != '}') {
        if (*ptr == ' ' || *ptr == '\t' || *ptr == '\n' || *ptr == '\r') {
            ptr++;
            continue;
        }

        if (*ptr == ',') {
            ptr++;
            continue;
        }

        char *key = NULL;
        char *value = NULL;

        if (*ptr == '\"') {
            char *start = ptr + 1;
            ptr++;

            while (*ptr != '\"' && *ptr != '\0') {
                ptr++;
            }

            if (*ptr == '\"') {
                key = (char *)malloc(ptr - start + 1);
                strncpy(key, start, ptr - start);
                key[ptr - start] = '\0';
            }
        }

        if (*ptr == ':') {
            ptr++;

            if (*ptr == '\"') {
                char *start = ptr + 1;
                ptr++;

                while (*ptr != '\"' && *ptr != '\0') {
                    ptr++;
                }

                if (*ptr == '\"') {
                    value = (char *)malloc(ptr - start + 1);
                    strncpy(value, start, ptr - start);
                    value[ptr - start] = '\0';
                }
            }
        }

        if (key != NULL && value != NULL) {
            (*result)[count].key = key;
            (*result)[count].value = value;
            count++;
        }

        ptr++;
    }

    free(buf);

    return count;
}

int main() {
    char *json_string = "{ \"name\": \"John\", \"age\": 30, \"city\": \"New York\" }";

    json_item *result = NULL;

    int count = parse_json(json_string, &result);

    for (int i = 0; i < count; i++) {
        printf("Key: %s, Value: %s\n", result[i].key, result[i].value);
        free(result[i].key);
        free(result[i].value);
    }

    free(result);

    return 0;
}