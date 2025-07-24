//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a linked list data structure for storing the parsed XML tags and their attributes */
typedef struct XMLTag {
    char* name;
    char* value;
    struct XMLAttribute* attributes;
    struct XMLTag* next;
} XMLTag;

typedef struct XMLAttribute {
    char* name;
    char* value;
    struct XMLAttribute* next;
} XMLAttribute;

/* Define a helper function for creating and initializing a new XML tag */
XMLTag* new_XMLTag(char* name, char* value) {
    XMLTag* tag = (XMLTag*)malloc(sizeof(XMLTag));
    tag->name = name;
    tag->value = value;
    tag->next = NULL;
    tag->attributes = NULL;
    return tag;
}

/* Define a helper function for creating and initializing a new XML attribute */
XMLAttribute* new_XMLAttribute(char* name, char* value) {
    XMLAttribute* attribute = (XMLAttribute*)malloc(sizeof(XMLAttribute));
    attribute->name = name;
    attribute->value = value;
    attribute->next = NULL;
    return attribute;
}

/* Define a helper function for appending an attribute to an XML tag's list of attributes */
void add_attribute(XMLTag* tag, char* name, char* value) {
    if (tag == NULL) {
        return;
    }
    if (tag->attributes == NULL) {
        tag->attributes = new_XMLAttribute(name, value);
        return;
    }
    XMLAttribute* attribute = tag->attributes;
    while (attribute->next != NULL) {
        attribute = attribute->next;
    }
    attribute->next = new_XMLAttribute(name, value);
}

/* Define a function for parsing an input string as an XML document */
XMLTag* parse_XML(char* input) {
    XMLTag* root = NULL;
    XMLTag* current_tag = NULL;
    int tag_start = -1; // The starting index of the current tag's name
    int tag_end = -1;   // The ending index of the current tag's name
    int value_start = -1; // The starting index of the current tag's value
    int value_end = -1;   // The ending index of the current tag's value
    int i = 0;
    while (i < strlen(input)) {
        if (input[i] == '<') {
            if (input[i+1] == '/') {
                // This is a closing tag
                tag_end = i;
                i++;
                while (input[i] != '>') {
                    i++; // Skip to end of tag
                }
                value_start = tag_end+2;
                value_end = i;
                char* value = (char*)malloc((value_end-value_start+1)*sizeof(char));
                strncpy(value, input+value_start, value_end-value_start);
                value[value_end-value_start] = '\0';
                if (current_tag != NULL && strcmp(value, current_tag->name) == 0) {
                    current_tag = current_tag->next;
                }
            } else {
                // This is an opening tag
                tag_start = i+1;
                tag_end = i+1;
                while (input[tag_end] != ' ' && input[tag_end] != '>') {
                    tag_end++; // Find the end of the tag name
                }
                char* tag_name = (char*)malloc((tag_end-tag_start+1)*sizeof(char));
                strncpy(tag_name, input+tag_start, tag_end-tag_start);
                tag_name[tag_end-tag_start] = '\0';
                XMLTag* tag = new_XMLTag(tag_name, "");
                if (root == NULL) {
                    root = tag;
                    current_tag = root;
                } else {
                    current_tag->next = tag;
                    current_tag = tag;
                }
                if (input[tag_end] == '>') {
                    continue; // No attributes or value for this tag, skip to next iteration
                }
                // Parse any attributes for this tag
                while (input[tag_end] != '>') {
                    tag_start = tag_end+1;
                    tag_end = tag_start;
                    while (input[tag_end] != ' ' && input[tag_end] != '=') {
                        tag_end++;
                    }
                    char* attr_name = (char*)malloc((tag_end-tag_start+1)*sizeof(char));
                    strncpy(attr_name, input+tag_start, tag_end-tag_start);
                    attr_name[tag_end-tag_start] = '\0';
                    tag_start = tag_end+2;
                    tag_end += 2;
                    while (input[tag_end] != '"' && input[tag_end] != '\'') {
                        tag_end++;
                    }
                    char quote_type = input[tag_end];
                    tag_end++;
                    tag_start = tag_end;
                    while (input[tag_end] != quote_type) {
                        tag_end++;
                    }
                    char* attr_value = (char*)malloc((tag_end-tag_start+1)*sizeof(char));
                    strncpy(attr_value, input+tag_start, tag_end-tag_start);
                    attr_value[tag_end-tag_start] = '\0';
                    add_attribute(current_tag, attr_name, attr_value);
                    free(attr_name);
                    free(attr_value);
                }
            }
        } else if (current_tag != NULL && input[i] != '\n' && input[i] != '\t') {
            if (current_tag->value[0] != '\0') {
                strcat(current_tag->value, " ");
            }
            char* word = (char*)malloc(sizeof(char)*2);
            word[0] = input[i];
            word[1] = '\0';
            strcat(current_tag->value, word);
            free(word);
        }
        i++;
    }
    return root;
}

/* Define a helper function for recursively printing an XML tag and all of its attributes and subtags */
void print_XMLTag_rec(XMLTag* tag, int depth) {
    if (tag == NULL) {
        return;
    }
    for (int i = 0; i < depth; i++) {
        printf("\t");
    }
    printf("<%s", tag->name);
    XMLAttribute* attribute = tag->attributes;
    while (attribute != NULL) {
        printf(" %s=\"%s\"", attribute->name, attribute->value);
        attribute = attribute->next;
    }
    if (strlen(tag->value) == 0 && tag->next == NULL) {
        printf("/>\n");
    } else {
        printf(">");
        if (strlen(tag->value) > 0) {
            printf("%s", tag->value);
        }
        printf("\n");
        XMLTag* subtag = tag->next;
        while (subtag != NULL) {
            print_XMLTag_rec(subtag, depth+1);
            subtag = subtag->next;
        }
        for (int i = 0; i < depth; i++) {
            printf("\t");
        }
        printf("</%s>\n", tag->name);
    }
}

/* Define a function for printing an XML document */
void print_XML(XMLTag* root) {
    printf("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
    XMLTag* tag = root;
    while (tag != NULL) {
        print_XMLTag_rec(tag, 0);
        tag = tag->next;
    }
}

/* Example usage */
int main() {
    char* input = "<root>\n\t<subtag id=\"1\"/>\n\t<subtag id=\"2\"/>This is some text.\n</root>\n";
    XMLTag* root = parse_XML(input);
    print_XML(root);
    return 0;
}