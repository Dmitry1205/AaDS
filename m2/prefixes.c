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

int main(int argc, char** argv) {
	if (argc != 2) {
		printf("ERROR");
		return 0;
	}
	char* str = argv[1];
	int len = strlen(str);
	int* otv = Prefix(str);
	for (int i = 1; i <= len; i++) {
		if (i  % (i - otv[i-1]) == 0) {
			if (i / (i - otv[i-1])>1) {
				printf("%d %d\n", i, i/(i-otv[i-1]));
			}
		}
	}
	free(otv);
	return 0;
}
