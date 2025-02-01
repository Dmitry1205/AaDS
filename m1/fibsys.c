#include <stdio.h>

int main() {
	long long s[100000];
	s[0] = 1;
	s[1] = 2;
	long long col = 2;
	long long x; scanf("%lld", &x);
	while (x >= s[col - 1] + s[col - 2]) {
		s[col] = s[col - 1] + s[col - 2];
		col++;
	}
	if (x == 1 || x == 0) {
		printf("%d", x);
	}
	else {
		for (int i = col - 1; i >= 0; i--) {
			if (x - s[i] >= 0) {
				printf("%d", 1);
				x -= s[i];
			}
			else
				printf("%d", 0);
		}
	}
}
