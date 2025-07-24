//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: light-weight
/* C program to parse JSON data */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure to store JSON object */
typedef struct {
    char key[50];
    char value[50];
} json_object;

/* Function declarations */
void parse_json(char* json_string, json_object* obj);

/* Main function */
int main() {
    char json_string[1000] = "{\"name\": \"John\",\"age\":30,\"city\":\"New York\"}";

    /* Create object to store JSON data */
    json_object obj[3];

    /* Parse JSON string */
    parse_json(json_string, obj);

    /* Print parsed data */
    printf("Name: %s\n", obj[0].value);
    printf("Age: %s\n", obj[1].value);
    printf("City: %s\n", obj[2].value);

    return 0;
}

/* Function to parse JSON string */
void parse_json(char* json_string, json_object* obj) {
    int i = 0, j = 0, k = 0;

    while(json_string[k] != '}') {
        /* Find key */
        while(json_string[k] != ':') {
            obj[i].key[j++] = json_string[k++];
        }
        obj[i].key[j] = '\0';

        /* Find value */
        j = 0; k++;
        while(json_string[k] != ',' && json_string[k] != '}') {
            obj[i].value[j++] = json_string[k++];
        }
        obj[i].value[j] = '\0';
        if(json_string[k] == ',') k++;
        i++; j = 0;
    }
}