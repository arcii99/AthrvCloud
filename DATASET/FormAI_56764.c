//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TAG_LENGTH 50
#define MAX_ATTRIBUTE_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct {
    char tag[MAX_TAG_LENGTH+1];
    char attributes[MAX_ATTRIBUTE_LENGTH+1][MAX_VALUE_LENGTH+1];
    int num_attributes;
} XMLNode;

typedef struct {
    XMLNode node;
    int index;
} XMLStackItem;

void parse_xml(const char* xml_str);

void push_stack(XMLStackItem* stack, XMLNode node, int* stack_ptr);

XMLNode pop_stack(XMLStackItem* stack, int* stack_ptr);

int main() {
    const char* xml_str = "<example attr1=\"value1\"><child>text</child></example>";
    parse_xml(xml_str);
    return 0;
}

void parse_xml(const char* xml_str) {
    int i = 0;
    char c;
    char tag[MAX_TAG_LENGTH+1];
    char value[MAX_VALUE_LENGTH+1];
    int tag_ptr = 0, value_ptr = 0;
    XMLStackItem stack[100];
    int stack_ptr = 0;

    while((c = xml_str[i++])) {
        if(tag_ptr == 0 && c == '<') {
            continue;
        } else if(tag_ptr == 0 && c == '/') {
            pop_stack(stack, &stack_ptr);
            continue;
        } else if(tag_ptr == 0 && c == '>') {
            XMLNode node;
            memcpy(node.tag, tag, tag_ptr);
            node.tag[tag_ptr] = 0;
            node.num_attributes = (stack_ptr == 0) ? 0 : stack[stack_ptr-1].node.num_attributes;
            push_stack(stack, node, &stack_ptr);
            tag_ptr = 0;
        } else if(tag_ptr == 0 && !isspace(c)) {
            tag[tag_ptr++] = c;
        } else if(tag_ptr > 0 && !isspace(c)) {
            if(tag_ptr <= MAX_TAG_LENGTH) {
                tag[tag_ptr++] = c;
            }
        } else if(tag_ptr > 0 && isspace(c)) {
            tag[tag_ptr++] = 0;
            while((c = xml_str[i++])) {
                if(value_ptr == 0 && isspace(c)) {
                    continue;
                } else if((value_ptr == 0 || value[0] == '\"') && c == '\"') {
                    value[value_ptr++] = 0;
                    memcpy(stack[stack_ptr-1].node.attributes[stack[stack_ptr-1].node.num_attributes++], value, value_ptr);
                    value_ptr = 0;
                    break;
                } else if(value_ptr <= MAX_VALUE_LENGTH) {
                    value[value_ptr++] = c;
                }
            }
        }
    }
}

void push_stack(XMLStackItem* stack, XMLNode node, int* stack_ptr) {
    stack[*stack_ptr].node = node;
    stack[*stack_ptr].index = 0;
    (*stack_ptr)++;
}

XMLNode pop_stack(XMLStackItem* stack, int* stack_ptr) {
    (*stack_ptr)--;
    return stack[*stack_ptr].node;
}