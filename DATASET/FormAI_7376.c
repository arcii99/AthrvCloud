//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 100

typedef enum {
    START,
    OPEN_BRACKET_FOUND,
    CLOSE_BRACKET_FOUND,
    FORWARD_SLASH_FOUND,
    TAG_NAME_START,
    TAG_NAME_END,
    ATTRIBUTE_NAME_START,
    ATTRIBUTE_NAME_END,
    ATTRIBUTE_VALUE_START,
    ATTRIBUTE_VALUE_END,
    DONE
} State;

typedef struct {
    char tag_name[MAX_SIZE];
    char attribute_name[MAX_SIZE];
    char attribute_value[MAX_SIZE];
} XML_Tag;

XML_Tag current_tag;
State current_state;

void reset_tag() {
    memset(current_tag.tag_name, 0, sizeof(current_tag.tag_name));
    memset(current_tag.attribute_name, 0, sizeof(current_tag.attribute_name));
    memset(current_tag.attribute_value, 0, sizeof(current_tag.attribute_value));
}

void parse_xml(char* input) {
    char* input_ptr = input;
    while (*input_ptr != '\0') {
        switch (current_state) {
            case START:
                if (*input_ptr == '<') {
                    current_state = OPEN_BRACKET_FOUND;
                }
                break;

            case OPEN_BRACKET_FOUND:
                if (*input_ptr == '/') {
                    current_state = FORWARD_SLASH_FOUND;
                } else {
                    current_state = TAG_NAME_START;
                }
                break;

            case CLOSE_BRACKET_FOUND:
                if (*input_ptr == '<') {
                    current_state = OPEN_BRACKET_FOUND;
                } else {
                    current_state = ATTRIBUTE_NAME_START;
                }
                break;

            case FORWARD_SLASH_FOUND:
                if (*input_ptr == '>') {
                    current_state = DONE;
                } else {
                    current_state = TAG_NAME_START;
                }
                break;

            case TAG_NAME_START:
                if (!isspace(*input_ptr)) {
                    current_tag.tag_name[strlen(current_tag.tag_name)] = *input_ptr;
                    current_state = TAG_NAME_END;
                }
                break;

            case TAG_NAME_END:
                if (isspace(*input_ptr)) {
                    current_state = ATTRIBUTE_NAME_START;
                } else if (*input_ptr == '/') {
                    current_state = CLOSE_BRACKET_FOUND;
                } else if (*input_ptr == '>') {
                    current_state = DONE;
                } else {
                    current_tag.tag_name[strlen(current_tag.tag_name)] = *input_ptr;
                }
                break;

            case ATTRIBUTE_NAME_START:
                if (!isspace(*input_ptr) && *input_ptr != '>' && *input_ptr != '/') {
                    reset_tag();
                    current_tag.attribute_name[strlen(current_tag.attribute_name)] = *input_ptr;
                    current_state = ATTRIBUTE_NAME_END;
                }
                break;

            case ATTRIBUTE_NAME_END:
                if (*input_ptr == '=') {
                    current_state = ATTRIBUTE_VALUE_START;
                } else if (isspace(*input_ptr)) {
                    current_state = ATTRIBUTE_NAME_START;
                } else if (*input_ptr == '>') {
                    current_state = DONE;
                } else {
                    current_tag.attribute_name[strlen(current_tag.attribute_name)] = *input_ptr;
                }
                break;

            case ATTRIBUTE_VALUE_START:
                if (*input_ptr == '\'' || *input_ptr == '\"') {
                    current_state = ATTRIBUTE_VALUE_END;
                } else if (isspace(*input_ptr)) {
                    current_state = ATTRIBUTE_VALUE_START;
                }
                break;

            case ATTRIBUTE_VALUE_END:
                if (*input_ptr == '\'' || *input_ptr == '\"') {
                    current_state = CLOSE_BRACKET_FOUND;
                } else if (*input_ptr == '>') {
                    current_state = DONE;
                } else {
                    current_tag.attribute_value[strlen(current_tag.attribute_value)] = *input_ptr;
                }
                break;

            case DONE:
                reset_tag();
                current_state = START;
                break;
        }
        input_ptr++;
    }
}

int main() {
    char* input = "<person name='John' age='20' gender='male' height='5.10'/><dog breed='labrador'/>";
    current_state = START;
    parse_xml(input);
    return 0;
}