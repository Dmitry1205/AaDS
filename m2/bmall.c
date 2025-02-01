#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int* Suffix(char* S) {
	int len_S = strlen(S);
	int* g = (int*)malloc(len_S*sizeof(int));
	int t = len_S-1;
	g[len_S - 1] = t;
	int i = len_S - 2;
	while (i >= 0) {
		while ((t < len_S - 1) && (S[t] != S[i])) {
			t = g[t + 1];
		}
		if (S[t] == S[i])
			t--;
		g[i] = t;
		i--;
	}
	return g;
}
int* Delta1(char* S, int size) {
	int len = strlen(S);
	int* g1 = (int*)malloc(size * sizeof(int));
	int a = 0;
	while (a < size) {
		g1[a] = len;
		a++;
	}
	int j = 0;
	while (j < len) {
		g1[S[j]] = len - j - 1;
		j++;
	}
	return g1;
}
int* Delta2(char* S) {
	int len = strlen(S);
	int* g2 = (int*)malloc(len*sizeof(int));
	int* d = Suffix(S);
	int i = 0;
	int t = d[0];
	while (i < len) {
		while (t < i) {
			t = d[t + 1];
		}
		g2[i] = -i + t + len;
		i++;
	}
	i = 0;
	while (i < len - 1) {
		t = i;
		while (t < len - 1) {
			t = d[t + 1];
			if (S[i] != S[t])
				g2[t] = -(i + 1) + len;
		}
		i++;
	}
	free(d);
	return g2;
}
void BMSubst(char* S, int size, char* T) {
	int len_S = strlen(S);
	int len_T = strlen(T);
	int* g1 = Delta1(S, size);
	int* g2 = Delta2(S);
	int k = len_S - 1;
	int c = 0;
	while (k<len_T) {
		int i = len_S - 1;
		while (T[k] == S[i]) {
			if (i == 0) {
				printf("%d\n", k);
				break;
			}
			i--;
			k--;
		}
		k = k + ((g1[T[k]] > g2[i]) ? g1[T[k]] : g2[i]);
	}
	k = len_T;
	free(g1);
	free(g2);
}
int main(int argc, char** argv) {
	if (argc != 3) {
		printf("ERROR");
		return 0;
	}
	char* str1 = argv[1];
	char* str2 = argv[2];
	BMSubst(str1, 126, str2);
	return 0;
}
