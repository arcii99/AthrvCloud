//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: shape shifting
#include <stdio.h>
#include <string.h>

// Define the shape-shifting function to shift the JSON object into a C struct
struct json_object {
    int id;
    char name[50];
    float price;
};

void shift_json_object(char *json_str, struct json_object *obj) {
    // Locate the position of the "id" field in the JSON object
    char *id_pos = strstr(json_str, "\"id\":");
    if (id_pos != NULL) {
        // If the "id" field is present, extract its value and assign it to the object
        sscanf(id_pos + 6, "%d", &obj->id);
    }

    // Locate the position of the "name" field in the JSON object
    char *name_pos = strstr(json_str, "\"name\":");
    if (name_pos != NULL) {
        // If the "name" field is present, extract its value and assign it to the object
        sscanf(name_pos + 8, "\"%[^\"]\"", obj->name);
    }

    // Locate the position of the "price" field in the JSON object
    char *price_pos = strstr(json_str, "\"price\":");
    if (price_pos != NULL) {
        // If the "price" field is present, extract its value and assign it to the object
        sscanf(price_pos + 8, "%f", &obj->price);
    }
}

int main() {
    // Example JSON string
    char json_str[] = "{\"id\": 1, \"name\": \"Example Object\", \"price\": 9.99}";

    // Create a new JSON object
    struct json_object obj;

    // Shift the JSON object into the C struct
    shift_json_object(json_str, &obj);

    // Print out the object's fields to verify successful shape-shifting
    printf("ID: %d\nName: %s\nPrice: %.2f\n", obj.id, obj.name, obj.price);

    return 0;
}