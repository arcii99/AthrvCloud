//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct json_object {
    char key[32];
    char value[64];
};

int main() {
    char json_string[512];
    struct json_object objects[16];
    int index = 0;

    printf("Enter JSON string: ");
    fgets(json_string, sizeof(json_string), stdin);
    strtok(json_string, "{");

    char *key = NULL;
    char *value = NULL;

    while (1) {
        key = strtok(NULL, ":");
        if (key == NULL) {
            break;
        }

        value = strtok(NULL, ",");
        if (value == NULL) {
            break;
        }

        strcpy(objects[index].key, key);
        strcpy(objects[index].value, value);
        index++;
    }

    printf("Parsed JSON:\n");
    for (int i = 0; i < index; i++) {
        printf("%s: %s\n", objects[i].key, objects[i].value);
    }

    return 0;
}