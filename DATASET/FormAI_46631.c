//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define MEANS 3 // Defining the number of means
#define ROWS 150 // Defining the number of rows in dataset
#define COLS 4 // Defining the number of columns in dataset

int main(void) {

    FILE *file;
    double dataset[ROWS][COLS];
    char line[1024];

    // Reading data from file and storing it into an array
    file = fopen("iris.csv", "r");

    if (file == NULL) {
        printf("Error opening file.");
        exit(EXIT_FAILURE);
    }

    int row = 0;
    while (fgets(line, 1024, file)) {
        char *temp;
        temp = strtok(line, ",");
        int col = 0;
        while(temp != NULL) {
            dataset[row][col] = atof(temp);
            col++;
            temp = strtok(NULL, ",");
        }
        row++;
    }

    // Initializing variables
    double old_means[MEANS][COLS], new_means[MEANS][COLS], distances[ROWS][MEANS], sum[MEANS][COLS];
    int cluster[ROWS];
    int i, j, k;

    // Selecting initial means randomly
    srand(time(NULL));
    for (i=0; i<MEANS; i++) {
        int random = rand() % ROWS;
        for (j=0; j<COLS; j++) {
            old_means[i][j] = dataset[random][j];
            new_means[i][j] = 0;
        }
    }

    // Starting K-Means Clustering Algorithm
    int iteration = 0;
    while (1) {
        // Resetting variables
        for (i=0; i<MEANS; i++) {
            for (j=0; j<COLS; j++) {
                sum[i][j] = 0;
                distances[i][j] = 0;
            }
        }

        // Calculating distances between each row and each mean
        for (i=0; i<ROWS; i++) {
            for (j=0; j<MEANS; j++) {
                double distance = 0;
                for (k=0; k<COLS; k++) {
                    distance += pow(dataset[i][k]-old_means[j][k], 2);
                }
                distances[i][j] = sqrt(distance);
            }
        }

        // Assigning rows to nearest mean
        int flag = 0;
        for (i=0; i<ROWS; i++) {
            double min_distance = distances[i][0];
            int nearest_mean = 0;
            for (j=1; j<MEANS; j++) {
                if (distances[i][j] < min_distance) {
                    min_distance = distances[i][j];
                    nearest_mean = j;
                }
            }
            if (cluster[i] != nearest_mean) {
                cluster[i] = nearest_mean;
                flag = 1;
            }
        }

        // Terminating if no more reallocation is necessary
        if (flag == 0) {
            break;
        }

        // Calculating new means
        for (i=0; i<ROWS; i++) {
            for (j=0; j<COLS; j++) {
                sum[cluster[i]][j] += dataset[i][j];
            }
        }
        for (i=0; i<MEANS; i++) {
            for (j=0; j<COLS; j++) {
                new_means[i][j] = sum[i][j]/(double)ROWS;
            }
        }

        // Updating means
        for (i=0; i<MEANS; i++) {
            for (j=0; j<COLS; j++) {
                old_means[i][j] = new_means[i][j];
            }
        }

        iteration++;
    }

    // Printing results
    printf("Number of iterations: %d\n", iteration);
    for (i=0; i<MEANS; i++) {
        printf("Cluster %d:\n", i+1);
        for (j=0; j<ROWS; j++) {
            if (cluster[j] == i) {
                printf("%lf\t%lf\t%lf\t%lf\n", dataset[j][0], dataset[j][1], dataset[j][2], dataset[j][3]);
            }
        }
        printf("\n");
    }

    return 0;
}