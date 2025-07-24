//FormAI DATASET v1.0 Category: Physics simulation ; Style: accurate
#include<stdio.h>
#include<math.h>

int main(){
    //defining variables
    float velocity, height, g=9.81, time, range;
    int i, n=30;
    
    //initializing values
    velocity=40.0; //m/s
    height=100.0; //m
    
    //calculating time of flight
    time= 2.0*velocity/g;
    
    //calculating range of projectile
    range= velocity*velocity*sin(2*M_PI/180)/g;
    
    //printing results
    printf("Time of Flight = %f seconds\nRange of Projectile = %f meters\n\n",time,range);
    
    //calculating height and velocity at every 1 second interval
    printf("Time\tHeight\tVelocity\n");
    for(i=0;i<=n;i++){
        time= i*1.0; //time in seconds
        height= 100.0 + velocity*time - 0.5*g*time*time; //height in meters
        velocity= velocity - g*time; //velocity in m/s
        
        printf("%d\t%.2f\t%.2f\n",i,(double)height,(double)velocity);
    }
    
    return 0;
}