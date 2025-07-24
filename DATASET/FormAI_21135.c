//FormAI DATASET v1.0 Category: Math exercise ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    double x, y, z, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, result;
    
    printf("Enter the values of x, y and z: ");
    scanf("%lf %lf %lf", &x, &y, &z);
    
    a = pow(x,2);
    b = pow(y,3);
    c = pow(z,4);
    d = sqrt(a);
    e = sqrt(b);
    f = sqrt(c);
    g = sin(x);
    h = sin(y);
    i = sin(z);
    j = cos(x);
    k = cos(y);
    l = cos(z);
    m = tan(x);
    n = tan(y);
    o = tan(z);
    p = log(x);
    q = log(y);
    r = log(z);
    s = exp(x);
    t = exp(y);
    u = exp(z);
    v = abs(x);
    w = abs(y);
    
    result = (d + e + f) / (g + h + i) + (j + k + l) / (m + n + o) - (p + q + r) / (s + t + u) * (v + w);
    
    printf("The result of the expression is: %lf", result);
    
    return 0;
}