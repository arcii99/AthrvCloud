//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 128

// example XML structure
typedef struct {
    char tag[MAX_SIZE];
    char value[MAX_SIZE];
    int child_count;
    struct xml_node* child_list[MAX_SIZE];
} xml_node;

int parse_xml_file(const char* file_path, xml_node* root_node);
int parse_xml_node(char* xml_str, int xml_str_len, xml_node* node);

int main() {
    xml_node root_node = { "", "", 0, { NULL } };
    if (parse_xml_file("example.xml", &root_node) == 0) {
        printf("Parsing successful!\n");
    }
    return 0;
}

int parse_xml_file(const char* file_path, xml_node* root_node) {
    int ret = -1;
    FILE* fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("Failed to open file: %s\n", file_path);
        return ret;
    }
    char line[MAX_SIZE], xml_str[MAX_SIZE];
    int xml_str_len = 0;
    xml_node* last_node_ptr = root_node;
    while (fgets(line, sizeof(line), fp) != NULL) {
        int line_len = strlen(line);
        if (line_len >= 2 && line[0] == '<' && line[line_len-2] == '>') {
            line[line_len-2] = '\0';
            strcat(xml_str, line);
            xml_str_len += (line_len - 2);
            xml_node* new_node = (xml_node*)malloc(sizeof(xml_node));
            new_node->child_count = 0;
            new_node->tag[0] = '\0';
            new_node->value[0] = '\0';
            new_node->child_list[0] = NULL;
            if (parse_xml_node(xml_str, xml_str_len, new_node) == 0) {
                last_node_ptr->child_list[last_node_ptr->child_count++] = new_node;
                last_node_ptr = new_node;
            }
            else {
                printf("Failed to parse XML node: %s\n", xml_str);
                free(new_node);
                fclose(fp);
                return ret;
            }
            xml_str[0] = '\0';
            xml_str_len = 0;
        }
        else {
            strcat(xml_str, line);
            xml_str_len += line_len;
        }
    }
    fclose(fp);
    return 0;
}

int parse_xml_node(char* xml_str, int xml_str_len, xml_node* node) {
    int ret = -1;
    if (xml_str[0] != '<' || xml_str[xml_str_len-1] != '>') {
        return ret;
    }
    xml_str[xml_str_len-1] = '\0';
    char* delim_pos = strchr(xml_str, '>');
    if (delim_pos == NULL) {
        return ret;
    }
    int tag_len = 0;
    while (xml_str[tag_len] != ' ' && xml_str[tag_len] != '>') {
        node->tag[tag_len] = xml_str[tag_len];
        tag_len++;
    }
    node->tag[tag_len] = '\0';
    if (xml_str[tag_len] == ' ') {
        char* value_start_pos = delim_pos + 1;
        char* value_end_pos = strchr(value_start_pos, '<');
        if (value_end_pos == NULL) {
            return ret;
        }
        memcpy(node->value, value_start_pos, value_end_pos - value_start_pos);
        node->value[value_end_pos-value_start_pos] = '\0';
    }
    return 0;
}