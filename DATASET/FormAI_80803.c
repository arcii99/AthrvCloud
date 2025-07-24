//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ELEMENTS 1000
#define MAX_ATTRIBUTE_NAME_LENGTH 50
#define MAX_ATTRIBUTE_VALUE_LENGTH 100
#define MAX_TAG_NAME_LENGTH 50
#define MAX_TAG_CONTENT_LENGTH 500

typedef struct {
    char name[MAX_TAG_NAME_LENGTH];
    char content[MAX_TAG_CONTENT_LENGTH];
    int parent;
    int num_elements;
}xml_tag;

typedef struct {
    char name[MAX_ATTRIBUTE_NAME_LENGTH];
    char value[MAX_ATTRIBUTE_VALUE_LENGTH];
}xml_attribute;

xml_tag _parse_xml(char *xml_content, xml_tag *tags, xml_attribute *attributes, int *num_attributes, int depth);

int main() {
    char xml_content[] = "<root><name first=\"John\" last=\"Doe\"> John Doe </name><age>30</age></root>";
    xml_tag tags[MAX_ELEMENTS];
    xml_attribute attributes[MAX_ELEMENTS * 10];
    int num_attributes = 0;

    memset(tags, 0, MAX_ELEMENTS * sizeof(xml_tag));
    memset(attributes, 0, (MAX_ELEMENTS * 10) * sizeof(xml_attribute));

    xml_tag root_tag = _parse_xml(xml_content, tags, attributes, &num_attributes, 0);

    // paranoid checks
    if(strcmp(root_tag.name, "root") != 0 || root_tag.parent != -1 || root_tag.num_elements != 2) {
        printf("\nError: Invalid root tag.\n");
        return 1;
    }

    xml_tag name_tag = tags[root_tag.parent + 1];
    xml_attribute first_attribute = attributes[name_tag.parent];
    xml_attribute last_attribute = attributes[name_tag.parent + 1];

    if(strcmp(name_tag.name, "name") != 0 || strcmp(name_tag.content, " John Doe ") != 0
       || strcmp(first_attribute.name, "first") != 0 || strcmp(first_attribute.value, "John") != 0
       || strcmp(last_attribute.name, "last") != 0 || strcmp(last_attribute.value, "Doe") != 0) {
        printf("\nError: Invalid name tag.\n");
        return 1;
    }

    xml_tag age_tag = tags[root_tag.parent + 2];

    if(strcmp(age_tag.name, "age") != 0 || strcmp(age_tag.content, "30") != 0) {
        printf("\nError: Invalid age tag.\n");
        return 1;
    }

    printf("\nXML parsing successful!\n");

    return 0;
}

xml_tag _parse_xml(char *xml_content, xml_tag *tags, xml_attribute *attributes, int *num_attributes, int depth) {
    xml_tag tag = {0};
    char *token;

    while((token = strsep(&xml_content, "<>"))) {
        if(token[0] == '\0') {
            continue;
        }

        if(token[0] == '/') {
            tag.content[strlen(tag.content)-1] = '\0';

            if(tags[depth-1].parent != -1) {
                tags[tags[depth-1].parent].num_elements++;
            }

            return tags[depth-1];
        }

        if(token[0] == '?') {
            continue;
        }

        if(token[0] == '!') {
            continue;
        }

        if(token[0] == ' ') {
            char *attribute;
            xml_attribute attr = {0};
            attribute = strtok(token, "=");
            strncpy(attr.name, attribute, MAX_ATTRIBUTE_NAME_LENGTH);

            attribute = strtok(NULL, " ");
            attribute = strtok(attribute, "\"");
            attribute = strtok(NULL, "\"");
            strncpy(attr.value, attribute, MAX_ATTRIBUTE_VALUE_LENGTH);

            attributes[*num_attributes] = attr;
            (*num_attributes)++;

            continue;
        }

        if(token[strlen(token)-1] == '/') {
            continue;
        }

        tag = (xml_tag) {
            .parent = depth-1,
            .num_elements = 0
        };

        strncpy(tag.name, token, MAX_TAG_NAME_LENGTH);

        if(tags[depth-1].parent != -1) {
            tags[tags[depth-1].parent].num_elements++;
        }

        tags[depth] = tag;

        if(!(token = strsep(&xml_content, "<>"))) {
            return tag;
        }

        if(token[0] == '/') {
            continue;
        }

        if(token[0] == '?') {
            continue;
        }

        if(token[0] == '!') {
            continue;
        }

        if(strchr(token, '=') != NULL) {
            char *attribute;
            xml_attribute attr = {0};
            attribute = strtok(token, "=");
            strncpy(attr.name, attribute, MAX_ATTRIBUTE_NAME_LENGTH);

            attribute = strtok(NULL, "\"");
            attribute = strtok(NULL, "\"");
            strncpy(attr.value, attribute, MAX_ATTRIBUTE_VALUE_LENGTH);

            attributes[*num_attributes] = attr;
            (*num_attributes)++;
        }

        tags[depth].content[0] = '\0';
        _parse_xml(strdup(xml_content), tags, attributes, num_attributes, depth+1);
    }

    return tag;
}