//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: standalone
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <stdbool.h>  
#include <ctype.h>  

#define MAX_TAG_NAME_LENGTH 64  
#define MAX_ATTRIBUTE_NAME_LENGTH 64  
#define MAX_ATTRIBUTE_VALUE_LENGTH 256  
#define MAX_TEXT_LENGTH 1024  
#define MAX_STACK_SIZE 32  

typedef struct Node Node;
struct Node {
    char tag_name[MAX_TAG_NAME_LENGTH];
    char* attribute_name[MAX_ATTRIBUTE_NAME_LENGTH];
    char* attribute_value[MAX_ATTRIBUTE_VALUE_LENGTH];
    char text[MAX_TEXT_LENGTH];
    Node* children[MAX_STACK_SIZE];
    int num_children;
};

Node* current_node;  
Node* root_node;  
Node* stack[MAX_STACK_SIZE];  
int stack_pos = 0;  

bool is_whitespace(char c) {  
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');  
} 

void push(Node* node) {
    stack[stack_pos] = node;
    stack_pos++;
}

bool parse_attribute(char* start, char* end) {  
    char* equal_pos = strchr(start, '=');  
    if (!equal_pos) {  
        return false;  
    }  
    char* attr_name_end = equal_pos - 1;  
    char attribute_name[MAX_ATTRIBUTE_NAME_LENGTH];  
    int attribute_name_len = 0;  
    for (char* c = start; c <= attr_name_end; c++) {  
        attribute_name[attribute_name_len] = *c;  
        attribute_name_len++;  
    }  
    attribute_name[attribute_name_len] = '\0';  
    char* attr_value_start = equal_pos + 1;  
    char* attr_value_end = end - 1;  
    char attribute_value[MAX_ATTRIBUTE_VALUE_LENGTH];  
    int attribute_value_len = 0;  
    for (char* c = attr_value_start; c <= attr_value_end; c++) {  
        attribute_value[attribute_value_len] = *c;  
        attribute_value_len++;  
    }  
    attribute_value[attribute_value_len] = '\0';  
    char* new_attr_name = (char*)malloc(strlen(attribute_name) + 1);  
    strcpy(new_attr_name, attribute_name);  
    char* new_attr_value = (char*)malloc(strlen(attribute_value) + 1);  
    strcpy(new_attr_value, attribute_value);  
    current_node->attribute_name[current_node->num_children] = new_attr_name;  
    current_node->attribute_value[current_node->num_children] = new_attr_value;  
    current_node->num_children++;  
    return true;  
}  

bool parse_tag(char* start, char* end) {  
    bool is_closing_tag = false;  
    if (*start == '/') {  
        is_closing_tag = true;  
        start++;  
    }  
    char* tag_name_end = end - 1;  
    char tag_name[MAX_TAG_NAME_LENGTH];  
    int tag_name_len = 0;  
    for (char* c = start; c <= tag_name_end; c++) {  
        tag_name[tag_name_len] = *c;  
        tag_name_len++;  
    }  
    tag_name[tag_name_len] = '\0';  
    if (!is_closing_tag) {  
        Node* new_node = (Node*)malloc(sizeof(Node));  
        strcpy(new_node->tag_name, tag_name);  
        current_node->children[current_node->num_children] = new_node;  
        current_node->num_children++;  
        push(new_node);  
        current_node = new_node;  
    } else {  
        if (strcmp(current_node->tag_name, tag_name) != 0) {  
            return false;  
        }  
        stack_pos--;  
        current_node = stack[stack_pos - 1];  
    }  
    return true;  
}  

bool parse_text(char* start, char* end) {  
    char text[MAX_TEXT_LENGTH];  
    int text_len = 0;  
    for (char* c = start; c <= end; c++) {  
        text[text_len] = *c;  
        text_len++;  
    }  
    text[text_len] = '\0';  
    strcpy(current_node->text, text);  
    return true;  
}  

bool parse_element(char* start, char* end) {  
    bool is_tag = false;  
    bool is_text = false;  
    for (char* c = start; c <= end; c++) {  
        if (*c == '<') {  
            is_tag = true;  
            break;  
        } else if (!is_whitespace(*c)) {  
            is_text = true;  
            break;  
        }  
    }  
    if (is_tag) {  
        int len = end - start;  
        char str[len - 1];  
        int pos = 0;  
        for (char* c = start; c <= end; c++) {  
            if (*c == '>') {  
                if (!parse_tag(start + 1, c)) {  
                    return false;  
                }  
                is_tag = false;  
                start = c + 1;  
            } else if (*c == ' ') {  
                if (!parse_attribute(start + 1, c)) {  
                    return false;  
                }  
                start = c;  
            }  
        }  
        if (is_tag) {  
            if (!parse_tag(start + 1, end)) {  
                return false;  
            }  
        }  
    }  
    if (is_text) {  
        if (!parse_text(start, end)) {  
            return false;  
        }  
    }  
    return true;  
}  

bool parse_xml(char* xml, int len) {  
    int pos = 0;  
    while (pos < len) {  
        char c = xml[pos];  
        if (c == '<') {  
            int end_pos = pos + 1;  
            while (end_pos < len) {  
                if (xml[end_pos] == '>') {  
                    if (!parse_element(xml + pos, xml + end_pos)) {  
                        return false;  
                    }  
                    pos = end_pos + 1;  
                    break;  
                }  
                end_pos++;  
            }  
        } else {  
            pos++;  
        }  
    }  
    return true;  
}  

void print_node(Node* node, int indent) {  
    for (int i = 0; i < indent; i++) {  
        printf("  ");  
    }  
    printf("<%s", node->tag_name);  
    for (int i = 0; i < node->num_children; i++) {  
        printf(" %s=\"%s\"", node->attribute_name[i], node->attribute_value[i]);  
    }  
    printf(">\n");  
    if (strlen(node->text) > 0) {  
        for (int i = 0; i < indent + 1; i++) {  
            printf("  ");  
        }  
        printf("%s\n", node->text);  
    }  
    for (int i = 0; i < node->num_children; i++) {  
        print_node(node->children[i], indent + 1);  
    }  
    for (int i = 0; i < indent; i++) {  
        printf("  ");  
    }  
    printf("</%s>\n", node->tag_name);  
}  

int main() {  
    char xml[] = "<library>\n"
                "  <book id=\"bk101\">\n"
                "    <author>Gambardella, Matthew</author>\n"
                "    <title>XML Developer's Guide</title>\n"
                "    <genre>Computer</genre>\n"
                "    <price>44.95</price>\n"
                "    <publish_date>2000-10-01</publish_date>\n"
                "    <description>An in-depth look at creating applications \n"
                "      with XML.</description>\n"
                "  </book>\n"
                "  <book id=\"bk102\">\n"
                "    <author>Ralls, Kim</author>\n"
                "    <title>Midnight Rain</title>\n"
                "    <genre>Fantasy</genre>\n"
                "    <price>5.95</price>\n"
                "    <publish_date>2000-12-16</publish_date>\n"
                "    <description>A former architect battles corporate zombies, \n"
                "      an evil sorceress, and her own childhood to become queen \n"
                "      of the world.</description>\n"
                "  </book>\n"
                "</library>\n";  
    int len = strlen(xml);  
  
    root_node = (Node*)malloc(sizeof(Node));  
    strcpy(root_node->tag_name, "root");  
    current_node = root_node;  
    push(root_node);  

    if (!parse_xml(xml, len)) {  
        printf("Failed to parse XML!\n");  
        return 1;  
    }  

    print_node(root_node, 0);  
    
    return 0;  
}