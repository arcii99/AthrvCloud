//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// defining a JSON structure
typedef struct JSON {
    char *key;
    char *value;
    struct JSON *nxt;
} json;

// function to remove whitespace from a string
char *trimStr(char *str) {
    char *end;
    while (isspace(*str)) str++;
    if (*str == '\0') return str;
    end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) end--;
    *(end + 1) = '\0';
    return str;
}

// function to create and return a new JSON structure
json *createJSON(char *key, char *value) {
    json *newNode = (json *)malloc(sizeof(json));
    newNode->key = key;
    newNode->value = value;
    newNode->nxt = NULL;
    return newNode;
}

// function to parse and retrieve JSON objects
json *parseJSON(char *JSONStr) {
    int len = strlen(JSONStr);
    int i = 0;
    json *first, *last = NULL;
    char *key, *value;
    while (i < len) {
        if(JSONStr[i] == '{') {
            json *newNode;
            key = value = NULL;
            while (JSONStr[i] != '}') {
                i++;
                if (JSONStr[i] == '"') {
                    i++;
                    char buffer[100];
                    int j = 0;
                    while (JSONStr[i] != '"') {
                        buffer[j] = JSONStr[i];
                        i++; j++;
                    }
                    buffer[j] = '\0';
                    if(key == NULL) key = strdup(buffer);
                    else value = strdup(buffer);
                }
            }
            newNode = createJSON(key, value);
            if (first == NULL) {
                first = newNode;
                last = newNode;
            } else {
                last->nxt = newNode;
                last = newNode;
            }
        }
        i++;
    }
    return first;
}

int main() {
    char JSONString[1000] = "{ \"name\":\"John\", \"age\":31, \"city\":\"New York\" }";
    char *trimmedJSON = trimStr(JSONString);
    json *parsedJSON = parseJSON(trimmedJSON);
    while(parsedJSON) {
        printf("%s: %s\n", parsedJSON->key, parsedJSON->value);
        parsedJSON = parsedJSON->nxt;
    }
    return 0;
}