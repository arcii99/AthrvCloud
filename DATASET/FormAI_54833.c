//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// XML tag struct
typedef struct tag {
    char* name;
    char* content;
    struct attr* attributes;
    struct tag* children;
    struct tag* next;
} tag;

// Attribute struct
typedef struct attr {
    char* name;
    char* value;
    struct attr* next;
} attr;

// Current tag being parsed
tag* current_tag;

// Root of XML tree
tag* root;

// Function to add attribute to current tag
void add_attribute(char* name, char* value) {
    // Allocate memory for attribute
    attr* new_attr = (attr*) malloc(sizeof(attr));
    new_attr->name = strdup(name);
    new_attr->value = strdup(value);
    new_attr->next = current_tag->attributes;
    current_tag->attributes = new_attr;
}

// Function to add child tag to current tag
void add_child(tag* child) {
    child->next = current_tag->children;
    current_tag->children = child;
}

// Function to parse XML content
void parse_xml(char* xml) {
    int xml_len = strlen(xml);
    int i = 0;
    while (i < xml_len) {
        if (xml[i] == '<') {
            i++;
            if (xml[i] != '/') {
                // New opening tag
                int j = i;
                while (xml[j] != ' ' && xml[j] != '>') j++;
                char* tag_name = strndup(xml + i, j - i);
                tag* new_tag = (tag*) malloc(sizeof(tag));
                new_tag->name = tag_name;
                new_tag->content = "";
                new_tag->attributes = NULL;
                new_tag->children = NULL;
                new_tag->next = NULL;
                if (!root) {
                    root = new_tag;
                } else {
                    add_child(new_tag);
                }
                current_tag = new_tag;
                while (xml[j] != '>') {
                    if (xml[j] == ' ') {
                        // New attribute
                        int k = j + 1;
                        while (xml[k] != '=') k++;
                        char* attr_name = strndup(xml + j + 1, k - j - 1);
                        k += 2;
                        int l = k;
                        while (xml[l] != '"') l++;
                        char* attr_value = strndup(xml + k, l - k);
                        add_attribute(attr_name, attr_value);
                        j = l + 1;
                    } else {
                        j++;
                    }
                }
                i = j + 1;
            } else {
                // Closing tag
                int j = i + 1;
                while (xml[j] != '>') j++;
                char* tag_name = strndup(xml + i + 1, j - i - 1);
                if (strcmp(tag_name, current_tag->name) != 0) {
                    printf("Error: Invalid XML\n");
                    return;
                }
                current_tag = current_tag->next;
                i = j + 1;
            }
        } else {
            // Text content
            int j = i + 1;
            while (xml[j] != '<') j++;
            current_tag->content = strndup(xml + i, j - i);
            i = j;
        }
    }
}

int main() {
    // Sample XML content
    char* xml = "<note importance=\"high\">\n"
                "  <to>Jane</to>\n"
                "  <from>John</from>\n"
                "  <heading>Reminder</heading>\n"
                "  <body>Don't forget the meeting!</body>\n"
                "</note>";
    // Parse XML content
    parse_xml(xml);
    // Print parsed XML tree
    printf("<%s", root->name);
    attr* a = root->attributes;
    while (a) {
        printf(" %s=\"%s\"", a->name, a->value);
        a = a->next;
    }
    printf(">\n");
    tag* child = root->children;
    while (child) {
        printf("  ");
        printf("<%s", child->name);
        attr* a = child->attributes;
        while (a) {
            printf(" %s=\"%s\"", a->name, a->value);
            a = a->next;
        }
        printf(">");
        if (strlen(child->content) > 0) printf("%s", child->content);
        printf("</%s>\n", child->name);
        child = child->next;
    }
    printf("</%s>\n", root->name);
    return 0;
}