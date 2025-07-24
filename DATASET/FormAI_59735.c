//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 1024

int main() {

    char input[MAX], word[MAX], key[MAX][MAX], c;
    int i, j, count, k = 0;
    FILE *keys;

    keys = fopen("keys.txt", "r");

    if (keys == NULL) {
        printf("Error in opening file");
        exit(0);
    }

    while ((c = fgetc(keys)) != EOF) {
        if (c == '\n') {
            word[k] = '\0';
            strcpy(key[count++], word);
            k = 0;
        } else {
            word[k++] = c;
        }
    }

    while (1) {

        printf("Enter input:");
        fgets(input, sizeof(input), stdin);

        for (i = 0; input[i] != '\0'; i++) {
            input[i] = toupper(input[i]);
        }

        for (i = 0; i < count; i++) {
            if (strstr(input, key[i]) != NULL) {
                printf("Intrusion detected in input\n");
                exit(0);
            }
        }
    }

    return 0;
}