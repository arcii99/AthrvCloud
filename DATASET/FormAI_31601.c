//FormAI DATASET v1.0 Category: Robot movement control ; Style: lively
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i, j, k, x, y, n;  // variables for loop control and storing inputs

    printf("Enter the size of the robot matrix: ");
    scanf("%d", &n); // user input for size of matrix
    
    printf("\nEnter the starting point of the robot (x, y): ");
    scanf("%d%d", &x, &y); // user input for initial position of robot

    // Matrix creation
    int matrix[n][n];

    // Filling the matrix with zeroes
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            matrix[i][j]=0;
  
    // Assigning robot's initial position
    matrix[x][y]=1;

    // Loop for robot movements   
    while(1)
    {
        printf("\nThe robot is at position (%d, %d)", x, y);
        printf("\n Enter the direction in which the robot moves : ");
        printf("\n 1) Up \n 2) Down \n 3) Left \n 4) Right \n 5) Stop and exit program\n");
        scanf("%d", &k);

        // Switch case for robot movement
        switch(k)
        {
            // Move up
            case 1:
                if(x>0)
                {
                x=x-1;
                matrix[x][y]=1;
                }else{
                    printf("\nAlert: Robot cannot move up. It's already at the top of the matrix.\n");
                }
            break;

            // Move down
            case 2:
                if(x<n-1)
                {
                x=x+1;
                matrix[x][y]=1;
                }else{
                    printf("\nAlert: Robot cannot move down. It's already at the bottom of the matrix.\n");
                }
            break;

            // Move left
            case 3:
                if(y>0)
                {
                y=y-1;
                matrix[x][y]=1;
                }else{
                    printf("\nAlert: Robot cannot move left. It's already at the leftmost position of the matrix.\n");
                }          
            break;

            // Move right
            case 4:
                if(y<n-1)
                {
                y=y+1;
                matrix[x][y]=1;
                }else{
                    printf("\nAlert: Robot cannot move right. It's already at the rightmost position of the matrix.\n");
                }
            break;

            // Stop and exit
            case 5:
                printf("\nProgram terminated successfully!\n");
                exit(0);
            break;

            // Default case
            default:
                printf("\nInvalid input. Please enter a valid movement direction number.\n");
            break;
        }

        // Matrix display
        for(i=0;i<n;i++)
        {
            printf("\n");
            for(j=0;j<n;j++)
            {
            printf("%d \t",matrix[i][j]);    
            }
        }   
    }
    return 0;
}