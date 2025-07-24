//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to hold a JSON object
typedef struct {
    int id;
    char name[50];
    float price;
} Item;

// function that parses a JSON object and returns an Item struct
Item parseJSON(char* jsonString) {
    Item item;
    char* token;
    char* key;
    char* value;

    // loop through each token separated by commas
    token = strtok(jsonString, ",");
    while (token != NULL) {
        // split each key/value pair using a colon
        key = strtok(token, ":");
        value = strtok(NULL, ":");

        // remove any quotes from the value string
        value[strlen(value)-1] = '\0'; // remove closing quote
        value++; // remove opening quote

        // store the key/value pair in the item struct
        if (strcmp(key, "id") == 0) {
            item.id = atoi(value);
        } else if (strcmp(key, "name") == 0) {
            strcpy(item.name, value);
        } else if (strcmp(key, "price") == 0) {
            item.price = atof(value);
        }

        // get the next token
        token = strtok(NULL, ",");
    }

    return item;
}

int main() {
    // sample JSON string
    char* jsonString = "{ \"id\": 1, \"name\": \"item1\", \"price\": 4.99 }";
    // parse the JSON string and store it in an Item struct
    Item item = parseJSON(jsonString);
    // print the parsed item
    printf("Item ID: %d\n", item.id);
    printf("Item Name: %s\n", item.name);
    printf("Item Price: $%.2f\n", item.price);

    return 0;
}