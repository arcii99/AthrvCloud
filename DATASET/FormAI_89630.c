//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024     //Maximum length of each csv line
#define MAX_FIELDS 100        //Maximum number of fields in csv file

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: csvreader <filename>\n");
        exit(1);
    }

    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");    //Opening file in reading mode

    if (!fp) {
        printf("Could not open file %s\n", filename);
        exit(1);
    }

    char line[MAX_LINE_LEN];
    char *fields[MAX_FIELDS];
    int num_fields;

    while (fgets(line, MAX_LINE_LEN, fp)) {   //Read each line from csv file

        num_fields = 0;

        char *field = strtok(line, ",");
        while (field != NULL) {    //Tokenize each field of the line using ',' as delimiter
            fields[num_fields++] = field;
            field = strtok(NULL, ",");
        }

        for (int i = 0; i < num_fields; i++) {
            printf("%s, ", fields[i]);  //Print each field
        }

        printf("\n");
    }

    fclose(fp);   //Closing file
    return 0;
}