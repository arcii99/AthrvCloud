//FormAI DATASET v1.0 Category: Data structures visualization ; Style: mathematical
#include <stdio.h>

// Define a struct to represent a mathematical vector
typedef struct Vector {
  int size; // The number of dimensions of the vector
  double* data; // The components of the vector
} Vector;

// Define a function to initialize a vector with a given size and values
void init_vector(Vector* vector, int size, double* data) {
  vector->size = size;
  vector->data = data;
}

// Define a function to compute the dot product of two vectors
double dot_product(Vector vector_1, Vector vector_2) {
  double sum = 0;
  for (int i = 0; i < vector_1.size; i++) {
    sum += vector_1.data[i] * vector_2.data[i];
  }
  return sum;
}

int main() {
  // Define two 3-dimensional vectors
  double data_1[] = {1, 2, 3};
  double data_2[] = {4, 5, 6};
  Vector vector_1;
  Vector vector_2;
  init_vector(&vector_1, 3, data_1);
  init_vector(&vector_2, 3, data_2);

  // Compute their dot product and print the result
  double dot_prod = dot_product(vector_1, vector_2);
  printf("The dot product of the vectors is: %f\n", dot_prod);
  return 0;
}