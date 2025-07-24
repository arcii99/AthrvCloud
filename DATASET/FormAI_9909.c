//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    
    if(argc < 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        exit(1);
    }
    
    char *filename = argv[1];
    char virus_signature[] = "BADvirus";
    FILE *fp = fopen(filename, "rb");
    
    if(!fp) {
        printf("File not found or could not be opened.\n");
        exit(1);
    }
    
    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    rewind(fp);
    
    char *buffer = (char*)malloc(sizeof(char)*(filesize+1));
    fread(buffer, 1, filesize, fp);
    fclose(fp);
    buffer[filesize] = '\0';
    
    if(strstr(buffer, virus_signature)) {
        printf("WARNING: Virus detected!\n");
    } else {
        printf("File is clean!\n");
    }
    
    free(buffer);
    return 0;
}