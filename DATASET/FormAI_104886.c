//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
   int n, k, i, j, m, iter;
   float **data, **centers, **clusters_sum, *clusters_size, dist, min_dist;
   
   printf("Enter the number of data points: ");
   scanf("%d", &n);
   
   printf("\nEnter the number of clusters: ");
   scanf("%d", &k);
   
   data = (float **)malloc(n * sizeof(float *));
   for(i = 0; i < n; i++)
   {
      data[i] = (float *)malloc(2 * sizeof(float));
   }
   
   printf("\nEnter the data points:\n");
   for(i = 0; i < n; i++)
   {
      for(j = 0; j < 2; j++)
      {
         scanf("%f", &data[i][j]);
      }
   }
   
   centers = (float **)malloc(k * sizeof(float *));
   for(i = 0; i < k; i++)
   {
      centers[i] = (float *)malloc(2 * sizeof(float));
   }
   
   printf("\nEnter the initial cluster centers:\n");
   for(i = 0; i < k; i++)
   {
      for(j = 0; j < 2; j++)
      {
         scanf("%f", &centers[i][j]);
      }
   }
   
   clusters_sum = (float **)malloc(k * sizeof(float *));
   for(i = 0; i < k; i++)
   {
      clusters_sum[i] = (float *)calloc(2, sizeof(float));
   }
   
   clusters_size = (float *)calloc(k, sizeof(float));
   
   iter = 1;
   while(iter <= 100)
   {
      for(i = 0; i < k; i++)
      {
         clusters_sum[i][0] = 0.0;
         clusters_sum[i][1] = 0.0;
         clusters_size[i] = 0.0;
      }
      
      for(i = 0; i < n; i++)
      {
         min_dist = 1000000.0;
         for(j = 0; j < k; j++)
         {
            dist = sqrt(pow(data[i][0] - centers[j][0], 2) + pow(data[i][1] - centers[j][1], 2));
            if(dist < min_dist)
            {
               m = j;
               min_dist = dist;
            }
         }
         clusters_sum[m][0] += data[i][0];
         clusters_sum[m][1] += data[i][1];
         clusters_size[m]++;
      }
      
      for(i = 0; i < k; i++)
      {
         centers[i][0] = clusters_sum[i][0] / clusters_size[i];
         centers[i][1] = clusters_sum[i][1] / clusters_size[i];
      }
      
      iter++;
   }
   
   printf("\nThe final cluster centers are:\n");
   for(i = 0; i < k; i++)
   {
      for(j = 0; j < 2; j++)
      {
         printf("%f ", centers[i][j]);
      }
      printf("\n");
   }
   
   for(i = 0; i < n; i++)
   {
      free(data[i]);
   }   
   free(data);
   
   for(i = 0; i < k; i++)
   {
      free(centers[i]);
      free(clusters_sum[i]);
   }
   free(centers);
   free(clusters_sum);
   free(clusters_size);   
   
   return 0;
}