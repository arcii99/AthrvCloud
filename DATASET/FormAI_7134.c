//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_LENGTH 1024  // Maximum length of input JSON string
#define MAX_KEY_LENGTH 50     // Maximum length of key string
#define MAX_VALUE_LENGTH 200  // Maximum length of value string
#define MAX_CHILDREN 50       // Maximum number of children for each JSON object

// Node structure to store a JSON object
typedef struct Node {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct Node *children[MAX_CHILDREN];
} Node;

// Helper function to check if a string is a number
int is_number(const char *str) {
    int i = 0;
    if (str[0] == '-') {  // Skip minus sign for negative numbers
        i++;
    }
    for (; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Helper function to trim whitespace from a string
char *trim(char *str) {
    char *end;
    while (isspace((unsigned char)*str)) {
        str++;
    }
    if (*str == '\0') {
        return str;
    }
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) {
        end--;
    }
    *(end + 1) = '\0';
    return str;
}

// Function to parse a JSON string and return the root node of the resulting tree
Node *parse_json(char *json_str) {
    Node *root = NULL;
    int len = strlen(json_str);
    int pos = 0;

    // Skip leading whitespace
    while (isspace((unsigned char)json_str[pos])) {
        pos++;
    }

    // Check if input is a JSON object
    if (json_str[pos] != '{') {
        printf("Error: input is not a JSON object.\n");
        return NULL;
    }

    // Allocate memory for root node
    root = (Node *)malloc(sizeof(Node));
    root->key[0] = '\0';
    root->value[0] = '\0';

    // Parse child nodes
    pos++;
    int num_children = 0;
    while (json_str[pos] != '}' && pos < len) {
        // Skip leading whitespace
        while (isspace((unsigned char)json_str[pos])) {
            pos++;
        }
        if (json_str[pos] != '\"') {
            printf("Error: malformed JSON string at position %d.\n", pos);
            free(root);
            return NULL;
        }
        pos++;

        // Read key string
        int i = 0;
        while (json_str[pos] != '\"' && i < MAX_KEY_LENGTH && pos < len) {
            root->children[num_children] = NULL;
            root->key[i] = json_str[pos];
            i++;
            pos++;
        }
        if (i == MAX_KEY_LENGTH) {
            printf("Error: key string at position %d exceeds maximum length.\n", pos);
            free(root);
            return NULL;
        }
        root->key[i] = '\0';
        pos++;

        // Skip whitespace and colon
        while (isspace((unsigned char)json_str[pos]) || json_str[pos] == ':') {
            pos++;
        }

        // Read value string
        i = 0;
        if (json_str[pos] == '\"') {  // String value
            pos++;
            while (json_str[pos] != '\"' && i < MAX_VALUE_LENGTH && pos < len) {
                root->value[i] = json_str[pos];
                i++;
                pos++;
            }
            if (i == MAX_VALUE_LENGTH) {
                printf("Error: string value at position %d exceeds maximum length.\n", pos);
                free(root);
                return NULL;
            }
            root->value[i] = '\0';
            pos++;
        } else {  // Numeric value
            while (!isspace((unsigned char)json_str[pos]) && json_str[pos] != ',' && pos < len) {
                root->value[i] = json_str[pos];
                i++;
                pos++;
            }
            if (i == MAX_VALUE_LENGTH) {
                printf("Error: numeric value at position %d exceeds maximum length.\n", pos);
                free(root);
                return NULL;
            }
            root->value[i] = '\0';
        }

        // Add child node to parent
        num_children++;
        if (num_children == MAX_CHILDREN) {
            printf("Error: maximum number of children exceeded for key \"%s\".\n", root->key);
            free(root);
            return NULL;
        }
        root->children[num_children - 1] = (Node *)malloc(sizeof(Node));
        strcpy(root->children[num_children - 1]->key, root->key);
        strcpy(root->children[num_children - 1]->value, root->value);

        // Skip whitespace and comma
        while (isspace((unsigned char)json_str[pos]) || json_str[pos] == ',') {
            pos++;
        }
    }

    // Null-terminate child list and return root node
    root->children[num_children] = NULL;
    return root;
}

// Function to free dynamic memory used by a JSON object
void free_json(Node *root) {
    if (root == NULL) {
        return;
    }
    int i = 0;
    while (root->children[i] != NULL) {
        free_json(root->children[i]);
        i++;
    }
    free(root);
}

// Example program to parse a JSON string and print its contents
int main() {
    char json_str[MAX_JSON_LENGTH] = "{\"name\": \"John Doe\",\"age\": 37,\"isMarried\": \"true\",\"hobbies\": [\"reading\",\"running\",\"gaming\"]}";
    Node *root = parse_json(json_str);
    if (root == NULL) {
        return 1;
    }
    printf("JSON object:\n");
    int i = 0;
    while (root->children[i] != NULL) {
        printf("%s: ", root->children[i]->key);
        if (is_number(root->children[i]->value)) {
            printf("%d\n", atoi(root->children[i]->value));
        } else {
            printf("%s\n", trim(root->children[i]->value));
        }
        i++;
    }
    free_json(root);
    return 0;
}