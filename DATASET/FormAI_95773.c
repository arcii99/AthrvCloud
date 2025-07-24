//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: introspective
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

void parseXML(char* xml) {
  char tag[MAX_SIZE], attrib[MAX_SIZE], value[MAX_SIZE], c;
  int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0, flag = 0;
  printf("Parser Output:\n");
  while (xml[i]) {
    c = xml[i];
    if (c == '<') {
      j = i + 1;
      while (xml[j] != '>' && xml[j] != ' ') {
        tag[k++] = xml[j++];
      }
      tag[k] = '\0';
      if (xml[j] == ' ') {
        while (xml[j] != '>') {
          if (xml[j] == '=') {
            flag = 1;
          }
          if (flag == 0 && xml[j] != ' ') {
            attrib[l++] = xml[j];
          }
          if (xml[j] == '\"' && flag == 1) {
            m = j + 1;
            while (xml[m] != '\"') {
              value[n++] = xml[m++];
            }
            value[n] = '\0';
            flag = 0;
          }
          j++;
        }
        if (strlen(value) == 0) {
          printf("Error: Attribute '%s' of tag '%s' has no value.\n", attrib, tag);
        } else {
          printf("Tag: '%s', Attribute: '%s', Value: '%s'\n", tag, attrib, value);
        }
        k = 0;
        l = 0;
        n = 0;     
        memset(tag, 0, sizeof(tag));
        memset(attrib, 0, sizeof(attrib));
        memset(value, 0, sizeof(value));
      }
    }
    i++;
  }
}

int main() {
  char xml[MAX_SIZE] = "<book category='fiction'><title lang='en'>The Hitchhiker's Guide to the Galaxy</title><author>Douglas Adams</author><year>1979</year><price>12.99</price></book>";
  printf("Parser Input:\n%s\n", xml);
  parseXML(xml);
  return 0;
}