//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Romeo, oh Romeo, wherefore art thou code?
// Here I am Juliet, with an XML parser in tow


char* parseTag(char* xml, char* tag) {
    char* tagStart = strstr(xml, "<");
    char* tagEnd = strstr(tagStart, ">");
    char* tagContent = (char*) malloc(sizeof(char) * strlen(tagEnd) + 1);
    strcpy(tagContent, tagEnd + 1);
    char* endTagStart = (char*) malloc(sizeof(char) * strlen(tag) + 3);
    sprintf(endTagStart, "</%s>", tag);
    char* endTagEnd = strstr(tagContent, endTagStart);
    *endTagEnd = '\0';
    return tagContent;
}

int main() {

    char* xml = "<myXML><title>Example XML</title><body><paragraph>This is an example XML for Romeo and Juliet</paragraph></body></myXML>";

    char* titleTag = parseTag(xml, "title"); // Romeo, I have parsed the title tag!
    char* bodyTag = parseTag(xml, "body"); // And I have parsed the body tag too!
    char* paragraphTag = parseTag(bodyTag, "paragraph"); // And the paragraph tag as well! My code is complete!

    printf("%s\n", titleTag);
    printf("%s\n", paragraphTag);

    free(titleTag);
    free(bodyTag);
    free(paragraphTag);

    return 0;
}