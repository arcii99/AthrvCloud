//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 200000
#define MAX_LINE_SIZE 1000

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_SIZE], buffer[MAX_FILE_SIZE];
    int i, length, virus_count = 0;
    char *viruses[] = {"Trojan", "Ransomware", "Worm", "Spyware", "Adware"};
    
    if(argc < 2){
        printf("Usage: %s [file name]\n", argv[0]);
        exit(1);
    }
    
    file = fopen(argv[1], "r");
    if(file == NULL){
        printf("Error: Unable to open %s\n", argv[1]);
        exit(1);
    }
    
    /* Read entire file into buffer */
    fgets(line, MAX_LINE_SIZE, file);
    while(!feof(file) && strlen(buffer) + strlen(line) < MAX_FILE_SIZE){
        strcat(buffer, line);
        fgets(line, MAX_LINE_SIZE, file);
    }
    
    fclose(file);
    
    /* Scan buffer for viruses */ 
    for(i = 0; i < 5; i++){
        length = strlen(viruses[i]);
        if(strcasestr(buffer, viruses[i]) != NULL){
            printf("Virus found: %s\n", viruses[i]);
            virus_count++;
        }
    }
    
    if(virus_count == 0){
        printf("File appears to be clean!\n");
    }
    
    return 0;
}