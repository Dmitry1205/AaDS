#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int* Prefix(char* S) {
	int len = strlen(S);
	int* P = (int*)malloc(len * sizeof(int));
	int t = 0;
	P[0] = t;
	int i = 1;
	while (i < len) {
		while (t > 0 && S[t] != S[i]) {
			t = P[t - 1];
		}
		if (S[t] == S[i]) {
			t++;
		}
		P[i] = t;
		i++;
	}
	return P;
}
void KMPSubst(char* T, char* S) {
	int* p = Prefix(S);
	int q = 0;
	int k = 0;
	int len_T = strlen(T);
	int len_S = strlen(S);
	while (k < len_T) {
		while (q > 0 && S[q] != T[k])
			q = p[q - 1];
		if (S[q] == T[k])
			q++;
		if (q == len_S) {
			k = k - len_S + 1;
			printf("%d\n", k);
			q = 0;
		}
		k++;
	}
	free(p);
}
int main(int argc, char** argv) {
	if (argc != 3) {
		printf("ERROR");
		return 0;
	}
	char* str1 = argv[2];
	char* str2 = argv[1];
	KMPSubst(str1, str2);
	return 0;
}
