//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void subnet_calculation(int n, int m, int k) {
    int i,j,p,q,r,s,t,ct,sbt;
    int ns;
    int bit[32];
    int a[4];
    int mask[4];
    int network[4];
    int broadcast[4];
    int d_max[4];
    int d_min[4];

    ns=n-m;
    if(ns==0) {
        ct=0;
        for(i=1;i<=n;i++)
            if(k==i)
                ct=1;
        if(ct==1)
            for(i=0;i<=31;i++) {
                if(i<m)
                    bit[i]=1;
                else
                    bit[i]=0;
            }
        else
            for(i=0;i<=31;i++)
                bit[i]=0;
        t=0;
        for(i=0;i<=24;i+=8) {
            s=0;
            for(j=i;j<=i+7;j++)
                s=s+(bit[j]*pow(2,7-j+i));
            a[t]=s;
            t++;
        }
        printf("\n Subnet address for the given address is: \n %d.%d.%d.%d ",a[0],a[1],a[2],a[3]);

        for(i=0;i<=3;i++)
            mask[i]=255;

        for(i=0;i<=3;i++)
            network[i]=a[i];
        for(i=0;i<=3;i++)
            broadcast[i]=(network[i]|(~mask[i]));
        for(i=0;i<=3;i++)
            d_max[i]=broadcast[i]-1;
        for(i=0;i<=3;i++)
            d_min[i]=network[i]+1;

        printf("\n The broadcast address is %d.%d.%d.%d.",broadcast[0],broadcast[1],broadcast[2],broadcast[3]);

        printf("\n The network range is from %d.%d.%d.%d to %d.%d.%d.%d.",d_min[0],d_min[1],d_min[2],d_min[3],d_max[0],d_max[1],d_max[2],d_max[3]);
        printf("\n\n");
    }

    else {
        for(i=0;i<=31;i++) {
                if(i<m)
                    bit[i]=1;
                else
                    bit[i]=0;
            }
        t=0;
        for(i=0;i<=24;i+=8) {
            s=0;
            for(j=i;j<=i+7;j++)
                s=s+(bit[j]*pow(2,7-j+i));
            a[t]=s;
            t++;
        }
        printf("\n Subnet address for the given address is: \n %d.%d.%d.%d/%d ",a[0],a[1],a[2],a[3],(32-n));

        ns=n-m;
        sbt=n-ns;
        if(sbt<0)
            sbt=0;
        subnet_calculation(n-1,m-1,sbt);
    }
}

int main() {
    int n,m;
    printf("\n Enter the number of addresses needed : ");
    scanf("%d",&n);
    m=log2(n);
    if(pow(2,m)!=n)
        m++;
    subnet_calculation(32,m,0);
    return 0;
}