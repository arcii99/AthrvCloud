//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_SIZE 100
#define MAX_ATTR_SIZE 100

typedef struct XMLNode {
  char tag[MAX_TAG_SIZE];
  char *attr_names[MAX_ATTR_SIZE];
  char *attr_values[MAX_ATTR_SIZE];
  struct XMLNode *children;
  struct XMLNode *sibling;
} XMLNode;

XMLNode* parse_xml(FILE* fp);
void print_xml(XMLNode* xml);

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  FILE* fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("Error: could not open file %s\n", argv[1]);
    return 1;
  }

  XMLNode* root = parse_xml(fp);

  fclose(fp);

  print_xml(root);

  return 0;
}

XMLNode* parse_xml(FILE* fp) {
  char c;
  int i, j;

  XMLNode* root = (XMLNode*) malloc(sizeof(XMLNode));
  XMLNode* curr = root;
  XMLNode* parent = NULL;

  while (1) {
    c = fgetc(fp);

    if (c == '<') {
      // start of tag
      curr->tag[0] = '\0';

      c = fgetc(fp);

      if (c == '/') {
        // closing tag
        curr = parent;
        continue;
      } else {
        // opening tag
        parent = curr;
        curr->children = (XMLNode*) malloc(sizeof(XMLNode));
        curr = curr->children;

        i = 0;
        while (c != '>' && i < MAX_TAG_SIZE - 1) {
          curr->tag[i++] = c;
          c = fgetc(fp);
        }
        curr->tag[i] = '\0';

        if (c == '>') {
          continue;
        } else if (c == ' ') {
          // attributes
          i = 0;
          curr->attr_names[0] = (char*) malloc(sizeof(char) * MAX_ATTR_SIZE);
          curr->attr_values[0] = (char*) malloc(sizeof(char) * MAX_ATTR_SIZE);

          while (1) {
            c = fgetc(fp);
            if (c == '=') {
              curr->attr_names[i][j] = '\0';

              c = fgetc(fp);
              if (c == '\"' || c == '\'') {
                j = 0;
                while ((c = fgetc(fp)) != '\"' && (c = fgetc(fp)) != '\'') {
                  curr->attr_values[i][j++] = c;
                }
                curr->attr_values[i][j] = '\0';
                i++;

                curr->attr_names[i] = (char*) malloc(sizeof(char) * MAX_ATTR_SIZE);
                curr->attr_values[i] = (char*) malloc(sizeof(char) * MAX_ATTR_SIZE);
              }
            } else if (c == '>') {
              curr->attr_names[i][j] = '\0';
              break;
            } else if (c != ' ' && i < MAX_ATTR_SIZE - 1 && j < MAX_ATTR_SIZE - 1) {
              curr->attr_names[i][j++] = c;
            }
          }
        }
      }
    } else if (c == EOF) {
      break;
    } else {
      // text node
      curr->sibling = (XMLNode*) malloc(sizeof(XMLNode));
      curr = curr->sibling;
      curr->tag[0] = '\0';
      i = 0;

      while (c != '<' && c != EOF && i < MAX_TAG_SIZE - 1) {
        curr->tag[i++] = c;
        c = fgetc(fp);
      }
      curr->tag[i] = '\0';

      if (c == '<') {
        // start of new tag
        fseek(fp, -1, SEEK_CUR);
      } else if (c == EOF) {
        // end of file
        break;
      }
    }
  }

  return root;
}

void print_xml(XMLNode* xml) {
  if (xml == NULL) {
    return;
  }

  printf("<%s", xml->tag);

  for (int i = 0; xml->attr_names[i] != NULL; i++) {
    printf(" %s=\"%s\"", xml->attr_names[i], xml->attr_values[i]);
  }

  printf(">");

  if (xml->children != NULL) {
    printf("\n");
    print_xml(xml->children);
  } else if (xml->tag[0] != '\0') {
    printf("%s", xml->tag);
  }

  if (xml->sibling != NULL) {
    printf("\n");
    print_xml(xml->sibling);
  } else {
    printf("</%s>\n", xml->tag);
  }
}