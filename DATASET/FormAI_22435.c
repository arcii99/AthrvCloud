//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold XML element data
typedef struct xml_element_t {
    char *name;
    char *value;
    struct xml_element_t *parent;
    struct xml_element_t *children;
    struct xml_element_t *next_sibling;
} xml_element;

// Stack structure for tracking parent elements while parsing
typedef struct xml_stack_t {
    xml_element *element;
    struct xml_stack_t *next;
} xml_stack;

// Function to create a new XML element
xml_element* create_element(char *name) {
    xml_element *element = malloc(sizeof(xml_element));
    element->name = strdup(name);
    element->value = NULL;
    element->parent = NULL;
    element->children = NULL;
    element->next_sibling = NULL;
    return element;
}

// Function to add a child element to a parent element
void add_child(xml_element *parent, xml_element *child) {
    child->parent = parent;
    child->next_sibling = parent->children;
    parent->children = child;
}

// Function to push an element onto the stack
void push(xml_stack **stack, xml_element *element) {
    xml_stack *new_element = malloc(sizeof(xml_stack));
    new_element->element = element;
    new_element->next = *stack;
    *stack = new_element;
}

// Function to pop an element off the stack
xml_element* pop(xml_stack **stack) {
    xml_element *element = (*stack)->element;
    xml_stack *next = (*stack)->next;
    free(*stack);
    *stack = next;
    return element;
}

// Function to parse an XML string into a hierarchy of elements
xml_element* parse_xml(char *xml) {
    xml_element *root_element = NULL;
    xml_stack *stack = NULL;
    char *token = strtok(xml, "<>");

    while (token) {
        if (token[0] == '/') {
            // End element tag
            xml_element *end_element = pop(&stack);

            if (strcmp(end_element->name, token + 1) != 0) {
                fprintf(stderr, "Error: unexpected end tag '%s'\n", token);
                exit(1);
            }
        } else if (token[0] != '?' && token[0] != '!') {
            // Start element tag
            xml_element *element = create_element(token);
            if (!root_element) {
                root_element = element;
            }

            if (stack) {
                add_child(stack->element, element);
            }

            push(&stack, element);
        }

        token = strtok(NULL, "<>");
    }

    if (stack) {
        fprintf(stderr, "Error: unclosed element '%s'\n", stack->element->name);
        exit(1);
    }

    return root_element;
}

// Function to print an XML tree for debugging purposes
void print_xml(xml_element *element, int indent) {
    for (int i = 0; i < indent; i++) {
        printf(" ");
    }

    printf("<%s", element->name);

    if (element->value) {
        printf(">%s", element->value);
    } else if (element->children) {
        printf(">\n");
        xml_element *child = element->children;
        while (child) {
            print_xml(child, indent + 4);
            child = child->next_sibling;
        }
        for (int i = 0; i < indent; i++) {
            printf(" ");
        }
    } else {
        printf("/>\n");
    }
}

int main() {
    char xml[] = "<root><parent><child1>value1</child1><child2>value2</child2></parent></root>";
    xml_element *root_element = parse_xml(xml);
    print_xml(root_element, 0);
    return 0;
}