//FormAI DATASET v1.0 Category: Log analysis ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* function prototype */
void analyze_logs(const char *filename);

int main(int argc, char **argv) {
   if (argc != 2) {
       printf("ERROR: Invalid number of arguments.\n");
       printf("Usage: %s <filename>\n", argv[0]);
       return EXIT_FAILURE;
   } else {
       analyze_logs(argv[1]); // call the log analysis function
       return EXIT_SUCCESS;
   }
}

void analyze_logs(const char *filename) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int error_count = 0, warning_count = 0, info_count = 0, debug_count = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("ERROR: Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        char *tok = strtok(line, " ");
        while (tok != NULL) {
            if (strcmp(tok, "ERROR:") == 0) {
                error_count++;
                break;
            } else if (strcmp(tok, "WARNING:") == 0) {
                warning_count++;
                break;
            } else if (strcmp(tok, "INFO:") == 0) {
                info_count++;
                break;
            } else if (strcmp(tok, "DEBUG:") == 0) {
                debug_count++;
                break;
            } else {
                break;
            }
        }
    }

    printf("\nLog analysis report for file %s:\n", filename);
    printf("--------------------------------------\n");
    printf("Number of ERROR logs: %d\n", error_count);
    printf("Number of WARNING logs: %d\n", warning_count);
    printf("Number of INFO logs: %d\n", info_count);
    printf("Number of DEBUG logs: %d\n", debug_count);
    
    fclose(fp);
    if (line) {
        free(line);
    }
}