//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_LENGTH 10000

typedef struct {
    char key[50];
    char value[200];
} JSON;

int parseJSON(char *, JSON[]);

int main() {
    char jsonString[MAX_JSON_LENGTH];
    JSON jsonArray[MAX_JSON_LENGTH];
    int numObjects = 0;

    printf("Enter the JSON: ");
    fgets(jsonString, MAX_JSON_LENGTH, stdin);

    numObjects = parseJSON(jsonString, jsonArray);

    printf("\nParsed JSON:\n");
    for(int i = 0; i < numObjects; i++) {
        printf("%s : %s\n", jsonArray[i].key, jsonArray[i].value);
    }

    return 0;
}

int parseJSON(char *jsonString, JSON jsonArray[]) {
    char *token, *key, *value;
    int numObjects = 0;

    token = strtok(jsonString, " ,{\n\t\r");

    while(token != NULL) {

        if(*token == '}') break;

        if(*token == '"') {
            key = token + 1;
            token = strtok(NULL, "\"");
            strcpy(jsonArray[numObjects].key, key);
        }

        token = strtok(NULL, " :{\",}\n\t\r");

        if(*token == '"') {
            value = token + 1;
            token = strtok(NULL, "\"");
            strcpy(jsonArray[numObjects].value, value);
        }

        token = strtok(NULL, "{,}\n\t\r");

        numObjects++;
    }

    return numObjects;
}