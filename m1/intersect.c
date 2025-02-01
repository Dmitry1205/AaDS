#include <stdio.h>
#include <math.h>
int main() {
	int n; scanf("%d", &n);
	unsigned int a = 0;
	for (int i = 0; i < n; i++) {
		int el; scanf("%d", &el);
		a += (int)pow(2, el);
	}
	int k; scanf("%d", &k);
	unsigned int b = 0;
	for (int i = 0; i < k; i++) {
		int el; scanf("%d", &el);
		b += (int)pow(2, el);
	}
	unsigned int c = a & b;
	for (int i = 0; i <= 32; i++) {
		if (c % 2 == 1 && c / 2 == 0)
			printf("%d", i);
		else if(c%2==1)
			printf("%d ", i);
		c /= 2;
	}
}
