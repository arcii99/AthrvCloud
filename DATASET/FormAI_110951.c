//FormAI DATASET v1.0 Category: HTML beautifier ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printIndentation(int indentation);

void formatHTML(char *html, int indentation) {
    // Check if the string is empty
    if (strlen(html) == 0) {
        printf("The given HTML string is empty!\n");
        return;
    }

    char *openingTags[] = {"html", "head", "title", "body", "h1", "p"};
    char *closingTags[] = {"html", "head", "title", "body", "h1", "p"};
    int numTags = 6;

    // Find the first opening angle bracket
    char *openingBracketPtr = strchr(html, '<');
    // Find the first closing angle bracket
    char *closingBracketPtr = strchr(html, '>');

    // If either brackets are not found, it means there are no HTML tags in the string
    if (openingBracketPtr == NULL || closingBracketPtr == NULL) {
        printf("%s\n", html);
        return;
    }

    // Print the first part of the string before the first opening angle bracket
    int openingBracketIndex = openingBracketPtr - html;
    char *beforeOpeningBracket = malloc(openingBracketIndex + 1);
    strncpy(beforeOpeningBracket, html, openingBracketIndex);
    beforeOpeningBracket[openingBracketIndex] = '\0';
    printf("%s\n", beforeOpeningBracket);

    // Print the opening tag
    int closingBracketIndex = closingBracketPtr - html;
    int numSpaces = indentation * 4;
    char *tagName = malloc(closingBracketIndex - openingBracketIndex);
    strncpy(tagName, openingBracketPtr + 1, closingBracketIndex - openingBracketIndex - 1);
    tagName[closingBracketIndex - openingBracketIndex - 1] = '\0';
    printIndentation(indentation);
    printf("<%s>\n", tagName);

    // Find the matching closing tag
    char *matchingClosingTag = NULL;
    for (int i = 0; i < numTags; i++) {
        if (strcmp(openingTags[i], tagName) == 0) {
            matchingClosingTag = closingTags[i];
            break;
        }
    }

    // Recursively format the content between the opening and closing tag
    char *contentStartPtr = closingBracketPtr + 1;
    char *matchingClosingTagPtr;
    do {
        matchingClosingTagPtr = strstr(contentStartPtr, matchingClosingTag);
        if (matchingClosingTagPtr != NULL) {
            int contentEndIndex = matchingClosingTagPtr - html;
            char *content = malloc(contentEndIndex - (closingBracketIndex + 1));
            strncpy(content, html + closingBracketIndex + 1, contentEndIndex - (closingBracketIndex + 1));
            content[contentEndIndex - (closingBracketIndex + 1)] = '\0';
            formatHTML(content, indentation + 1);
            free(content);

            // Print the closing tag
            printIndentation(indentation);
            printf("</%s>\n", matchingClosingTag);
            
            // Update contentStartPtr to the character after the matching closing tag
            contentStartPtr = matchingClosingTagPtr + strlen(matchingClosingTag) + 1;
        }
    } while (matchingClosingTagPtr != NULL);

    // Print the last part of the string after the last matching closing tag
    int contentEndIndex = strlen(html);
    char *lastContent = malloc(contentEndIndex - (closingBracketIndex + 1));
    strncpy(lastContent, html + closingBracketIndex + 1, contentEndIndex - (closingBracketIndex + 1));
    lastContent[contentEndIndex - (closingBracketIndex + 1)] = '\0';
    formatHTML(lastContent, indentation + 1);
    free(lastContent);
    
    // Free allocated memory
    free(beforeOpeningBracket);
    free(tagName);
}

void printIndentation(int indentation) {
    for (int i = 0; i < indentation; i++) {
        printf("    ");
    }
}

int main() {
    char *html = "<html>\n<head>\n<title>Sample page</title>\n</head>\n<body>\n<h1>Welcome to my page</h1>\n<p>This is some sample text.\nIt's not very exciting, but it'll have to do.</p>\n</body>\n</html>";
    formatHTML(html, 0);

    return 0;
}