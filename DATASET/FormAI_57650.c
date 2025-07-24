//FormAI DATASET v1.0 Category: Digital signal processing ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void dft(double x[], double Xre[], double Xim[], int N)
{
    double pi = 3.141592653589793;
    for(int k=0; k<N; k++)
    {
        Xre[k]=0;
        Xim[k]=0;
        for(int n=0; n<N; n++)
        {
            double angle = 2*pi*n*k/N;
            Xre[k]+=(x[n]*cos(angle));
            Xim[k]-=(x[n]*sin(angle));
        }
    }
}

void main()
{
    int N;
    printf("Enter the number of samples: ");
    scanf("%d",&N);

    double x[N], Xre[N], Xim[N];

    printf("Enter the samples:\n");
    for(int i=0; i<N; i++)
        scanf("%lf", &x[i]);

    dft(x,Xre,Xim,N);

    printf("The DFT is:\n");
    for(int k=0; k<N; k++)
        printf("%.2lf + j%.2lf\n", Xre[k], Xim[k]);
}