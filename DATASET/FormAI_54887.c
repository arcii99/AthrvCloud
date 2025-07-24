//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//This program implements the "Surrealist Clustering Algorithm". The algorithm assigns a random cluster to each element and then reassigns the elements to a new cluster based on the result of two coin tosses.

int main() {
	srand(time(NULL));	//Seed the random number generator

	int n = 100;	//Number of elements
	int clusters = 5;	//Number of clusters
	int array[n];	//Array to store elements
	int cluster[n];	//Array to store cluster assignments

	//Initializing the array and assigning random clusters
	for(int i=0; i<n; i++) {
		array[i] = rand()%1000;	//Assigning random values to the array
		cluster[i] = rand()%clusters;	//Assigning random cluster
	}

	//Printing original cluster assignments
	printf("Original Cluster Assignments:\n");
	for(int i=0; i<n; i++) {
		printf("%d ", cluster[i]);
	}
	printf("\n");

	//Iterating 100 times to reassign clusters
	for(int i=0; i<100; i++) {
		for(int j=0; j<n; j++) {
			int coin1 = rand()%2;	//First coin toss
			int coin2 = rand()%2;	//Second coin toss
			if((coin1 && coin2) || (!coin1 && !coin2)) {
				//If both coins are the same
				if(j!=0) {
					//If not the first element, check the previous element's cluster
					if(cluster[j]==cluster[j-1]) {
						//If the current and previous elements belong to the same cluster, do nothing
						continue;
					}
					else {
						//If the current and previous elements belong to different clusters, assign the current element to the previous element's cluster
						cluster[j] = cluster[j-1];
					}
				}
				else {
					//If the first element, assign it to the last element's cluster
					cluster[j] = cluster[n-1];
				}	
			}
			else {
				//If the two coins are different
				if(j==(n-1)) {
					//If the last element, assign it to the first element's cluster
					cluster[j] = cluster[0];
				}
				else if(j==(n-2)) {
					//If the second last element assign it to its own cluster
					cluster[j] = j;
				}
				else {
					//For all other elements, assign the current element to its own cluster
					cluster[j] = j;
				}
			}
			
		}
	}

	//Printing final cluster assignments
	printf("Final Cluster Assignments:\n");
	for(int i=0; i<n; i++) {
		printf("%d ", cluster[i]);
	}
	printf("\n");
	
	return 0;
}