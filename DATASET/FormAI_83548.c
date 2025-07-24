//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define NUM_THREADS 3
#define IMAGE_WIDTH 500
#define IMAGE_HEIGHT 500

struct thread_data {
    int id;
    int **image;
};
void *flip_image(void *threadarg) {
    struct thread_data *my_data;
    my_data = (struct thread_data *) threadarg;
    int id = my_data->id;
    int **image = my_data->image;
    int i, j;
    int mid = IMAGE_WIDTH/2;
    if(id==0){
        for(i=0;i<IMAGE_HEIGHT;i++){
            for(int j=0;j<mid;j++){
                int temp = image[i][j];
                image[i][j] = image[i][IMAGE_WIDTH-j-1];
                image[i][IMAGE_WIDTH-j-1] = temp;
            }
        }
    }else if(id==1){
        int contrast_level = 50;
        for(i=0;i<IMAGE_HEIGHT;i++){
            for(j=0;j<IMAGE_WIDTH;j++){
                int pixel_value = image[i][j];
                if(pixel_value+contrast_level>=0 && pixel_value+contrast_level<=255){
                    image[i][j] = pixel_value+contrast_level;
                }
            }
        }
    }else if(id==2){
        int brightness_level = 100;
        for(i=0;i<IMAGE_HEIGHT;i++){
            for(j=0;j<IMAGE_WIDTH;j++){
                int pixel_value = image[i][j];
                if(pixel_value-brightness_level>=0 && pixel_value-brightness_level<=255){
                    image[i][j] = pixel_value-brightness_level;
                }
            } 
        }
    }
    pthread_exit(NULL);
}
int main(int argc, char *argv[]) {
    int i, j, l;
    int image[IMAGE_HEIGHT][IMAGE_WIDTH];
    for (i = 0; i < IMAGE_HEIGHT; i++) {
        for (j = 0; j < IMAGE_WIDTH; j++) {
            image[i][j] = rand() % 255;
        }
    }
    int **image_ptr = (int **) malloc(IMAGE_HEIGHT * sizeof(int *));
    for(i=0;i<IMAGE_HEIGHT;i++){
        image_ptr[i] = (int *) malloc(IMAGE_WIDTH * sizeof(int));
        for(j=0;j<IMAGE_WIDTH;j++){
            image_ptr[i][j] = image[i][j];
        }
    }
    pthread_t threads[NUM_THREADS];
    struct thread_data thread_data_array[NUM_THREADS];
    int rc;
    long t;
    for (t = 0; t < NUM_THREADS; t++) {
        thread_data_array[t].id = t;
        thread_data_array[t].image = image_ptr;
        rc = pthread_create(&threads[t], NULL, flip_image, (void *)&thread_data_array[t]);
        if (rc) {
            printf("Error:unable to create thread,%d\n", rc);
            exit(-1);
        }
    }

    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }
    FILE *file;
    file = fopen("processed_image.pgm", "w");
    fprintf(file, "P2\n%d %d\n255\n", IMAGE_WIDTH, IMAGE_HEIGHT);
    for (i = 0; i < IMAGE_HEIGHT; i++) {
        for (j = 0; j < IMAGE_WIDTH; j++) {
            fprintf(file, "%d ", image_ptr[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    pthread_exit(NULL);
}