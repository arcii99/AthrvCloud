//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TAG_LEN 100
#define MAX_ATTR_LEN 100
#define MAX_ATTR_VAL_LEN 100
#define MAX_VALUE_LEN 1000

/* XML Attribute Struct */
typedef struct xml_attr {
    char name[MAX_ATTR_LEN];
    char value[MAX_ATTR_VAL_LEN];
    struct xml_attr* next;
} xml_attr_t;

/* XML Node Struct */
typedef struct xml_node {
    char tag[MAX_TAG_LEN];
    xml_attr_t* attrs;
    struct xml_node* children;
    char value[MAX_VALUE_LEN];
    struct xml_node* next;
} xml_node_t;

/* Parse Attribute */
static void parse_attribute(xml_node_t* node, char* attr) {
    xml_attr_t* new_attr = (xml_attr_t*)malloc(sizeof(xml_attr_t));

    char* val_start = strchr(attr, '=');
    if (val_start == NULL) return;
    *val_start = '\0';

    char* val_end = val_start + 1;
    while (*val_end != '\"') val_end++;
    *val_end = '\0';
    val_end++;

    strncpy(new_attr->name, attr, MAX_ATTR_LEN);
    strncpy(new_attr->value, val_start+1, MAX_ATTR_VAL_LEN);
    new_attr->next = NULL;

    if (node->attrs == NULL) {
        node->attrs = new_attr;
    }
    else {
        xml_attr_t* cur_attr = node->attrs;
        while (cur_attr->next != NULL) cur_attr = cur_attr->next;
        cur_attr->next = new_attr;
    }
}

/* Parse Node */
static xml_node_t* parse_node(char* xml_str, int* idx) {
    xml_node_t* node = (xml_node_t*)malloc(sizeof(xml_node_t));
    node->attrs = NULL;
    node->children = NULL;
    node->next = NULL;

    /* Parse tag */
    int tag_idx = *idx;
    while (!isspace(xml_str[*idx]) && xml_str[*idx] != '>') (*idx)++;
    strncpy(node->tag, &xml_str[tag_idx], *idx - tag_idx);
    node->tag[*idx - tag_idx] = '\0';

    /* Parse attributes */
    while (xml_str[*idx] != '>') {
        if (isspace(xml_str[*idx])) {
            (*idx)++;
            continue;
        }
        if (xml_str[*idx] == '/') {
            (*idx)++;
            if (xml_str[*idx] == '>') {
                (*idx)++;
                return node;
            }
        }
        char* attr_start = xml_str + *idx;
        while (xml_str[*idx] != '=' && xml_str[*idx] != '>') (*idx)++;
        if (xml_str[*idx] == '=') {
            parse_attribute(node, attr_start);
            (*idx)++;
        }
    }

    (*idx)++;

    /* Parse children and value */
    int value_idx = *idx;
    if (xml_str[*idx] != '<') {
        while (xml_str[*idx] != '<') (*idx)++;
        strncpy(node->value, &xml_str[value_idx], *idx - value_idx);
        node->value[*idx - value_idx] = '\0';
    }

    int child_idx;
    while (xml_str[*idx] != '/') {
        if (xml_str[*idx] == '<') {
            if (xml_str[*idx + 1] == '/') {
                (*idx) += 2;
                return node;
            }
            else {
                (*idx)++;
                xml_node_t* child = parse_node(xml_str, idx);
                if (node->children == NULL) {
                    node->children = child;
                }
                else {
                    xml_node_t* cur_child = node->children;
                    while (cur_child->next != NULL) cur_child = cur_child->next;
                    cur_child->next = child;
                }
            }
        }
        else (*idx)++;
    }

    (*idx) += 2;

    return node;
}

/* Print XML Node */
static void print_node(xml_node_t* node, int level) {
    for (int i = 0; i < level; i++) printf("  ");
    printf("<%s", node->tag);
    xml_attr_t* cur_attr = node->attrs;
    while (cur_attr != NULL) {
        printf(" %s=\"%s\"", cur_attr->name, cur_attr->value);
        cur_attr = cur_attr->next;
    }
    if (node->children == NULL && strlen(node->value) == 0) {
        printf("/>\n");
    }
    else {
        printf(">");
        if (strlen(node->value) > 0) {
            printf("%s", node->value);
        }
        printf("\n");
        xml_node_t* cur_child = node->children;
        while (cur_child != NULL) {
            print_node(cur_child, level+1);
            cur_child = cur_child->next;
        }
        for (int i = 0; i < level; i++) printf("  ");
        printf("</%s>\n", node->tag);
    }
}

/* XML Parser */
void xml_parser(char* xml_str) {
    int idx = 0;
    while (xml_str[idx] != '\0') {
        if (xml_str[idx] == '<') {
            if (xml_str[idx+1] == '?') {
                while (xml_str[idx] != '>') idx++;
            }
            else {
                idx++;
                xml_node_t* root = parse_node(xml_str, &idx);
                print_node(root, 0);
            }
        }
        else idx++;
    }
}

/* Main Function */
int main() {
    char xml_str[] =
    "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
    "<catalog>\n"
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
    "</catalog>\n";
    xml_parser(xml_str);
    return 0;
}