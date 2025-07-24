//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a struct to hold the parsed data */
typedef struct {
  char *name;
  char *value;
} XMLAttribute;

/* Define a function to parse a single attribute */
XMLAttribute *parse_attribute(char *attr) {
  /* Allocate memory for the attribute struct */
  XMLAttribute *new_attr = (XMLAttribute*) malloc(sizeof(XMLAttribute));

  /* Use strtok to split the attribute into name and value */
  char *name = strtok(attr, "=");
  char *value = strtok(NULL, "=");

  /* Strip any quotes from the value string */
  value++;
  value[strlen(value) - 1] = '\0';

  /* Save the attribute data to the struct */
  new_attr->name = strdup(name);
  new_attr->value = strdup(value);

  /* Return the struct pointer */
  return new_attr;
}

/* Define a function to parse a single XML tag */
void parse_tag(char *tag) {
  /* Allocate memory for the tag name */
  char *tag_name = (char*) malloc(strlen(tag)+1);

  /* Use strtok to split the tag into name and attribute string */
  strcpy(tag_name, strtok(tag, " "));
  char *attr_str = strtok(NULL, ">");

  /* Print the opening tag */
  printf("<%s", tag_name);

  /* If there are attributes, parse and print them */
  if (attr_str) {
    /* Use strtok to split the attribute string into individual attributes */
    char *attr = strtok(attr_str, " ");

    /* Parse each attribute */
    while (attr) {
      XMLAttribute *new_attr = parse_attribute(attr);

      /* Print the attribute */
      printf(" %s=\"%s\"", new_attr->name, new_attr->value);

      /* Free the memory used by the attribute struct */
      free(new_attr->name);
      free(new_attr->value);
      free(new_attr);

      /* Move on to the next attribute */
      attr = strtok(NULL, " ");
    }
  }

  /* Print the closing bracket for the opening tag */
  printf(">");

  /* Free the memory used by the tag name */
  free(tag_name);
}

int main() {
  /* Define a test string containing an XML tag with attributes */
  char *test_xml = "<animal type=\"cat\" name=\"Fluffy\">";

  /* Parse the tag and print it */
  parse_tag(test_xml);
  printf("\n");

  /* Return 0 to indicate success */
  return 0;
}