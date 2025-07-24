//FormAI DATASET v1.0 Category: Fractal Generation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <stdbool.h>

#define SIZE 640

void plot(int x, int y, char color);
void reset_screen();
void show_screen();

double complex pick_point(double center_x, double center_y, double scale);
void mandelbrot_set(double start_x, double end_x, double start_y, double end_y);
bool is_in_set(double complex c);

int main(){
  mandelbrot_set(-2.0, 1.0, -1.0, 1.0);
  show_screen();
  return 0;
}

void plot(int x, int y, char color){
  printf("\033[%d;%dH%c", y,x,color);
}

void reset_screen(){
  printf("\033[2J");
}

void show_screen(){
  printf("\033[0;0H");
  fflush(stdout);
}

double complex pick_point(double center_x, double center_y, double scale){
  double x = ((double)rand()/RAND_MAX)*2*scale - scale + center_x;
  double y = ((double)rand()/RAND_MAX)*2*scale - scale + center_y;
  return x + y*I;
}

void mandelbrot_set(double start_x, double end_x, double start_y, double end_y){
  reset_screen();
  // pick a random point to start with
  double complex point = pick_point(0,0,3);
  for(int i = 0; i < SIZE*SIZE; i++){
    // check if current point is in the set
    bool in_set = is_in_set(point);
    // plot point on screen
    int x = (point - start_x)/(end_x-start_x)*SIZE + 1;
    int y = (point - start_y)/(end_y-start_y)*SIZE/2 + 1;
    plot(x, y, in_set ? '+' : ' ');
    // pick next point and scale if out of bounds
    if(creal(point) > end_x || creal(point) < start_x || cimag(point) > end_y || cimag(point) < start_y){
      point = pick_point((start_x+end_x)/2, (start_y+end_y)/2, (end_x-start_x)/2);
    } else {
      point += cpow(fabs(creal(point)), 2) - cpow(fabs(cimag(point)), 2) + 2*I*creal(point)*cimag(point);
    }
  }
}

bool is_in_set(double complex c){
  int max_iter = 1000;
  double complex z = 0;
  for(int i = 0; i < max_iter; i++){
    z = cpow(z,2) + c;
    if(cabs(z) > 2) return false;
  }
  return true;
}