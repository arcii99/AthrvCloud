//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_LENGTH 1024

/* Structure to hold JSON data */
typedef struct {
    char name[20];
    char value[20];
} JsonData;

/* Function to parse JSON string */
void parseJson(char *jsonString, JsonData jsonData[]) {
    int i = 0, j = 0, k = 0;

    /* Loop over all characters */
    while (jsonString[k] != '\0') {
        /* Check for opening brace */
        if (jsonString[k] == '{') {
            k++;
            /* Loop over all characters inside the brace */
            while (jsonString[k] != '}') {
                /* Copy the name */
                if (jsonString[k] == '\"') {
                    k++;
                    while (jsonString[k] != '\"') {
                        jsonData[i].name[j++] = jsonString[k++];
                    }
                    jsonData[i].name[j] = '\0';
                }
                /* Copy the value */
                if (jsonString[k] == ':') {
                    k++;
                    j = 0;
                    while (jsonString[k] != ',' && jsonString[k] != '}') {
                        jsonData[i].value[j++] = jsonString[k++];
                    }
                    jsonData[i].value[j] = '\0';
                    i++;
                }
                k++;
            }
        } else {
            k++;
        }
    }
}

int main() {
    char jsonString[MAX_JSON_LENGTH] = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";

    JsonData jsonData[3];

    parseJson(jsonString, jsonData);

    printf("Name: %s\n", jsonData[0].value);
    printf("Age: %s\n", jsonData[1].value);
    printf("City: %s\n", jsonData[2].value);

    return 0;
}