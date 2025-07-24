//FormAI DATASET v1.0 Category: Text Summarizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1024

// Function to recursively summarize the text
char* summarize(char* text, int words) {

    char* summary = (char*) malloc(SIZE * sizeof(char));

    int count = 0;
    int i = 0;
    int j = 0;
    int length = strlen(text);

    while (isspace(text[i])) {
        i++;
    }

    if (i < length && count < words) {

        // Add the first word of the sentence
        while (!isspace(text[i]) && count < words) {
            summary[j++] = text[i++];
            count++;
        }

        // Recursively summarize the rest of the text
        char* rest = summarize(&text[i], words - count);
        strcat(summary, rest); 
        free(rest);

    } else {
        summary[0] = '\0';
    }

    return summary;
}

int main() {
    char text[SIZE] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec ut dictum arcu. Aliquam erat volutpat. Nullam facilisis, mi vitae pretium hendrerit, risus leo maximus nulla, in interdum ex risus nec metus. Nam bibendum, massa sit amet pretium malesuada, lacus velit elementum odio, ut tempor velit est nec urna. Morbi pretium nunc a mauris aliquet, vitae laoreet tellus hendrerit. Suspendisse ultricies cursus nulla, faucibus venenatis magna. Pellentesque at ultrices lectus, id maximus mi. Curabitur vel pellentesque justo. Nam placerat lectus augue, et consectetur mauris facilisis ultricies.";

    char* summary = summarize(text, 20);
    printf("%s\n", summary);
    free(summary);

    return 0;
}