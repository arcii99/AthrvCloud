//FormAI DATASET v1.0 Category: Data mining ; Style: standalone
#include<stdio.h>
#include<stdlib.h>

#define MAX_ATTR 100
#define MAX_DATA 1000

typedef struct {
    int id;
    float attributes[MAX_ATTR];
} data;

int main() {
    int num_attr, num_data;

    printf("Enter the number of attributes: ");
    scanf("%d", &num_attr);

    printf("Enter the number of data: ");
    scanf("%d", &num_data);

    data* dataset = (data*) malloc(num_data * sizeof(data));

    for(int i=0; i<num_data; i++) {
        dataset[i].id = i+1;

        printf("\nData %d\n", i+1);
        for(int j=0; j<num_attr; j++) {
            printf("Attribute %d: ", j+1);
            scanf("%f", &dataset[i].attributes[j]);
        }
    }

    printf("\nDataset:\n");
    for(int i=0; i<num_data; i++) {
        printf("\nID: %d\n", dataset[i].id);
        for(int j=0; j<num_attr; j++) {
            printf("Attr%d: %.2f\n", j+1, dataset[i].attributes[j]);
        }
    }

    free(dataset);

    return 0;
}