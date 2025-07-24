//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char virus[] = "malicious";
    char *file = malloc(100);
    printf("Enter the file name to scan: ");
    scanf("%s", file);
    FILE *fptr = fopen(file, "rb");
    if(fptr == NULL) {
        printf("Could not open file.");
        exit(1);
    }
    int found = 0;
    char buffer[1024];
    while(!feof(fptr)) {
        fread(buffer, 1, 1024, fptr);
        if(strstr(buffer, virus) != NULL) {
            printf("Virus found in %s\n", file);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("%s is clean of viruses\n", file);
    }
    fclose(fptr);
    free(file);
    return 0;
}