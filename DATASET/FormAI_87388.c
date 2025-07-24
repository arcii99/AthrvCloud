//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* JSON string to be parsed */
char* json = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";

/* Structure for holding the parsed JSON data */
typedef struct {
    char name[50];
    int age;
    char city[50];
} Person;

/* Parse a JSON object and return a Person struct */
Person parse_json(char* json) {
    Person p;
    int i = 0;
    char c = json[i];

    /* Ignore leading whitespace */
    while (c == ' ' || c == '\n' || c == '\r' || c == '\t') {
        i++;
        c = json[i];
    }

    /* Check for opening brace */
    if (c == '{') {
        i++;
        c = json[i];

        /* Parse name */
        char key[50];
        int key_index = 0;
        while (c != ':') {
            key[key_index] = c;
            key_index++;
            i++;
            c = json[i];
        }
        key[key_index] = '\0';

        /* Ignore colon and leading whitespace */
        i++;
        c = json[i];
        while (c == ' ' || c == '\n' || c == '\r' || c == '\t') {
            i++;
            c = json[i];
        }

        /* Parse value */
        if (key[0] == 'n') { /* name */
            char name[50];
            int name_index = 0;
            while (c != '\"') {
                name[name_index] = c;
                name_index++;
                i++;
                c = json[i];
            }
            name[name_index] = '\0';
            strcpy(p.name, name);
        } else if (key[0] == 'a') { /* age */
            int age = 0;
            while (c >= '0' && c <= '9') {
                age = age * 10 + c - '0';
                i++;
                c = json[i];
            }
            p.age = age;
        } else if (key[0] == 'c') { /* city */
            char city[50];
            int city_index = 0;
            while (c != '\"') {
                city[city_index] = c;
                city_index++;
                i++;
                c = json[i];
            }
            city[city_index] = '\0';
            strcpy(p.city, city);
        }

        /* Ignore trailing whitespace */
        while (c == ' ' || c == ',' || c == '}' || c == '\n' || c == '\r' || c == '\t') {
            i++;
            c = json[i];
        }
    }

    return p;
}

int main() {
    Person p = parse_json(json);

    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("City: %s\n", p.city);

    return 0;
}