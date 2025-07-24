//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TAG_LENGTH 100
#define MAX_ATTRIBUTE_LENGTH 100

typedef struct {
    char name[MAX_TAG_LENGTH];
    int level;
    bool has_attributes;
    char attribute_name[MAX_ATTRIBUTE_LENGTH];
    char attribute_value[MAX_ATTRIBUTE_LENGTH];
} tag;

void parse_xml(char* xml) {
    char* p = xml;
    char buffer[MAX_TAG_LENGTH];
    int buffer_index = 0;
    int level = 0;
    bool inside_tag = false;
    bool inside_attribute = false;
    tag current_tag;
    current_tag.has_attributes = false;
    while (*p != '\0') {
        if (*p == '<') {
            inside_tag = true;
            if (buffer_index > 0) {
                // We have finished reading the name of a tag
                strncpy(current_tag.name, buffer, buffer_index);
                current_tag.name[buffer_index] = '\0';
                current_tag.level = level;
                printf("%*s%s\n", level * 4, "", current_tag.name);
                buffer_index = 0;
            }
        }
        else if (*p == '>') {
            inside_tag = false;
            if (buffer_index > 0) {
                // We have finished reading the name of an attribute
                strncpy(current_tag.attribute_name, buffer, buffer_index);
                current_tag.attribute_name[buffer_index] = '\0';
                buffer_index = 0;
                inside_attribute = true;
            }
            else if (current_tag.has_attributes) {
                // We have finished reading the value of an attribute
                strncpy(current_tag.attribute_value, buffer, buffer_index);
                current_tag.attribute_value[buffer_index] = '\0';
                printf("%*s%s=\"%s\"\n", level * 4, "", 
                    current_tag.attribute_name, current_tag.attribute_value);
                buffer_index = 0;
                inside_attribute = false;
            }
        }
        else if (*p == '/') {
            // This is a closing tag
            if (buffer_index > 0) {
                strncpy(buffer, p - buffer_index, buffer_index);
                buffer[buffer_index] = '\0';
                if (strcmp(buffer, current_tag.name) != 0) {
                    printf("ERROR: Closing tag %s does not match opening tag %s\n", buffer, current_tag.name);
                    break;
                }
            }
            level--;
            buffer_index = 0;
            printf("%*s</%s>\n", level * 4, "", current_tag.name);
        }
        else if (*p == ' ' && inside_tag) {
            // We have finished reading the name of a tag and encountered a space, which means we have attributes
            strncpy(current_tag.name, buffer, buffer_index);
            current_tag.name[buffer_index] = '\0';
            current_tag.has_attributes = true;
            buffer_index = 0;
        }
        else if (*p == '=' && inside_attribute) {
            // We have finished reading the attribute name and encountered an equals sign
            strncpy(current_tag.attribute_value, buffer, buffer_index);
            current_tag.attribute_value[buffer_index] = '\0';
            buffer_index = 0;
        }
        else if (*p == '"' && inside_attribute) {
            // We have finished reading the attribute value and encountered a closing quote
            strncpy(current_tag.attribute_value, buffer, buffer_index);
            current_tag.attribute_value[buffer_index] = '\0';
            printf("%*s%s=\"%s\"\n", level * 4, "", 
                current_tag.attribute_name, current_tag.attribute_value);
            buffer_index = 0;
            inside_attribute = false;
        }
        else if (inside_tag || inside_attribute) {
            buffer[buffer_index++] = *p;
        }
        p++;
    }
}

int main(void) {
    char* xml = "<root>\n"
        "   <person id=\"1\" name=\"John\">\n"
        "       <phone type=\"home\">555-1234</phone>\n"
        "       <phone type=\"work\">555-5678</phone>\n"
        "   </person>\n"
        "   <person id=\"2\" name=\"Jane\">\n"
        "       <phone type=\"home\">555-4321</phone>\n"
        "       <phone type=\"work\">555-8765</phone>\n"
        "   </person>\n"
        "</root>";
    parse_xml(xml);
    return 0;
}