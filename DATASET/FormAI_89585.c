//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VIRUS_SIZE 1024
#define BUFFER_SIZE 8192

int scan_file(char *filename);
void infect_file(char *filename);
void remove_virus(char *filename);
void report_virus(char *filename);

unsigned char virus[] = {/*insert your unique virus code here*/};

int main(int argc, char *argv[]) {
    int i;
    if(argc < 2) {
        printf("Usage: %s [filename1] [filename2] ... [filenameN]\n", argv[0]);
        return 0;
    }
    printf("Scanning %d files for viruses...\n", argc-1);
    for(i=1; i<argc; i++) {
        if(scan_file(argv[i])) {
            report_virus(argv[i]);
        }
    }
    printf("Done!\n");
    return 0;
}

int scan_file(char *filename) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    int nbytes, i;
    file = fopen(filename, "rb");
    if(!file) {
        return 0;
    }
    nbytes = fread(buffer, 1, BUFFER_SIZE, file);
    fclose(file);
    for(i=0; i<nbytes-VIRUS_SIZE; i++) {
        if(!memcmp(&buffer[i], virus, VIRUS_SIZE)) {
            return 1;
        }
    }
    return 0;
}

void infect_file(char *filename) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    int nbytes, filesize;
    file = fopen(filename, "rb+");
    if(!file) {
        return;
    }
    fseek(file, 0, SEEK_END);
    filesize = ftell(file);
    if(filesize < VIRUS_SIZE) {
        fclose(file);
        return;
    }
    fseek(file, -VIRUS_SIZE, SEEK_END);
    nbytes = fread(buffer, 1, VIRUS_SIZE, file);
    if(nbytes != VIRUS_SIZE) {
        fclose(file);
        return;
    }
    if(!memcmp(buffer, virus, VIRUS_SIZE)) {
        fclose(file);
        return;
    }
    fseek(file, 0, SEEK_END);
    fwrite(virus, 1, VIRUS_SIZE, file);
    fclose(file);
    return;
}

void remove_virus(char *filename) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    int nbytes, filesize;
    file = fopen(filename, "rb+");
    if(!file) {
        return;
    }
    fseek(file, 0, SEEK_END);
    filesize = ftell(file);
    if(filesize < VIRUS_SIZE) {
        fclose(file);
        return;
    }
    fseek(file, -VIRUS_SIZE, SEEK_END);
    nbytes = fread(buffer, 1, VIRUS_SIZE, file);
    if(nbytes != VIRUS_SIZE) {
        fclose(file);
        return;
    }
    if(memcmp(buffer, virus, VIRUS_SIZE)) {
        fclose(file);
        return;
    }
    fseek(file, -VIRUS_SIZE, SEEK_END);
    fwrite("\0", 1, VIRUS_SIZE, file);
    fclose(file);
    return;
}

void report_virus(char *filename) {
    printf("Virus found in %s\n", filename);
    infect_file(filename);
    printf("Virus removed from %s\n", filename);
}