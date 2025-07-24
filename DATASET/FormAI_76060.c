//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Defining the function for parsing JSON data */
void parseJSON(char *json) {
    int i = 0;
    char key[50];
    char value[50];
    bool inQuotes = false;
    bool isKey = true;
    int keyIndex = 0;
    int valueIndex = 0;

    while (json[i] != '\0') {
        if (json[i] == '\"' && !inQuotes) {
            inQuotes = true;
            i++;
            continue;
        }
        if (json[i] == '\"' && inQuotes) {
            inQuotes = false;
            i++;
            continue;
        }
        if (json[i] == ':' && !inQuotes) {
            isKey = false;
            i++;
            continue;
        }
        if (json[i] == ',' && !inQuotes) {
            isKey = true;
            keyIndex = 0;
            valueIndex = 0;
            i++;
            continue;
        }
        if (isKey) {
            key[keyIndex] = json[i];
            keyIndex++;
        } else {
            value[valueIndex] = json[i];
            valueIndex++;
        }
        i++;
    }

    // Print the key-value pairs
    printf("\nParsed JSON:\n");
    printf("------------\n");
    printf("{");
    printf("\"%s\":\"%s\", ", key, value);
    printf("}\n");
}


int main() {
    char *json = "{\"name\":\"Jhone Doe\", \"age\":25, \"city\":\"New York\"}";

    // Parse the JSON data
    parseJSON(json);

    return 0;
}