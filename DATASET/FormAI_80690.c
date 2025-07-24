//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_STRING_LENGTH 1000

typedef struct {
    char *key;
    char *value;
} json_pair;

typedef struct {
    json_pair *pairs;
    int num_pairs;
} json_object;

void free_json_object(json_object obj) {
    for (int i = 0; i < obj.num_pairs; i++) {
        free(obj.pairs[i].key);
        free(obj.pairs[i].value);
    }
    free(obj.pairs);
}

json_object parse_json(char *json_string) {
    json_object obj;
    obj.pairs = malloc(sizeof(json_pair));
    obj.num_pairs = 0;

    char *token;
    const char delimiter[] = ",:{}[] ";
    token = strtok(json_string, delimiter);

    while (token != NULL) {
        if (strcmp(token, "{") == 0) {
            // Starting a new object, do nothing
        } else if (strcmp(token, "}") == 0) {
            // Finished parsing the object, break out of loop
            break;
        } else if (strcmp(token, "[") == 0) {
            // Starting a new array, do nothing
        } else if (strcmp(token, "]") == 0) {
            // Finished parsing the array, do nothing
        } else if (strcmp(token, ",") == 0) {
            // Do nothing
        } else if (strcmp(token, ":") == 0) {
            // Do nothing
        } else {
            // Parse the key-value pair
            obj.num_pairs++;
            obj.pairs = realloc(obj.pairs, obj.num_pairs * sizeof(json_pair));

            obj.pairs[obj.num_pairs - 1].key = strdup(token);
            token = strtok(NULL, delimiter);
            obj.pairs[obj.num_pairs - 1].value = strdup(token);
        }

        token = strtok(NULL, delimiter);
    }

    return obj;
}

int main() {
    char json_string[MAX_JSON_STRING_LENGTH] = "{\"name\":\"John Doe\",\"age\":30,\"isMarried\":true}";

    json_object obj = parse_json(json_string);

    printf("Parsed JSON object:\n");
    for (int i = 0; i < obj.num_pairs; i++) {
        printf("%s: %s\n", obj.pairs[i].key, obj.pairs[i].value);
    }

    free_json_object(obj);

    return 0;
}