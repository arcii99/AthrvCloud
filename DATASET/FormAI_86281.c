//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *tag;
  char *data;
} Element;

typedef struct {
  Element *elements;
  int num_elements;
} XML;

XML parse_xml(char *xml_string) {
  XML xml;
  xml.elements = calloc(256, sizeof(Element));
  xml.num_elements = 0;

  char *token;
  char *ptr = xml_string;
  while ((token = strtok_r(ptr, "<>", &ptr))) {
    if (token[0] != '/') {
      char *tag = strtok(token, " ");
      char *data = strtok(0, " ");

      Element element = {tag, data};
      xml.elements[xml.num_elements++] = element;
    }
  }

  return xml;
}

int main() {
  char *xml_string = "<person gender='male'>\n  <name>John</name>\n  <age>30</age>\n</person>";
  XML xml = parse_xml(xml_string);

  for (int i = 0; i < xml.num_elements; i++) {
    printf("%s: %s\n", xml.elements[i].tag, xml.elements[i].data);
  }

  return 0;
}