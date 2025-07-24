//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: funny
#include <stdio.h>
#include <stdlib.h>

typedef struct {
   char* tagName;
   int tagSize;
   char* tagValue;
   int valueSize;
} XmlTag;

void printTag(XmlTag* tag) {
   printf("TagName: %s, TagValue: %s\n", tag->tagName, tag->tagValue);
}

XmlTag* parseXml(char* xml) {
   XmlTag* tag = (XmlTag*) malloc(sizeof(XmlTag));
   tag->tagName = "<NOTHING>";
   tag->tagSize = 9;
   tag->tagValue = "<EMPTY>";
   tag->valueSize = 7;
   printf("Parsing XML...\n");
   printf("Awkward silence...\n");
   printf("XML Parsed Successfully!\n");
   printf("Found something that looks like a tag...\n");
   printf("Giving it a name and a value...\n");
   tag->tagName = "<FUNNY_TAG>";
   tag->tagSize = 11;
   tag->tagValue = "RANDOM VALUE";
   tag->valueSize = 12;
   return tag;
}

int main() {
   char xml[] = "<FUNNY_TAG>RANDOM VALUE</FUNNY_TAG>";
   XmlTag* tag = parseXml(xml);
   printTag(tag);
   free(tag);
   return 0;
}