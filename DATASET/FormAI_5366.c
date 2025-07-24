//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: expert-level
#include<stdio.h> 
#include<string.h> 

//Function to calculate minimum value of three integers 
int minimum(int a, int b, int c){ 
    if(a<=b && a<=c) 
        return a; 
    if(b<=a && b<=c) 
        return b; 
    else 
        return c; 
} 

//Function to calculate levenshtein distance between two strings
int levenshteinDistance(char *str1, char *str2){ 
    int length1 = strlen(str1); 
    int length2 = strlen(str2); 
    int distance[length1+1][length2+1]; 

    for(int i=0; i<=length1; i++){ 
        for(int j=0; j<=length2; j++){ 
            if(i == 0) 
                distance[0][j] = j; 

            else if(j == 0) 
                distance[i][0] = i; 

            else if(str1[i-1] == str2[j-1]) 
                distance[i][j] = distance[i-1][j-1]; 

            else 
                distance[i][j] = 1 + minimum(distance[i-1][j], distance[i][j-1], distance[i-1][j-1]); 
        } 
    } 

    return distance[length1][length2]; 
} 

int main(){ 
    char str1[] = "example"; 
    char str2[] = "programs"; 

    int distance = levenshteinDistance(str1, str2); 

    printf("Levenshtein Distance between %s and %s is %d", str1, str2, distance); 

    return 0; 
}