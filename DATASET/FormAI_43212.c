//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: mind-bending
#include<stdio.h>

#define MAX_POINTS 10000

int main() 
{
    int num_points = 0;
    float points[MAX_POINTS][2];

    printf("Enter the number of points: ");
    scanf("%d", &num_points);
    
    for (int i = 0; i < num_points; i++) 
    {
        printf("Enter the coordinates for point %d: ", i+1);
        scanf("%f %f", &points[i][0], &points[i][1]);
    }

    int k = 2;
    float clusters[k][MAX_POINTS][2];

    float x_min = points[0][1];
    float x_max = points[0][1];
    float y_min = points[0][1];
    float y_max = points[0][1];

    for (int i = 1; i < num_points; i++) 
    {
        if (points[i][0] < x_min) 
        {
            x_min = points[i][0];
        } 
        else if (points[i][0] > x_max) 
        {
            x_max = points[i][0];
        }

        if (points[i][1] < y_min) 
        {
            y_min = points[i][1];
        } 
        else if (points[i][1] > y_max) 
        {
            y_max = points[i][1];
        }
    }

    int threshold = 1;

    while (k > threshold) 
    {
        float distance[num_points][num_points];
        float cluster_distance[MAX_POINTS][MAX_POINTS];

        for (int i = 0; i < num_points; i++) 
        {
            for (int j = 0; j < num_points; j++) 
            {
                if (i == j) 
                {
                    distance[i][j] = 0;
                }
                else 
                {
                    distance[i][j] = sqrt(pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2));
                }
            }
        }

        int a, b;
        float min_distance = distance[0][1];

        for (int i = 0; i < num_points; i++) 
        {
            for (int j = i+1; j < num_points; j++) 
            {
                if (min_distance > distance[i][j]) 
                {
                    min_distance = distance[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        for (int i = 0; i < num_points; i++) 
        {
            for (int j = 0; j < num_points; j++) 
            {
                if (i != a && i != b && j != a && j != b) 
                {
                    cluster_distance[i][j] = distance[i][j];
                } 
                else if (i == a && j != b) 
                {
                    cluster_distance[i][j] = (distance[i][j] + distance[b][j])/2;
                } 
                else if (i == b && j != a) 
                {
                    cluster_distance[i][j] = (distance[i][j] + distance[a][j])/2;
                } 
                else if (j == a && i != b) 
                {
                    cluster_distance[i][j] = (distance[i][j] + distance[b][i])/2;
                } 
                else if (j == b && i != a) 
                {
                    cluster_distance[i][j] = (distance[i][j] + distance[a][i])/2;
                }
            }
        }

        for (int i = 0; i < num_points; i++) 
        {
            for (int j = 0; j < num_points; j++) 
            {
                distance[i][j] = cluster_distance[i][j];
            }
        }

        for (int i = 0; i < num_points; i++) 
        {
            for (int j = 0; j < num_points; j++) 
            {
                if ((i == a || i == b) && (j == a || j == b)) 
                {
                    distance[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < num_points; i++) 
        {
            for (int j = 0; j < num_points; j++) 
            {
                if ((i == a || i == b) && j != a && j != b) 
                {
                    distance[j][i] = distance[i][j];
                }
            }
        }

        for (int i = 0; i < num_points; i++) 
        {
            for (int j = 0; j < num_points; j++) 
            {
                if ((i == a || i == b) && j != a && j != b) 
                {
                    distance[j][i] = distance[i][j];
                }
            }
        }

        int cluster_count = 0;

        for (int i = 0; i < num_points; i++) 
        {
            for (int j = 0; j < num_points; j++) 
            {
                if (i == j) 
                {
                    clusters[cluster_count][i][0] = points[i][0];
                    clusters[cluster_count][i][1] = points[i][1];
                    continue;
                } 
                else if (distance[i][j] < threshold) 
                {
                    clusters[cluster_count][i][0] = (points[i][0] + points[j][0])/2;
                    clusters[cluster_count][i][1] = (points[i][1] + points[j][1])/2;
                }
            }
            cluster_count++;
        }

        for (int i = 0; i < num_points; i++) 
        {
            for (int j = 0; j < 2; j++) 
            {
                points[i][j] = clusters[0][i][j];
            }
        }
        k--;
    }

    return 0;
}