//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold JSON object
typedef struct {
    char *key;
    char *value;
} JsonObject;

// Structure to hold parsed JSON
typedef struct {
    int count;
    JsonObject *objects;
} JsonParsedObject;

// Function to parse JSON
JsonParsedObject parseJson(char *jsonData) {
    JsonParsedObject parsed;
    parsed.count = 0;
    parsed.objects = NULL;

    int len = strlen(jsonData);
    if (len <= 0 || jsonData[0] != '{' || jsonData[len - 1] != '}') {
        printf("Invalid JSON data");
        return parsed;
    }

    char *jsonCopy = malloc((len + 1) * sizeof(char));
    strcpy(jsonCopy, jsonData);

    char *token = strtok(jsonCopy, "{}\":,");
    while (token != NULL) {
        if (parsed.count % 2 == 0) {
            parsed.objects = realloc(parsed.objects, (parsed.count + 1) * sizeof(JsonObject));
            parsed.objects[parsed.count / 2].key = token;
        } else {
            parsed.objects[parsed.count / 2].value = token;
        }
        parsed.count++;
        token = strtok(NULL, "{}\":,");
    }

    free(jsonCopy);
    return parsed;
}

// Function to free parsed JSON
void freeParsedJson(JsonParsedObject parsedJson) {
    for (int i = 0; i < parsedJson.count; i++) {
        free(parsedJson.objects[i].key);
        free(parsedJson.objects[i].value);
    }
    free(parsedJson.objects);
}

int main() {
    char *json = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";

    JsonParsedObject parsedJson = parseJson(json);
    if (parsedJson.count > 0) {
        printf("Parsed JSON:\n");
        for (int i = 0; i < parsedJson.count / 2; i++) {
            printf("\t%s : %s\n", parsedJson.objects[i].key, parsedJson.objects[i].value);
        }
    }

    freeParsedJson(parsedJson);
    return 0;
}