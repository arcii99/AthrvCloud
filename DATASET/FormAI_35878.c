//FormAI DATASET v1.0 Category: Data mining ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define a struct for our data
typedef struct {
    int id;
    float value1;
    float value2;
} Data;

// Define a struct for storing the results of our data mining
typedef struct {
    int max_id;
    float max_value1;
    float max_value2;
    float average_value1;
    float average_value2;
} Results;

// Define a function to read in data from a file
Data* read_data(char* filename, int* size) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return NULL;
    }
    
    // Get the number of lines in the file
    char buffer[1000];
    int num_lines = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        num_lines++;
    }
    rewind(file);
    
    // Allocate memory for our data array
    Data* data = (Data*) malloc(num_lines * sizeof(Data));
    if (data == NULL) {
        printf("Error: Unable to allocate memory\n");
        fclose(file);
        return NULL;
    }
    
    // Read in the data
    int i = 0;
    while (fscanf(file, "%d,%f,%f", &data[i].id, &data[i].value1, &data[i].value2) == 3) {
        i++;
    }
    *size = i;
    fclose(file);
    
    return data;
}

// Define a function to perform data mining on our data array
Results* perform_data_mining(Data* data, int size) {
    Results* results = (Results*) malloc(sizeof(Results));
    if (results == NULL) {
        printf("Error: Unable to allocate memory\n");
        return NULL;
    }
    
    // Calculate the max value of value1
    float max_value1 = data[0].value1;
    int max_value1_id = data[0].id;
    for (int i = 1; i < size; i++) {
        if (data[i].value1 > max_value1) {
            max_value1 = data[i].value1;
            max_value1_id = data[i].id;
        }
    }
    results->max_value1 = max_value1;
    
    // Calculate the max value of value2
    float max_value2 = data[0].value2;
    int max_value2_id = data[0].id;
    for (int i = 1; i < size; i++) {
        if (data[i].value2 > max_value2) {
            max_value2 = data[i].value2;
            max_value2_id = data[i].id;
        }
    }
    results->max_value2 = max_value2;
    
    // Calculate the average value of value1
    float sum1 = 0.0;
    for (int i = 0; i < size; i++) {
        sum1 += data[i].value1;
    }
    results->average_value1 = sum1 / size;
    
    // Calculate the average value of value2
    float sum2 = 0.0;
    for (int i = 0; i < size; i++) {
        sum2 += data[i].value2;
    }
    results->average_value2 = sum2 / size;
    
    // Set the max id
    results->max_id = max_value1_id > max_value2_id ? max_value1_id : max_value2_id;
    
    return results;
}

// Define a function to print out the results of our data mining
void print_results(Results* results) {
    printf("Max Value 1: %.2f (ID: %d)\n", results->max_value1, results->max_id);
    printf("Max Value 2: %.2f (ID: %d)\n", results->max_value2, results->max_id);
    printf("Average Value 1: %.2f\n", results->average_value1);
    printf("Average Value 2: %.2f\n", results->average_value2);
}

int main() {
    int size;
    Data* data = read_data("data.txt", &size);
    if (data == NULL) {
        return 1;
    }
    
    Results* results = perform_data_mining(data, size);
    if (results == NULL) {
        free(data);
        return 1;
    }
    
    print_results(results);
    
    free(data);
    free(results);
    
    return 0;
}