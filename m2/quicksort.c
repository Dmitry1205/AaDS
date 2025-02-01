#include <stdio.h>
#include <stdlib.h>

#define ll long long
void SelectSort(ll s[], ll l, ll r) {
	ll j = r;
	while (j > l) {
		ll k = j;
		ll i = j - 1;
		while (i >= 0) {
			if (s[k] < s[i])
				k = i;
			i--;
		}
		ll dop = s[j];
		s[j] = s[k];
		s[k] = dop;
		j--;
	}
}
ll Partion(ll low, ll high, ll p[]) {
	ll i = low;
	ll j = low;
	while (j < high) {
		if (p[j] < p[high]) {
			ll dop = p[i];
			p[i] = p[j];
			p[j] = dop;
			i++;
		}
		j++;
	}
	ll dop2 = p[i];
	p[i] = p[high];
	p[high] = dop2;
	return i;
}
void QuickSortRec(ll low, ll high, ll s[], ll m) {
	while (low < high) {
		if (high - low + 1 < m) {
			SelectSort(s, low, high);
			return;
		}
		ll q = Partion(low, high, s);
		if (q - low < high - q) {
			QuickSortRec(low, q - 1, s, m);
			low = q + 1;
		}
		else {
			QuickSortRec(q+1, high, s, m);
			high = q - 1;
		}
	}
}
void QuickSort(ll n, ll s[], ll m) {
	QuickSortRec(0, n-1, s, m);
}

int main() {
	ll n, m;
	scanf("%lld %lld", &n, &m);
	ll s[1000] = {0};
	for (ll i = 0; i < n; i++) {
		scanf("%lld", &s[i]);
	}
	QuickSort(n, s, m);
	for (ll i = 0; i < n; i++) {
		printf("%lld ", s[i]);
	}
}
