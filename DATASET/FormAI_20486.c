//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: post-apocalyptic
#include<stdio.h>
#include<string.h>

// Function to calculate the minimum of three integers
int min(int a, int b, int c){
    if(a<=b && a<=c) return a;
    if(b<=a && b<=c) return b;
    else return c;
}

// Function to calculate the Levenshtein distance between two strings
int levenshteinDistance(char* str1, char* str2, int m, int n){

    // Create a table to store the distances
    int table[m+1][n+1];
    memset(table, 0, sizeof(table));

    // Initialize the first row and first column of the table
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0) table[i][j]=j;
            else if(j==0) table[i][j]=i;
        }
    }

    // Calculate the distances for the remaining cells
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(str1[i-1]==str2[j-1]) table[i][j]=table[i-1][j-1];
            else table[i][j]=1+min(table[i][j-1], table[i-1][j], table[i-1][j-1]);
        }
    }

    // Return the distance
    return table[m][n];
}

int main(){

    // Retrieve two strings from user input
    char str1[100], str2[100];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    // Calculate the Levenshtein distance between the strings
    int distance = levenshteinDistance(str1, str2, strlen(str1), strlen(str2));

    // Print out a post-apocalyptic message based on the distance
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", str1, str2, distance);
    if(distance<5) printf("Communications are still functioning! We can still rebuild!\n");
    else if(distance>=5 && distance<10) printf("We're starting to lose communication. Stay vigilant.\n");
    else if(distance>=10 && distance<15) printf("We're losing communication! Gather supplies and find shelter.\n");
    else printf("The world as we know it is over. It's every man for himself now.\n");

    return 0;
}