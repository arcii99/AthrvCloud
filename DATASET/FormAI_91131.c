//FormAI DATASET v1.0 Category: Image Classification system ; Style: shocked
#include <stdio.h>

int main() {
  printf("Welcome to the Image Classification System!\n");

  // Load image data
  int image[28][28]; // an example 28x28 grayscale image
  // Load the grayscale pixel values of the image into the 2D array named 'image'

  // Normalize pixel values to be between 0 and 1
  for (int i = 0; i < 28; i++) {
    for (int j = 0; j < 28; j++) {
      image[i][j] /= 255.0; // assuming the original values were between 0-255
    }
  }

  // Load model parameters
  float weights[10][784]; // 10 classes and 28x28=784 features
  float biases[10]; // each class has a bias term
  // Load the learned weights and biases into arrays named 'weights' and 'biases'

  // Compute logits
  float logits[10] = {};
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 784; j++) {
      logits[i] += image[j/28][j%28] * weights[i][j];
    }
    logits[i] += biases[i];
  }

  // Compute softmax probabilities
  float max_logit = logits[0];
  for (int i = 1; i < 10; i++) {
    if (logits[i] > max_logit) {
      max_logit = logits[i];
    }
  }
  float exp_logits[10] = {};
  float sum_exp_logits = 0;
  for (int i = 0; i < 10; i++) {
    exp_logits[i] = exp(logits[i] - max_logit);
    sum_exp_logits += exp_logits[i];
  }
  float softmax[10] = {};
  for (int i = 0; i < 10; i++) {
    softmax[i] = exp_logits[i] / sum_exp_logits;
  }

  // Print prediction probabilities
  printf("Prediction probabilities:\n");
  for (int i = 0; i < 10; i++) {
    printf("%d: %.2f%%\n", i, softmax[i] * 100);
  }

  // Print predicted class label
  int pred_class = 0;
  float max_prob = softmax[0];
  for (int i = 1; i < 10; i++) {
    if (softmax[i] > max_prob) {
      pred_class = i;
      max_prob = softmax[i];
    }
  }
  printf("Predicted class: %d\n", pred_class);

  return 0;
}