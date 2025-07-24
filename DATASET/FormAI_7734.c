//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_OBJECTS 100
#define MAX_OBJECT_PROPERTIES 100

// JSON Object Structure
typedef struct {
    char name[50];
    char type[10];
    int property_count;
    char properties[MAX_OBJECT_PROPERTIES][2][50];
} JsonObject;

// JSON Parser function
JsonObject *parse_json(char *json_string) {
    JsonObject *objects = (JsonObject *) malloc(sizeof(JsonObject) * MAX_OBJECTS);
    int object_count = 0;
    int property_count = 0;
    char property_name[50], property_value[50];
    char current_object_name[50], current_object_type[10];
    int i = 1; // Ignore the opening '{' of the JSON string

    while (json_string[i] != '\0') {
        if (json_string[i] == '{') {
            // Start of new JSON object
            property_count = 0;
            i++;
        } else if (json_string[i] == '}') {
            // End of current JSON object
            strcpy(objects[object_count].name, current_object_name);
            strcpy(objects[object_count].type, current_object_type);
            objects[object_count].property_count = property_count;
            for (int j = 0; j < property_count; j++) {
                strcpy(objects[object_count].properties[j][0], property_name);
                strcpy(objects[object_count].properties[j][1], property_value);
            }
            object_count++;
            i++;
        } else {
            // Parse property name
            int j = 0;
            while (json_string[i] != ':') {
                property_name[j++] = json_string[i];
                i++;
            }
            property_name[j] = '\0';
            i++; // Skip colon

            // Parse property value
            j = 0;
            while (json_string[i] != ',' && json_string[i] != '}') {
                property_value[j++] = json_string[i];
                i++;
            }
            property_value[j] = '\0';
            property_count++;

            // If current object type is not set, set it as the first property value
            if (object_count > 0 && strlen(current_object_type) == 0) {
                strcpy(current_object_type, property_value);
            }

            // If current object name is not set, set it as the first property name
            if (object_count > 0 && strlen(current_object_name) == 0) {
                strcpy(current_object_name, property_name);
            }

            i++; // Skip comma
        }
    }

    return objects;
}

int main() {
    char json_string[1000] = "{\"person\":{\"name\":\"John Doe\",\"age\":30,\"email\":\"john.doe@example.com\"},\"company\":{\"name\":\"XYZ Inc.\",\"employees\":50,\"revenue\":1000000}}";
    JsonObject *objects = parse_json(json_string);

    for (int i = 0; i < 2; i++) {
        JsonObject object = objects[i];
        printf("Name: %s\nType: %s\nProperties:\n", object.name, object.type);
        for (int j = 0; j < object.property_count; j++) {
            printf("%s: %s\n", object.properties[j][0], object.properties[j][1]);
        }
        printf("\n");
    }

    free(objects);

    return 0;
}