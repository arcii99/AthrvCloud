//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// JSON Parser function
char *jsonParser(char *jsonStr, char *key)
{
    char *value = NULL;
    char *token, *subtoken;

    // Get the key-value pair from the JSON string
    token = strtok(jsonStr, "{}");

    while (token != NULL) {
        subtoken = strtok(token, ":");
        if (strcmp(subtoken, key) == 0) {
            subtoken = strtok(NULL, ":");
            value = (char*)malloc(strlen(subtoken)*sizeof(char));
            strcpy(value, subtoken);
            break;
        }
        token = strtok(NULL, "{}");
    }

    return value;
}

int main()
{
    // Example JSON string
    char jsonStr[] = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";

    // Call the JSON parser function with the key and get the value
    char *name = jsonParser(jsonStr, "\"name\"");
    char *age = jsonParser(jsonStr, "\"age\"");
    char *city = jsonParser(jsonStr, "\"city\"");

    // Print the values obtained from the JSON parser
    printf("Name: %s\n", name);
    printf("Age: %s\n", age);
    printf("City: %s\n", city);

    // Free the memory allocated for the values
    free(name);
    free(age);
    free(city);

    return 0;
}