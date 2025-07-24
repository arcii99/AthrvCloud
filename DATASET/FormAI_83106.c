//FormAI DATASET v1.0 Category: Fractal Generation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define DIM 512
#define MAX_ITER 100

// Fractal Dimension (Calculated as 'slope' of regression line from log-log plot of 'boxes occupied' vs 'box size')
double fractal_dimension(int img[][DIM], int size, int n_boxes){
    double box_size = size/n_boxes;
    double boxes_occupied[n_boxes];
    double log_boxes_occupied[n_boxes];
    double log_box_size[n_boxes];

    // Count boxes occupied for each box size
    for(int i=0; i<n_boxes; i++){
        int boxes_occupied_count = 0;
        for(int j=0; j<size; j+=box_size){
            for(int k=0; k<size; k+=box_size){
                int occupied = 0;
                for(int l=j; l<j+box_size; l++){
                    for(int m=k; m<k+box_size; m++){
                        if(img[l][m] == 1){
                            occupied = 1;
                            break;
                        }
                    }
                    if(occupied == 1) break;
                }

                if(occupied == 1) boxes_occupied_count++;
            }
        }
        boxes_occupied[i] = boxes_occupied_count;
        log_boxes_occupied[i] = log10(boxes_occupied[i]);
        log_box_size[i] = log10(box_size);
    }

    // Calculate slope of regression line for log-log plot of 'boxes occupied' vs 'box size'
    double sum_xy = 0.0;
    double sum_x = 0.0;
    double sum_y = 0.0;
    double sum_x2 = 0.0;

    for(int i=0; i<n_boxes; i++){
        sum_xy += log_box_size[i]*log_boxes_occupied[i];
        sum_x += log_box_size[i];
        sum_y += log_boxes_occupied[i];
        sum_x2 += pow(log_box_size[i], 2);
    }

    double slope = (n_boxes*sum_xy - sum_x*sum_y)/(n_boxes*sum_x2 - pow(sum_x, 2));
    return slope;
}

int main(){
    int img[DIM][DIM];

    // Random initialization of image
    srand(time(NULL));
    for(int i=0; i<DIM; i++){
        for(int j=0; j<DIM; j++){
            img[i][j] = rand() % 2;
        }
    }

    // Iterate on image to create fractal
    int iter_count = 0;
    while(iter_count < MAX_ITER){
        int new_img[DIM][DIM];

        // Copy image to new image
        for(int i=0; i<DIM; i++){
            for(int j=0; j<DIM; j++){
                new_img[i][j] = img[i][j];
            }
        }

        // Create fractal
        for(int i=1; i<DIM-1; i++){
            for(int j=1; j<DIM-1; j++){
                double adjacent_count = 0;
                for(int k=-1; k<=1; k++){
                    for(int l=-1; l<=1; l++){
                        if(k == 0 && l == 0) continue;
                        adjacent_count += img[i+k][j+l];
                    }
                }

                if(adjacent_count >= 4){
                    new_img[i][j] = 1;
                }else{
                    new_img[i][j] = 0;
                }
            }
        }

        // Check for convergence
        double fractal_dim = fractal_dimension(new_img, DIM, 16);
        printf("Iteration: %d, Fractal Dimension: %f\n", iter_count, fractal_dim);
        if(fractal_dim > 1.6){
            printf("Fractal converged after %d iterations.\n", iter_count);
            break;
        }

        // Update image with new image
        for(int i=0; i<DIM; i++){
            for(int j=0; j<DIM; j++){
                img[i][j] = new_img[i][j];
            }
        }

        iter_count++;
    }

    // Write final image to file
    FILE *fp;
    fp = fopen("output.ppm", "w");
    fprintf(fp, "P3\n%d %d\n255\n", DIM, DIM);
    for(int i=0; i<DIM; i++){
        for(int j=0; j<DIM; j++){
            fprintf(fp, "%d %d %d ", img[i][j]*255, img[i][j]*255, img[i][j]*255);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);

    return 0;
}