//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* key;
    char* value;
} pair;

typedef struct {
    int size;
    pair* pairs;
} json;

void parse_pair(char* pair_str, pair* p) {
    char* key_end = strchr(pair_str, ':');
    int key_len = key_end - pair_str;
    char* value_start = key_end + 1;

    char* key = malloc((key_len + 1) * sizeof(char));
    strncpy(key, pair_str, key_len);
    key[key_len] = '\0';

    char* value = malloc((strlen(value_start) + 1) * sizeof(char));
    strcpy(value, value_start);

    p->key = key;
    p->value = value;
}

void parse_json(char* json_str, json* j) {
    // Count the number of pairs in the JSON string
    int pair_count = 0;
    for (char* c = json_str; *c != '\0'; c++) {
        if (*c == ':') {
            pair_count++;
        }
    }

    // Allocate memory for the pairs
    pair* pairs = malloc(pair_count * sizeof(pair));

    // Initialize the JSON object
    j->size = pair_count;
    j->pairs = pairs;

    // Parse each pair
    char* pair_str = strtok(json_str, ",");
    int i = 0;
    while (pair_str != NULL) {
        parse_pair(pair_str, &pairs[i]);
        pair_str = strtok(NULL, ",");
        i++;
    }
}

int main() {
    char* json_str = "{\"name\":\"John Smith\",\"age\":42,\"isMarried\":true,\"address\":{\"street\":\"123 Main St\",\"city\":\"Anytown\",\"state\":\"CA\",\"zip\":12345}}";

    json j;
    parse_json(json_str, &j);

    for (int i = 0; i < j.size; i++) {
        printf("%s: %s\n", j.pairs[i].key, j.pairs[i].value);
        free(j.pairs[i].key);
        free(j.pairs[i].value);
    }
    free(j.pairs);

    return 0;
}