//FormAI DATASET v1.0 Category: Browser Plugin ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the plugin function
void applyRandomColor(char* html) {
    srand(time(NULL)); // Seed the random number generator with the current time
    char* color = malloc(sizeof(char) * 7); // Allocate memory for the hexadecimal color string

    // Generate a random hexadecimal color
    for (int i = 0; i < 6; i++) {
        int randomDigit = rand() % 16;
        if (randomDigit < 10) {
            color[i] = '0' + randomDigit;
        } else {
            color[i] = 'A' + (randomDigit - 10);
        }
    }
    color[6] = '\0'; // Add null terminator to the color string

    // Apply the random color as the background color of the HTML
    char* tagStart = strstr(html, "<html");
    char tagEnd = '>';
    char* bodyStart = strstr(html, "<body");
    char bodyEnd = '>';
    char* bgColorAttr = "style=\"background-color: #";
    int tagStartIndex = tagStart - html;
    int bodyStartIndex = bodyStart - html;

    // Insert the style attribute with the random color at the correct position
    if (tagStartIndex < bodyStartIndex) { // The <html> tag appears before the <body> tag
        sprintf(html, "%.*s%s%s%.*s", tagStartIndex, html, bgColorAttr, color, tagStartIndex + 5, html + tagStartIndex + 5);
    } else { // The <body> tag appears before the <html> tag
        sprintf(html, "%.*s%s%s%.*s", bodyStartIndex, html, bgColorAttr, color, bodyStartIndex + 5, html + bodyStartIndex + 5);
    }

    free(color); // Free the allocated memory for the color string
}

// Test the plugin
int main() {
    char* html = "<html><head><title>Test Page</title></head><body><p>Random background color plugin test</p></body></html>";
    printf("Original HTML:\n%s\n\n", html);
    applyRandomColor(html);
    printf("HTML after plugin applied:\n%s\n", html);
    return 0;
}