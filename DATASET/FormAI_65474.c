//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    bool is_self_closing;
    char *name;
    char *value;
    struct Node *children;
    struct Node *next;
} Node;

static char* read_file(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
      perror("Could not open file");
      exit(EXIT_FAILURE);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *buffer = (char*) calloc(size+1, sizeof(char));
    if (!buffer) {
      fclose(fp);
      perror("Could not allocate buffer");
      exit(EXIT_FAILURE);
    }

    size_t new_len = fread(buffer, sizeof(char), size, fp);
    if (new_len == 0) {
      perror("Empty file");
      exit(EXIT_FAILURE);
    }

    buffer[++new_len] = '\0';
    fclose(fp);
    return buffer;
}

static bool is_whitespace(char c) {
    return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == '\f';
}

static char* trim_whitespace(char *string) {
    if (!string) {
      return NULL;
    }

    int start = 0, end = strlen(string)-1;

    while (string[start] && is_whitespace(string[start])) {
      start++;
    }

    while (end > start && is_whitespace(string[end])) {
      end--;
    }

    int new_len = end - start + 1;

    char *new_str = (char*) calloc(new_len+1, sizeof(char));
    if (!new_str) {
      perror("Could not allocate new string");
      exit(EXIT_FAILURE);
    }

    strncpy(new_str, string+start, new_len);
    return new_str;
}

static Node* create_node(char *name, char *value, bool is_self_closing) {
    Node *node = (Node*) malloc(sizeof(Node));
    if (!node) {
      perror("Could not allocate node");
      exit(EXIT_FAILURE);
    }

    node->name = trim_whitespace(name);
    node->value = trim_whitespace(value);
    node->is_self_closing = is_self_closing;
    node->children = NULL;
    node->next = NULL;

    return node;
}

static char** parse_attributes(char *tag) {
    char **attributes = (char**) calloc(1000, sizeof(char*));
    if (!attributes) {
      perror("Could not allocate attribute array");
      exit(EXIT_FAILURE);
    }

    int attribute_count = 0;
    char *name = (char*) calloc(1000, sizeof(char));
    char *value = (char*) calloc(1000, sizeof(char));
    bool in_name = true, has_value = false;

    for (int i = 0; i < strlen(tag); i++) {
      char c = tag[i];

      if (c == '>') {
        break;
      }

      if (c == '=') {
        in_name = false;
        has_value = false;
      } else if (c == '"' || c == '\'') {
        if (!has_value) {
          has_value = true;
        } else {
          has_value = false;
          attribute_count++;
          name = (char*) calloc(1000, sizeof(char));
          value = (char*) calloc(1000, sizeof(char));
        }
      } else if (in_name) {
        name[strlen(name)] = c;
      } else if (has_value) {
        value[strlen(value)] = c;
      }

      attributes[attribute_count] = name;
      attributes[attribute_count+1] = value;
    }

    return attributes;
}

static bool is_self_closing_tag(char *tag) {
    return tag[strlen(tag)-2] == '/';
}

static char* get_tag_name(char *tag) {
    char *name = (char*) calloc(1000, sizeof(char));
    int i = 1;

    while (tag[i] != ' ' && tag[i] != '>') {
      name[strlen(name)] = tag[i];
      i++;
    }

    return name;
}

static Node* get_next_node(char *document, int *index) {
    Node *node = NULL;
    char *tag = (char*) calloc(1000, sizeof(char));
    int i = *index+1, j = 0;

    while (document[i] && document[i] != '<') {
      i++;
    }

    if (document[i+1] == '/') {
      *index = i;
      return NULL;
    }

    i--;

    while (is_whitespace(document[i])) {
      i--;
    }

    while (tag[j] != '>') {
      tag[j] = document[i];
      i--;
      j++;
    }

    if (is_self_closing_tag(tag)) {
      node = create_node(get_tag_name(tag), NULL, true);
    } else {
      node = create_node(get_tag_name(tag), NULL, false);
      char **attributes = parse_attributes(tag);
      for (int k = 0; k < 1000; k += 2) {
        if (attributes[k] && attributes[k+1]) {
          Node *child = create_node(attributes[k], attributes[k+1], true);
          child->next = node->children;
          node->children = child;
        }
      }
    }

    *index = i;
    return node;
}

static Node* parse_xml(char *document) {
    int index = -1, len = strlen(document);
    Node *root = NULL, *prev = NULL;

    while (index < len-1) {
      Node *node = get_next_node(document, &index);

      if (node && !root) {
        root = node;
      } else if (node && prev) {
        prev->next = node;
      }

      prev = node;
    }

    return root;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
      printf("Usage: %s <xml_file>\n", argv[0]);
      exit(EXIT_FAILURE);
    }

    char *filename = argv[1];
    char *document = read_file(filename);

    Node *root = parse_xml(document);

    printf("<%s>\n", root->name);

    Node *current = root->children;
    while (current) {
      printf("  <%s> %s </%s>\n", current->name, current->value, current->name);
      current = current->next;
    }

    printf("</%s>\n", root->name);

    return 0;
}