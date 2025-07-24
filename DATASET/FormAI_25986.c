//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 100

int main()
{
    int i,j,k,n;
    float x[N],y[N],cx[N],cy[N],d,md[N],sumx,sumy;
    printf("\nEnter number of points to be clustered: ");
    scanf("%d",&n);
    printf("\nEnter x and y coordinates of %d points\n",n);
    for(i=0;i<n;i++)
    {
        printf("Point %d: ",i+1);
        scanf("%f%f",&x[i],&y[i]);
    }

    //Randomly initializing cluster centroids
    cx[0]=x[0],cy[0]=y[0];
    cx[1]=x[n-1],cy[1]=y[n-1];
    printf("\nInitial Centroids: C1=(%.2f,%.2f) and C2=(%.2f,%.2f)\n",cx[0],cy[0],cx[1],cy[1]);

    //Initially assigning all points to cluster1
    int cluster[n],temp;
    for(i=0;i<n;i++)
        cluster[i]=1;
     
     //Updating centroids and assigning points to clusters iteratively until convergence
    while(1)
    {
        for(i=0;i<n;i++)
        {
            //Finding Minimum Distance from clusters
            md[i]=sqrt(pow(cx[0]-x[i],2)+pow(cy[0]-y[i],2));
            if(sqrt(pow(cx[1]-x[i],2)+pow(cy[1]-y[i],2))<md[i])
                cluster[i]=2,md[i]=sqrt(pow(cx[1]-x[i],2)+pow(cy[1]-y[i],2));
            else
                cluster[i]=1;
        }
        sumx=sumy=0;
        temp=cx[0],cx[0]=0,cx[1]=0,cy[0]=0,cy[1]=0;
        for(i=0;i<n;i++)
        {
            //Computing new centroids
            if(cluster[i]==1)
            {
                sumx+=x[i],sumy+=y[i];
                cx[0]=cx[0]+1;
                cx[1]+=x[i];
                cy[1]+=y[i];
            }
            else
            {
                cx[1]=cx[1]+1;
                cx[0]+=x[i];
                cy[0]+=y[i];
            }
        }
        if(cx[0]==0)
            cx[0]=temp;
        cx[0]=sumx/cx[0];
        cy[0]=sumy/cx[0],cx[1]=cx[1]/cx[1];
        cy[1]=cy[1]/cx[1];

        //Checking for convergence
        if(d==sqrt(pow(cx[0]-temp,2)+pow(cy[0]-cy[1],2)))
            break;
        d=sqrt(pow(cx[0]-temp,2)+pow(cy[0]-cy[1],2));
    }

    //Assigning final clusters
    printf("\nFinal Centroids: C1=(%.2f,%.2f) and C2=(%.2f,%.2f)\n",cx[0],cy[0],cx[1],cy[1]);
    printf("\nAssigned Clusters:\n");
    for(j=1;j<=2;j++)
    {
        printf("\nCluster %d: \n",j);
        for(i=0;i<n;i++)
            if(cluster[i]==j)
            {
                printf("(%0.2f,%0.2f)  ",x[i],y[i]);
            }
    } 

    return 0;
}