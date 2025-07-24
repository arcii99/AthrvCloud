//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define n 10
#define st 2

int main()
{
    float x[n],y[n],dist;
    int i,j,k,min,s,stClus[n],clus[n],numStClus;
    numStClus=n/st; 
  
    /* generating random data */
    for(i=0;i<n;i++)
    {
        x[i]=rand()%10;
        y[i]=rand()%10;
    }
  
    /* initializing clusters */
    for(i=0;i<n;i++)
    {
        stClus[i]=i/st;      
    }
  
    /* Repeat Until number of clusters is equal to produced clusters */
    do
    {       
        /* finding minimum distance between points and assigning cluster */         
        for(i=0;i<n;i++)
        {
            min=1000000;      
            for(j=0;j<n;j++)
            {
                dist=sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));                                                
                if(dist<min && stClus[i]!=stClus[j])
                { 
                    min=dist;
                    k=j;
                }
            }
            clus[i]=stClus[k];  
        }
  
        /* assigning starting to clusters */  
        for (i=0;i<numStClus;i++)
        {
            stClus[i]=i;
        }
  
        /* reassigning clusters */  
        for (i=numStClus;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                if (i!=j)
                {
                    if (clus[j]==i)
                    {
                        stClus[j]=stClus[clus[j]];
                    }
                }
            }
        }
  
    } while (numStClus!=st);
  
    /* printing clusters */  
    for(i=0;i<n;i++)
    {
        printf("Point %d belongs to Cluster %d\n",i,clus[i]);
    }
    return 0;
}