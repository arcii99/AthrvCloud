//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Helper function to trim whitespace from beginning and end of string
char *trim(char *str)
{
    char *end;

    while (isspace((unsigned char)*str)) {
        str++;
    }

    if (*str == 0) {
        return str;
    }

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) {
        end--;
    }

    *(end+1) = 0;

    return str;
}

// Main JSON parsing function
void parse_json(char *json_str)
{
    printf("Parsing JSON...\n");

    // Remove any whitespace before and after the JSON string
    char *trimmed_str = trim(json_str);

    // Check if JSON string starts with '{' and ends with '}'
    if (trimmed_str[0] != '{' || trimmed_str[strlen(trimmed_str)-1] != '}') {
        printf("Error: Invalid JSON syntax\n");
        return;
    }

    // Loop through JSON string to find individual key-value pairs
    char *tok1, *tok2, *saveptr1 = NULL, *saveptr2 = NULL;
    char *key, *val;
    int count = 0;
    tok1 = strtok_r(trimmed_str+1, ",", &saveptr1);
    while (tok1 != NULL) {
        // Get key and value for current key-value pair
        tok2 = strtok_r(tok1, ":", &saveptr2);
        while (tok2 != NULL) {
            if (count % 2 == 0) {
                key = trim(tok2);
            } else {
                val = trim(tok2);
                // Print key-value pair
                printf("%s: %s\n", key, val);
            }
            tok2 = strtok_r(NULL, ":", &saveptr2);
            count++;
        }
        tok1 = strtok_r(NULL, ",", &saveptr1);
    }
}

int main()
{
    char *json_str = "{ \"name\": \"John Doe\", \"age\": 30, \"city\": \"New York\" }";
    parse_json(json_str);

    return 0;
}