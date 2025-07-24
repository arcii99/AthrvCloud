//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct to represent a JSON key value pair
typedef struct {
    char *key;
    char *value;
} json_pair;

// A struct to represent a JSON object
typedef struct {
    int num_pairs;
    json_pair *pairs;
} json_object;

// A function to parse a JSON object from a string
json_object *parse_json(char *json_str) {
    // First, let's count the number of key value pairs in the JSON string
    int num_pairs = 0;
    char *temp = json_str;
    while (*temp != '\0') {
        if (*temp == ':') {
            num_pairs++;
        }
        temp++;
    }

    // Allocate memory for the JSON object and its key value pairs
    json_object *jo = (json_object *)malloc(sizeof(json_object));
    jo->num_pairs = num_pairs;
    jo->pairs = (json_pair *)malloc(num_pairs * sizeof(json_pair));

    // Parse the key value pairs
    char *key_start, *key_end, *value_start, *value_end;
    temp = json_str;
    int pair_index = 0;
    while (*temp != '\0') {
        if (*temp == ':') {
            // Get the key
            key_start = temp - 1;
            while (*key_start != '\"') {
                key_start--;
            }
            key_end = temp - 1;
            while (*key_end != '\"') {
                key_end++;
            }
            jo->pairs[pair_index].key = (char *)malloc((key_end - key_start) + 1);
            strncpy(jo->pairs[pair_index].key, key_start + 1, (key_end - key_start));
            jo->pairs[pair_index].key[key_end - key_start - 1] = '\0';

            // Get the value
            value_start = temp + 2;
            while (*value_start == ' ') {
                value_start++;
            }
            if (*value_start == '\"') {
                value_start++;
            }
            value_end = value_start;
            while (*value_end != ',' && *value_end != '}') {
                value_end++;
            }
            jo->pairs[pair_index].value = (char *)malloc((value_end - value_start) + 1);
            strncpy(jo->pairs[pair_index].value, value_start, (value_end - value_start));
            jo->pairs[pair_index].value[value_end - value_start] = '\0';

            pair_index++;
        }
        temp++;
    }

    return jo;
}

int main() {
    char *json_str = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}";
    json_object *jo = parse_json(json_str);

    printf("Name: %s\n", jo->pairs[0].value);
    printf("Age: %s\n", jo->pairs[1].value);
    printf("City: %s\n", jo->pairs[2].value);

    // Free memory allocated for the JSON object and its key value pairs
    for (int i = 0; i < jo->num_pairs; i++) {
        free(jo->pairs[i].key);
        free(jo->pairs[i].value);
    }
    free(jo->pairs);
    free(jo);

    return 0;
}