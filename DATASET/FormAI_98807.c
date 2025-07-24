//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define TAG_NAME_SIZE 32
#define MAX_ATTRIBUTES 10

typedef struct {
    char name[TAG_NAME_SIZE];
    char value[TAG_NAME_SIZE];
} attribute;

typedef struct {
    char name[TAG_NAME_SIZE];
    attribute attributes[MAX_ATTRIBUTES];
    int attribute_count;
    char content[BUFFER_SIZE];
} tag;

tag read_tag(char *text, int *index) {
    tag t;
    t.attribute_count = 0;
    memset(t.content, 0, BUFFER_SIZE);
    memset(&t.attributes, 0, sizeof(attribute) * MAX_ATTRIBUTES);

    // Read the tag name
    sscanf(&text[*index], "<%[^ />]", t.name);
    *index += strlen(t.name) + 1;

    // Read the attributes
    char *end = strstr(&text[*index], ">");
    while (text[*index] != '>' && t.attribute_count < MAX_ATTRIBUTES) {
        sscanf(&text[*index], "%s=\"%[^\"]\"", t.attributes[t.attribute_count].name, t.attributes[t.attribute_count].value);
        t.attribute_count++;
        *index += strlen(t.attributes[t.attribute_count - 1].name) + strlen(t.attributes[t.attribute_count - 1].value) + 4;
    }
    *index += 1;

    // Read the content if it exists
    end = strstr(&text[*index], "</");
    if (end != NULL) {
        strncpy(t.content, &text[*index], end - &text[*index]);
        *index += strlen(t.content);
    }

    return t;
}

void print_tag(tag t) {
    printf("Tag: %s\n", t.name);
    for (int i = 0; i < t.attribute_count; i++) {
        printf("\tAttribute: %s=%s\n", t.attributes[i].name, t.attributes[i].value);
    }
    printf("\tContent: %s\n\n", t.content);
}

int main() {
    char xml[] = "<note>\n"
                 "<to>Tove</to>\n"
                 "<from>Jani</from>\n"
                 "<heading>Reminder</heading>\n"
                 "<body>Don't forget me this weekend!</body>\n"
                 "</note>\n";

    int index = 0;
    while (index < strlen(xml)) {
        tag t = read_tag(xml, &index);
        print_tag(t);
    }

    return 0;
}