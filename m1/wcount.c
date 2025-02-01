#include <stdio.h>
int wcount(char* s) {
	long ind = 0;
	short is_alpha = 0;
	long col = 0;
	while (s[ind] != '\0') {
		if (s[ind] != ' ' && is_alpha == 0) {
			is_alpha = 1; 
			col++;
		}
		else if (s[ind] == ' ' && is_alpha == 1) {
			is_alpha = 0;
		}
		ind++;
	}
	return col;
}
int main() {
	char str[10000]; gets(str);
	printf("%d", wcount(str));
	return 0;
}
