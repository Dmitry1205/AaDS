#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ll long long
void sort_vs(ll n, ll* a) {
    ll el, loc;
    ll i = 1;
    while(i < n){
        el = a[i];
        loc = i - 1;
        while (loc >= 0 && abs(a[loc]) > abs(el)){
            a[loc + 1] = a[loc];
            loc = loc - 1;
        }
        a[loc + 1] = el;
        i++;
    }
}
void merge_sort(ll n, ll* a) {
    if (n < 5) {
        sort_vs(n, a);
        return;
    }
    ll* left = (ll*)malloc((n / 2 + 1) * sizeof(ll));
    ll* right = (ll*)malloc((n - n / 2 + 1) * sizeof(ll));
    for (ll i = 0; i < n; i++) {
        if (i < n / 2)
            left[i] = a[i];
        else
            right[i - n / 2] = a[i];
    }
    merge_sort(n / 2, left);
    merge_sort(n - (n / 2), right);
    ll uk1 = 0; 
    ll uk2 = 0;
    while (uk1 + uk2 < n) {
        if (uk1 >= n / 2) {
            a[uk1 + uk2] = right[uk2];
            uk2 ++;
        }
        else if (uk2 >= n - n / 2) {
            a[uk1 + uk2] = left[uk1];
            uk1++;
        }
        else {
            if (abs(left[uk1]) <= abs(right[uk2])) {
                a[uk1 + uk2] = left[uk1];
                uk1++;
            }
            else {
                a[uk1 + uk2] = right[uk2];
                uk2++;
            }
        }
    }
    free(left);
    free(right);
}

int main() {
    ll n; scanf("%lld", &n);
    ll* a = (ll*)malloc(n * sizeof(ll));
    for (ll i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    merge_sort(n, a);
    for (ll i = 0; i < n; i++)
        printf("%lld ", a[i]);
    free(a);
    return 0;
}
