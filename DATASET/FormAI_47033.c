//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* extract_metadata(char* filename){
    FILE* file = fopen(filename, "r");
    if(file == NULL){
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char* metadata = malloc(sizeof(char) * 100);
    char line[200];
    while(fgets(line, sizeof(line), file)){
        if(strstr(line, "metadata")){
            strcpy(metadata, line);
            break;
        }
    }

    fclose(file);
    return metadata;
}

int main(){
    char* filename = "example.mp3";
    char* metadata = extract_metadata(filename);
    if(metadata[0] == '\0'){
        printf("No metadata found in %s", filename);
    }else{
        printf("Metadata found in %s: %s", filename, metadata);
    }
    free(metadata);
    return 0;
}