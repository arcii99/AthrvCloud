//FormAI DATASET v1.0 Category: Digital signal processing ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define SYM_RATE 500
#define AMP 0.8

typedef struct {
    double re;
    double im;
} complex_t;

complex_t a[8], b[8], c[8], d[8], e[8], f[8], g[8], h[8];

void complex_mult(complex_t *a, complex_t *b, complex_t *c) {
    c->re = a->re * b->re - a->im * b->im;
    c->im = a->re * b->im + a->im * b->re;
}

void generate_signal(double *signal) {
    double t = 0.0;
    double dt = 1.0 / SAMPLE_RATE;
    double sym_dt = 1.0 / SYM_RATE;
    double t_sym = 0.0;
    int i, j;
    complex_t mod_sig[8];
    
    for(i = 0; i < 8; i++) {
        mod_sig[i].re = AMP * cos(2.0 * M_PI * (double)i / 8.0);
        mod_sig[i].im = AMP * sin(2.0 * M_PI * (double)i / 8.0);
    }
    
    for(i = 0; i < SAMPLE_RATE; i++) {
        signal[i] = 0.0;
        for(j = 0; j < 8; j++) {
            complex_mult(&mod_sig[j], &e[j], &c[j]);
            signal[i] += c[j].re * cos(2.0 * M_PI * j * SYM_RATE * t_sym);
            signal[i] -= c[j].im * sin(2.0 * M_PI * j * SYM_RATE * t_sym);
        }
        t += dt;
        t_sym += sym_dt;
    }
}

int main(void) {
    int i;
    double signal[SAMPLE_RATE];
    generate_signal(signal);
    for(i = 0; i < SAMPLE_RATE; i++) {
        printf("%f\n", signal[i]);
    }
    return EXIT_SUCCESS;
}