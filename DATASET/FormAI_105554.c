//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char tag[50];
    char value[50];
    // You can add more fields here depending on your XML structure
} XMLNode;

const char* get_node_value(char* xml, char* tag) {
    // This function returns the value of the first node that matches the specified tag
    char opening_tag[50], closing_tag[50], value[50];
    sprintf(opening_tag, "<%s>", tag);
    sprintf(closing_tag, "</%s>", tag);

    char* start = strstr(xml, opening_tag);
    if (start == NULL) return NULL;

    char* end = strstr(start, closing_tag);
    if (end == NULL) return NULL;

    int len = end - start - strlen(opening_tag);
    strncpy(value, start + strlen(opening_tag), len);
    value[len] = '\0';

    return strdup(value);
}

int main() {
    char xml[200] = "<person><name>John Smith</name><age>30</age></person>";

    XMLNode person_node;
    strcpy(person_node.tag, "person");

    const char* name = get_node_value(xml, "name");
    const char* age = get_node_value(xml, "age");

    if (name) strcpy(person_node.value, name);
    else person_node.value[0] = '\0';

    printf("The person's name is %s and age is %s", person_node.value, age);

    free((char*)name);

    return 0;
}