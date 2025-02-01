#include <stdio.h>
#include <math.h>

int main() {
	unsigned long long a, b, m; scanf("%llu %llu %llu", &a, &b, &m);
	int x[65] = { 0 };
	int ind = 0;
	while (b != 0) {
		x[ind++] = b % 2;
		b /= 2;
	}
	unsigned long long otv = (a%m)*x[64];
	for (int i = 63; i >= 0; i--) {
		otv = (((otv%m) * (2%m))%m + (a%m) * x[i])%m;
	}
	printf("%llu", otv);
}
