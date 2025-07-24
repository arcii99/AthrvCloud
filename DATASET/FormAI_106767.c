//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: funny
#include <stdio.h>

int main() {

  printf("Welcome to the XML Parser!\n");
  printf("I hope you brought your sense of humor because XML can be a real pain...\n");

  FILE* xml_file = fopen("example.xml", "r");

  if (!xml_file) {
    printf("Cannot open XML file! Aborting mission...\n");
    return 1;
  }

  char line[100];
  int indent = 0;
  while (fgets(line, sizeof(line), xml_file)) {

    for (int i = 0; i < indent; i++) {
      printf("    ");
    }
    printf("%s", line);

    if (strstr(line, "<") != NULL && strstr(line, "</") == NULL) {
      indent++;
    }
    else if (strstr(line, "<") != NULL && strstr(line, "</") != NULL) {
      indent--;
    }
  }

  fclose(xml_file);

  printf("\nTa daa! Your XML file has been parsed. Wasn't that fun?\n");

  return 0;
}