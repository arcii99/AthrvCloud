//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct metadata {
    char* key;
    char* value;
};

void extract_metadata(char* str, struct metadata** md, int *n) {
    int len = strlen(str);
    char* key;
    char* value;
    int i = 0;
    while (i < len) {
        key = (char*) malloc(sizeof(char)*50);
        value = (char*) malloc(sizeof(char)*50);
        int j = i;
        while (str[j] != ':') {
            key[j-i] = str[j];
            j++;
        }
        key[j-i] = '\0';
        j++; // skip ':'
        int k = j;
        while (str[k] != '\n' && k < len) {
            value[k-j] = str[k];
            k++;
        }
        value[k-j] = '\0';
        md[*n] = (struct metadata*) malloc(sizeof(struct metadata));
        md[*n]->key = key;
        md[*n]->value = value;
        (*n)++;
        i = k+1;
    }
}

void print_metadata(struct metadata** md, int n) {
    int i;
    for (i=0; i<n; i++) {
        printf("%s: %s\n", md[i]->key, md[i]->value);
    }
}

int main() {
    char* str = "Title: The Catcher in the Rye\nAuthor: J. D. Salinger\nYear: 1951\n";
    int n = 0;
    struct metadata** md = (struct metadata**) malloc(sizeof(struct metadata*)*10);
    extract_metadata(str, md, &n);
    printf("Extracted Metadata:\n");
    print_metadata(md, n);
    return 0;
}