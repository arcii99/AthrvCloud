//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

/* function to extract metadata */
void extract_metadata(char filename[]) {
    FILE *fp;
    char ch;

    /* open the file */
    fp = fopen(filename, "r");

    /* read the file character by character */
    while((ch = fgetc(fp)) != EOF) {

        /* check for metadata tag */
        if(ch == '@') {
            printf("\nMetadata found: ");
            while((ch = fgetc(fp)) != '|') {
                printf("%c", ch);
            }
        }
    }

    /* close the file */
    fclose(fp);
}

int main() {

    /* file to extract metadata from */
    char filename[] = "sample.txt";

    /* extract metadata from the file */
    extract_metadata(filename);

    return 0;
}