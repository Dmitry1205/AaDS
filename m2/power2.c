#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
int main() {
	int n; scanf("%d", &n);
	long long s[24];
	long long a = pow(2, n);
	long long col = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &s[i]);
	}
	for (int j = a; j > 0; j--) {
		long long sum = 0;
		long long c = j;
		for (int i = 0; i < n; i++) {
			if (c % 2 != 0)
				sum += s[i];
			c /= 2;
		}
		if ((sum & (sum - 1)) == 0 && sum!=0){
            col++;
        }
	}
	printf("\n%lld", col);
}
