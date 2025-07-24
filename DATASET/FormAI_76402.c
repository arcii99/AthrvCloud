//FormAI DATASET v1.0 Category: Image Classification system ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_CLASSES 5
#define NUM_FEATURES 10
#define LEARNING_RATE 0.01
#define NUM_EPOCHS 100
#define NUM_IMAGES 1000

int main()
{
    srand(time(NULL));
    double weights[NUM_CLASSES][NUM_FEATURES];
    for(int i=0; i<NUM_CLASSES; i++) {
        for(int j=0; j<NUM_FEATURES; j++) {
            weights[i][j] = ((double)rand()/(double)RAND_MAX);
        }   
    }
    int train_labels[NUM_IMAGES];
    double train_data[NUM_IMAGES][NUM_FEATURES];
    for(int i=0; i<NUM_IMAGES; i++) {
        int label = rand()%NUM_CLASSES;
        train_labels[i] = label;
        for(int j=0; j<NUM_FEATURES; j++) {
            train_data[i][j] = ((double)rand()/(double)RAND_MAX);
            if(j%3 == 0) {
                train_data[i][j] += label*0.1;
            }
        }
    }

    for(int epoch=0; epoch<NUM_EPOCHS; epoch++) {
        double total_loss = 0;
        for(int i=0; i<NUM_IMAGES; i++) {
            double max_score = -INFINITY;
            int predicted_label = -1;
            for(int j=0; j<NUM_CLASSES; j++) {
                double score = 0;
                for(int k=0; k<NUM_FEATURES; k++) {
                    score += weights[j][k]*train_data[i][k];
                }
                if(score > max_score) {
                    max_score = score;
                    predicted_label = j;
                }
            }
            double loss = max_score - weights[train_labels[i]][0] - weights[train_labels[i]][1]*train_data[i][0] - weights[train_labels[i]][2]*train_data[i][3];
            total_loss += loss;
            weights[train_labels[i]][0] -= LEARNING_RATE*(max_score - 1);
            weights[train_labels[i]][1] -= LEARNING_RATE*(max_score - 1)*train_data[i][0];
            weights[train_labels[i]][2] -= LEARNING_RATE*(max_score - 1)*train_data[i][3];
            weights[predicted_label][0] -= LEARNING_RATE*max_score;
            weights[predicted_label][1] -= LEARNING_RATE*max_score*train_data[i][0];
            weights[predicted_label][2] -= LEARNING_RATE*max_score*train_data[i][3];
        }
        printf("Epoch %d, Loss: %f\n", epoch+1, total_loss);
    }

    int test_labels[NUM_IMAGES];
    double test_data[NUM_IMAGES][NUM_FEATURES];
    for(int i=0; i<NUM_IMAGES; i++) {
        int label = rand()%NUM_CLASSES;
        test_labels[i] = label;
        for(int j=0; j<NUM_FEATURES; j++) {
            test_data[i][j] = ((double)rand()/(double)RAND_MAX);
            if(j%3 == 0) {
                test_data[i][j] += label*0.1;
            }
        }
    }

    int num_correct = 0;
    for(int i=0; i<NUM_IMAGES; i++) {
        double max_score = -INFINITY;
        int predicted_label = -1;
        for(int j=0; j<NUM_CLASSES; j++) {
            double score = 0;
            for(int k=0; k<NUM_FEATURES; k++) {
                score += weights[j][k]*test_data[i][k];
            }
            if(score > max_score) {
                max_score = score;
                predicted_label = j;
            }
        }
        if(predicted_label == test_labels[i]) {
            num_correct++;
        }
    }
    printf("Test Accuracy: %f\n", (double)num_correct/(double)NUM_IMAGES);
    return 0;
}