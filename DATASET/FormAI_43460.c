//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char filename[128];
    printf("\nEnter the filename to scan: ");
    scanf("%s", filename);
    FILE *fp;
    unsigned char *buffer;
    long fileLen;
    
    fp = fopen(filename, "rb");
    if (!fp) {
        printf("Unable to open file '%s'\n", filename);
        return 1;
    }
    
    fseek(fp, 0, SEEK_END);
    fileLen= ftell(fp);
    rewind(fp);

    buffer = (unsigned char *) malloc((fileLen+1)*sizeof(unsigned char));
    if (!buffer) {
        fclose(fp);
        printf("Memory error!");
        return 1;
    }

    fread(buffer, fileLen, 1, fp);
    fclose(fp);
    int i=0;
    if('\x89'==buffer[0] && 'P'==buffer[1] && 'N'==buffer[2] && 'G'==buffer[3]) {
        printf("The file '%s' is a PNG file, which is safe.\n",filename);
    } else if('\xFF'==buffer[0] && '\xD8'==buffer[1] && '\xFF'==buffer[2] && ('\xE0' <= buffer[3] && buffer[3] <= '\xEF')) {
        printf("The file '%s' is a JPEG file, which may contain virus.\n",filename);
    } else {
        printf("Cannot determine the type of file '%s' with header bytes:\n",filename);
        for(i=0;i<8;i++) {
            printf("%x",buffer[i]);
        }
        printf("\n");
    }
    free(buffer);
    return 0;
}