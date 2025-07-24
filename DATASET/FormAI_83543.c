//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct JSON {
    char *key;
    char *value;
    struct JSON *next;
};

void addJSON(struct JSON **head, char *key, char *value) {
    struct JSON *newJSON = (struct JSON*) malloc(sizeof(struct JSON));
    newJSON->key = (char*) malloc(strlen(key) + 1);
    newJSON->value = (char*) malloc(strlen(value) + 1);

    strcpy(newJSON->key, key);
    strcpy(newJSON->value, value);

    newJSON->next = NULL;

    if (*head == NULL) {
        *head = newJSON;
    } else {
        struct JSON *lastJSON = *head;
        while (lastJSON->next != NULL) {
            lastJSON = lastJSON->next;
        }
        lastJSON->next = newJSON;
    }
}

void parseJSON(char *JSON_string, struct JSON **head) {
    char *key_start, *key_end, *value_start, *value_end;
    int len = strlen(JSON_string);
    int index = 0;

    while (index < len) {
        if (JSON_string[index] == '{') {
            index++;
        } else if (JSON_string[index] == '}') {
            break;
        } else if (JSON_string[index] == '\"') {
            key_start = JSON_string + index + 1;
            index++;
            while (index < len && JSON_string[index] != '\"') {
                index++;
            }
            key_end = JSON_string + index;
            index++;

            while (index < len && JSON_string[index] != ':') {
                index++;
            }
            index++;

            while (index < len && JSON_string[index] == ' ') {
                index++;
            }

            if (JSON_string[index] == '\"') {
                value_start = JSON_string + index + 1;
                index++;
                while (index < len && JSON_string[index] != '\"') {
                    index++;
                }
                value_end = JSON_string + index;
                addJSON(head, key_start, value_start);
            } else {
                value_start = JSON_string + index;
                while (index < len && JSON_string[index] != ',' && JSON_string[index] != '}') {
                    index++;
                }
                value_end = JSON_string + index;
                addJSON(head, key_start, value_start);
            }
            index++;
        } else {
            index++;
        }
    }
}

int main() {
    char *JSON_string = "{\"name\": \"Ken Thompson\", \"age\": 77, \"language\": \"C\"}";
    struct JSON *head = NULL;

    parseJSON(JSON_string, &head);

    struct JSON *currentJSON = head;
    while (currentJSON != NULL) {
        printf("%s: %s\n", currentJSON->key, currentJSON->value);
        currentJSON = currentJSON->next;
    }

    return 0;
}