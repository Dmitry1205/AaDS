#include <stdio.h>
#include <stdlib.h>
char* fibstr(int n) {
	long long a=1, b=1;
	for (int i = 2; i < n; i++) {
		long long dop;
		dop = a;
		a = b;
		b = dop + b;
	}
	char* cstr = (char*)malloc((b + 1) * sizeof(char));
	char* astr = (char*)malloc((b + 1) * sizeof(char));
	char* bstr = (char*)malloc((b + 1) * sizeof(char));
	if (n == 1) {
		cstr[0] = 'a'; cstr[1] = '\0';
		free(astr);
		free(bstr);
		return cstr;
	}
	else if (n == 2) {
		cstr[0] = 'b'; cstr[1] = '\0';
		free(astr);
		free(bstr);
		return cstr;
	}
	astr[0] = 'a'; astr[1] = '\0'; astr[b] = '\0';
	bstr[0] = 'b'; bstr[1] = '\0'; bstr[b] = '\0';
	cstr[0] = '\0';
	for (int i = 2; i < n; i++) {
		for (int j = 0; j < b; j++) {
			if(astr[j]=='\0'){
				cstr[j] = '\0';
				break;
			}
			cstr[j] = astr[j];
		}
		for (int j = 0; j < b; j++) {
			if (bstr[j] == '\0') {
				astr[j] = '\0';
				break;
			}
			astr[j] = bstr[j];
			}
			long long ind = 0;
			while (ind < b && cstr[ind]!='\0') {
				bstr[ind] = cstr[ind];
				ind++;
			}
			for (int j = 0; j < b; j++) {
				if (astr[j] == '\0') {
					bstr[ind] = '\0';
					break;
				}
				bstr[ind] = astr[j];
				ind++;
				}
			}
			free(astr);
			free(cstr);
			bstr[b] = '\0';
			return bstr;

}

int main() {
	int n; scanf("%d", &n);
	char* res=fibstr(n);
	puts(res);
	free(res);
}
