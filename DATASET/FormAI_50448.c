//FormAI DATASET v1.0 Category: Recursive ; Style: Cryptic
int cipher(int n, int p) {
    return ((n & 1) << p) | (n & ~1);
}

int decode(int n, int p) {
    return ((n >> p) & 1) | (n & ~1);
}

int recurse(int n, int h, int w) {
    if (h == 0 && w == 0) {
        return n;
    }
    if (h == 0) {
        return recurse(cipher(n, w-1), 0, w-1);
    }
    if (w == 0) {
        return recurse(cipher(n, h-1), h-1, 0);
    }
    return recurse(cipher(n, w-1), h-1, w) + recurse(cipher(n, h-1), h, w-1) - recurse(cipher(n, h-1), h-1, w-1) + decode(n, h*w-1);
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Enter the height of the matrix: ");
    int h;
    scanf("%d", &h);
    printf("Enter the width of the matrix: ");
    int w;
    scanf("%d", &w);
    printf("The result of recursive cipher computation is: %d\n", recurse(n, h, w));
    return 0;
}