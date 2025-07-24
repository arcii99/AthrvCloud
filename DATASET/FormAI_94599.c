//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME_LENGTH 50
#define MAX_ATTRIBUTE_NAME_LENGTH 50
#define MAX_ATTRIBUTE_VALUE_LENGTH 100
#define MAX_ELEMENT_CONTENT_LENGTH 500

typedef struct attribute {
    char name[MAX_ATTRIBUTE_NAME_LENGTH];
    char value[MAX_ATTRIBUTE_VALUE_LENGTH];
} Attribute;

typedef struct element {
    char tag_name[MAX_TAG_NAME_LENGTH];
    Attribute attributes[10];
    int num_attributes;
    char content[MAX_ELEMENT_CONTENT_LENGTH];
    int num_children;
    struct element *children[10];
} Element;

Element *parse_xml(char *xml_string) {
    int xml_length = strlen(xml_string);
    int xml_index = 0;

    Element *root = (Element*)malloc(sizeof(Element));
    root->num_attributes = 0;
    root->num_children = 0;

    while (xml_index < xml_length) {
        char current_char = xml_string[xml_index];
        if (current_char == '<') {
            xml_index++;
            if (xml_string[xml_index] == '/') {
                xml_index++;
                char tag_name[MAX_TAG_NAME_LENGTH];
                int tag_index = 0;
                while (xml_string[xml_index] != '>') {
                    tag_name[tag_index] = xml_string[xml_index];
                    xml_index++;
                    tag_index++;
                }
                tag_name[tag_index] = '\0';
                if (strcmp(tag_name, root->tag_name) != 0) {
                    printf("Error: Mismatched tag <%s> and <%s>\n", root->tag_name, tag_name);
                }
                else {
                    break;
                }
            }
            else {
                char tag_name[MAX_TAG_NAME_LENGTH];
                int tag_index = 0;
                while (xml_string[xml_index] != ' ' && xml_string[xml_index] != '>') {
                    tag_name[tag_index] = xml_string[xml_index];
                    xml_index++;
                    tag_index++;
                }
                tag_name[tag_index] = '\0';
                Element *new_element = (Element*)malloc(sizeof(Element));
                strcpy(new_element->tag_name, tag_name);
                new_element->num_attributes = 0;
                new_element->num_children = 0;
                while (xml_string[xml_index] != '>') {
                    if (xml_string[xml_index] == ' ') {
                        xml_index++;
                        char attr_name[MAX_ATTRIBUTE_NAME_LENGTH];
                        int attr_index = 0;
                        while (xml_string[xml_index] != '=') {
                            attr_name[attr_index] = xml_string[xml_index];
                            xml_index++;
                            attr_index++;
                        }
                        attr_name[attr_index] = '\0';
                        xml_index++;
                        char quote = xml_string[xml_index];
                        xml_index++;
                        char attr_value[MAX_ATTRIBUTE_VALUE_LENGTH];
                        int value_index = 0;
                        while (xml_string[xml_index] != quote) {
                            attr_value[value_index] = xml_string[xml_index];
                            xml_index++;
                            value_index++;
                        }
                        attr_value[value_index] = '\0';
                        Attribute *new_attr = (Attribute*)malloc(sizeof(Attribute));
                        strcpy(new_attr->name, attr_name);
                        strcpy(new_attr->value, attr_value);
                        new_element->attributes[new_element->num_attributes] = *new_attr;
                        new_element->num_attributes++;
                    }
                    else {
                        xml_index++;
                    }
                }
                xml_index++;
                int content_index = 0;
                while (xml_string[xml_index] != '<') {
                    new_element->content[content_index] = xml_string[xml_index];
                    xml_index++;
                    content_index++;
                }
                new_element->content[content_index] = '\0';
                if (new_element->content[0] != '\0') {
                    root->children[root->num_children] = new_element;
                    root->num_children++;
                }
                else {
                    Element *child = parse_xml(xml_string+xml_index);
                    if (child != NULL) {
                        root->children[root->num_children] = child;
                        root->num_children++;
                    }
                }
            }
        }
        else {
            xml_index++;
        }
    }
    return root;
}

int main() {
    char xml_string[] = "<bookstore>\n"
                        "  <book category=\"cooking\">\n"
                        "    <title lang=\"en\">Everyday Italian</title>\n"
                        "    <author>Giada De Laurentiis</author>\n"
                        "    <year>2005</year>\n"
                        "    <price>30.00</price>\n"
                        "  </book>\n"
                        "  <book category=\"children\">\n"
                        "    <title lang=\"en\">Harry Potter</title>\n"
                        "    <author>J.K. Rowling</author>\n"
                        "    <year>2005</year>\n"
                        "    <price>29.99</price>\n"
                        "  </book>\n"
                        "</bookstore>";
    Element *root = parse_xml(xml_string);
    printf("Root element: %s\n", root->tag_name);
    printf("Attributes: %d\n", root->num_attributes);
    int i;
    for (i = 0; i < root->num_children; i++) {
        Element *child = root->children[i];
        printf("Child element: %s\n", child->tag_name);
        printf("Content: %s\n", child->content);
    }
    return 0;
}