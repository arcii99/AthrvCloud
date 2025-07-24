//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//Constants
#define G 6.674e-11    //Gravitational constant
#define H 0.006        //Time-step
#define WIDTH 80       //Width of the console
#define HEIGHT 50      //Height of the console
#define SCALE 1e-9     //Scaling factor for the distances
#define MSCALE 1e-25   //Scaling factor for the masses

//Data structure for a celestial body
typedef struct {
    double x, y, vx, vy, fx, fy, m, r;
} Body;

//Initialization function
void init(Body* bodies, int n) {
    srand(time(NULL));
    for(int i=0; i<n; i++) {
        bodies[i].x = (rand()%WIDTH+1)/(double)WIDTH*2-1;
        bodies[i].y = (rand()%HEIGHT+1)/(double)HEIGHT*2-1;
        bodies[i].vx = (rand()%2001-1000)/(double)1000;
        bodies[i].vy = (rand()%2001-1000)/(double)1000;
        bodies[i].m = (rand()%2001+1000)/(double)1000*MSCALE;
        bodies[i].r = pow(bodies[i].m/MSCALE,1/3.0);
    }
}

//Force calculation function
void calculate_force(Body* bodies, int n) {
    for(int i=0; i<n; i++) {
        bodies[i].fx = bodies[i].fy = 0;
        for(int j=0; j<n; j++) {
            if(j==i) continue;
            double dx = bodies[j].x-bodies[i].x;
            double dy = bodies[j].y-bodies[i].y;
            double d = sqrt(dx*dx+dy*dy);
            double f = G*bodies[i].m*bodies[j].m/(d*d);
            bodies[i].fx += f*dx/d;
            bodies[i].fy += f*dy/d;
        }
    }
}

//Integration function
void integrate(Body* bodies, int n) {
    for(int i=0; i<n; i++) {
        bodies[i].vx += bodies[i].fx/bodies[i].m*H;
        bodies[i].vy += bodies[i].fy/bodies[i].m*H;
        bodies[i].x += bodies[i].vx*H;
        bodies[i].y += bodies[i].vy*H;
    }
}

//Render function
void render(Body* bodies, int n) {
    char screen[HEIGHT*WIDTH];
    for(int i=0; i<HEIGHT*WIDTH; i++) screen[i] = ' ';
    for(int i=0; i<n; i++) {
        int x = (bodies[i].x+1)/2*WIDTH;
        int y = (bodies[i].y+1)/2*HEIGHT;
        if(x<0 || x>=WIDTH-1 || y<0 || y>=HEIGHT-1) continue;
        int r = bodies[i].r/SCALE*WIDTH;
        for(int j=-r; j<=r; j++) {
            for(int k=-r; k<=r; k++) {
                if(j*j+k*k<=r*r) {
                    int px = x+j;
                    int py = y+k;
                    if(px<0 || px>=WIDTH || py<0 || py>=HEIGHT) continue;
                    screen[py*WIDTH+px] = '#';
                }
            }
        }
    }
    system("cls"); //Clear console
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            putchar(screen[i*WIDTH+j]);
        }
        putchar('\n');
    }
}

//Main function
int main() {
    int n = 5; //Number of bodies
    Body bodies[n];
    init(bodies,n);
    while(1) {
        calculate_force(bodies,n);
        integrate(bodies,n);
        render(bodies,n);
    }
    return 0;
}