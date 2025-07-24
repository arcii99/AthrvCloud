//FormAI DATASET v1.0 Category: Fractal Generation ; Style: unmistakable
#include <stdio.h>
#include <math.h>

typedef struct complex {
  float real;
  float imag;
} Complex;

Complex multiply(Complex a, Complex b) {
    Complex ans;
    ans.real = a.real * b.real - a.imag * b.imag;
    ans.imag = a.real * b.imag + a.imag * b.real;
    return ans;
}

Complex add(Complex a, Complex b) {
    Complex ans;
    ans.real = a.real + b.real;
    ans.imag = a.imag + b.imag;
    return ans;
}

int main() {
    Complex z0;
    Complex z1;
    Complex z2;
    int n; // number of iterations
    int h = 800; // image height
    int w = 800; // image width
    float x, y, newX, newY;
    float dx, dy;
    float zoom = 1.2;
    int max_iterations = 50;
    float ratioX = (zoom * 2) / w;
    float ratioY = (zoom * 2) / h;
    float cx = -0.5; // center of the fractal in the complex plane
    float cy = 0.0;
    
    // loop through image pixels
    for (int i=0; i<w; i++) {
        for (int j=0; j<h; j++) {
            // set initial conditions
            x = (i - w/2) * ratioX + cx;
            y = (j - h/2) * ratioY + cy;
            z0.real = x;
            z0.imag = y;
            n = 0;
            while (n < max_iterations) {
                z1 = multiply(z0, z0);
                z2 = add(z1, z0);
                if (sqrt(z2.real * z2.real + z2.imag * z2.imag) > 2.0) {
                    break;
                }
                z0.real = z2.real + x;
                z0.imag = z2.imag + y;
                n++;
            }
            // set pixel color based on the number of iterations before escaping
            if (n == max_iterations) {
                printf("0 0 0\n"); // black
            } else {
                dx = (float)n / max_iterations;
                dy = 1.0 - dx;
                newX = dx * 255;
                newY = dy * 255;
                printf("%d %d 0\n", (int)newX, (int)newY); // shades of yellow and blue
            }
        }
    }
    return 0;
}