#include <stdio.h>
int main() {
	long long x; scanf("%lld", &x);
	x = (x > 0) ? x : -x;
	short s[100000] = { 0 };
	s[0] = 1; s[1] = 1;
	long long otv = 0;
	for (long long i = 2; i * i <= x; i++) {
		if (s[i] == 1) continue;
		if (x % i == 0) {
			otv = i;
			for (long long j = 2 * i; j * j <= x; j += i) {
				s[j] = 1;
			}
			while (x % i == 0) {
				x /= i;
			}
		}
	}
	printf("%lld", (x == 1) ? otv : x);
}
