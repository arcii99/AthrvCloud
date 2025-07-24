//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1024

char json[MAX_LEN];

void skip_white_spaces(char* s, int* i) {
    while (isspace((int)s[*i])) {
        (*i)++;
    }
}

int parse_object(char* s, int* i, char* key, char* value) {
    skip_white_spaces(s, i);
    if (s[*i] == '}') {
        // End of object
        return 0;
    } else if (s[*i] != '"') {
        // Invalid key
        return -1;
    } else {
        (*i)++;
        int j = 0;
        while (s[*i] != '"' && j < MAX_LEN) {
            key[j++] = s[*i];
            (*i)++;
        }
        if (s[*i] != '"') {
            // Invalid key
            return -1;
        } else {
            key[j] = '\0';
            (*i)++;
            skip_white_spaces(s, i);
            if (s[*i] != ':') {
                // Invalid syntax
                return -1;
            } else {
                (*i)++;
                skip_white_spaces(s, i);
                if (s[*i] == '{') {
                    // Nested object
                    int res = parse_object(s, i, key, value);
                    if (res != 0) {
                        return res;
                    }
                } else if (s[*i] == '"') {
                    // String value
                    (*i)++;
                    int j = 0;
                    while (s[*i] != '"' && j < MAX_LEN) {
                        value[j++] = s[*i];
                        (*i)++;
                    }
                    if (s[*i] != '"') {
                        // Invalid value
                        return -1;
                    } else {
                        value[j] = '\0';
                        (*i)++;
                    }
                } else {
                    // Invalid syntax
                    return -1;
                }
                skip_white_spaces(s, i);
                if (s[*i] != ',' && s[*i] != '}') {
                    // Invalid syntax
                    return -1;
                }
            }
        }
    }
    return 0;
}

int parse_json(char* s, char* key, char* value) {
    int i = 0;
    int res = parse_object(s, &i, key, value);
    if (res != 0 || s[i] != '\0') {
        // Invalid JSON syntax
        return -1;
    }
    return 0;
}

int main() {
    strcpy(json, "{\"name\":\"John\",\"age\":30,\"city\":{\"name\":\"New York\",\"state\":\"NY\"}}");
    char key[MAX_LEN];
    char value[MAX_LEN];
    int res = parse_json(json, key, value);
    if (res == 0) {
        printf("Parsed JSON:\n");
        printf("%s : %s\n", key, value);
    } else {
        printf("Invalid JSON syntax.\n");
    }
    return 0;
}