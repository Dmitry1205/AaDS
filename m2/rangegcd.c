#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long gcd(long long a, long long b) {
	a = (int)fabs(a);
	b = (int)fabs(b);
	if (a < b) {
		return gcd(b, a);
	}
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}
void build(long long* a, long long** tree, int n) {
	for (int i = 0; i < n; i++) {
		(*tree)[i + n] = a[i];
	}
	for (int i = n - 1; i > 0; i--) {
		(*tree)[i] = gcd((*tree)[2 * i], (*tree)[2 * i + 1]);
	}
}
long long gcd_tree(long long l, long long r, long long* tree, int n) {
	long long ans = 0;
	l += n;
	r += n;
	while (l < r) {
		if (l % 2 != 0) {
			ans = gcd(ans, tree[l]);
			l++;
		}
		if (r % 2 != 0) {
			r--;
			ans = gcd(ans, tree[r]);
		}
		l /= 2;
		r /= 2;
	}
	return ans;
}

int main() {
	int n;
	scanf("%d", &n);
	long long* a = (long long*)malloc(n * sizeof(long long));
	for (int i = 0; i < n; i++) {
		long long x;
		scanf("%lld", &x);
		a[i] = x;
	}
	long long* tree = (long long*)malloc(2 * n * sizeof(long long));
	for (int i = 0; i < 2 * n; i++) {
		tree[i] = 0;
	}
	build(a, &tree, n);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%lld\n", gcd_tree(l, r+1, tree, n));
	}
	free(a);
	free(tree);
}
