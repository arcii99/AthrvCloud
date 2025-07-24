//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_SIZE 512

int main(void) {
    char json[MAX_JSON_SIZE];
    char key[MAX_JSON_SIZE];
    char value[MAX_JSON_SIZE];

    printf("Enter a simple JSON string: ");
    fgets(json, MAX_JSON_SIZE, stdin);

    // Start parsing
    int i = 0;
    while (json[i] != '\0') {
        if (json[i] == '{' || json[i] == '}' || json[i] == ':' || json[i] == ',') {
            i++; // ignore these characters
        } else if (isspace(json[i])) {
            i++; // ignore white spaces
        } else {
            // parse key
            int j = i;
            while (json[j] != ':') {
                key[j-i] = json[j];
                j++;
            }
            key[j-i] = '\0';

            // parse value
            j++; // skip ':'
            int k = j;
            while (json[k] != ',' && json[k] != '}') {
                value[k-j] = json[k];
                k++;
            }
            value[k-j] = '\0';

            // print key-value pair
            printf("'%s' : '%s'\n", key, value);

            i = k+1; // move to next item
        }
    }

    return 0;
}