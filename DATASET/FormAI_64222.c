//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_KEY_LEN 256
#define MAX_VAL_LEN 256
#define MAX_ENTRIES 100

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VAL_LEN];
} json_entry_t;

typedef struct {
    json_entry_t entries[MAX_ENTRIES];
    size_t count;
} json_t;

json_t parse_json(char* json_str) {
    json_t result = {0};
    char* ptr = json_str;
    while (*ptr != '\0') {
        // skip whitespace
        while (isspace(*ptr)) {
            ptr++;
        }
        // read key
        char* key_start = ptr;
        char* key_end = NULL;
        while (*ptr != ':') {
            if (*ptr == '\0') {
                // error, key without value
                return result;
            }
            ptr++;
        }
        key_end = ptr;
        *ptr = '\0';
        ptr++;
        // skip whitespace
        while (isspace(*ptr)) {
            ptr++;
        }
        // read value
        char* val_start = ptr;
        char* val_end = NULL;
        while (*ptr != ',' && *ptr != '\0') {
            ptr++;
        }
        val_end = ptr;
        *ptr = '\0';
        ptr++;
        // add entry to result
        if (result.count < MAX_ENTRIES) {
            json_entry_t entry = {0};
            strncpy(entry.key, key_start, MAX_KEY_LEN);
            strncpy(entry.value, val_start, MAX_VAL_LEN);
            result.entries[result.count] = entry;
            result.count++;
        } else {
            // error, too many entries
            return result;
        }
    }
    return result;
}

int main() {
    char json_str[] = "{\"name\": \"John\", \"age\": 42, \"city\": \"New York\"}";
    json_t json = parse_json(json_str);
    for (size_t i = 0; i < json.count; i++) {
        printf("%s: %s\n", json.entries[i].key, json.entries[i].value);
    }
    return 0;
}