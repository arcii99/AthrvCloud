//FormAI DATASET v1.0 Category: HTML beautifier ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *remove_comments(char *html) {
    // Remove HTML comments
    char *clean_html = malloc(strlen(html) + 1);
    int i = 0, j = 0;
    while (html[i] != '\0') {
        if (html[i] == '<' && html[i + 1] == '!') {
            while (html[i] != '-' || html[i + 1] != '-' || html[i + 2] != '>') {
                i++;
            }
            i += 3;
            continue;
        }
        clean_html[j] = html[i];
        i++;
        j++;
    }
    clean_html[j] = '\0';
    return clean_html;
}

char *remove_whitespace(char *html) {
    // Remove unnecessary whitespace
    char *clean_html = malloc(strlen(html) + 1);
    int i = 0, j = 0;
    while (html[i] != '\0') {
        if (html[i] == ' ' && (html[i - 1] == '>' || html[i + 1] == '<')) {
            i++;
            continue;
        }
        clean_html[j] = html[i];
        i++;
        j++;
    }
    clean_html[j] = '\0';
    return clean_html;
}

void uppercase_tags(char *html) {
    // Uppercase all HTML tags
    int i = 0;
    while (html[i] != '\0') {
        if (html[i] == '<') {
            i++;
            while (html[i] != '>') {
                html[i] = toupper(html[i]);
                i++;
            }
        }
        i++;
    }
}

void beautify_html(char *html) {
    char *clean_html;
    clean_html = remove_comments(html);
    free(html);
    html = remove_whitespace(clean_html);
    free(clean_html);
    uppercase_tags(html);
    printf("%s", html);
    free(html);
}

int main() {
    char *html = "<html>  <head><title>Hello, World!</title></head><body><h1>Welcome to my website!</h1><p>This is the homepage.</p></body></HTML>";
    beautify_html(html);
    return 0;
}