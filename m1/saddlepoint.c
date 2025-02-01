#include <stdio.h>

int main() {
	int n, m; scanf("%d %d", &n, &m);
	long long coloumn[10] = { 100000, 100000, 100000,
		100000, 100000, 100000, 100000, 100000, 100000, 100000};
	long long line[10];
	for (int i = 0; i < n; i++) {
		long long max = -1000000;
		for (int j = 0; j < m; j++) {
			long long d; scanf("%lld", &d);
			max = (d > max) ? d : max;
			coloumn[j] = (d < coloumn[j]) ? d : coloumn[j];
		}
		line[i] = max;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (line[i] == coloumn[j]) {
				printf("%d %d", i, j);
				goto end;
			}
		}
	}
	printf("none");
	end: return 0;
}
