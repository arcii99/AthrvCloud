//FormAI DATASET v1.0 Category: Data mining ; Style: all-encompassing
#include <stdio.h>

// Function to compute cosine similarity between two vectors
double cosine_similarity(double vector1[], double vector2[], int n) {
    double dot_product = 0;
    double magnitude_vector1 = 0;
    double magnitude_vector2 = 0;
    
    for (int i = 0; i < n; i++) {
        dot_product += vector1[i] * vector2[i];
        magnitude_vector1 += vector1[i] * vector1[i];
        magnitude_vector2 += vector2[i] * vector2[i];
    }
    
    magnitude_vector1 = sqrt(magnitude_vector1);
    magnitude_vector2 = sqrt(magnitude_vector2);
    
    return dot_product / (magnitude_vector1 * magnitude_vector2);
}

int main() {
    // Toy dataset of 5 customers and their purchase history in a grocery store
    double customers[5][6] = {
        {1, 2, 3, 4, 0, 1},
        {1, 0, 1, 0, 2, 0},
        {2, 1, 2, 1, 1, 1},
        {4, 2, 3, 0, 0, 1},
        {0, 2, 1, 2, 1, 2}
    };
    
    // Compute the cosine similarity between each pair of customers
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            double similarity = cosine_similarity(customers[i], customers[j], 6);
            printf("Similarity between customer %d and customer %d: %f\n", i+1, j+1, similarity);
        }
    }
    
    return 0;
}