//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for maximum size of XML tags and attributes
#define MAX_TAG_SIZE 50
#define MAX_ATTR_SIZE 50

// Define a struct to hold information about a single XML tag
typedef struct {
  char name[MAX_TAG_SIZE];
  char attributes[MAX_ATTR_SIZE][2][MAX_ATTR_SIZE];
  int num_attributes;
  char value[MAX_TAG_SIZE];
} xml_tag;

// Function to parse an XML tag and extract its information
xml_tag parse_tag(char* tag) {
  xml_tag parsed;
  parsed.num_attributes = 0;
  char* token = strtok(tag, " ");
  strcpy(parsed.name, token);
  token = strtok(NULL, "\"");
  while (token != NULL) {
    strcpy(parsed.attributes[parsed.num_attributes][0], token);
    token = strtok(NULL, "\"");
    strcpy(parsed.attributes[parsed.num_attributes][1], token);
    parsed.num_attributes++;
    token = strtok(NULL, "\"");
  }
  return parsed;
}

int main() {
  // Example XML document to parse
  char* document = "<note><to>Tove</to><from>Jani</from><heading>Reminder</heading><body>Don't forget me this weekend!</body></note>";

  // Parse the document and extract the tags and their information
  xml_tag tags[10];
  int num_tags = 0;
  char* token = strtok(document, "<>");
  while (token != NULL) {
    if (token[0] != '/') {
      tags[num_tags] = parse_tag(token);
      num_tags++;
    }
    token = strtok(NULL, "<>");
  }

  // Print out the extracted information for each tag
  for (int i = 0; i < num_tags; i++) {
    printf("Tag name: %s\n", tags[i].name);
    printf("Tag value: %s\n", tags[i].value);
    printf("Tag attributes:\n");
    for (int j = 0; j < tags[i].num_attributes; j++) {
      printf("%s: %s\n", tags[i].attributes[j][0], tags[i].attributes[j][1]);
    }
    printf("\n");
  }

  // Exit the program
  return 0;
}