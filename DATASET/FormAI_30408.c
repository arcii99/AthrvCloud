//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DIGITS 10

typedef struct {
    int n[MAX_DIGITS];
    int digits;
} big_int;

void big_int_init(big_int *a) {
    memset(a->n, 0, sizeof(a->n));
    a->digits = 0;
}

void big_int_from_int(big_int *a, int x) {
    big_int_init(a);
    while(x) {
        a->n[a->digits++] = x % 10;
        x /= 10;
    }
}

void big_int_assign(big_int *a, big_int *b) {
    memcpy(a->n, b->n, sizeof(a->n));
    a->digits = b->digits;
}

void big_int_print(big_int *a) {
    for(int i=a->digits-1; i>=0; i--)
        printf("%d", a->n[i]);
}

void big_int_random(big_int *a, big_int *p) {
    big_int_init(a);
    while(a->digits < p->digits)
        a->n[a->digits++] = rand() % 10;
    for(int i=a->digits-1; i>=0; i--)
        if(a->n[i])
            break;
        else
            a->digits--;
}

void big_int_add(big_int *a, big_int *b, big_int *p) {
    int carry = 0;
    for(int i=0; i<MAX_DIGITS; i++) {
        int x = a->n[i] + b->n[i] + carry;
        a->n[i] = x % 10;
        carry = x / 10;
    }
    while(a->digits > 0 && a->n[a->digits-1] == 0)
        a->digits--;
}

void big_int_subtract(big_int *a, big_int *b, big_int *p) {
    int borrow = 0;
    for(int i=0; i<MAX_DIGITS; i++) {
        int x = a->n[i] - b->n[i] - borrow;
        if(x < 0) {
            x += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        a->n[i] = x;
    }
    while(a->digits > 0 && a->n[a->digits-1] == 0)
        a->digits--;
}

void big_int_multiply(big_int *a, big_int *b, big_int *p) {
    big_int c;
    big_int_init(&c);
    for(int i=0; i<b->digits; i++) {
        int carry = 0;
        for(int j=0; j<a->digits; j++) {
            int x = a->n[j] * b->n[i] + carry;
            int y = c.n[i+j] + x;
            c.n[i+j] = y % 10;
            carry = y / 10;
        }
        if(carry)
            c.n[i+a->digits] += carry;
    }
    if(c.n[a->digits+b->digits-1] > 0)
        c.digits = a->digits + b->digits;
    else
        c.digits = a->digits + b->digits - 1;
    big_int_assign(a, &c);
}

int big_int_compare(big_int *a, big_int *b) {
    if(a->digits < b->digits)
        return -1;
    if(a->digits > b->digits)
        return 1;
    for(int i=a->digits-1; i>=0; i--) {
        if(a->n[i] < b->n[i])
            return -1;
        if(a->n[i] > b->n[i])
            return 1;
    }
    return 0;
}

void big_int_divide(big_int *a, big_int *b, big_int *q, big_int *r) {
    big_int c;
    big_int_init(&c);
    big_int_assign(r, a);
    q->digits = a->digits - b->digits + 1;
    for(int i=q->digits-1; i>=0; i--) {
        int lo = 0, hi = 9;
        while(lo < hi) {
            int mid = (lo + hi + 1) / 2;
            big_int_from_int(&c, mid);
            big_int_multiply(b, &c, NULL);
            if(big_int_compare(b, r) <= 0)
                lo = mid;
            else
                hi = mid - 1;
        }
        big_int_from_int(&c, lo);
        big_int_multiply(b, &c, NULL);
        big_int_subtract(r, b, NULL);
        big_int_assign(&q->n[i], &c);
        b->n[b->digits-1] = 0;
        b->digits--;
    }
    while(q->digits > 0 && q->n[q->digits-1] == 0)
        q->digits--;
    if(r->digits == 0)
        r->digits = 1;
}

void big_int_mod_exp(big_int *a, big_int *b, big_int *p, big_int *c) {
    big_int t;
    big_int_init(&t);
    if(b->digits == 1 && b->n[0] == 0) {
        big_int_from_int(c, 1);
        return;
    }
    if(b->n[0] & 1) {
        big_int_mod_exp(a, &b->n[0], p, c);
    } else {
        big_int_assign(&t, p);
        big_int_mod_exp(a, &b->n[0], p, c);
        big_int_multiply(c, c, p);
        big_int_divide(c, &t, NULL, c);
    }
    big_int_assign(&t, a);
    big_int_multiply(&t, &t, p);
    big_int_divide(&t, p, NULL, &t);
    for(int i=1; i<b->digits; i++) {
        big_int_multiply(&t, &t, p);
        big_int_divide(&t, p, NULL, &t);
        if(b->n[i] & 1) {
            big_int_multiply(c, &t, p);
            big_int_divide(c, p, NULL, c);
            big_int_mod_exp(a, &b->n[i], p, &t);
            big_int_multiply(c, &t, p);
            big_int_divide(c, p, NULL, c);
        }
    }
}

void rsa_encrypt(char *message, big_int *e, big_int *n, big_int *c) {
    big_int m;
    big_int_init(&m);
    while(*message) {
        big_int_from_int(&m, *message++);
        big_int_mod_exp(&m, e, n, c);
        big_int_multiply(c, c, n);
    }
}

void rsa_decrypt(big_int *c, big_int *d, big_int *n, char *message) {
    big_int m;
    big_int_init(&m);
    while(c->digits > 0) {
        big_int_mod_exp(c, d, n, &m);
        *message++ = m.n[0];
        big_int_divide(c, n, NULL, c);
    }
    *message = '\0';
}

int main() {
    srand(time(NULL));
    big_int p, q, phi, n, e, d, c;
    char message[1024];

    big_int_init(&p);
    big_int_init(&q);
    big_int_init(&phi);
    big_int_init(&n);
    big_int_init(&e);
    big_int_init(&d);
    big_int_init(&c);

    // Generate p and q
    big_int_from_int(&p, 997);
    big_int_from_int(&q, 1009);

    // Calculate n and phi
    big_int_multiply(&p, &q, &n);
    big_int_subtract(&p, &p, NULL);
    big_int_subtract(&q, &q, NULL);
    big_int_multiply(&p, &q, &phi);

    // Choose e coprime to phi
    big_int_from_int(&e, 3);
    while(1) {
        big_int_mod_exp(&e, &phi, &n, &c);
        if(c.digits == 1 && c.n[0] == 1)
            break;
        big_int_add(&e, &e, &phi);
    }

    // Calculate d, the modular inverse of e
    big_int_assign(&d, &e);
    big_int_mod_exp(&d, &phi, &n, &c);

    // Encrypt and decrypt a message
    strcpy(message, "Hello, world!");
    rsa_encrypt(message, &e, &n, &c);
    rsa_decrypt(&c, &d, &n, message);
    printf("%s\n", message);

    return 0;
}