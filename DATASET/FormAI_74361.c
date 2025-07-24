//FormAI DATASET v1.0 Category: Digital signal processing ; Style: single-threaded
#include<stdio.h>
#include<math.h>

#define PI 3.141592653589793

int main()
{
    int n,i,j,k;
    float x[100],h[100],y[100],real[100],imag[100],temp;
    float mag[100],phase[100];
    printf("Enter the number of input samples: ");
    scanf("%d",&n);
    printf("Enter the input samples:\n");
    for(i=0;i<n;i++) scanf("%f",&x[i]);
    printf("Enter the number of filter coefficients: ");
    scanf("%d",&k);
    printf("Enter the filter coefficients:\n");
    for(i=0;i<k;i++) scanf("%f",&h[i]);
    for(i=n;i<=n+k-1;i++) x[i]=0;
    for(i=k;i<=n+k-1;i++) y[i]=0;
    for(i=0;i<=n+k-2;i++)
    {
        temp=0;
        for(j=0;j<k;j++)
        {
            if(i>=j) temp+=x[i-j]*h[j];
        }
        y[i]=temp;
    }
    printf("\nFiltered Output:\n");
    for(i=0;i<=n+k-2;i++) printf("%f\n",y[i]);
    printf("\nMagnitude Response:\n");
    for(i=0;i<100;i++)
    {
        real[i]=0; imag[i]=0;
        for(j=0;j<k;j++)
        {
            real[i]+=h[j]*cos(2*PI*i*j/100);
            imag[i]+=h[j]*sin(2*PI*i*j/100);
        }
        mag[i]=sqrt(real[i]*real[i]+imag[i]*imag[i]);
        phase[i]=atan(imag[i]/real[i]);
        printf("%d %f\n",i,mag[i]);
    }
    printf("\nPhase Response:\n");
    for(i=0;i<100;i++) printf("%d %f\n",i,phase[i]*(180/PI));
    return 0;
}