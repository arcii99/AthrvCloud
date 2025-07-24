//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITERATIONS 1000

typedef struct {
    double x;
    double y;
} Complex;

int main() {
    int i, j, k;
    double cx, cy, zx, zy, zx2, zy2, mag, color;
    Complex c, z, delta;
    unsigned char img[HEIGHT][WIDTH][3];
    
    // Calculate delta value for each pixel
    delta.x = 3.0 / (double)WIDTH;
    delta.y = 3.0 / (double)HEIGHT;
    
    // Iterate over each pixel
    for(i=0; i<HEIGHT; i++) {
        for(j=0; j<WIDTH; j++) {
            cx = -1.5 + j * delta.x;
            cy = -1.5 + i * delta.y;
            c.x = cx;
            c.y = cy;
            
            z.x = 0.0;
            z.y = 0.0;
            
            // Iterate until divergence or max iterations is reached
            for(k=0; k<MAX_ITERATIONS; k++) {
                zx = z.x * z.x - z.y * z.y + c.x;
                zy = 2 * z.x * z.y + c.y;
                z.x = zx;
                z.y = zy;
                
                zx2 = z.x * z.x;
                zy2 = z.y * z.y;
                mag = sqrt(zx2 + zy2);
                
                // Check if the point diverges
                if(mag > 2.0) {
                    color = k - log(log(mag))/log(2);
                    color /= MAX_ITERATIONS;
                    img[i][j][0] = (unsigned char)(255 * color);
                    img[i][j][1] = (unsigned char)(255 * color);
                    img[i][j][2] = (unsigned char)(255 * color);
                    break;
                }
            }
            
            // The point does not diverge, set the color to black
            if(k == MAX_ITERATIONS) {
                img[i][j][0] = 0;
                img[i][j][1] = 0;
                img[i][j][2] = 0;
            }
        }
    }
    
    // Output the image
    printf("P3 %d %d 255\n", WIDTH, HEIGHT);
    for(i=0; i<HEIGHT; i++) {
        for(j=0; j<WIDTH; j++) {
            printf("%d %d %d ", img[i][j][0], img[i][j][1], img[i][j][2]);
        }
        printf("\n");
    }
    
    return 0;
}