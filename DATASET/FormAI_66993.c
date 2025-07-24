//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare JSON parser function
void parseJSON(char* jsonString);

int main() {

    printf("Input your JSON string: ");

    char jsonString[1024];
    fgets(jsonString, 1024, stdin);

    parseJSON(jsonString);

    return 0;
}

void parseJSON(char* jsonString) {

    printf("\nParsing...\n");

    // Declare variables for parsing
    int index = 0;
    char key[1024];
    char value[1024];

    printf("{\n");

    // Loop through the JSON string
    while (jsonString[index] != '\0') {

        // Check for opening brace
        if (jsonString[index] == '{') {
            index++;
            continue;
        }

        // Check for closing brace
        if (jsonString[index] == '}') {
            printf("}\n");
            break;
        }

        // Check for key
        if (jsonString[index] == '\"') {
            index++;
            int i = 0;
            while (jsonString[index] != '\"') {
                key[i] = jsonString[index];
                index++;
                i++;
            }
            key[i] = '\0';

            printf("\t%s: ", key);
            index += 2;
        }

        // Check for value
        if (jsonString[index] == '\"') {
            index++;
            int i = 0;
            while (jsonString[index] != '\"') {
                value[i] = jsonString[index];
                index++;
                i++;
            }
            value[i] = '\0';

            printf("\"%s\"\n", value);
        }

        // Check for comma
        if (jsonString[index] == ',') {
            index++;
            printf(",\n");
        }

        // Increment index
        index++;
    }

    printf("JSON parsing complete!\n");
}