//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_LENGTH 1000
#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 100

int main() {
    char json[MAX_JSON_LENGTH];
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
    int i = 0, j = 0, k = 0;

    printf("Enter JSON string:\n");
    fgets(json, MAX_JSON_LENGTH, stdin);

    // Remove whitespace characters
    for (int i = 0; i < strlen(json); i++) {
        if (json[i] != ' ' && json[i] != '\n' && json[i] != '\r' && json[i] != '\t') {
            json[j++] = json[i];
        }
    }
    json[j] = '\0';

    // Check if JSON is valid by counting the number of curly braces
    int count = 0;
    for (int i = 0; i < strlen(json); i++) {
        if (json[i] == '{') {
            count++;
        } else if (json[i] == '}') {
            count--;
        }
    }
    if (count != 0) {
        printf("Invalid JSON!\n");
        return 0;
    }

    // Parse JSON by extracting key-value pairs
    i = 0;
    while (json[i] != '\0') {
        // Extract key
        k = 0;
        while (json[i] != ':') {
            key[k++] = json[i++];
        }
        key[k] = '\0';

        i++; // Skip ':'

        // Extract value
        k = 0;
        while (json[i] != ',' && json[i] != '}') {
            value[k++] = json[i++];
        }
        value[k] = '\0';

        // Print key-value pair
        printf("%s : %s\n", key, value);

        i++; // Skip ',' or '}'
    }

    return 0;
}