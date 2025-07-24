//FormAI DATASET v1.0 Category: Data mining ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 1000
#define MAX_NUM_ATTRIBUTES 20
#define MAX_NUM_INSTANCES 1000

typedef struct {
    int num_attributes;
    char attributes[MAX_NUM_ATTRIBUTES][MAX_STRING_LEN];
    int class_label;
} Instance;

typedef struct {
    int num_instances;
    Instance instances[MAX_NUM_INSTANCES];
} Data;

Data read_data(char* filename) {
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        fprintf(stderr, "Error: Could not read input file '%s'\n", filename);
        exit(1);
    }
    Data data;
    data.num_instances = 0;
    char line[MAX_STRING_LEN];
    while(fgets(line, MAX_STRING_LEN, fp) != NULL) {
        Instance instance;
        char* token = strtok(line, ",");
        int attr_count = 0;
        while(token != NULL) {
            if(attr_count == 0) {
                instance.class_label = atoi(token);
            } else {
                strcpy(instance.attributes[attr_count-1], token);
            }
            attr_count++;
            token = strtok(NULL, ",");
        }
        instance.num_attributes = attr_count-1;
        data.instances[data.num_instances] = instance;
        data.num_instances++;
    }
    fclose(fp);
    return data;
}

void print_data(Data data) {
    printf("Number of instances: %d\n", data.num_instances);
    printf("Number of attributes: %d\n", data.instances[0].num_attributes);
    for(int i=0; i<data.num_instances; i++) {
        printf("Instance #%d: ", i+1);
        for(int j=0; j<data.instances[i].num_attributes; j++) {
            printf("%s ", data.instances[i].attributes[j]);
        }
        printf("Class Label: %d\n", data.instances[i].class_label);
    }
}

int main(int argc, char* argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Error: Usage ./data_mining <input_file>\n");
        exit(1);
    }
    Data data = read_data(argv[1]);
    print_data(data);
    return 0;
}