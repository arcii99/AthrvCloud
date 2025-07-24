//FormAI DATASET v1.0 Category: Physics simulation ; Style: Cryptic
#include<stdio.h>
#include<math.h>
#include<ctype.h>

struct {
    double a,b,c,d,e,f,x,y,z;
} particle;

int main()
{
    printf("Enter the initial positions of the particle:\n");
    scanf("%lf %lf %lf",&particle.x,&particle.y,&particle.z);
    printf("Enter the initial velocities of the particle:\n");
    scanf("%lf %lf %lf",&particle.a,&particle.b,&particle.c);
    printf("Enter the mass of the particle:\n");
    scanf("%lf",&particle.d);
    for(int t=0;t<100;t++)
    {
        particle.e = (-5*particle.x*particle.y+3*particle.z)*particle.a/particle.d;
        particle.f = (-5*particle.y*particle.z+3*particle.x)*particle.b/particle.d;
        particle.c = (-5*particle.z*particle.x+3*particle.y)*particle.c/particle.d;
        particle.x = particle.x + particle.a*t + particle.e*pow(t,2)/2;
        particle.y = particle.y + particle.b*t + particle.f*pow(t,2)/2;
        particle.z = particle.z + particle.c*t + pow(t,2)/2;
        particle.a = particle.a + particle.e*t;
        particle.b = particle.b + particle.f*t;
        particle.c = particle.c + pow(t,2)/particle.d;
    }
    printf("The final positions of the particle are:\n");
    printf("%.2lf %.2lf %.2lf\n",particle.x,particle.y,particle.z);
    printf("The final velocities of the particle are:\n");
    printf("%.2lf %.2lf %.2lf\n",particle.a,particle.b,particle.c);
    return 0;
}