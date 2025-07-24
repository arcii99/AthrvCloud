//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LENGTH 50
#define MAX_ATTR_LENGTH 50
#define MAX_VALUE_LENGTH 200
#define MAX_DATA_LENGTH 2000

typedef struct Attr {
    char name[MAX_ATTR_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Attr;

typedef struct Tag {
    char name[MAX_TAG_LENGTH];
    Attr attrs[10];
    int num_attrs;
    char data[MAX_DATA_LENGTH];
    struct Tag *children[25];
    int num_children;
} Tag;

void print_tag(Tag *tag) {
    printf("<%s", tag->name);
    for (int i = 0; i < tag->num_attrs; i++) {
        printf(" %s=\"%s\"", tag->attrs[i].name, tag->attrs[i].value);
    }
    printf(">\n");
    if (strlen(tag->data) > 0) {
        printf("%s\n", tag->data);
    }
    for (int i = 0; i < tag->num_children; i++) {
        print_tag(tag->children[i]);
    }
    printf("</%s>\n", tag->name);
}

Tag *parse_tag(char *xml, int *pos);

Tag *parse_attr(char *xml, int *pos) {
    char attr_name[MAX_ATTR_LENGTH];
    char attr_value[MAX_VALUE_LENGTH];
    int len = strlen(xml);
    int i = 0;
    while (i < len) {
        if (xml[i] == '=') {
            break;
        }
        attr_name[i] = xml[i];
        i++;
    }
    attr_name[i] = '\0';
    i++; // skip the '='
    int j = 0;
    while (i < len) {
        if (xml[i] == '\"') {
            break;
        }
        attr_value[j] = xml[i];
        i++;
        j++;
    }
    attr_value[j] = '\0';
    i++; // skip the closing quote
    *pos = i;
    Attr *attr = (Attr*)malloc(sizeof(Attr));
    strncpy(attr->name, attr_name, MAX_ATTR_LENGTH);
    strncpy(attr->value, attr_value, MAX_VALUE_LENGTH);
    return attr;
}

Tag *parse_tag(char *xml, int *pos) {
    char tag_name[MAX_TAG_LENGTH];
    int len = strlen(xml);
    int i = *pos;
    while (i < len) {
        if (xml[i] == '>') {
            break;
        }
        tag_name[i - *pos] = xml[i];
        i++;
    }
    tag_name[i - *pos] = '\0';
    i++; // skip the closing '>'
    *pos = i;
    Tag *tag = (Tag*)malloc(sizeof(Tag));
    strncpy(tag->name, tag_name, MAX_TAG_LENGTH);
    tag->num_attrs = 0;
    tag->num_children = 0;
    memset(tag->data, 0, MAX_DATA_LENGTH);
    i--;
    while (i < len) {
        if (strncmp(&xml[i], "</", 2) == 0) {
            i += 2;
            break;
        } else if (strncmp(&xml[i], "<", 1) == 0) {
            i++; // skip the '<'
            Tag *child_tag = parse_tag(xml, &i);
            tag->children[tag->num_children] = child_tag;
            tag->num_children++;
            continue;
        } else if (strncmp(&xml[i], "/", 1) == 0) {
            i++;
            break;
        } else if (strncmp(&xml[i], " ", 1) == 0) {
            i++;
            continue;
        } else {
            int j = 0;
            while (i < len) {
                if (xml[i] == '=') {
                    break;
                }
                i++;
            }
            i++; // skip the '='
            i++; // skip the opening quote
            j = 0;
            char attr_value[MAX_VALUE_LENGTH];
            while (i < len) {
                if (xml[i] == '\"') {
                    break;
                }
                attr_value[j] = xml[i];
                i++;
                j++;
            }
            attr_value[j] = '\0';
            Attr *attr = (Attr*)malloc(sizeof(Attr));
            strncpy(attr->name, &xml[i - j - 1], j);
            strncpy(attr->value, attr_value, MAX_VALUE_LENGTH);
            tag->attrs[tag->num_attrs] = *attr;
            tag->num_attrs++;
            i++; // skip the closing quote
        }
    }
    i--;
    int j = 0;
    while (*pos < i) {
        tag->data[j] = xml[*pos];
        (*pos)++;
        j++;
    }
    tag->data[j] = '\0';
    *pos = i;
    return tag;
}

int main() {
    char xml[] = "<bookstore>\n"
                "  <book category=\"cooking\">\n"
                "    <title lang=\"en\">Everyday Italian</title>\n"
                "    <author>Giada De Laurentiis</author>\n"
                "    <year>2005</year>\n"
                "    <price>30.00</price>\n"
                "  </book>\n"
                "  <book category=\"children\">\n"
                "    <title lang=\"en\">Harry Potter</title>\n"
                "    <author>J.K. Rowling</author>\n"
                "    <year>2005</year>\n"
                "    <price>29.99</price>\n"
                "  </book>\n"
                "</bookstore>\n";
    int pos = 0;
    Tag *root = parse_tag(xml, &pos);
    print_tag(root);
    return 0;
}