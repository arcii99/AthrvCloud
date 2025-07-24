//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LENGTH 16
#define MAX_ATTRIBUTE_LENGTH 32
#define MAX_ATTRIBUTE_VALUE_LENGTH 256
#define MAX_TAG_STACK_DEPTH 64

typedef struct Attribute {
    char key[MAX_ATTRIBUTE_LENGTH];
    char value[MAX_ATTRIBUTE_VALUE_LENGTH];
} Attribute;

typedef struct Tag {
    char name[MAX_TAG_LENGTH];
    Attribute attributes[MAX_ATTRIBUTE_LENGTH];
    int attribute_count;
} Tag;

typedef struct ParserContext {
    char* xml_string;
    int xml_string_length;
    Tag tag_stack[MAX_TAG_STACK_DEPTH];
    int tag_stack_top;
} ParserContext;

int parse_xml(ParserContext* context);

void parse_tag(ParserContext* context, char* start);
void parse_attribute(ParserContext* context, char* start, char* end);

int main() {
    // Sample XML string
    char* xml_string = "<bookstore> \
                        <book category='cooking'> \
                            <title lang='en'>Everyday Italian</title> \
                            <author>Giada De Laurentiis</author> \
                            <year>2005</year> \
                            <price>30.00</price> \
                        </book> \
                        <book category='children'> \
                            <title lang='en'>Harry Potter</title> \
                            <author>J.K. Rowling</author> \
                            <year>2005</year> \
                            <price>29.99</price> \
                        </book> \
                    </bookstore>";
    ParserContext context = { .xml_string = xml_string, .xml_string_length = strlen(xml_string), .tag_stack_top = -1 };
    
    int result = parse_xml(&context);
    if(result == 0) {
        printf("XML Parsing completed successfully!\n");
    }
    else {
        printf("XML Parsing error occurred!\n");
    }
    
    return 0;
}

int parse_xml(ParserContext* context) {
    char* current_ptr = context->xml_string;

    while(current_ptr - context->xml_string < context->xml_string_length) {
        // If current character is a tag start
        if(*current_ptr == '<') {
            // If it is a closing tag
            if(*(current_ptr + 1) == '/') {
                // Move current_ptr to the end of tag
                current_ptr = strchr(current_ptr, '>');
                if(current_ptr == NULL) {
                    // No closing bracket found for tag
                    return -1; // Parsing error
                }
                // Pop tag from stack
                context->tag_stack_top--;
            }
            else { // If it is an opening tag
                parse_tag(context, current_ptr + 1);
            }
        }
        current_ptr++;
    }

    return 0;
}

void parse_tag(ParserContext* context, char* start) {
    char* end = strchr(start, ' ');
    if(end == NULL) {
        end = strchr(start, '>');
    }

    int tag_length = end - start;
    if(tag_length > MAX_TAG_LENGTH) {
        printf("Tag name too long: %.*s\n", tag_length, start);
        return;
    }

    // Create new tag
    Tag tag = { .attribute_count = 0 };
    strncpy(tag.name, start, tag_length);

    // If tag is empty
    if(*(end - 1) == '/') {
        return;
    }

    // Push tag onto stack
    context->tag_stack[++(context->tag_stack_top)] = tag;

    // Parse attributes
    while(*end != '>') {
        if(*end == ' ') {
            parse_attribute(context, end + 1, strchr(end, '='));
            end = strchr(end, ' ');
        }
        else {
            end++;
        }
    }
}

void parse_attribute(ParserContext* context, char* start, char* end) {
    int key_length = end - start;
    if(key_length > MAX_ATTRIBUTE_LENGTH) {
        printf("Attribute key too long: %.*s\n", key_length, start);
        return;
    }

    Attribute attribute;
    strncpy(attribute.key, start, key_length);

    start = end + 1;
    end = strchr(start, '\"') + 1;

    int value_length = strchr(end, '\"') - end;
    if(value_length > MAX_ATTRIBUTE_VALUE_LENGTH) {
        printf("Attribute value too long: %.*s\n", value_length, start);
        return;
    }

    strncpy(attribute.value, end, value_length);

    context->tag_stack[context->tag_stack_top].attributes[context->tag_stack[context->tag_stack_top].attribute_count++] = attribute;
}