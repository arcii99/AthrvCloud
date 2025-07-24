//FormAI DATASET v1.0 Category: Data mining ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_NODES 2000

double data[MAX_ROWS][MAX_COLS];
int nrows, ncols;

struct TreeNode {
    int feature_index;
    double split_value;
    double output_value;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct Dataset {
    double X[MAX_NODES][MAX_COLS];
    double y[MAX_NODES];
    int n_samples;
    int n_features;
};

void read_data(FILE *fp) {
    char line[1024];
    int i, j;

    nrows = 0;
    while (fgets(line, 1024, fp) != NULL) {
        char *token = strtok(line, ",");
        j = 0;
        while (token != NULL) {
            data[nrows][j++] = atof(token);
            token = strtok(NULL, ",");
        }
        nrows++;
    }
    ncols = j;
}

double find_variance(double *y, int n) {
    double mean, sum = 0.0, sq_sum = 0.0, var;
    int i;

    /* Calculate the mean */
    for (i = 0; i < n; i++)
        sum += y[i];
    mean = sum / n;

    /* Calculate the variance */
    for (i = 0; i < n; i++)
        sq_sum += pow(y[i] - mean, 2);
    var = sq_sum / n;

    return var;
}

double find_split_point(double *feature, double *y, int n) {
    double split_point = 0.0, min_variance = 99999.0;
    int i, j;

    /* Loop over all possible split points */
    for (i = 0; i < n; i++) {
        double left_y[i+1], right_y[n-i-1];
        int left_n = i+1, right_n = n-i-1;

        /* Split the data into left and right subsets */
        for (j = 0; j <= i; j++)
            left_y[j] = y[j];
        for (j = i+1; j < n; j++)
            right_y[j-i-1] = y[j];

        /* Calculate the variance of each subset */
        double var_left = find_variance(left_y, left_n);
        double var_right = find_variance(right_y, right_n);

        /* Calculate the weighted variance */
        double weighted_var = (var_left * left_n + var_right * right_n) / n;

        /* Update the split point if this is the best split point so far */
        if (weighted_var < min_variance) {
            min_variance = weighted_var;
            split_point = (feature[i] + feature[i+1]) / 2.0;
        }
    }

    return split_point;
}

struct TreeNode* build_tree(double X[MAX_NODES][MAX_COLS], double y[MAX_NODES], int n_samples, int n_features) {
    struct TreeNode *node;

    /* Allocate memory for a new node */
    node = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    /* Check if we need to stop splitting */
    if (n_samples == 1 || find_variance(y, n_samples) == 0.0) {
        node->feature_index = -1;
        node->split_value = -1.0;
        node->output_value = y[0];
        node->left = NULL;
        node->right = NULL;
    } else {
        double *features, split_point;
        int i, j;

        /* Allocate memory for temporary arrays */
        features = (double*)malloc(sizeof(double) * n_samples);

        /* Loop over each feature and find the best split point */
        for (i = 0; i < n_features; i++) {
            for (j = 0; j < n_samples; j++)
                features[j] = X[j][i];
            split_point = find_split_point(features, y, n_samples);
            if (split_point != 0.0)
                break;
        }

        /* Free memory for temporary arrays */
        free(features);

        /* Split the data into left and right subsets */
        double left_X[MAX_NODES][MAX_COLS], right_X[MAX_NODES][MAX_COLS];
        double left_y[MAX_NODES], right_y[MAX_NODES];
        int left_n = 0, right_n = 0;
        for (i = 0; i < n_samples; i++) {
            if (X[i][i] <= split_point) {
                for (j = 0; j < n_features; j++)
                    left_X[left_n][j] = X[i][j];
                left_y[left_n] = y[i];
                left_n++;
            } else {
                for (j = 0; j < n_features; j++)
                    right_X[right_n][j] = X[i][j];
                right_y[right_n] = y[i];
                right_n++;
            }
        }

        /* Recursively build the left and right subtrees */
        node->feature_index = i;
        node->split_value = split_point;
        node->output_value = -1.0;
        node->left = build_tree(left_X, left_y, left_n, n_features);
        node->right = build_tree(right_X, right_y, right_n, n_features);
    }

    return node;
}

double predict(double sample[MAX_COLS], struct TreeNode *node) {
    if (node->feature_index == -1)
        return node->output_value;

    if (sample[node->feature_index] <= node->split_value)
        return predict(sample, node->left);
    else
        return predict(sample, node->right);
}

int main() {
    FILE *fp;
    int i, j;

    /* Read in the data */
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error reading file\n");
        return 1;
    }
    read_data(fp);
    fclose(fp);

    /* Build the decision tree */
    struct Dataset dataset;
    struct TreeNode *root;
    dataset.n_samples = nrows;
    dataset.n_features = ncols - 1;
    for (i = 0; i < nrows; i++) {
        dataset.y[i] = data[i][ncols-1];
        for (j = 0; j < ncols-1; j++)
            dataset.X[i][j] = data[i][j];
    }
    root = build_tree(dataset.X, dataset.y, dataset.n_samples, dataset.n_features);

    /* Make predictions using the decision tree */
    for (i = 0; i < nrows; i++)
        printf("%f\n", predict(data[i], root));

    return 0;
}