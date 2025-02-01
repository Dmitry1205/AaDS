#include <stdio.h>
#include <stdlib.h>

struct Date {
	int Day, Month, Year;
};
struct Date* DistributionSort(int m, struct Date* S, int n, int q) {
	int count[100000] = {0};
	int j = 0, k=0;
	while (j < n) {
		switch (q) {
			case 0: k = S[j].Year-1970; break;
			case 1: k = S[j].Month-1; break;
			case 2: k = S[j].Day-1; break;
		}
		count[k] ++;
		j++;
	}
	int i = 1;
	while (i < m) {
		count[i] = count[i] + count[i - 1];
		i++;
	}
	struct Date* D = (struct Date*)malloc((n+1) * sizeof(struct Date));
	j = n - 1;
	while (j >= 0) {
		switch (q) {
			case 0: k = S[j].Year-1970; break;
			case 1: k = S[j].Month-1; break;
			case 2: k = S[j].Day-1; break;
		}
		i = count[k] - 1;
		count[k] = i;
		D[i] = S[j];
		j--;
	}
	free(S);
	return D;
}

struct Date* RadixSort(int q, int col_m[], struct Date S[], int n) {
	struct Date* D = (struct Date*)malloc((n+1)*sizeof(struct Date));
	for (int i = 0; i < n; i++) {
		D[i] = S[i];
	}
	int i = q-1;
	while (i >= 0) {
		D = DistributionSort(col_m[i], D, n, i);
		i--;
	}
	return D;
}
int col_m[3] = { 61, 13, 32 };
int main() {
	int n; scanf("%d", &n);
	struct Date dates[100000] = { 0 };
	for (int i = 0; i < n; i++) {
		int year, month, day; scanf("%d %d %d", &year, &month, &day);
		dates[i].Day = day;
		dates[i].Month = month;
		dates[i].Year = year;
	}
	struct Date* otv = RadixSort(3, col_m, dates, n);
	for (int i = 0; i < n; i++) {
		printf("%04d %02d %02d\n", otv[i].Year, otv[i].Month, otv[i].Day);
	}
	free(otv);
	return 0;
}
