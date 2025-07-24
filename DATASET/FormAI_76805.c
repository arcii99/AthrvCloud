//FormAI DATASET v1.0 Category: Image Classification system ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define NUM_THREADS 4
#define NUM_IMAGES 10

int classification_results[NUM_IMAGES] = {0};

typedef struct{
    int image_data[100];
    int image_id;
} Image;

typedef struct{
    int thread_id;
    int start_index;
    int end_index;
    Image* images;
    int* results;
} ThreadData;

//Simulating image classification function
int classify_image(Image* img){
    //Some random image classification algorithm
    int result = 0;
    for(int i = 0; i < 100; i++){
        result += img->image_data[i];
    }
    return result % 5; //Return one of five possible classifications
}

//Thread function to classify images
void* classify_images(void* args){
    ThreadData* data = (ThreadData*) args;
    int start = data->start_index;
    int end = data->end_index;
    Image* images = data->images;
    int* results = data->results;
    for(int i = start; i < end; i++){
        results[i] = classify_image(&images[i]);
    }
    pthread_exit(NULL);
}

int main(){
    //Creating sample images with random data
    Image images[NUM_IMAGES];
    for(int i = 0; i < NUM_IMAGES; i++){
        images[i].image_id = i;
        for(int j = 0; j < 100; j++){
            images[i].image_data[j] = rand()%100;
        }
    }

    //Creating threads and partitioning work
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];
    int images_per_thread = NUM_IMAGES/NUM_THREADS;
    for(int i = 0; i < NUM_THREADS; i++){
        thread_data[i].thread_id = i;
        thread_data[i].start_index = i * images_per_thread;
        thread_data[i].end_index = thread_data[i].start_index + images_per_thread;
        if(i == NUM_THREADS - 1) thread_data[i].end_index = NUM_IMAGES; //Last thread
        thread_data[i].images = images;
        thread_data[i].results = classification_results;
        pthread_create(&threads[i], NULL, classify_images, (void*) &thread_data[i]);
    }
    
    //Wait for threads to complete
    for(int i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }

    //Printing classification results
    printf("Classification Results:\n");
    for(int i = 0; i < NUM_IMAGES; i++){
        printf("Image [%d] classified as %d\n", i, classification_results[i]);
    }

    return 0;
}