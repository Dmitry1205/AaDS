#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long max(long long a, long long b) {
    return (a > b) ? a : b;
}
void build(long long v[], long long i, long long a, long long b, long long T[]) {
    if (a == b)
        T[i] = v[a];
    else {
        int m = (a + b) / 2;
        build(v, 2 * i + 1, a, m, T);
        build(v, 2 * i + 2, m + 1, b, T);
        T[i] = max(T[2 * i + 1],  T[2 * i + 2]);
    }
}
long long* SegmentTree_Build(long long v[], long long n) {
    long long* T = (long long*) malloc(4*n * sizeof(long long));
    build(v, 0, 0, n - 1, T);
    return T;
}
void update(long long j, long long x, long long i, long long a, long long b, long long T[]) {
    if (a == b)
        T[i] = x;
    else {
        long long m = (a + b) / 2;
        if (j <= m)
            update(j, x, 2 * i + 1, a, m, T);
        else
            update(j, x, 2 * i + 2, m + 1, b, T);
        T[i] = max(T[2 * i + 1], T[2 * i + 2]);
    }
}
void SegmentTree_Update(long long j, long long x, long long n, long long T[]) {
    update(j, x, 0, 0, n-1, T);
}
long long query(long long* T, long long l, long long r, long long i, long long a, long long b) {
    long long maximum = -1000000000;
    if (l == a && r == b)
        maximum = T[i];
    else {
        long long m = (a + b) / 2;
        if (r <= m)
            maximum = query(T, l, r, 2 * i + 1, a, m);
        else if (l > m)
            maximum = query(T, l, r, 2 * i + 2, m + 1, b);
        else {
            maximum = max(query(T, l, m, 2 * i + 1, a, m),
                query(T, m + 1, r, 2 * i + 2, m + 1, b));
        }
    }
    return maximum;
}
long long SegmentTree_Query(long long* T, long long n, long long l, long long r) {
    //printf("%lld %lld", l, r);
    long long maximum = query(T, l, r, 0, 0, n-1);
    return maximum;
}

int main() {
    long long n; scanf("%lld", &n);
    long long* v = (long long*)malloc(sizeof(long long) * (n+1));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &v[i]);
    }
    long long* T = SegmentTree_Build(v, n);
    char op[3]; scanf("%s", op);
    long long left, right;
    while (op[0]!='E') {
        if (op[0] == 'M') {
            scanf("%lld %lld", &left, &right);
            printf("%lld\n", SegmentTree_Query(T, n, left, right));
        }
        else if(op[0] == 'U') {
            long long i, zn; scanf("%lld %lld", &i, &zn);
            SegmentTree_Update(i, zn, n, T);
        }
        scanf("%s", op);
    }
    free(v);
    free(T);
}
