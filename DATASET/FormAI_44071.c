//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the maximum size of the buffer and string for JSON object */
#define BUFFER_SIZE 1024
#define STRING_SIZE 128

/* Define the JSON object structure with name-value pairs */
typedef struct {
    int id;
    char name[STRING_SIZE];
    double price;
} JsonObject;

/* Function declarations */
void parseJsonObject(char *buffer, JsonObject *json);
void printJsonObject(JsonObject *json);

int main() {
    char buffer[BUFFER_SIZE];
    JsonObject json;

    /* Sample JSON object as string */
    char *jsonString = "{ \"id\": 123, \"name\": \"Test Item\", \"price\": 10.99 }";

    /* Copy the sample JSON object string to buffer */
    strcpy(buffer, jsonString);

    /* Parse the JSON object from the buffer */
    parseJsonObject(buffer, &json);

    /* Print the parsed JSON object */
    printJsonObject(&json);

    return 0;
}

/* Function to parse JSON object from buffer */
void parseJsonObject(char *buffer, JsonObject *json) {
    char *token, *subtoken;
    char *saveptr1, *saveptr2;
    int count = 0;

    /* Get the delimiters */
    char *delims1 = "{,}";
    char *delims2 = ":\"";

    /* Parse the JSON object using strtok_r */
    for (token = strtok_r(buffer, delims1, &saveptr1);
         token != NULL; token = strtok_r(NULL, delims1, &saveptr1))
    {
        /* Parse the name-value pairs using strtok_r */
        for (subtoken = strtok_r(token, delims2, &saveptr2);
             subtoken != NULL; subtoken = strtok_r(NULL, delims2, &saveptr2))
        {
            /* Parse the id */
            if (count == 1) {
                json->id = atoi(subtoken);
            }
            /* Parse the name */
            if (count == 3) {
                strcpy(json->name, subtoken);
            }
            /* Parse the price */
            if (count == 5) {
                json->price = atof(subtoken);
            }

            count++;
        }
        count = 0;
    }
}

/* Function to print JSON object */
void printJsonObject(JsonObject *json) {
    printf("ID: %d\n", json->id);
    printf("Name: %s\n", json->name);
    printf("Price: $%.2f\n", json->price);
}