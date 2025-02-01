#include <stdio.h>
#include <stdbool.h>
bool permutation(int* it, int n, long long *a, long long *b) {
	bool is_eqv = 0;
	if (n == 8) {
		for (int i = 0; i < 8; i++) {
			if (a[it[i]] != b[i]) {
				return 0;
			}
		}
		return 1;
	}
	for (int i = 0; i < 8; i++) {
		bool is_in = 0;
		for (int j = 0; j < n; j++) {
			if (i == it[j]) {
				is_in = 1;
				break;
			}
		}
		if (is_in) continue;
		it[n] = i;
		is_eqv |= permutation(it, n + 1, a, b);
	}
	return is_eqv;
}

int main() {
	long long a[8];
	long long b[8];
	int it[8] = { -1 };
	for (int i = 0; i < 8; i++) {
		scanf("%lld", &a[i]);
	}
	for (int i = 0; i < 8; i++) {
		scanf("%lld", &b[i]);
	}
	printf((permutation(it, 0, a, b))?"yes":"no");
}
