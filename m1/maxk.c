#include <stdio.h>
#define MIN_INF -1000000000

int main() {
	long long n; scanf("%lld", &n);
	long long x[1000001];
	for (int i = 0; i < n; i++) {
		scanf("%lld", &x[i]);
	}
	long long k; scanf("%lld", &k);
	long long max = MIN_INF;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		if (i < k)
			sum += x[i];
		else
			sum += x[i] - x[i - k];
		if (i >= k - 1)
			max = (sum > max) ? sum : max;
	}
	printf("%lld", max);
}
