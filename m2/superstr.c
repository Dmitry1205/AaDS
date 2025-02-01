#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define ll long long

ll lens[10] = { 0 };
ll pers[10][10] = { {0} };
ll per(char* str1, char* str2, int l, int r) {
	ll a = lens[l];
	ll b = lens[r];
	for (ll j = ((a < b) ? a : b) - 1; j >= 0; j--) {
		bool prerv = 0;
		for (ll q = 0; q <= j; q++) {
			if (str1[a - 1 - j + q] != str2[q]) {
				prerv = 1;
				break;
			}
		}
		if (prerv == 0) {
			return j + 1;
		}
	}
	return 0;
}

ll permutation(int* it, int c, int n, char** list) {
	ll min = 100000;
	if (c == n) {
		if (n == 1)
			return strlen(list[0]);
		ll count = 0;
		ll all = 0;
		for (ll i = 1; i < n; i++) {
			ll peres = pers[it[i - 1]][it[i]];
			ll a = lens[it[i - 1]];
			ll b = lens[it[i]];
			all += a;
			if (i == n - 1)
				all += b;
			count += peres;
		}
		return (min < all - count) ? min : all - count;
	}
	for (int i = 0; i < n; i++) {
		bool is_in = 0;
		for (int j = 0; j < c; j++) {
			if (i == it[j]) {
				is_in = 1;
				break;
			}
		}
		if (is_in) continue;
		it[c] = i;
		ll otv = permutation(it, c + 1, n, list);
		min = (min < otv) ? min : otv;
	}
	return min;
}


int main() {
	int n; scanf("%d\n", &n);
	int it[10] = { -1 };
	char** s = (char**)malloc((n + 1) * sizeof(char*));
	for (int i = 0; i < n; i++) {
		char* a = (char*)malloc(1001 * sizeof(char));
		fgets(a, 1001, stdin);
		s[i] = a;
		s[i][strlen(s[i]) - 1] = '\0';
		lens[i] = strlen(s[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;
			pers[i][j] = per(s[i], s[j], i, j);
		}
	}	
	printf("%lld", permutation(it, 0, n, s));
	for (int i = 0; i < n; i++) {
		free(s[i]);
	}
	free(s);
}
