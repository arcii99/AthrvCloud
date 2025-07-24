//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *value;
} Attribute;

typedef struct {
    char *name;
    Attribute **attributes;
} Tag;

void parse_tag(char *line, Tag *tag);
void parse_attribute(char *attribute_str, Attribute *attribute);
char *remove_whitespace(char *s);

int main() {
    char *xml = "<example attr1=\"value1\" attr2=\"value2\">\n"
                "  <tag1>\n"
                "    Hello World!\n"
                "  </tag1>\n"
                "  <tag2>\n"
                "    <tag3>Some Text</tag3>\n"
                "  </tag2>\n"
                "</example>\n";
    char *token;
    Tag *tags[10];
    int tag_index = 0;

    token = strtok(xml, "\n");
    while (token != NULL) {
        Tag *new_tag = malloc(sizeof(Tag));
        parse_tag(token, new_tag);
        tags[tag_index++] = new_tag;
        token = strtok(NULL, "\n");
    }

    for (int i = 0; i < tag_index; i++) {
        Tag *tag = tags[i];
        printf("%s\n", tag->name);
        for (int j = 0; tag->attributes[j] != NULL; j++) {
            Attribute *attribute = tag->attributes[j];
            printf("  %s=%s\n", attribute->name, attribute->value);
        }
    }

    return 0;
}

void parse_tag(char *line, Tag *tag) {
    char *opening_bracket = strchr(line, '<');
    char *closing_bracket = strchr(line, '>');
    int num_attributes = 0;
    Attribute **attributes = malloc(10 * sizeof(Attribute *));
    char *attribute_str = strndup(opening_bracket+1, closing_bracket-opening_bracket-1);
    char *attribute_token;

    tag->name = remove_whitespace(attribute_str);
    attribute_token = strtok(NULL, " ");
    while (attribute_token != NULL) {
        attributes[num_attributes] = malloc(sizeof(Attribute));
        parse_attribute(attribute_token, attributes[num_attributes]);
        num_attributes++;
        attribute_token = strtok(NULL, " ");
    }

    tag->attributes = attributes;
}

void parse_attribute(char *attribute_str, Attribute *attribute) {
    char *equals = strchr(attribute_str, '=');
    attribute->name = remove_whitespace(strndup(attribute_str, equals-attribute_str));
    attribute->value = remove_whitespace(strndup(equals+1, strlen(attribute_str)-(equals-attribute_str)-2));
}

char *remove_whitespace(char *s) {
    char *new_s = malloc(strlen(s));
    char *new_s_index = new_s;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] != ' ') {
            *new_s_index++ = s[i];
        }
    }
    *new_s_index = '\0';
    return new_s;
}