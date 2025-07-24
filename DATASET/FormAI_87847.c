//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* XML Parser Example Program */

struct xml_elem {
    struct xml_elem *parent;
    struct xml_elem *child;
    struct xml_elem *sibling;
    char *name;
    char *value;
};

typedef struct xml_elem xml_elem;

xml_elem *parse_xml(char *xml_string);
void print_xml(xml_elem *elem);

/* Main function */

int main(void) {
    char *xml_string = "<root><person><name>John Doe</name><age>30</age></person></root>";
    xml_elem *root = parse_xml(xml_string);
    print_xml(root);
    return 0;
}

/* Parse XML string */

xml_elem *parse_xml(char *xml_string) {
    // TODO: Implement XML parser here
}

/* Print XML tree */

void print_xml(xml_elem *elem) {
    if (elem == NULL) {
        return;
    }
    printf("<%s>%s</%s>\n", elem->name, elem->value, elem->name);
    print_xml(elem->child);
    print_xml(elem->sibling);
}