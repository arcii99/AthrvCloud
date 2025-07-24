//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void scan_file(char* filename){
    char command[1000];
    sprintf(command, "clang -S -o - %s | grep -v '^$' | grep -v '^#' > output.s", filename);
    system(command);
    FILE* file = fopen("output.s", "r");
    char buffer[1000];
    while(fgets(buffer, sizeof(buffer), file)){
        if(strstr(buffer, "system") != NULL){
            printf("Potential virus detected in file %s. System command found.\n", filename);
            return;
        }
    }
    fclose(file);
    remove("output.s");
    printf("Scan completed. No virus detected in file %s.\n", filename);
}

int main(){
    char filename[200];
    printf("Enter filename to scan: ");
    scanf("%s", filename);
    scan_file(filename);
    return 0;
}