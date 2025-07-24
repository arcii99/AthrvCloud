//FormAI DATASET v1.0 Category: Recursive ; Style: complex
#include <stdio.h>

int isPerfectSquare(int n, int i){
    if (i * i == n)
        return i;
    if (i * i > n)
        return -1;
    return isPerfectSquare(n, i + 1);
}

int findSquareRoot(int n){
    if (n <= 0)
        return -1;
    if (n == 1)
        return 1;
    int start = 1, end = n / 2, ans;
    while (start <= end){
        int mid = (start + end) / 2;
        int res = mid * mid;
        if (res == n)
            return mid;
        else if (res > n)
            end = mid - 1;
        else{
            start = mid + 1;
            ans = mid;
        }
    }
    return isPerfectSquare(n, ans);
}

int main(){
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (findSquareRoot(n) == -1)
        printf("The number is not a perfect square");
    else
        printf("The square root of %d is %d", n, findSquareRoot(n));

    return 0;
}