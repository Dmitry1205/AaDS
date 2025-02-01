#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define ll long long
void csort(char* src, char *dest) {
	char words[1001][1001];
	ll ind = 0, i = 0, col = 0;
	bool is_alpha = 0;
	while (src[ind] != '\0') {
		if (src[ind] != ' ' && is_alpha == 0) {
			words[col][i] = src[ind];
			i++;
			is_alpha = 1;
		}
		else if (src[ind] == ' ' && is_alpha == 1) {
			words[col][i] = '\0';
			col++;
			i = 0;
			is_alpha = 0;
		}
		else if (src[ind] != ' ') {
			words[col][i] = src[ind];
			i++;
			if (src[ind + 1] == '\0' || src[ind + 1] == '\n') {
				words[col][i] = '\0';
				col++;
				break;
			}
		}
		ind++;
	}
	ll count[1001] = { 0 };
	ll j = 0;
	while (j < col - 1) {
		ll i = j + 1;
		while (i < col) {
			if (strlen(words[i]) < strlen(words[j]))
				count[j] = count[j] + 1;
			else
				count[i] = count[i] + 1;
			i++;
		}
		j++;
	}
	char *itog[1200];
	for (ll i = 0; i < col; i++) {
		itog[count[i]]=words[i];
	}
	ll q = 0;
	for (ll i = 0; i < col; i++) {
		ll ind = 0;
		while (itog[i][ind]!='\0') {
			dest[q] = itog[i][ind];
			ind++;
			q++;
		}
		if (i != col - 1) {
			dest[q] = ' ';
			q++;
		}
		else
			dest[q] = '\0';
	}
}

int main() {
	char src[2001];
	char dest[2001];
	fgets(src, 2001, stdin);
	csort(src, dest);
	printf("%s", dest);
}
