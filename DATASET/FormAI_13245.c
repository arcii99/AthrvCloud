//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Defining the struct for each XML tag/element
typedef struct xml_element {
    char name[50];
    char value[100];
    struct xml_element *first_child;
    struct xml_element *next_sibling;
} xml_element;

// A recursive function to parse through the XML input and create a tree of xml_elements
xml_element* parse_xml(char* xml_input) {
    // Initializing variables
    xml_element *root = NULL;
    xml_element *current_element = NULL;
    xml_element *prev_sibling = NULL;
    bool inside_tag = false;
    bool inside_value = false;
    char tag_name[50] = { 0 };
    char value[100] = { 0 };

    // Looping through each character in the XML input string
    for (int i = 0; i < strlen(xml_input); i++) {
        // If we encounter an opening tag character '<', set inside_tag true
        if (xml_input[i] == '<') {
            inside_tag = true;
            continue;
        }
        // If we encounter a closing tag character '>', set inside_tag false and inside_value true
        else if (xml_input[i] == '>') {
            inside_tag = false;
            inside_value = true;
            // If this is a closing tag, set prev_sibling to current_element
            if (tag_name[0] == '/') {
                prev_sibling = current_element;
                current_element = current_element->first_child;
            }
            // Else this is an opening tag, so create a new xml_element and set current_element as its child
            else {
                xml_element *new_element = malloc(sizeof(xml_element));
                strcpy(new_element->name, tag_name);
                // If this is the root element, store it in root
                if (root == NULL) {
                    root = new_element;
                    current_element = root;
                }
                // Else set current_element's first child as this new_element
                else {
                    current_element->first_child = new_element;
                    current_element = new_element;
                }
            }
            // Reset tag_name and value for the next element
            memset(tag_name, 0, sizeof(tag_name));
            memset(value, 0, sizeof(value));
            continue;
        }
        // If we are inside a tag, append the character to tag_name
        else if (inside_tag) {
            strncat(tag_name, &xml_input[i], 1);
        }
        // If we are inside a value, append the character to value
        else if (inside_value) {
            strncat(value, &xml_input[i], 1);
            // If we encounter a closing tag character '<', store the value in current_element and set inside_value false
            if (i < strlen(xml_input) - 1 && xml_input[i + 1] == '<') {
                strcpy(current_element->value, value);
                inside_value = false;
            }
        }
        // If we encounter a closing tag '/', set current_element as its parent's next sibling
        else if (xml_input[i] == '/') {
            current_element = prev_sibling->next_sibling;
        }
    }
    return root;
}

// A function to print the xml_element tree in a formatted manner
void print_xml(xml_element *root, int depth) {
    // If the input root is NULL, return
    if (root == NULL) {
        return;
    }
    // Print the current element's name and value, with appropriate indentation
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("<%s>%s\n", root->name, root->value);
    // Recursively print the children of this element
    print_xml(root->first_child, depth + 1);
    // If there are any siblings, recursively print them as well
    if (root->next_sibling != NULL) {
        print_xml(root->next_sibling, depth);
    }
    // Print the closing tag with appropriate indentation
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("</%s>\n", root->name);
}

// Example usage
int main() {
    char xml_input[] = "<bookstore><book><title>Harry Potter</title><author>J.K. Rowling</author><year>2005</year></book><book><title>The Hobbit</title><author>J.R.R. Tolkien</author><year>1937</year></book></bookstore>";

    xml_element *root = parse_xml(xml_input);
    print_xml(root, 0);

    return 0;
}