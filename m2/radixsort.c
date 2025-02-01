#include <stdio.h>
#include <stdlib.h>
union Int32 {
	int x;
	unsigned char bytes[4];
};
typedef union Int32 Int32;
Int32 *DistributionSort(int m, Int32* S, int n, int q) {
	int count[512] = {0};
	int j = 0, k=0;
	while (j < n) {
		switch (q) {
			case 0: k = S[j].bytes[0]; break;
			case 1: k = S[j].bytes[1]; break;
			case 2: k = S[j].bytes[2]; break;
			case 3: k = S[j].bytes[3]; break;
		}
		if (S[j].x >= 0)
			k += 256;
		count[k] ++;
		j++;
	}
	int i = 1;
	while (i < m) {
		count[i] = count[i] + count[i - 1];
		i++;
	}
	Int32* D = (Int32 *)malloc((n+1) * sizeof(Int32));
	j = n - 1;
	while (j >= 0) {
		switch (q) {
			case 0: k = S[j].bytes[0]; break;
			case 1: k = S[j].bytes[1]; break;
			case 2: k = S[j].bytes[2]; break;
			case 3: k = S[j].bytes[3]; break;
		}
		if (S[j].x >= 0)
			k += 256;
		i = count[k] - 1;
		count[k] = i;
		D[i] = S[j];
		j--;
	}
	free(S);
	return D;
}

Int32* RadixSort(int q, int col_m, Int32* S, int n) {
	Int32* D = (Int32*)malloc((n+1)*sizeof(Int32));
	for (int i = 0; i < n; i++) {
		D[i] = S[i];
	}
	int i = 0;
	while (i <= q-1) {
		D = DistributionSort(col_m, D, n, i);
		i++;
	}
	return D;
}
int main() {
	int n; scanf("%d", &n);
	Int32* list=(Int32 *)malloc(1000000*sizeof(Int32));
	for (int i = 0; i < n; i++) {
		int h; scanf("%d", &h);
		list[i].x = h;
	}
	union Int32* otv = RadixSort(4, 512, list, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", otv[i].x);
	}
	free(otv);
	free(list);
	return 0;
}
