//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* tag_name;
    char** attributes;
    int num_attributes;
    char* content;
} element;

typedef struct {
    element** elements;
    int num_elements;
} xml_document;

void parse_attributes(char* attributes_str, char** attributes) {
    char* token;
    int i = 0;
    token = strtok(attributes_str, " ");
    while (token != NULL) {
        attributes[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
}

void parse_element(char* element_str, element* new_element) {
    // get tag name
    char* end_tag = strchr(element_str, '>');
    int tag_name_len = end_tag - element_str - 1;
    new_element->tag_name = calloc(tag_name_len + 1, sizeof(char));
    strncpy(new_element->tag_name, element_str + 1, tag_name_len);
    // check if self-closing tag
    if (*(end_tag - 1) == '/') {
        new_element->num_attributes = 0;
        new_element->attributes = NULL;
        new_element->content = NULL;
        return;
    }
    // get attributes
    char* attributes_str_start = strchr(element_str, ' ');
    char* attributes_str_end = end_tag;
    int attributes_str_len = attributes_str_end - attributes_str_start - 1;
    char* attributes_str = calloc(attributes_str_len + 1, sizeof(char));
    strncpy(attributes_str, attributes_str_start + 1, attributes_str_len);
    new_element->num_attributes = 0;
    char* temp_str = strdup(attributes_str);
    char* token = strtok(temp_str, " ");
    while (token != NULL) {
        new_element->num_attributes++;
        token = strtok(NULL, " ");
    }
    new_element->attributes = calloc(new_element->num_attributes, sizeof(char*));
    parse_attributes(attributes_str, new_element->attributes);
    // get content
    char* content_start = end_tag + 1;
    char* content_end = strstr(content_start, "</");
    int content_len = content_end - content_start;
    new_element->content = calloc(content_len + 1, sizeof(char));
    strncpy(new_element->content, content_start, content_len);
}

xml_document* parse_xml(char* xml_str) {
    xml_document* doc = calloc(1, sizeof(xml_document));
    char* temp_str = strdup(xml_str);
    char* token = strtok(temp_str, "<");
    while (token != NULL) {
        if (*token == '/') {
            // closing tag, do nothing
        } else {
            element* new_element = calloc(1, sizeof(element));
            parse_element(token, new_element);
            doc->num_elements++;
            doc->elements = realloc(doc->elements, doc->num_elements * sizeof(element*));
            doc->elements[doc->num_elements - 1] = new_element;
        }
        token = strtok(NULL, "<");
    }
    return doc;
}

void print_xml(xml_document* doc) {
    printf("<xml>\n");
    for (int i = 0; i < doc->num_elements; i++) {
        element* el = doc->elements[i];
        printf("\t<%s", el->tag_name);
        for (int j = 0; j < el->num_attributes; j++) {
            printf(" %s", el->attributes[j]);
        }
        if (el->num_attributes > 0) {
            printf(" ");
        }
        printf(">%s</%s>\n", el->content, el->tag_name);
    }
    printf("</xml>\n");
}

int main() {
    char* test_xml = "<xml><person name='Alice' age='25'>Hello, world!</person></xml>";
    xml_document* doc = parse_xml(test_xml);
    print_xml(doc);
    return 0;
}