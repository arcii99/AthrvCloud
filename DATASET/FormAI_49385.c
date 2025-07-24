//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_SIZE 1000
#define STACK_SIZE 1000

typedef struct {
    char key[50];
    char value[50];
} JSON_ENTRY;

// Stack implementation
JSON_ENTRY stack[STACK_SIZE];
int top = -1;

void push(JSON_ENTRY entry) {
    if (top == STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = entry;
}

JSON_ENTRY pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

int main() {
    FILE *file = fopen("example.json", "r");
    char json[MAX_JSON_SIZE];
    char c;
    int i = 0;
    while ((c = fgetc(file)) != EOF && i < MAX_JSON_SIZE) {
        json[i++] = c;
    }
    json[i] = '\0';
    fclose(file);
    printf("Parsing JSON file\n\n");

    int num_entries = 0;
    for (i = 0; i < strlen(json); i++) {
        if (json[i] == '{') {
            printf("Found object\n");
        } else if (json[i] == '}') {
            printf("End of object\n\n");
        } else if (json[i] == ':') {
            printf("Key-Value pair\n");
            num_entries++;
        } else if (json[i] == ',') {
            printf("End of value\n\n");
        } else if (json[i] == '"') {
            printf("String value\n");
            char value[50];
            int j = 0;
            for (i++; json[i] != '"'; i++) {
                value[j++] = json[i];
            }
            value[j] = '\0';
            JSON_ENTRY entry;
            strcpy(entry.value, value);
            entry = pop();
            push(entry);
        } else if (json[i] == 't' || json[i] == 'f' || (json[i] >= '0' && json[i] <= '9') || json[i] == '-') {
            printf("Value\n");
            char value[50];
            int j = 0;
            for (; json[i] != ',' && json[i] != '}' && json[i] != ' '; i++) {
                value[j++] = json[i];
            }
            value[j] = '\0';
            JSON_ENTRY entry;
            strcpy(entry.key, "");
            strcpy(entry.value, value);
            push(entry);
        }
    }

    printf("\nTotal entries: %d\n", num_entries);
    for (i = 1; i <= num_entries; i++) {
        JSON_ENTRY entry = pop();
        printf("\nEntry %d\n", i);
        printf("Key: %s\n", entry.key);
        printf("Value: %s\n", entry.value);
    }
    return 0;
}