//FormAI DATASET v1.0 Category: HTML beautifier ; Style: grateful
#include <stdio.h>
#include <string.h>

int indent = 0;
char output[100000];

void printTabs() {
    int i;
    for (i = 0; i < indent; i++) {
        strcat(output, "    ");
    }
}

int main() {
    char input[100000];
    FILE *fptr;

    if ((fptr = fopen("input.html", "r")) == NULL) {
        printf("Error opening file.");
        return 1;
    }

    fgets(input, 100000, fptr);
    strcat(output, input);

    while (fgets(input, 100000, fptr)) {
        if (strstr(input, "<html>")) {
            printTabs();
            strcat(output, "<html>\n");
            indent++;
        } else if (strstr(input, "</html>")) {
            indent--;
            printTabs();
            strcat(output, "</html>\n");
        } else if (strstr(input, "<body>")) {
            printTabs();
            strcat(output, "<body>\n");
            indent++;
        } else if (strstr(input, "</body>")) {
            indent--;
            printTabs();
            strcat(output, "</body>\n");
        } else if (strstr(input, "<head>")) {
            printTabs();
            strcat(output, "<head>\n");
            indent++;
        } else if (strstr(input, "</head>")) {
            indent--;
            printTabs();
            strcat(output, "</head>\n");
        } else {
            printTabs();
            strcat(output, input);
        }
    }

    fclose(fptr);

    printf("%s", output);

    return 0;
}