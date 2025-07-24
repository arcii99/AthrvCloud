//FormAI DATASET v1.0 Category: Data validation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define a struct to store the data validation result
typedef struct {
    int is_valid;
    char *error_msg;
} DataValidationResult;

// Define the data validation function
DataValidationResult validate_data(char *data) {
    DataValidationResult result;

    // Check if data is NULL
    if (data == NULL) {
        result.is_valid = 0;
        result.error_msg = "Data is NULL";
        return result;
    }

    // Check if data is empty
    if (data[0] == '\0') {
        result.is_valid = 0;
        result.error_msg = "Data is empty";
        return result;
    }

    // Check if data is within length bounds
    if (strlen(data) < 8 || strlen(data) > 20) {
        result.is_valid = 0;
        result.error_msg = "Data is not within length bounds";
        return result;
    }

    // Data is valid
    result.is_valid = 1;
    result.error_msg = "";
    return result;
}

// Define the thread function to validate the data
void *validate_data_thread(void *arg) {
    char *data = (char *) arg;
    DataValidationResult result = validate_data(data);
    printf("Data: %s\n", data);
    if (result.is_valid) {
        printf("Data is valid\n");
    } else {
        printf("Data is invalid: %s\n", result.error_msg);
    }
    pthread_exit(NULL);
}

int main() {
    char *data1 = "12345678";
    char *data2 = "";
    char *data3 = "123456789012345678901";
    char *data4 = NULL;

    // Create threads to validate the data
    pthread_t thread1, thread2, thread3, thread4;
    pthread_create(&thread1, NULL, validate_data_thread, (void *) data1);
    pthread_create(&thread2, NULL, validate_data_thread, (void *) data2);
    pthread_create(&thread3, NULL, validate_data_thread, (void *) data3);
    pthread_create(&thread4, NULL, validate_data_thread, (void *) data4);

    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);

    return 0;
}