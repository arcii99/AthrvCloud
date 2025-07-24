//FormAI DATASET v1.0 Category: Digital signal processing ; Style: standalone
#include<stdio.h>
#include<math.h>

//Function to compute Fast Fourier Transform
void FFT(int N, double *xr, double *xi, double dir)
{
    int n,m,i,i1,j,k,i2,l,l1,l2;
    double c1,c2,tx,ty,t1,t2,u1,u2,z;

    //Compute the number of points N as a power of 2
    n = N;
    int bit = -1;
    for(i=0; i<32; i++)
    {
        if((n>>i) & 1)
        {
            if(bit == -1) bit = i;
            else
            {
                printf("The number should be a power of 2\n");
                return;
            }
        }
    }
    if(bit == -1)
    {
        printf("The number should be a power of 2\n");
        return;
    }

    //Perform the bit-reverse permutation
    m = bit;
    for(i=0; i<N; i++)
    {
        j = 0;
        for(k=0; k<m; k++)
        {
            j = (j<<1) | ((i>>k) & 1);
        }
        if(j < i)
        {
            tx = xr[i];
            ty = xi[i];
            xr[i] = xr[j];
            xi[i] = xi[j];
            xr[j] = tx;
            xi[j] = ty;
        }
    }

    //Perform the FFT
    c1 = -1.0;
    c2 = 0.0;
    l2 = 1;
    for(l=0; l<m; l++)
    {
        l1 = l2;
        l2 <<= 1;
        u1 = 1.0;
        u2 = 0.0;
        for(j=0; j<l1; j++)
        {
            for(i=j; i<N; i+=l2)
            {
                i1 = i+l1;
                t1 = u1*xr[i1] - u2*xi[i1];
                t2 = u1*xi[i1] + u2*xr[i1];
                xr[i1] = xr[i] - t1;
                xi[i1] = xi[i] - t2;
                xr[i] += t1;
                xi[i] += t2;
            }
            z =  u1*c1 - u2*c2;
            u2 = u1*c2 + u2*c1;
            u1 = z;
        }
        c2 = sqrt((1.0-c1)/2.0);
        if(dir == 1) c2 = -c2;
        c1 = sqrt((1.0+c1)/2.0);
    }

    //Scale the output
    if(dir == -1)
    {
        for(i=0; i<N; i++)
        {
            xr[i] /= N;
            xi[i] /= N;
        }
    }
}

int main()
{
    int n = 8;
    double xr[] = {1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0};
    double xi[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    int i;

    //Print the input data
    printf("Input Data:\n");
    for(i=0; i<n; i++)
    {
        printf("%f + i%f\n", xr[i], xi[i]);
    }

    //Compute the FFT
    FFT(n, xr, xi, 1);

    //Print the FFT coefficients
    printf("\nFFT Coefficients:\n");
    for(i=0; i<n; i++)
    {
        printf("%f + i%f\n", xr[i], xi[i]);
    }

    //Compute the inverse FFT
    FFT(n, xr, xi, -1);

    //Print the original data
    printf("\nReconstructed Data:\n");
    for(i=0; i<n; i++)
    {
        printf("%f + i%f\n", xr[i], xi[i]);
    }

    return 0;
}