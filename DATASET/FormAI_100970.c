//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_JSON_LENGTH 2048

// Struct for a JSON object
typedef struct JSON_Object
{
    char* name;
    char* value;
    struct JSON_Object* next;
} JSON_Object;

// Function to initialize a new JSON object
JSON_Object* create_json_object(char* name, char* value)
{
    JSON_Object* new_object = (JSON_Object*) malloc(sizeof(JSON_Object));
    new_object->name = (char*) malloc(sizeof(char) * (strlen(name) + 1));
    new_object->value = (char*) malloc(sizeof(char) * (strlen(value) + 1));
    strcpy(new_object->name, name);
    strcpy(new_object->value, value);

    new_object->next = NULL;

    return new_object;
}

// Function to free the memory allocated for a JSON object
void free_json_object(JSON_Object* object)
{
    free(object->name);
    free(object->value);
    free(object);
}

// Function to parse JSON data and return a linked list of JSON objects
JSON_Object* parse_json(char* json_data)
{
    char* json_copy = (char*) malloc(sizeof(char) * (strlen(json_data) + 1));
    strcpy(json_copy, json_data);

    JSON_Object* first_object = NULL;
    JSON_Object* last_object = NULL;

    char* name = NULL;
    char* value = NULL;

    bool in_string = false;
    bool in_name = false;
    bool in_value = false;

    for(int i = 0; i < strlen(json_copy); i++)
    {
        if(json_copy[i] == '\"' && !in_string)
        {
            // Start of a new string
            in_string = true;
        }
        else if(json_copy[i] == '\"' && in_string && !in_value)
        {
            // End of the name string
            in_string = false;
            in_name = true;
        }
        else if(json_copy[i] == '\"' && in_string && in_value)
        {
            // End of the value string
            in_string = false;
            in_value = false;
            JSON_Object* new_object = create_json_object(name, value);

            if(first_object == NULL)
            {
                first_object = new_object;
                last_object = first_object;
            }
            else
            {
                last_object->next = new_object;
                last_object = new_object;
            }

            // Reset name and value pointers
            name = NULL;
            value = NULL;
        }
        else if(json_copy[i] == ':' && in_name)
        {
            // End of name, start of value
            in_name = false;
            in_value = true;
        }
        else if(json_copy[i] == ',' && !in_string)
        {
            // End of object, start of a new one
            in_name = false;
            in_value = false;
            name = NULL;
            value = NULL;
        }
        else if(json_copy[i] == '{' && !in_string)
        {
            // Start of an object, ignore
        }
        else if(json_copy[i] == '}' && !in_string)
        {
            // End of the json string, exit loop
            break;
        }
        else if(in_string)
        {
            // Add character to name/value string
            if(in_name)
            {
                if(name == NULL)
                {
                    name = (char*) malloc(sizeof(char) * 2);
                    name[0] = json_copy[i];
                    name[1] = '\0';
                }
                else
                {
                    name = (char*) realloc(name, sizeof(char) * (strlen(name) + 2));
                    name[strlen(name)] = json_copy[i];
                    name[strlen(name) + 1] = '\0';
                }
            }
            else if(in_value)
            {
                if(value == NULL)
                {
                    value = (char*) malloc(sizeof(char) * 2);
                    value[0] = json_copy[i];
                    value[1] = '\0';
                }
                else
                {
                    value = (char*) realloc(value, sizeof(char) * (strlen(value) + 2));
                    value[strlen(value)] = json_copy[i];
                    value[strlen(value) + 1] = '\0';
                }
            }
        }
    }

    free(json_copy);
    return first_object;
}

int main()
{
    char json_data[MAX_JSON_LENGTH] = "{"
                                       "\"name\":\"John Doe\","
                                       "\"age\":30,"
                                       "\"city\":\"Los Angeles\""
                                     "}";

    JSON_Object* json_objects = parse_json(json_data);

    JSON_Object* current = json_objects;

    while(current != NULL)
    {
        printf("%s: %s\n", current->name, current->value);
        current = current->next;
    }

    // Free the memory allocated for the JSON objects
    while(json_objects != NULL)
    {
        JSON_Object* temp = json_objects;
        json_objects = json_objects->next;
        free_json_object(temp);
    }

    return 0;
}