#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* concat(char** s, int n) {
	long long itog_len = 0;
	for (int i = 0; i < n; i++) {
		itog_len += strlen(s[i]);
	}
	char* itog = (char*)malloc((itog_len + 1) * sizeof(char));
	long long ind = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10000001; j++) {
			if (s[i][j] == '\0' || s[i][j] == '\n')
				break;
			itog[ind] = s[i][j];
			ind++;
		}
	}
	itog[ind] = '\0';
	return itog;
}

int main() {
	int n; scanf("%d\n", &n);
	char** s = (char**)malloc((n + 1) * sizeof(char*));
	for (int i = 0; i < n; i++) {
		char* a = (char*)malloc(1001 * sizeof(char));
		fgets(a, 1001, stdin);
		s[i] = a;
		s[i][strlen(s[i]) - 1] = '\0';
	}
	char* res = concat(s, n);
	puts(res);
	free(res);
	for (int i = 0; i < n; i++) {
		free(s[i]);
	}
	free(s);
}
