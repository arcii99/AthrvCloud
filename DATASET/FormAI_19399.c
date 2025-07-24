//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Parsed JSON object structure
typedef struct parsed_obj {
    char *name;
    char *value;
} parsed_obj;

// JSON parser function
parsed_obj* parse_json(char *json) {
    int i = 0, j = 0, k = 0, n = 0;
    int len = strlen(json);
    char *name = NULL, *value = NULL;
    parsed_obj *parsed = NULL;

    // Allocate memory for parsed object
    parsed = (parsed_obj*)malloc(sizeof(parsed_obj));
    parsed->name = NULL;
    parsed->value = NULL;

    // Handle JSON object start
    if (*(json + 0) == '{') {
        i = 1;
        j = 2;
    }

    // Loop through JSON object
    for (; j < len - 1; j++) {
        if (*(json + j) == '\"') {
            // Obtain name string
            if (!name) {
                i = j + 1;
            } else {
                // Obtain value string
                k = j + 1;
                while (*(json + k) != '\"') {
                    k++;
                }
                *(json + k) = '\0';
                
                value = (char*)malloc(sizeof(char) * (k - j));
                strcpy(value, json + i);
                value[k - j - 1] = '\0';

                parsed->value = value;
            }
            // Obtain name string
            name = (char*)malloc(sizeof(char) * (j - i));
            strcpy(name, json + i);
            name[j - i] = '\0';

            parsed->name = name;
        } else if (*(json + j) == ':') {
            i = j + 1;
        } else if (*(json + j) == ',') {
            // Add parsed object to list
            printf("%s: %s\n", parsed->name, parsed->value);
            free(parsed->name);
            free(parsed->value);

            parsed->name = NULL;
            parsed->value = NULL;

            parsed = (parsed_obj*)realloc(parsed, sizeof(parsed_obj) * ++n);
            parsed[n - 1].name = NULL;
            parsed[n - 1].value = NULL;

            i = j + 1;
            name = NULL;
            value = NULL;
        }
    }

    // Handle JSON object end
    printf("%s: %s\n", parsed->name, parsed->value);
    free(parsed->name);
    free(parsed->value);
    free(parsed);

    return parsed;
}

int main() {
    printf("Enter JSON object: ");
    char json[100];
    fgets(json, 100, stdin);

    parsed_obj *result = parse_json(json);

    return 0;
}