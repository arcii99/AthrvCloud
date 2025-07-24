//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define maximum string length
#define MAX_STRING_LENGTH 100

// define the structure for the xml tag
typedef struct xml_tag {
    char* tag_name;                 // tag name
    char* attribute_name;           // attribute name
    char* attribute_value;          // attribute value
    struct xml_tag* child_tag;      // child tag
    struct xml_tag* sibling_tag;    // sibling tag
} xml_tag;

// define function to create a new xml tag
xml_tag* create_xml_tag(char* tag_name, char* attribute_name, char* attribute_value) {
    // allocate memory for the tag
    xml_tag* tag = (xml_tag*)malloc(sizeof(xml_tag));
    
    // assign tag name
    tag->tag_name = (char*)malloc(sizeof(char) * strlen(tag_name) + 1);
    strcpy(tag->tag_name, tag_name);

    // assign attribute name
    tag->attribute_name = (char*)malloc(sizeof(char) * strlen(attribute_name) + 1);
    strcpy(tag->attribute_name, attribute_name);

    // assign attribute value
    tag->attribute_value = (char*)malloc(sizeof(char) * strlen(attribute_value) + 1);
    strcpy(tag->attribute_value, attribute_value);

    // assign child tag and sibling tag to NULL
    tag->child_tag = NULL;
    tag->sibling_tag = NULL;

    // return the tag
    return tag;
}

// define function to add a child tag to an existing parent tag
xml_tag* add_child_tag(xml_tag* parent, xml_tag* child) {
    // check if parent already has a child
    if (parent->child_tag == NULL) {
        parent->child_tag = child;
    }
    // if parent already has a child, add the new child as a sibling tag of the existing child
    else {
        xml_tag* sibling = parent->child_tag;
        while (sibling->sibling_tag != NULL) {
            sibling = sibling->sibling_tag;
        }
        sibling->sibling_tag = child;
    }
    // return the updated parent tag
    return parent;
}

// define function to parse an xml string and create an xml tag hierarchy
xml_tag* parse_xml(char* xml_string) {
    xml_tag* root = NULL;
    xml_tag* parent = NULL;
    xml_tag* child = NULL;

    // iterate over the xml string character by character
    int i = 0;
    while (i < strlen(xml_string)) {
        // check if current character is the start of a tag
        if (xml_string[i] == '<') {
            // check if current tag is a closing tag
            if (xml_string[i+1] == '/') {
                // move to the tag name
                i += 2;
                // read the tag name
                char tag_name[MAX_STRING_LENGTH];
                int j = 0;
                while (xml_string[i] != '>') {
                    tag_name[j++] = xml_string[i++];
                }
                tag_name[j] = '\0';

                // check if parent exists
                if (parent != NULL) {
                    // set the parent to be the parent's sibling
                    parent = parent->sibling_tag;
                }
            }
            // if the current tag is not a closing tag, it must be an opening tag
            else {
                // move to the tag name
                i++;
                // read the tag name
                char tag_name[MAX_STRING_LENGTH];
                int j = 0;
                while (xml_string[i] != ' ' && xml_string[i] != '>') {
                    tag_name[j++] = xml_string[i++];
                }
                tag_name[j] = '\0';
                
                // create a new tag with the tag name
                xml_tag* tag = create_xml_tag(tag_name, "", "");
                
                // if this is the first tag, set it as the root
                if (root == NULL) {
                    root = tag;
                }
                
                // add the tag as a child of the parent if it exists, otherwise set it as the parent
                if (parent != NULL) {
                    add_child_tag(parent, tag);
                } else {
                    parent = tag;
                }

                // read any attributes the tag might have
                while (xml_string[i] != '>') {
                    char attribute_name[MAX_STRING_LENGTH];
                    char attribute_value[MAX_STRING_LENGTH];
                    int k = 0;
                    while (xml_string[i] != '=') {
                        attribute_name[k++] = xml_string[i++];
                    }
                    attribute_name[k] = '\0';

                    i++; // move past the '='

                    int delim = xml_string[i++]; // get the delimiter (either ' or ")
                    int l = 0;
                    while (xml_string[i] != delim) {
                        attribute_value[l++] = xml_string[i++];
                    }
                    attribute_value[l] = '\0';

                    // set the attribute for the current tag
                    tag->attribute_name = (char*)malloc(sizeof(char) * strlen(attribute_name) + 1);
                    strcpy(tag->attribute_name, attribute_name);
                    
                    tag->attribute_value = (char*)malloc(sizeof(char) * strlen(attribute_value) + 1);
                    strcpy(tag->attribute_value, attribute_value);
                }
            }
        }
        i++;
    }
    return root;
}

// define function to free all memory associated with an xml tag hierarchy
void free_xml_tags(xml_tag* tag) {
    if (tag == NULL) {
        return;
    }
    // free all child tags
    if (tag->child_tag != NULL) {
        free_xml_tags(tag->child_tag);
    }
    // free all sibling tags
    if (tag->sibling_tag != NULL) {
        free_xml_tags(tag->sibling_tag);
    }
    // free tag name, attribute name, attribute value and tag itself
    free(tag->tag_name);
    free(tag->attribute_name);
    free(tag->attribute_value);
    free(tag);
}

int main() {
    // define an example xml string
    char xml_string[MAX_STRING_LENGTH] = "<books><book title=\"The Catcher in the Rye\" author=\"J.D. Salinger\" /><book title=\"To Kill a Mockingbird\" author=\"Harper Lee\" /></books>";

    // parse the xml string and create an xml tag hierarchy
    xml_tag* root = parse_xml(xml_string);

    // print out the tag hierarchy
    printf("%s", root->tag_name);
    xml_tag* child = root->child_tag;
    while (child != NULL) {
        printf("\n");
        printf("%s", child->tag_name);
        printf("\n%s: %s", child->attribute_name, child->attribute_value);
        child = child->sibling_tag;
    }

    // free the memory associated with the tag hierarchy
    free_xml_tags(root);

    return 0;
}