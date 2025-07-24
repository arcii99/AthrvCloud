//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LENGTH 50
#define MAX_TEXT_LENGTH 1000

struct xml_element {
    char tag[MAX_TAG_LENGTH];
    char text[MAX_TEXT_LENGTH];
    struct xml_element *children;
    struct xml_element *next_sibling;
};

void parse_element(struct xml_element *parent_element, char *xml_data);
void parse_attribute(struct xml_element *element, char *attr_data);

int main() {
    char *xml_data =
        "<xml>"
        "<person name=\"John\" age=\"30\">"
        "<city>New York</city>"
        "<occupation>Software Developer</occupation>"
        "</person>"
        "<person name=\"Jane\" age=\"25\">"
        "<city>Los Angeles</city>"
        "<occupation>Teacher</occupation>"
        "</person>"
        "</xml>";

    struct xml_element root_element;

    root_element.children = NULL;
    root_element.next_sibling = NULL;

    parse_element(&root_element, xml_data);

    return 0;
}

void parse_element(struct xml_element *parent_element, char *xml_data) {
    char *start_tag = strstr(xml_data, "<");
    char *end_tag = strstr(xml_data, ">");

    if (start_tag == NULL || end_tag == NULL) {
        return;
    }

    int tag_length = end_tag - start_tag - 1;
    strncpy(parent_element->tag, start_tag + 1, tag_length);
    parent_element->tag[tag_length] = '\0';

    char *text_start = end_tag + 1;
    char *text_end = strstr(text_start, "<");

    if (text_end == NULL) {
        return;
    }

    int text_length = text_end - text_start;
    strncpy(parent_element->text, text_start, text_length);
    parent_element->text[text_length] = '\0';

    char *child_start = strstr(text_end, "<");

    if (child_start != NULL) {
        struct xml_element child_element;
        child_element.children = NULL;
        child_element.next_sibling = NULL;

        parse_element(&child_element, child_start);

        parent_element->children = &child_element;
    }

    char *next_start = strstr(text_end, "<");

    if (next_start != NULL) {
        struct xml_element next_element;
        next_element.children = NULL;
        next_element.next_sibling = NULL;

        parse_element(&next_element, next_start);

        parent_element->next_sibling = &next_element;
    }
}

void parse_attribute(struct xml_element *element, char *attr_data) {
    char *space_pos = strchr(attr_data, ' ');

    if (space_pos == NULL) {
        return;
    }

    int attr_length = space_pos - attr_data - 1;
    char attribute[attr_length];
    strncpy(attribute, attr_data + 1, attr_length);
    attribute[attr_length] = '\0';

    char *value_pos = strstr(attr_data, "=") + 2;
    char value[MAX_TEXT_LENGTH];
    strcpy(value, value_pos);
    value[strlen(value) - 1] = '\0';

    // Do something with attribute and value
    printf("%s=%s\n", attribute, value);

    char *next_attr_start = strchr(space_pos + 1, ' ');

    if (next_attr_start != NULL) {
        parse_attribute(element, next_attr_start);
    }
}