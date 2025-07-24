//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store XML elements
typedef struct xml_element {
    char *tag_name;
    char *text;
    struct xml_element *next_sibling;
    struct xml_element *first_child;
} xml_element;

// Function to parse an XML string and return the root element
xml_element* parse_xml(char* xml) {
    xml_element *root = NULL;
    xml_element *current = NULL;
    char *tag_name = NULL;
    char *text = NULL;
    int i = 0;
    int tag_start = 0;
    int tag_end = 0;
    int text_start = 0;
    int text_end = 0;
    int closing_tag = 0;
    int in_tag = 0;
    int in_text = 0;
    int in_quote = 0;
    int quote_char = 0;
    
    // Loop through each character in the XML string
    while (xml[i] != '\0') {
        // Check if we're inside a tag
        if (in_tag) {
            // Check if we're inside a quoted attribute value
            if (in_quote) {
                if (xml[i] == quote_char) {
                    in_quote = 0;
                }
            }
            // Otherwise, check for tag end
            else {
                if (xml[i] == '>') {
                    in_tag = 0;
                    closing_tag = (xml[tag_start+1] == '/');
                    // Check if this is a closing tag
                    if (closing_tag) {
                        if (current != NULL && 
                            strncmp(current->tag_name, &xml[tag_start+2], tag_end-tag_start-2) == 0) {
                            current = current->next_sibling;
                        }
                        tag_name = NULL;
                    }
                    // Otherwise, create a new element
                    else {
                        // Allocate memory for the new element
                        xml_element *new_elem = (xml_element*) malloc(sizeof(xml_element));
                        new_elem->tag_name = (char*) malloc(sizeof(char) * (tag_end-tag_start-1));
                        new_elem->text = NULL;
                        new_elem->next_sibling = NULL;
                        new_elem->first_child = NULL;
                        // Copy the tag name
                        strncpy(new_elem->tag_name, &xml[tag_start+1], tag_end-tag_start-1);
                        new_elem->tag_name[tag_end-tag_start-1] = '\0';
                        // Check if there is any text following the tag
                        if (text_start < text_end) {
                            new_elem->text = (char*) malloc(sizeof(char) * (text_end-text_start+1));
                            strncpy(new_elem->text, &xml[text_start], text_end-text_start+1);
                            new_elem->text[text_end-text_start] = '\0';
                        }
                        // Add the new element to the tree
                        if (root == NULL) {
                            root = new_elem;
                            current = root;
                        }
                        else {
                            current->next_sibling = new_elem;
                            current = new_elem;
                        }
                    }
                }
                // Otherwise, check for attribute start
                else if (xml[i] == ' ') {
                    if (tag_name != NULL && tag_name[0] != '\0') {
                        char *attr_name = (char*) malloc(sizeof(char) * (i-tag_end-1));
                        char *attr_value = NULL;
                        int attr_value_start = 0;
                        int attr_value_end = 0;
                        strncpy(attr_name, &xml[tag_end+1], i-tag_end-1);
                        attr_name[i-tag_end-1] = '\0';
                        while (xml[i+1] == ' ' || xml[i+1] == '\t') {
                            i++;
                        }
                        i++;
                        // Check for quoted attribute value
                        if (xml[i] == '"' || xml[i] == '\'') {
                            in_quote = 1;
                            quote_char = xml[i];
                            attr_value_start = i+1;
                            while (xml[i+1] != '\0' && xml[i+1] != quote_char) {
                                i++;
                            }
                            attr_value_end = i;
                        }
                        // Otherwise, look for next whitespace or closing tag
                        else {
                            attr_value_start = i;
                            while (xml[i+1] != '\0' && xml[i+1] != ' ' && xml[i+1] != '\t' && xml[i+1] != '>') {
                                i++;
                            }
                            attr_value_end = i;
                        }
                        if (attr_value_start < attr_value_end) {
                            attr_value = (char*) malloc(sizeof(char) * (attr_value_end-attr_value_start+1));
                            strncpy(attr_value, &xml[attr_value_start], attr_value_end-attr_value_start+1);
                            attr_value[attr_value_end-attr_value_start] = '\0';
                        }
                        if (attr_name[0] != '\0') {
                            free(attr_name);
                        }
                        if (attr_value != NULL) {
                            free(attr_value);
                        }
                    }
                }
                // Otherwise, set text end to beginning of tag
                else {
                    text_end = i-1;
                }
            }
        }
        // Otherwise, check if we're inside a text node
        else if (in_text) {
            // Check for text end
            if (xml[i] == '<') {
                in_text = 0;
                text_end = i-1;
                // Check if there is any text before the tag
                if (text_start < text_end) {
                    current->text = (char*) malloc(sizeof(char) * (text_end-text_start+1));
                    strncpy(current->text, &xml[text_start], text_end-text_start+1);
                    current->text[text_end-text_start] = '\0';
                }
                text_start = 0;
            }
        }
        // Otherwise, check for tag start
        else {
            if (xml[i] == '<') {
                in_tag = 1;
                tag_start = i;
                text_end = i-1;
            }
            // Otherwise, check for text start
            else if (xml[i] != ' ' && xml[i] != '\t' && xml[i] != '\r' && xml[i] != '\n') {
                in_text = 1;
                text_start = i;
            }
        }
        i++;
    }
    
    return root;
}

// Function to free memory allocated for an XML element tree
void free_xml(xml_element *root) {
    if (root != NULL) {
        free_xml(root->first_child);
        free_xml(root->next_sibling);
        if (root->tag_name != NULL) {
            free(root->tag_name);
        }
        if (root->text != NULL) {
            free(root->text);
        }
        free(root);
    }
}

// Main function
int main(int argc, char* argv[]) {
    char *xml = "<root><a b=\"c\">Text</a><b>More text</b><c/></root>";
    xml_element *root = parse_xml(xml);
    // Print out the XML element tree
    xml_element *current = root;
    while (current != NULL) {
        printf("Tag name: %s\n", current->tag_name);
        if (current->text != NULL) {
            printf("Text: %s\n", current->text);
        }
        if (current->first_child != NULL) {
            printf("Children:\n");
            xml_element *child = current->first_child;
            while (child != NULL) {
                printf("  %s\n", child->tag_name);
                child = child->next_sibling;
            }
        }
        printf("\n");
        current = current->next_sibling;
    }
    // Clean up memory
    free_xml(root);
    return 0;
}