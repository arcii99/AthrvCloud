//FormAI DATASET v1.0 Category: Physics simulation ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* This program simulates the motion of two objects under the influence of gravity. 
The objects revolve around their center of mass, and their corresponding velocities and accelerations are calculated using the principles of centripetal and gravitational forces*/

int main(void){
    double x1,y1,x2,y2; /* positions of two objects */
    double vx1,vy1,vx2,vy2; /* velocities of two objects */
    double ax1,ay1,ax2,ay2; /* accelerations of two objects */
    double m1=1,m2=2; /* masses of the objects */
    double G=6.67E-11; /* gravitational constant */
    double dt=0.01; /* time step */
    int nsteps=1000; /* number of time steps */
    int i,j; /* loop variables */
    double r,dx,dy,F; /* variables for calculating gravitational forces */ 

    /* set initial positions and velocities */
    x1=0; y1=0; vx1=0; vy1=3;
    x2=10; y2=0; vx2=0; vy2=-1.5;

    /* calculate initial accelerations */
    r=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    dx=(x2-x1)/r; dy=(y2-y1)/r;
    F=G*m1*m2/(r*r);
    ax1=F/m1*dx; ay1=F/m1*dy;
    ax2=-F/m2*dx; ay2=-F/m2*dy;

    /* update positions and velocities */
    for(i=0;i<nsteps;i++){
        x1+=vx1*dt; y1+=vy1*dt; x2+=vx2*dt; y2+=vy2*dt;
        vx1+=ax1*dt; vy1+=ay1*dt; vx2+=ax2*dt; vy2+=ay2*dt;
        /* recalculate accelerations */
        r=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        dx=(x2-x1)/r; dy=(y2-y1)/r;
        F=G*m1*m2/(r*r);
        ax1=F/m1*dx; ay1=F/m1*dy;
        ax2=-F/m2*dx; ay2=-F/m2*dy;
        /* print out positions */
        printf("%f %f %f %f\n",x1,y1,x2,y2);
    }

    return 0;
}