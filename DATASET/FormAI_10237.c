//FormAI DATASET v1.0 Category: Spam Detection System ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <math.h>

#define TOLERANCE 0.1  // Tolerance for delta metric

// Function to calculate the dot product of two arrays
double dot_product(int n, double X[], double Y[]) {
    double result = 0;
    for (int i = 0; i < n; i++) {
        result += X[i] * Y[i];
    }
    return result;
}

// Function to calculate the magnitude of an array
double magnitude(int n, double X[]) {
    double result = 0;
    for (int i = 0; i < n; i++) {
        result += pow(X[i], 2);
    }
    return sqrt(result);
}

// Function to calculate the delta metric between two arrays
double delta_metric(int n, double X[], double Y[]) {
    double dot_XY = dot_product(n, X, Y);
    double mag_X = magnitude(n, X);
    double mag_Y = magnitude(n, Y);
    double cosine_similarity = dot_XY / (mag_X * mag_Y);
    return 1 - cosine_similarity;
}

// Function to detect spam messages
int spam_detection(int n, double X[], double Y[]) {
    double delta = delta_metric(n, X, Y);
    if (delta < TOLERANCE) {
        printf("The message is spam.\n");
        return 1;
    } else {
        printf("The message is not spam.\n");
        return 0;
    }
}

int main() {
    double message_sample_1[7] = {0, 0, 1, 1, 1, 0, 0};
    double message_sample_2[7] = {1, 0, 1, 0, 1, 0, 0};
    double message_sample_3[7] = {0, 0, 0, 1, 0, 0, 1};
    double spam_template[7] = {1, 0, 1, 1, 1, 0, 0};

    spam_detection(7, message_sample_1, spam_template);
    spam_detection(7, message_sample_2, spam_template);
    spam_detection(7, message_sample_3, spam_template);

    return 0;
}