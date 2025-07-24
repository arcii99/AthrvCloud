//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the structure to hold parsed JSON data */
typedef struct json {
    char *key;
    char *value;
    struct json *next;
} JSON;

/* Function to parse JSON string input */
JSON* parseJSON(char *input) {
    JSON *head = NULL;
    JSON *current = NULL;

    /* Find opening and closing braces */
    char *start = strchr(input, '{');
    char *end = strrchr(input, '}');

    /* Check if input is valid JSON with opening and closing braces */
    if (start == NULL || end == NULL || start > end) {
        printf("Input is not valid JSON\n");
        exit(1);
    }

    /* Extract substrings between braces and split using commas */
    char *tokens[100];
    int numTokens = 0;
    char *token = strtok(start+1, ",");
    while (token != NULL) {
        tokens[numTokens++] = token;
        token = strtok(NULL, ",");
    }

    /* Loop through tokens and extract key-value pairs */
    int i;
    for (i = 0; i < numTokens; i++) {
        char *keyStart = strchr(tokens[i], '\"') + 1;
        char *keyEnd = strrchr(tokens[i], '\"');
        char *valueStart = strchr(tokens[i], ':') + 1;
        char *valueEnd;
        if (valueStart[0] == '\"') {
            valueEnd = strrchr(tokens[i], '\"');
        } else {
            valueEnd = tokens[i] + strlen(tokens[i]) - 1;
        }

        /* Allocate memory for new JSON node */
        JSON *newNode = (JSON *) malloc(sizeof(JSON));
        newNode->key = (char *) malloc(keyEnd - keyStart + 1);
        newNode->value = (char *) malloc(valueEnd - valueStart + 1);
        newNode->next = NULL;

        /* Copy key-value pairs to new node */
        strncpy(newNode->key, keyStart, keyEnd - keyStart);
        newNode->key[keyEnd - keyStart] = '\0';
        strncpy(newNode->value, valueStart, valueEnd - valueStart);
        newNode->value[valueEnd - valueStart] = '\0';

        /* Add new node to linked list of parsed JSON data */
        if (head == NULL) {
            head = current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    /* Return head of linked list containing parsed JSON data */
    return head;
}

/* Function to print parsed JSON data */
void printJSON(JSON *head) {
    JSON *current = head;
    while (current != NULL) {
        printf("\"%s\": \"%s\"\n", current->key, current->value);
        current = current->next;
    }
}

int main() {
    char input[] = "{\"name\": \"John Smith\", \"age\": 32, \"city\": \"New York\"}";
    JSON *parsed = parseJSON(input);
    printJSON(parsed);
    return 0;
}