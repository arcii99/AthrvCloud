//FormAI DATASET v1.0 Category: Image Classification system ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 4

pthread_mutex_t mutex;
int finished_threads = 0;

/* Struct to hold image and corresponding classification */
typedef struct {
    char* image_data;
    int classification;
} ImageClassification;

/* Simulating image classification by randomly assigning a classification */
int classify_image(char* image_data) {
    srand(time(NULL));
    return rand() % 2; // Return either 0 or 1
}

/* Thread function to classify image */
void* classify_image_thread(void* arg) {
    ImageClassification* img_cls = (ImageClassification*) arg;
    int classification = classify_image(img_cls -> image_data);
    
    /* Update classification of the image */
    pthread_mutex_lock(&mutex);
    img_cls -> classification = classification;
    finished_threads++;
    pthread_mutex_unlock(&mutex);
    
    pthread_exit(NULL);
}

int main() {
    /* Generate some sample images */
    char* img1 = "00101010101010101110011001110000";
    char* img2 = "10101001100111100111010001110010";
    char* img3 = "11100011100101101001101010010101";
    char* img4 = "00011001010100101010101101010001";
    
    /* Create array of ImageClassification structs */
    ImageClassification images[4] = {
        {img1, -1}, {img2, -1}, {img3, -1}, {img4, -1}
    };
    
    /* Create threads to classify each image */
    pthread_t threads[NUM_THREADS];
    
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        printf("Error creating mutex\n");
        return 1;
    }
    
    for (int i=0; i<NUM_THREADS; i++) {
        int rc = pthread_create(&threads[i], NULL, classify_image_thread, (void*) &images[i]);
        if (rc) {
            printf("Error creating thread %d\n", i);
            return 1;
        }
    }
    
    /* Wait for all threads to complete */
    while (finished_threads < NUM_THREADS) continue;
    
    /* Print classification results */
    for (int i=0; i<NUM_THREADS; i++) {
        printf("Image %d classified as: %d\n", i+1, images[i].classification);
    }
    
    pthread_mutex_destroy(&mutex);
    pthread_exit(NULL);
}