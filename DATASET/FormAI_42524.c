//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[50];
    int age;
    char occupation[50];
} Person;

char *parse_string(char *ptr, char *value) {
    char *end_ptr = strchr(ptr + 1, '\"');
    size_t length = end_ptr - ptr - 1;
    strncpy(value, ptr + 1, length);
    value[length] = '\0';
    return end_ptr + 1;
}

char *parse_number(char *ptr, int *value) {
    char *end_ptr = ptr;
    while (isdigit(*end_ptr)) {
        end_ptr++;
    }
    char temp = *end_ptr;
    *end_ptr = '\0';
    *value = atoi(ptr);
    *end_ptr = temp;
    return end_ptr;
}

int parse_object(char *ptr, Person *person) {
    ptr++;
    while (*ptr != '}') {
        char key[50];
        char value[50];
        if (*ptr != '\"') {
            return 0;
        }
        ptr = parse_string(ptr, key);
        if (*ptr != ':') {
            return 0;
        }
        ptr++;
        if (strcmp(key, "name") == 0) {
            ptr = parse_string(ptr, person->name);
        } else if (strcmp(key, "age") == 0) {
            ptr = parse_number(ptr, &person->age);
        } else if (strcmp(key, "occupation") == 0) {
            ptr = parse_string(ptr, person->occupation);
        } else {
            return 0;
        }
        if (*ptr == ',') {
            ptr++;
        } else if (*ptr != '}') {
            return 0;
        }
    }
    return 1;
}

int parse_json(char *json, Person *person) {
    if (*json != '{') {
        return 0;
    }
    return parse_object(json, person);
}

int main() {
    char *json = "{ \"name\": \"John Smith\", \"age\": 42, \"occupation\": \"Software Developer\" }";
    Person person;
    if (parse_json(json, &person)) {
        printf("Name: %s\n", person.name);
        printf("Age: %d\n", person.age);
        printf("Occupation: %s\n", person.occupation);
    } else {
        printf("Invalid JSON\n");
    }
    return 0;
}