//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length for keys and values
#define MAX_KEY_LEN 100
#define MAX_VAL_LEN 200

// Define the maximum number of items in the JSON object
#define MAX_ITEMS 100

typedef struct {
    char key[MAX_KEY_LEN]; // Key of the item
    char value[MAX_VAL_LEN]; // Value of the item
} Item;

int main() {
    // Initialize an array of items
    Item items[MAX_ITEMS];

    // Read the input json string
    char json_str[MAX_VAL_LEN];
    printf("Enter JSON string: ");
    fgets(json_str, MAX_VAL_LEN, stdin);

    // Remove any newline characters in the json string
    for (int i = 0; i < strlen(json_str); i++) {
        if (json_str[i] == '\n') {
            json_str[i] = '\0';
        }
    }

    // Parse the input json string
    int num_items = 0;
    char key[MAX_KEY_LEN];
    char val[MAX_VAL_LEN];
    int i;
    for (i = 0; i < strlen(json_str); i++) {
        if (json_str[i] == '{') {
            continue;
        } else if (json_str[i] == '}') {
            break;
        } else if (json_str[i] == ',') {
            num_items++;
            continue;
        } else if (json_str[i] == '\"') {
            int j = i + 1;
            int k = 0;
            while (json_str[j] != '\"') {
                key[k] = json_str[j];
                j++;
                k++;
            }
            key[k] = '\0';
            i = j + 2;
            j = i;
            k = 0;
            while (json_str[j] != '\"') {
                val[k] = json_str[j];
                j++;
                k++;
            }
            val[k] = '\0';
            strcpy(items[num_items].key, key);
            strcpy(items[num_items].value, val);
        }
    }
    num_items++;

    // Print the parsed JSON object
    printf("{\n");
    for (int i = 0; i < num_items; i++) {
        printf("    \"%s\": \"%s\"", items[i].key, items[i].value);
        if (i < num_items - 1) {
            printf(",");
        }
        printf("\n");
    }
    printf("}\n");

    return 0;
}