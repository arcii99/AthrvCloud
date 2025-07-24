//FormAI DATASET v1.0 Category: Log analysis ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure to hold Log file Data */
typedef struct LogData {
    char timestamp[20];
    char ip[16];
    char request[512];
    char responseCode[4];
} LogData;

/* Function to read log file and create LogData array */
LogData* readLogFile(char *filename, int *count) {
    FILE *file = fopen(filename, "r");
    char line[1024];
    int lineCount = 0;

    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    /* Count the number of lines in the file */
    while (fgets(line, sizeof(line), file)) {
        lineCount++;
    }

    /* Allocate memory for the LogData array */
    LogData *data = (LogData*) malloc(sizeof(LogData) * lineCount);
    if (data == NULL) {
        printf("Error allocating memory\n");
        return NULL;
    }

    /* Reset file pointer to beginning of file */
    fseek(file, 0, SEEK_SET);

    /* Parse each line of the file and populate LogData array */
    int i = 0;
    while (fgets(line, sizeof(line), file)) {
        /* Split each line into timestamp, ip, request, and response code */
        sscanf(line, "%[^ ] %[^\[][%*[^\"]\"%[^\"]\" %[^\n]", data[i].timestamp, data[i].ip, data[i].request, data[i].responseCode);
        i++;
    }

    /* Set count to number of LogData entries read */
    *count = i;
    fclose(file);
    return data;
}

/* Function to count number of unique Requesters */
int countRequesters(LogData *data, int count) {
    int unique = 1;
    char *prevIP = data[0].ip;

    /* Loop through LogData array and compare IP addresses */
    for (int i = 1; i < count; i++) {
        /* If IP address is different from previous, increment unique count */
        if (strcmp(data[i].ip, prevIP) != 0) {
            unique++;
            prevIP = data[i].ip;
        }
    }

    return unique;
}

/* Main function */
int main(int argc, char *argv[]) {
    int count = 0;

    /* Parse command line arguments */
    if (argc != 2) {
        printf("Usage: ./loganalysis filename\n");
        return 1;
    }

    /* Read the log file and populate the LogData array */
    LogData *data = readLogFile(argv[1], &count);
    if (data == NULL) {
        return 1;
    }

    /* Count the number of unique requesters and print the result */
    int uniqueRequesters = countRequesters(data, count);
    printf("Number of unique requesters: %d\n", uniqueRequesters);

    /* Free memory allocated for LogData array */
    free(data);

    return 0;
}