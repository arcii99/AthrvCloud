//FormAI DATASET v1.0 Category: String manipulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

int main() {
    char juliet[] = "O Romeo, Romeo! wherefore art thou Romeo?";
    char romeo[] = "Here's the code, my dear Juliet: ";

    printf("%s\n", juliet);
    printf("%s\n", romeo);

    char code[100];

    // Romeo's response
    sprintf(code, "char* code = \"%s\";\n", juliet);
    strcat(romeo, code);

    // Juliet's reply
    char* token = strtok(juliet, " ");
    char juliet_code[100] = "";
    while (token != NULL) {
        strcat(juliet_code, token);
        strcat(juliet_code, "_");
        token = strtok(NULL, " ");
    }
    juliet_code[strlen(juliet_code) - 1] = '\0';
    sprintf(code, "printf(\"%s\\n\");\n", juliet_code);
    strcat(romeo, code);

    printf("%s", romeo);

    return 0;
}