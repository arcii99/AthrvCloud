//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1024

typedef struct {
    char *key;
    char *value;
} xml_attribute;

typedef struct {
    char *name;
    xml_attribute **attributes;
    int attributes_count;
    char *content;
} xml_element;

xml_element *parse_element(char *str);
xml_attribute *parse_attribute(char *str);
char *parse_content(char *str);

int main() {
    char input[MAX_LEN];
    printf("Enter XML string: ");
    fgets(input, MAX_LEN, stdin);
    input[strcspn(input, "\n")] = 0;  // remove trailing newline
    xml_element *root = parse_element(input);
    printf("Parsed XML:\n%s\n", root->name);
    printf("Attributes:\n");
    for (int i = 0; i < root->attributes_count; i++) {
        printf("%s=%s\n", root->attributes[i]->key, root->attributes[i]->value);
    }
    printf("Content:\n%s\n", root->content);
    return 0;
}

xml_element *parse_element(char *str) {
    xml_element *element = malloc(sizeof(xml_element));
    element->attributes_count = 0;
    char *p = strchr(str, '<');
    if (p == NULL) {
        return NULL;
    }
    char *q = strchr(p, '>');
    if (q == NULL) {
        return NULL;
    }
    int name_len = q - p - 1;
    element->name = malloc(name_len);
    strncpy(element->name, p + 1, name_len);
    element->name[name_len] = '\0';
    char *r = strchr(q, '<');
    if (r == NULL) {
        return NULL;
    }
    int content_len = r - q - 1;
    element->content = parse_content(strndup(q + 1, content_len));
    p = q;
    while (*p != '\0') {
        p++;
        if (*p == '/') {
            break;
        }
        if (*p == ' ') {
            xml_attribute *attribute = parse_attribute(p + 1);
            element->attributes_count++;
            element->attributes = realloc(element->attributes, element->attributes_count * sizeof(xml_attribute *));
            element->attributes[element->attributes_count - 1] = attribute;
        }
    }
    return element;
}

xml_attribute *parse_attribute(char *str) {
    xml_attribute *attribute = malloc(sizeof(xml_attribute));
    char *p = strchr(str, '=');
    if (p == NULL) {
        return NULL;
    }
    int key_len = p - str;
    attribute->key = malloc(key_len);
    strncpy(attribute->key, str, key_len);
    attribute->key[key_len] = '\0';
    char *q = strchr(p + 1, '"');
    if (q == NULL) {
        return NULL;
    }
    char *r = strchr(q + 1, '"');
    if (r == NULL) {
        return NULL;
    }
    int value_len = r - q - 1;
    attribute->value = malloc(value_len);
    strncpy(attribute->value, q + 1, value_len);
    attribute->value[value_len] = '\0';
    return attribute;
}

char *parse_content(char *str) {
    char *content = malloc(strlen(str));
    int i = 0;
    while (*str != '\0') {
        if (*str == '<') {
            break;
        }
        if (*str == '&') {
            if (strncmp(str, "&lt;", 4) == 0) {
                content[i++] = '<';
                str += 4;
            } else if (strncmp(str, "&gt;", 4) == 0) {
                content[i++] = '>';
                str += 4;
            } else if (strncmp(str, "&quot;", 6) == 0) {
                content[i++] = '"';
                str += 6;
            } else if (strncmp(str, "&apos;", 6) == 0) {
                content[i++] = '\'';
                str += 6;
            } else if (strncmp(str, "&amp;", 5) == 0) {
                content[i++] = '&';
                str += 5;
            } else {
                content[i++] = *str++;
            }
        } else {
            content[i++] = *str++;
        }
    }
    content[i] = '\0';
    return content;
}