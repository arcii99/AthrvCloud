//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct {
    char tag[20];
    char attribute[20];
    char value[100];
} xml_tag;

void parse_xml(char* xml) {
    bool is_opening_tag = false;
    bool is_closing_tag = false;
    bool is_attribute = false;
    bool is_value = false;
    char temp_tag[20], temp_attribute[20], temp_value[100];
    int tag_index = 0, attribute_index = 0, value_index = 0;
    xml_tag tags[100];
    int tag_counter = 0;
    
    for (int i = 0; i < strlen(xml); i++) {
        if (xml[i] == '<') {
            is_opening_tag = true;
            is_closing_tag = false;
            is_attribute = false;
            is_value = false;
            tag_index = 0;
            attribute_index = 0;
            value_index = 0;
        }
        else if (xml[i] == '/') {
            is_opening_tag = false;
            is_closing_tag = true;
            tag_index = 0;
        }
        else if (is_opening_tag && !is_closing_tag && !is_attribute && !is_value) {
            if (!isspace(xml[i])) {
                temp_tag[tag_index++] = xml[i];
            }
            else {
                temp_tag[tag_index] = '\0';
                strncpy(tags[tag_counter].tag, temp_tag, strlen(temp_tag));
                tag_counter++;
                memset(temp_tag, 0, sizeof temp_tag);
                tag_index = 0;
            }
        }
        else if (!is_opening_tag && is_closing_tag && !is_attribute && !is_value) {
            if (!isspace(xml[i])) {
                temp_tag[tag_index++] = xml[i];
            }
            else {
                temp_tag[tag_index] = '\0';
                tag_counter--;
                if (strcmp(tags[tag_counter].tag, temp_tag) != 0) {
                    printf("Error: Mismatched tag '%s'\n", temp_tag);
                    return;
                }
                memset(temp_tag, 0, sizeof temp_tag);
                tag_index = 0;
            }
        }
        else if (is_opening_tag && !is_closing_tag && !is_attribute && isspace(xml[i])) {
            is_attribute = true;
        }
        else if (is_attribute && !is_value && xml[i] != '=') {
            temp_attribute[attribute_index++] = xml[i];
        }
        else if (is_attribute && !is_value && xml[i] == '=') {
            is_attribute = false;
            is_value = true;
        }
        else if (is_value && xml[i] != '\"') {
            temp_value[value_index++] = xml[i];
        }
        else if (is_value && xml[i] == '\"') {
            strncpy(tags[tag_counter].attribute, temp_attribute, strlen(temp_attribute));
            strncpy(tags[tag_counter].value, temp_value, strlen(temp_value));
            memset(temp_attribute, 0, sizeof temp_attribute);
            memset(temp_value, 0, sizeof temp_value);
            is_value = false;
        }
    }
    
    if (tag_counter != 0) {
        printf("Error: Unclosed tag '%s'\n", tags[tag_counter-1].tag);
        return;
    }
    
    printf("Parsed XML tags:\n");
    for (int i = 0; i < tag_counter; i++) {
        printf("%s -> %s=%s\n", tags[i].tag, tags[i].attribute, tags[i].value);
    }
}

int main() {
    char xml[] = "<person name=\"John Doe\"><age>30</age><city>New York</city></person>";
    parse_xml(xml);
    return 0;
}