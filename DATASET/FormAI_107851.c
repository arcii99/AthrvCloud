//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define HTML tags
const char *HTML_OPEN_TAG = "<";
const char *HTML_CLOSE_TAG = ">";
const char *HTML_COMMENT_OPEN = "<!--";
const char *HTML_COMMENT_CLOSE = "-->";

// Define maximum string length
const int MAX_CHAR = 1000;

// Main function
int main() {
    // Prompt the user to enter an HTML file
    printf("Please enter the name of the HTML file: ");
    char file_name[MAX_CHAR];
    fgets(file_name, MAX_CHAR, stdin);

    // Remove newline character from file name
    file_name[strcspn(file_name, "\n")] = 0;

    // Open the HTML file for reading
    FILE *file = fopen(file_name, "r");

    if (file == NULL) {
        printf("File could not be opened.\n");
        return 1;
    }

    // Read the contents of the HTML file
    char html_content[MAX_CHAR];
    fgets(html_content, MAX_CHAR, file);

    // Remove newline character from HTML content
    html_content[strcspn(html_content, "\n")] = 0;

    // Close the HTML file
    fclose(file);

    // Initialize counters for open and close tags
    int open_tags = 0;
    int close_tags = 0;

    // Loop through the HTML content
    for (int i = 0; i < strlen(html_content); i++) {
        // If an open tag is found, increase the open tag counter
        if (strncmp(&html_content[i], HTML_OPEN_TAG, 1) == 0) {
            open_tags++;
        }
        // If a close tag is found, increase the close tag counter
        else if (strncmp(&html_content[i], HTML_CLOSE_TAG, 1) == 0) {
            close_tags++;
        }
        // If an HTML comment is found, skip over it
        else if (strncmp(&html_content[i], HTML_COMMENT_OPEN, strlen(HTML_COMMENT_OPEN)) == 0) {
            i += strlen(HTML_COMMENT_OPEN);
            int j = i;
            while (j < strlen(html_content)) {
                if (strncmp(&html_content[j], HTML_COMMENT_CLOSE, strlen(HTML_COMMENT_CLOSE)) == 0) {
                    i = j + strlen(HTML_COMMENT_CLOSE) - 1;
                    break;
                }
                j++;
            }
        }
    }

    // Determine if HTML content is valid
    if (open_tags == close_tags) {
        printf("Valid HTML file.\n");
    }
    else if (open_tags > close_tags) {
        printf("Missing %d close tags.\n", open_tags - close_tags);
    }
    else {
        printf("Missing %d open tags.\n", close_tags - open_tags);
    }

    return 0;
}