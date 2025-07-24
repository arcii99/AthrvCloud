//FormAI DATASET v1.0 Category: Image Classification system ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max 1000

double sigmoid(double a){
    return 1/(1+exp(-a));
}

int main(){

    int n,m;
    printf("Enter the number of training examples: ");
    scanf("%d",&m);

    printf("Enter the number of features: ");
    scanf("%d",&n);

    int i,j;
    double theta[n+1];
    printf("Enter the parameters of theta: ");
    for(i=0;i<n+1;i++){
        scanf("%lf",&theta[i]);
    }

    double x[m][n+1];
    printf("Enter the training examples: \n");
    for(i=0;i<m;i++){
        x[i][0] = 1;
        for(j=1;j<n+1;j++){
            scanf("%lf",&x[i][j]);
        }
    }

    double y[m];
    printf("Enter the class labels: \n");
    for(i=0;i<m;i++){
        scanf("%lf",&y[i]);
    }

    double h_x[m], error[m], cost=0;
    for(i=0;i<m;i++){
        h_x[i] = sigmoid(theta[0]*x[i][0] + theta[1]*x[i][1] + theta[2]*x[i][2] + theta[3]*x[i][3]);
        error[i] = -y[i]*log(h_x[i]) - (1-y[i])*log(1-h_x[i]);
        cost += error[i];
    }
    cost /= m;

    printf("Cost before gradient descent: %lf\n",cost);

    double alpha = 0.01;
    int iterations = 1000;

    for(i=0;i<iterations;i++){
        double gradient[n+1];
        for(j=0;j<n+1;j++){
            gradient[j] = 0;
            int k;
            for(k=0;k<m;k++){
                gradient[j] += (h_x[k]-y[k])*x[k][j];
            }
            gradient[j] /= m;
        }
        for(j=0;j<n+1;j++){
            theta[j] = theta[j] - alpha*gradient[j];
        }
        cost = 0;
        for(j=0;j<m;j++){
            h_x[j] = sigmoid(theta[0]*x[j][0] + theta[1]*x[j][1] + theta[2]*x[j][2] + theta[3]*x[j][3]);
            error[j] = -y[j]*log(h_x[j]) - (1-y[j])*log(1-h_x[j]);
            cost += error[j];
        }
        cost /= m;
        printf("Cost after iteration %d: %lf\n",i+1,cost);
    }

    printf("Final values of theta: \n");
    for(i=0;i<n+1;i++){
        printf("%lf\n",theta[i]);
    }

    return 0;
}