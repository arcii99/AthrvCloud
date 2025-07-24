//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a struct to hold our JSON key-value pairs */
typedef struct {
    char* key;
    char* value;
} json_pair;

/* Define a function to parse a JSON string */
void parse_json(char* json_string) {
    /* Create a list to hold our key-value pairs */
    json_pair* pairs = malloc(sizeof(json_pair));
    int num_pairs = 0;

    /* Start by stripping the outer braces */
    strtok(json_string, "{");
    char* inner_string = strtok(NULL, "}");
    
    /* Break the inner string into individual pairs */
    char* pair_string = strtok(inner_string, ",");
    while (pair_string != NULL) {
        /* Strip whitespace and quotation marks */
        strtok(pair_string, "\"");
        char* key = strtok(NULL, "\"");
        strtok(NULL, ":");
        char* value = strtok(NULL, ",");

        /* Add the pair to our list */
        num_pairs++;
        pairs = realloc(pairs, num_pairs * sizeof(json_pair));
        pairs[num_pairs - 1].key = key;
        pairs[num_pairs - 1].value = value;

        /* Move on to the next pair */
        pair_string = strtok(NULL, ",");
    }

    /* Print out the resulting pairs */
    printf("Parsed JSON:\n");
    for (int i = 0; i < num_pairs; i++) {
        printf("%s: %s\n", pairs[i].key, pairs[i].value);
    }

    /* Free up memory */
    for (int i = 0; i < num_pairs; i++) {
        free(pairs[i].key);
        free(pairs[i].value);
    }
    free(pairs);
}

int main() {
    char json_string[100] = "{\"name\": \"Sherlock Holmes\", \"age\": 37, \"address\": { \"house\": \"221B Baker Street\", \"city\": \"London\" } }";
    parse_json(json_string);
    return 0;
}