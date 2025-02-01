#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define ll long long

int main() {
	char* str = (char*)malloc(1000001 * sizeof(char));
	scanf("%s", str);
	ll n = strlen(str);
	str[n] = '\0';
	int m = 26;
	ll count[26] = { 0 };
	ll j = 0;
	while (j < n) {
		ll k = str[j] - 'a';
		count[k]++;
		j++;
	}
	ll i = 1;
	while (i < m) {
		count[i] = count[i] + count[i - 1];
		i++;
	}
	char* otv = (char*)malloc(1000001 * sizeof(char));
	j = n - 1;
	while (j >= 0) {
		ll k = str[j] - 'a';
		ll i = count[k] - 1;
		count[k] = i;
		otv[i] = str[j];
		j--;
	}
	otv[n] = '\0';
	puts(otv);
	free(str);
	free(otv);
}
