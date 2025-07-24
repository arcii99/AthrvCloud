//FormAI DATASET v1.0 Category: Log analysis ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    char line[256];

    if (file == NULL) {
        printf("Error: %s could not be opened.\n", filename);
        exit(1);
    }

    int total_requests = 0;
    int successful_requests = 0;
    int redirect_requests = 0;
    int unsuccessful_requests = 0;
    int error_400 = 0;
    int error_401 = 0;
    int error_404 = 0;

    while (fgets(line, sizeof(line), file)) {
        char *request_type = strtok(line, " ");
        char *request_path = strtok(NULL, " ");
        char *status_code = strtok(NULL, " ");

        if (strcmp(request_type, "GET") == 0) {
            total_requests++;

            if (strcmp(status_code, "200") == 0) {
                successful_requests++;
            } else if (strcmp(status_code, "301") == 0 || strcmp(status_code, "302") == 0) {
                redirect_requests++;
            } else {
                unsuccessful_requests++;

                if (strcmp(status_code, "400") == 0) {
                    error_400++;
                } else if (strcmp(status_code, "401") == 0) {
                    error_401++;
                } else if (strcmp(status_code, "404") == 0) {
                    error_404++;
                }
            }
        }
    }

    printf("Total requests: %d\n", total_requests);
    printf("Successful requests: %d\n", successful_requests);
    printf("Redirect requests: %d\n", redirect_requests);
    printf("Unsuccessful requests: %d\n", unsuccessful_requests);
    printf("400 errors: %d\n", error_400);
    printf("401 errors: %d\n", error_401);
    printf("404 errors: %d\n", error_404);

    fclose(file);
    return 0;
}