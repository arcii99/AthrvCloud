//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: enthusiastic
#include<stdio.h>
#include<math.h>

int main()
{
    int n;
    printf("Enter the number of points in the space: ");
    scanf("%d", &n);

    float x[n], y[n], z[n];
    printf("\nEnter the coordinates in x y z format:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%f%f%f",&x[i],&y[i],&z[i]);
    }

    float distance, max_distance = 0;
    int index1, index2;

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            distance = sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2)+pow(z[i]-z[j],2));
            if(distance>max_distance)
            {
                max_distance = distance;
                index1 = i;
                index2 = j;
            }
        }
    }

    printf("\nLongest line is formed between points (%.2f,%.2f,%.2f) and (%.2f,%.2f,%.2f)", x[index1], y[index1], z[index1], x[index2], y[index2], z[index2]);

    return 0;
}