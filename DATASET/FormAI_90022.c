//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: standalone
#include <stdio.h>

struct metadata {
    char author[50];
    char title[100];
    int year;
};

void extract_metadata(struct metadata *data, char *filename) {
    FILE *fp;
    char buffer[100];
    
    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    while(fgets(buffer, 100, fp)) {
        if(strncmp(buffer, "Author: ", 8) == 0) {
            sscanf(buffer + 8, "%s", data->author);
        }
        else if(strncmp(buffer, "Title: ", 7) == 0) {
            sscanf(buffer + 7, "%[^\n]s", data->title);
        }
        else if(strncmp(buffer, "Year: ", 6) == 0) {
            sscanf(buffer + 6, "%d", &data->year);
        }
    }
    
    fclose(fp);
}

int main() {
    struct metadata data;
    char filename[20];
    
    printf("Enter filename: ");
    scanf("%s", filename);
    
    extract_metadata(&data, filename);
    
    printf("Author: %s\n", data.author);
    printf("Title: %s\n", data.title);
    printf("Year: %d\n", data.year);
    
    return 0;
}