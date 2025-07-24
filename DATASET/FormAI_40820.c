//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sanitize(char *url) {
    int i = 0, j = 0;
    char out[strlen(url)+1];

    // convert url to lowercase
    for (i=0; i < strlen(url); i++) {
        url[i] = tolower(url[i]);
    }

    // copy url to out, only keeping a-z, 0-9, and _
    for (i=0; i < strlen(url); i++) {
        if (isalnum(url[i]) || url[i] == '_') {
            out[j] = url[i];
            j++;
        }
    }
    out[j] = '\0';
    strcpy(url, out);

    // replace multiple _ with just one _
    for (i=0; i < strlen(url); i++) {
        if (url[i] == '_') {
            while (url[i+1] == '_') {
                memmove(&url[i+1], &url[i+2], strlen(url)-i);
            }
        }
    }

    // remove trailing _
    while (url[strlen(url)-1] == '_') {
        url[strlen(url)-1] = '\0';
    }
}

void sanitize_recursive(char *url, char *out, int i, int j) {
    if (i == strlen(url)) { // base case
        out[j] = '\0';
        strcpy(url, out);
        return;
    }

    // recursive case
    if (isalnum(url[i]) || url[i] == '_') {
        out[j] = url[i];
        j++;
    }
    sanitize_recursive(url, out, i+1, j);
}

int main() {
    char url[100] = "hTTpS://wWW.EXisTinG_weBSiTe.COm/prOduct_12__3_";
    printf("Original URL: %s\n", url);

    // non-recursive version
    sanitize(url);
    printf("Sanitized URL (non-recursive): %s\n", url);

    // recursive version
    char out[strlen(url)+1];
    sanitize_recursive(url, out, 0, 0);
    printf("Sanitized URL (recursive): %s\n", url);

    return 0;
}