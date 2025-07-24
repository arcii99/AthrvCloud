//FormAI DATASET v1.0 Category: Log analysis ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    if (argc < 2){
        printf("Error: no file supplied. Program terminated.\n");
        exit(0);
    }

    FILE *log_file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    log_file = fopen(argv[1], "r");
    if (log_file == NULL){
        printf("Error: cannot open file %s. Program terminated.\n", argv[1]);
        exit(0);
    }

    int num_lines = 0; 
    int num_get_requests = 0;
    int num_post_requests = 0;
    int num_total_requests = 0;
    char *most_requested_page = "";
    int num_requests_most_requested_page = 0;
    char *current_page = "";
    int num_requests_current_page = 0;

    printf("Analyzing file %s...\n", argv[1]);
    while ((read = getline(&line, &len, log_file)) != -1) {
        num_lines++;

        char *token;
        token = strtok(line, " ");
        if (token != NULL && strcmp(token, "GET") == 0){
            num_get_requests++;
        }
        else if (token != NULL && strcmp(token, "POST") == 0){
            num_post_requests++;
        }

        token = strtok(NULL, " ");
        if (token != NULL){
            num_total_requests++;

            if (strcmp(token, most_requested_page) == 0){
                num_requests_most_requested_page++;
            }
            else{
                if (strlen(current_page) > 0){
                    printf("%s: %d requests\n", current_page, num_requests_current_page);
                }
                current_page = token;
                num_requests_current_page = 1;
            }

            if (num_requests_current_page > num_requests_most_requested_page){
                most_requested_page = current_page;
                num_requests_most_requested_page = num_requests_current_page;
            }
        }
    }

    printf("File %s analyzed successfully.\n", argv[1]);
    printf("Total number of lines: %d\n", num_lines);
    printf("Total number of requests: %d\n", num_total_requests);
    printf("Number of GET requests: %d\n", num_get_requests);
    printf("Number of POST requests: %d\n", num_post_requests);
    printf("Most requested page: %s (%d requests)\n", most_requested_page, num_requests_most_requested_page);

    fclose(log_file);
    if (line){
        free(line);
    }

    return 0;
}