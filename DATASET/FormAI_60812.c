//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int age;
    char name[50];
} Person;

void parse_json(char* json_string, size_t length) {
    int i = 0;
    char key[50];
    char value[50];
    Person person;

    while (i < length) {
        if (json_string[i] == '{') {
            printf("Ooh, another person!\n");

            // reset variables
            memset(key, 0, 50);
            memset(value, 0, 50);
        } else if (json_string[i] == '}') {
            printf("Done parsing this person!\n");

            // print parsed data
            printf("Name: %s\n", person.name);
            printf("Age: %d\n", person.age);

            // reset variables
            memset(key, 0, 50);
            memset(value, 0, 50);
        } else if (json_string[i] == ',') {
            printf("Finished parsing %s\n", key);

            // map key-value pairs to struct
            if (strcmp(key, "name") == 0) {
                strcpy(person.name, value);
            } else if (strcmp(key, "age") == 0) {
                person.age = atoi(value);
            }

            // reset variables
            memset(key, 0, 50);
            memset(value, 0, 50);
        } else if (json_string[i] == '"') {
            // parse key or value based on the index of the quote
            int quote_index = i;
            i++;

            while (json_string[i] != '"') {
                if (quote_index == i) {
                    // parse key
                    int key_index = 0;
                    while (json_string[i] != ':') {
                        key[key_index] = json_string[i];
                        key_index++;
                        i++;
                    }
                } else {
                    // parse value
                    int value_index = 0;
                    while (json_string[i] != ',' && json_string[i] != '}') {
                        value[value_index] = json_string[i];
                        value_index++;
                        i++;
                    }
                }
                i++;
            }
        } else {
            // ignore whitespace and other characters
            i++;
        }
    }
}

int main() {
    char json_string[] = "{\"name\":\"Alice\",\"age\":21},{\"name\":\"Bob\",\"age\":28}";
    size_t length = sizeof(json_string) / sizeof(json_string[0]);

    parse_json(json_string, length);

    return 0;
}