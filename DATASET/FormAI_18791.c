//FormAI DATASET v1.0 Category: Data mining ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_FEATURES 10
#define K 5

struct Record {
    double features[MAX_FEATURES];
    int target;
};

int main() {
    struct Record records[MAX_RECORDS];
    int n = 0;
    FILE *fp = fopen("customer_data.csv", "r");
    if (!fp) {
        printf("Could not open customer_data.csv\n");
        return 1;
    }
    char buffer[1024];
    while (fgets(buffer, 1024, fp)) {
        char *token = strtok(buffer, ",");
        int i = 0;
        while (token != NULL) {
            if (i < MAX_FEATURES) {
                records[n].features[i] = atof(token);
            } else {
                records[n].target = atoi(token);
            }
            token = strtok(NULL, ",");
            i++;
        }
        n++;
    }
    fclose(fp);

    // Split data into training and test sets
    int n_train = n * 0.8;
    int n_test = n - n_train;
    struct Record *trainset = (struct Record *)malloc(n_train * sizeof(struct Record));
    struct Record *testset = (struct Record *)malloc(n_test * sizeof(struct Record));
    memcpy(trainset, records, n_train * sizeof(struct Record));
    memcpy(testset, records + n_train, n_test * sizeof(struct Record));

    // Normalize data
    double means[MAX_FEATURES] = {0};
    double std_devs[MAX_FEATURES] = {0};
    for (int j = 0; j < MAX_FEATURES; j++) {
        for (int i = 0; i < n_train; i++) {
            means[j] += trainset[i].features[j];
        }
        means[j] /= n_train;
        for (int i = 0; i < n_train; i++) {
            std_devs[j] += pow(trainset[i].features[j] - means[j], 2);
        }
        std_devs[j] = sqrt(std_devs[j] / (n_train - 1));
    }
    for (int i = 0; i < n_train; i++) {
        for (int j = 0; j < MAX_FEATURES; j++) {
            trainset[i].features[j] = (trainset[i].features[j] - means[j]) / std_devs[j];
        }
    }
    for (int i = 0; i < n_test; i++) {
        for (int j = 0; j < MAX_FEATURES; j++) {
            testset[i].features[j] = (testset[i].features[j] - means[j]) / std_devs[j];
        }
    }

    // Predict targets for test set using k-NN
    int num_correct = 0;
    for (int i = 0; i < n_test; i++) {
        double dists[n_train];
        for (int j = 0; j < n_train; j++) {
            double dist = 0;
            for (int k = 0; k < MAX_FEATURES; k++) {
                dist += pow(testset[i].features[k] - trainset[j].features[k], 2);
            }
            dists[j] = sqrt(dist);
        }
        for (int k = 1; k <= K; k++) {
            for (int j = k; j < n_train; j++) {
                if (dists[j] < dists[j-k]) {
                    double temp_dist = dists[j];
                    dists[j] = dists[j-k];
                    dists[j-k] = temp_dist;
                    struct Record temp_record = trainset[j];
                    trainset[j] = trainset[j-k];
                    trainset[j-k] = temp_record;
                }
            }
        }
        int count_0 = 0;
        int count_1 = 0;
        for (int j = 0; j < K; j++) {
            if (trainset[j].target == 0) {
                count_0++;
            } else {
                count_1++;
            }
        }
        int predicted_target = (count_0 > count_1) ? 0 : 1;
        if (predicted_target == testset[i].target) {
            num_correct++;
        }
    }

    printf("Accuracy: %f%%\n", (double)num_correct / n_test * 100);

    free(trainset);
    free(testset);

    return 0;
}