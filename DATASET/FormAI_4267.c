//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LEN 100
#define MAX_ATTR_LEN 100

#define STATE_START 0
#define STATE_TAG_BEGIN 1
#define STATE_TAG_NAME 2
#define STATE_TAG_CLOSE 3
#define STATE_ATTR_BEGIN 4
#define STATE_ATTR_NAME 5
#define STATE_ATTR_VALUE_BEGIN 6
#define STATE_ATTR_VALUE 7

typedef struct {
  char name[MAX_TAG_LEN];
  char attrs[MAX_ATTR_LEN][2][MAX_TAG_LEN];
  int attr_count;
} Tag;

void handle_tag(Tag* tag) {
  printf("<%s ", tag->name);
  for (int i = 0; i < tag->attr_count; i++) {
    printf("%s=\"%s\" ", tag->attrs[i][0], tag->attrs[i][1]);
  }
  printf("/>\n");
  tag->name[0] = '\0';
  tag->attr_count = 0;
}

void handle_attr(char* name, char* value, Tag* tag) {
  strcpy(tag->attrs[tag->attr_count][0], name);
  strcpy(tag->attrs[tag->attr_count][1], value);
  tag->attr_count++;
}

void parse_xml(char* xml_str) {
  Tag tag;
  int state = STATE_START;
  int i = 0;
  char c;
  char buf[MAX_TAG_LEN];
  int buf_i = 0;
  char attr_name[MAX_TAG_LEN];
  char attr_value[MAX_TAG_LEN];
  while (1) {
    c = xml_str[i];
    switch (state) {
      case STATE_START:
        if (c == '<') {
          state = STATE_TAG_BEGIN;
        }
        else {
          printf("%c", c);
        }
        break;
      case STATE_TAG_BEGIN:
        if (c == '/') {
          state = STATE_TAG_CLOSE;
        }
        else {
          state = STATE_TAG_NAME;
          buf[0] = c;
          buf_i = 1;
        }
        break;
      case STATE_TAG_NAME:
        if (c == ' ' || c == '>') {
          buf[buf_i] = '\0';
          strcpy(tag.name, buf);
          buf_i = 0;
          if (c == ' ') {
            state = STATE_ATTR_BEGIN;
          }
          else {
            handle_tag(&tag);
            state = STATE_START;
          }
        }
        else {
          buf[buf_i] = c;
          buf_i++;
        }
        break;
      case STATE_TAG_CLOSE:
        if (c == '>') {
          printf("</%s>\n", tag.name);
          tag.name[0] = '\0';
          state = STATE_START;
        }
        break;
      case STATE_ATTR_BEGIN:
        if (c == '>') {
          handle_tag(&tag);
          state = STATE_START;
        }
        else if (c != ' ') {
          state = STATE_ATTR_NAME;
          buf[0] = c;
          buf_i = 1;
        }
        break;
      case STATE_ATTR_NAME:
        if (c == '=') {
          buf[buf_i] = '\0';
          strcpy(attr_name, buf);
          buf_i = 0;
          state = STATE_ATTR_VALUE_BEGIN;
        }
        else {
          buf[buf_i] = c;
          buf_i++;
        }
        break;
      case STATE_ATTR_VALUE_BEGIN:
        if (c == '"' || c == '\'') {
          state = STATE_ATTR_VALUE;
        }
        break;
      case STATE_ATTR_VALUE:
        if (c == '"' || c == '\'') {
          buf[buf_i] = '\0';
          strcpy(attr_value, buf);
          buf_i = 0;
          handle_attr(attr_name, attr_value, &tag);
          state = STATE_ATTR_BEGIN;
        }
        else {
          buf[buf_i] = c;
          buf_i++;
        }
        break;
    }

    if (c == '\0') {
      break;
    }
    i++;
  }
}

int main() {
  char xml_str[] = "<root>\n"
                   "  <person name=\"Alice\" age=\"25\"/>\n"
                   "  <person name=\"Bob\" age=\"30\"/>\n"
                   "</root>";
  parse_xml(xml_str);
  return 0;
}