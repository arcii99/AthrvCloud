//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Maximum length of a JSON value */
#define MAX_VALUE_LENGTH 100

/* JSON value data type */
typedef union {
    char str[MAX_VALUE_LENGTH];
    int num;
    float fnum;
    char boolean[6];
} Value;

/* JSON node structure */
typedef struct Node {
    Value val;
    char key[MAX_VALUE_LENGTH];
    struct Node *next;
    struct Node *child;
} Node;

/* JSON parse function declarations */
void parse_object(Node **);
void parse_array(Node **);
void parse_value(Node **);
void parse_string(char *);
void parse_number(char *);
void parse_boolean(char *);

/* Global variables */
char json_string[MAX_VALUE_LENGTH];
int pos = 0;

/* JSON parse function implementations */
void parse_object(Node **node) {
    Node *last = NULL;
    while (json_string[pos] != '\0') {
        /* Skip whitespace */
        while (isspace(json_string[pos])) {
            pos++;
        }
        
        /* Check for end of object */
        if (json_string[pos] == '}') {
            pos++;
            return;
        }
        
        /* Parse key */
        char key[MAX_VALUE_LENGTH];
        parse_string(key);
        
        /* Skip whitespace */
        while (isspace(json_string[pos])) {
            pos++;
        }
        
        /* Check for colon */
        if (json_string[pos] != ':') {
            printf("Error: expected colon\n");
            exit(1);
        }
        
        pos++;
        
        /* Parse value */
        Node *new_node = malloc(sizeof(Node));
        new_node->next = NULL;
        strcpy(new_node->key, key);
        parse_value(&(new_node->child));
        
        if (*node == NULL) {
            *node = new_node;
        } else {
            last->next = new_node;
        }
        
        last = new_node;
        
        /* Skip whitespace */
        while (isspace(json_string[pos])) {
            pos++;
        }
        
        /* Check for comma or end of object */
        if (json_string[pos] == ',') {
            pos++;
        } else if (json_string[pos] == '}') {
            pos++;
            return;
        } else {
            printf("Error: expected comma or end of object\n");
            exit(1);
        }
    }
}

void parse_array(Node **node) {
    Node *last = NULL;
    while (json_string[pos] != '\0') {
        /* Skip whitespace */
        while (isspace(json_string[pos])) {
            pos++;
        }
        
        /* Check for end of array */
        if (json_string[pos] == ']') {
            pos++;
            return;
        }
        
        /* Parse value */
        Node *new_node = malloc(sizeof(Node));
        new_node->next = NULL;
        parse_value(&(new_node->child));
        
        if (*node == NULL) {
            *node = new_node;
        } else {
            last->next = new_node;
        }
        
        last = new_node;
        
        /* Skip whitespace */
        while (isspace(json_string[pos])) {
            pos++;
        }
        
        /* Check for comma or end of array */
        if (json_string[pos] == ',') {
            pos++;
        } else if (json_string[pos] == ']') {
            pos++;
            return;
        } else {
            printf("Error: expected comma or end of array\n");
            exit(1);
        }
    }
}

void parse_value(Node **node) {
    /* Skip whitespace */
    while (isspace(json_string[pos])) {
        pos++;
    }
    
    /* Determine value type */
    if (json_string[pos] == '{') {
        pos++;
        parse_object(node);
    } else if (json_string[pos] == '[') {
        pos++;
        parse_array(node);
    } else if (json_string[pos] == '\"') {
        pos++;
        parse_string((*node)->val.str);
    } else if (isdigit(json_string[pos])) {
        parse_number((*node)->val.str);
    } else {
        parse_boolean((*node)->val.boolean);
    }
}

void parse_string(char *str) {
    int i = 0;
    while (json_string[pos] != '\0' && json_string[pos] != '\"') {
        str[i] = json_string[pos];
        pos++;
        i++;
    }
    str[i] = '\0';
    pos++;
}

void parse_number(char *num) {
    int i = 0;
    while (isdigit(json_string[pos]) || json_string[pos] == '.') {
        num[i] = json_string[pos];
        pos++;
        i++;
    }
    num[i] = '\0';
}

void parse_boolean(char *bool) {
    if (strncmp(&json_string[pos], "true", 4) == 0) {
        strncpy(bool, "true", 5);
        pos += 4;
    } else if (strncmp(&json_string[pos], "false", 5) == 0) {
        strncpy(bool, "false", 6);
        pos += 5;
    } else {
        printf("Error: expected boolean value\n");
        exit(1);
    }
}

int main() {
    /* Example JSON string: { "name": "John Smith", "age": 30, "height": 5.11, "isMarried": true } */
    strcpy(json_string, "{ \"name\": \"John Smith\", \"age\": 30, \"height\": 5.11, \"isMarried\": true }");
    
    Node *root = NULL;
    parse_value(&root);
    
    /* Print parsed JSON data */
    Node *node = root;
    while (node != NULL) {
        printf("%s: ", node->key);
        
        if (isdigit(node->child->val.str[0])) {
            printf("%d\n", node->child->val.num);
        } else if (node->child->val.boolean[0] != '\0') {
            printf("%s\n", node->child->val.boolean);
        } else {
            printf("%s\n", node->child->val.str);
        }
        
        node = node->next;
    }
    
    return 0;
}