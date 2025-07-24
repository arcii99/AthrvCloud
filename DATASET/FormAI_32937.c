//FormAI DATASET v1.0 Category: Data recovery tool ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXFILEPATH 256
#define MAXBUFFERSIZE 1024

int recoverData(char* filename);

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }

    if (!recoverData(argv[1])) {
        printf("Data couldn't be recovered.\n");
        return -1;
    }

    return 0;
}

int recoverData(char* filename) {

    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("File couldn't be opened.\n");
        return 0;
    }

    printf("File opened successfully.\n");

    char outfilename[MAXFILEPATH];
    memset(outfilename, 0, MAXFILEPATH);

    unsigned char buffer[MAXBUFFERSIZE];
    memset(buffer, 0, MAXBUFFERSIZE);

    int bytesRead = 0;
    int fileNum = 0;

    while ((bytesRead = fread(buffer, sizeof(char), MAXBUFFERSIZE, fp))) {
        sprintf(outfilename, "%s.%d", filename, ++fileNum);

        FILE* outfile = fopen(outfilename, "wb");
        if (!outfile) {
            printf("Output file couldn't be opened: %s.\n", outfilename);
            continue;
        }

        printf("Output file %s opened successfully.\n", outfilename);

        fwrite(buffer, sizeof(char), bytesRead, outfile);
        fclose(outfile);

        memset(outfilename, 0, MAXFILEPATH);
        memset(buffer, 0, MAXBUFFERSIZE);
    }

    fclose(fp);

    return 1;
}