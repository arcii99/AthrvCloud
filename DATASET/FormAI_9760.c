//FormAI DATASET v1.0 Category: Digital signal processing ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Function to find the magnitude response
void magnitude_response(float B[], float A[], float w[])
{
    float H_re[1024];
    float H_im[1024];
    for(int i=0; i<1024; i++)
    {
        H_re[i] = 0;
        H_im[i] = 0;
    }

    for(int i=0; i<1024; i++)
    {
        for(int j=0; j<6; j++)
        {
            if((i+j) < 1024)
            {
                H_re[i] += B[j] * cos(w[i+j]);
                H_im[i] -= B[j] * sin(w[i+j]);
            }
            if((i+j) < 1024 && A[j] != 0)
            {
                H_re[i] -= A[j] * cos(w[i+j]);
                H_im[i] += A[j] * sin(w[i+j]);
            }
        }
    }

    float H_mag[1024];

    for(int i=0; i<1024; i++)
    {
        H_mag[i] = sqrt(H_re[i]*H_re[i] + H_im[i]*H_im[i]);
    }

    //Plotting the magnitude response
    FILE *data_file = fopen("magnitude_response.dat","w");

    for(int i=0; i<1024; i++)
    {
        fprintf(data_file, "%f %f\n", w[i], H_mag[i]);
    }

    fclose(data_file);
}

int main()
{
    float B[6] = {1, 2, 1, 0, 0, 0};
    float A[6] = {1, -0.5, 0.25, 0, 0, 0};
    float w[1024];

    for(int i=0; i<1024; i++)
    {
        w[i] = (3.14159*i)/1024;
    }

    magnitude_response(B, A, w);
    
    printf("Magnitude response computed successfully and stored in 'magnitude_response.dat' file.");

    return 0;
}