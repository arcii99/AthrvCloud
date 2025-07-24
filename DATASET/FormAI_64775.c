//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 512

char* parse_value(char* json, char* key);
void find_key(char* json, char* key, char* value);

int main() {
    char json[MAX_SIZE] = "{\"name\": \"John\", \"age\": 25, \"city\": \"New York\"}";
    char* name = parse_value(json, "name");
    printf("Name: %s\n", name);
    free(name);

    char* age = parse_value(json, "age");
    printf("Age: %s\n", age);
    free(age);

    char* city = parse_value(json, "city");
    printf("City: %s\n", city);
    free(city);

    return 0;
}

char* parse_value(char* json, char* key) {
    char* value = (char*) malloc(MAX_SIZE * sizeof(char));
    find_key(json, key, value);
    return value;
}

void find_key(char* json, char* key, char* value) {
    char* pos = strstr(json, key);
    if (pos == NULL) {
        value[0] = '\0';
        return;
    }

    pos += strlen(key) + 2;
    int i = 0;
    while (pos[i] != '\"') {
        value[i] = pos[i];
        i++;
    }
    value[i] = '\0';
}