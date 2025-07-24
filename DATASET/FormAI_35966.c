//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// JSON Data Structure
typedef struct {
    char *key;
    char *value;
} json_object;

// Function to Parse the JSON
void parse_json(char *json_string, json_object *objects) {
    char key[MAX_LENGTH];
    char value[MAX_LENGTH];
    int i = 0, j = 0, object_count = 0;
    int string_length = strlen(json_string);

    while (i < string_length) {
        // Check for opening brace of JSON Object
        if (json_string[i] == '{') {
            j = 0; // Reset Value Index
            i++; // Move to next character

            while (json_string[i] != '}') {
                // Check for Key and Value Separated by colon
                if (json_string[i] == ':') {
                    key[j] = '\0'; // Mark End of Key

                    j = 0; // Reset Value Index
                    i++; // Move to Next Character After Colon

                    // Check for Opening Brace of Nested JSON Object
                    if (json_string[i] == '{') {
                        // Recursive Call to Parse Nested JSON Object
                        json_object nested_objects[MAX_LENGTH];
                        parse_json(json_string + i, nested_objects);
                        char nested_json[MAX_LENGTH];
                        int index = 0;
                        do {
                            nested_json[index++] = json_string[i++];
                        } while (json_string[i - 1] != '}');
                        nested_json[index] = '\0';

                        // Convert Parsed Nested JSON Object to String
                        char *nested_json_string = malloc(sizeof(char) * strlen(nested_json));
                        int k;
                        for (k = 0; k < index; k++) {
                            nested_json_string[k] = nested_json[k];
                        }
                        nested_json_string[k] = '\0';

                        // Add Parsed Nested JSON Object to Parent Object
                        objects[object_count].key = malloc(sizeof(char) * strlen(key));
                        objects[object_count].value = nested_json_string;

                        strcpy(objects[object_count].key, key);
                        object_count++;

                    } else if (json_string[i] == '[') { // Check for Opening Bracket of JSON Array
                        //TODO: Parse JSON Array
                    } else {
                        // Parse Value of JSON Object
                        while (json_string[i] != ',' && json_string[i] != '}') {
                            value[j++] = json_string[i++];
                        }
                        value[j] = '\0'; // Mark End of Value

                        // TODO: Convert Parsed Value to Appropriate Data Type

                        // Add Parsed Key-Value Pair to Object
                        objects[object_count].key = malloc(sizeof(char) * strlen(key));
                        objects[object_count].value = malloc(sizeof(char) * strlen(value));

                        strcpy(objects[object_count].key, key);
                        strcpy(objects[object_count].value, value);

                        object_count++;
                    }
                } else {
                    key[j++] = json_string[i++];
                }
            }
            i++; // Move to Next Character After Closing Brace
        } else {
            i++;
        }
    }
}

// Main Function to Test JSON Parser
int main() {
    char json_string[MAX_LENGTH] = "{"
                                    "\"firstName\": \"John\","
                                    "\"lastName\": \"Doe\","
                                    "\"age\": 25,"
                                    "\"address\": {"
                                    "    \"streetAddress\": \"21 2nd Street\","
                                    "    \"city\": \"New York\","
                                    "    \"state\": \"NY\","
                                    "    \"postalCode\": \"10021\""
                                    "},"
                                    "\"phoneNumbers\": ["
                                    "    {"
                                    "        \"type\": \"home\","
                                    "        \"number\": \"212 555-1234\""
                                    "    },"
                                    "    {"
                                    "        \"type\": \"fax\","
                                    "        \"number\": \"646 555-4567\""
                                    "    }"
                                    "],"
                                    "\"email\": \"john.doe@example.com\""
                            "}";

    json_object objects[MAX_LENGTH];
    parse_json(json_string, objects);

    int i;
    for (i = 0; i < 8; i++) {
        printf("%s: %s\n", objects[i].key, objects[i].value);
    }

    return 0;
}