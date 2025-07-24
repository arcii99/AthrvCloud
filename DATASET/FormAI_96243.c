//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A simple JSON object */
char json[] = "{\"name\":\"John\",\"age\":32,\"city\":\"New York\"}";

/* Structure to hold the JSON data */
struct json_data {
    char* name;
    int age;
    char* city;
};

/* Function to parse the JSON object */
struct json_data parse_json(char* str) {
    char* ptr = str;
    struct json_data jd;

    /* Parse name */
    ptr = strstr(ptr, "\"name\":");
    ptr += strlen("\"name\":");
    jd.name = malloc(sizeof(char) * 50);
    sscanf(ptr, "\"%[^\"]\"", jd.name);

    /* Parse age */
    ptr = strstr(ptr, "\"age\":");
    ptr += strlen("\"age\":");
    sscanf(ptr, "%d", &jd.age);

    /* Parse city */
    ptr = strstr(ptr, "\"city\":");
    ptr += strlen("\"city\":");
    jd.city = malloc(sizeof(char) * 50);
    sscanf(ptr, "\"%[^\"]\"", jd.city);

    return jd;
}

int main() {
    struct json_data data = parse_json(json);
    printf("Name: %s\nAge: %d\nCity: %s\n", data.name, data.age, data.city);

    free(data.name);
    free(data.city);
    return 0;
}