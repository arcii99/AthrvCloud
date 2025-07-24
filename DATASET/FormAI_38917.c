//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Cryptic
#include <stdio.h>

#define N 256
#define pi 3.14159

void FFT(float *x, int m)
{
    int i,j,k,n1,n2;
    float c,s,e,a,t1,t2;

    j = 0;
    n1 = m-1;

    for(i=0; i<n1; i++)
    {
        if(i<j)
        {
            t1 = x[j];
            x[j] = x[i];
            x[i] = t1;
        }

        k = m/2;

        while(k<=j)
        {
            j -= k;
            k /= 2;
        }

        j += k;
    }

    n1 = 1;
    n2 = 0;

    for(i=0; i<m; i++)
    {
        c = cos(n2*pi/N);
        s = -sin(n2*pi/N);
        n2 += n1;

        if(n2>=N)
        {
            n2 = n2 - N;
        }

        if(i<n2)
        {
            t1 = x[i];
            x[i] = x[n2];
            x[n2] = t1;
        }

        e = c;
        a = s;

        for(j=1; j<n1; j++)
        {
            c = e*c - a*s;
            a = e*s + a*c;
            k = i + j*m;
            t1 = x[k];
            t2 = x[k+n1]*c + x[k+n1+n1]*a;
            x[k] = t1 + t2;
            x[k+n1+n1] = t1 - t2;
        }

        if(i&(n1-1))
        {
            continue;
        }

        e = c;
        a = s;

        for(j=0; j<n1; j++)
        {
            k = i + j*m;
            t1 = x[k];
            t2 = x[k+n1]*e + x[k+n1+n1]*a;
            x[k] = t1 + t2;
            x[k+n1+n1] = t1 - t2;
        }
    }

    return;
}

int main()
{
    float input[N];
    float output[N];
    int i;

    for(i=0; i<N; i++)
    {
        input[i] = sin((2*pi*i)/N);
    }

    FFT(input, N);

    for(i=0; i<N; i++)
    {
        output[i] = input[i]*input[i];
    }

    FFT(output, N);

    for(i=0; i<N; i++)
    {
        printf("%f\n", output[i]);
    }

    return 0;
}