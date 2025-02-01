#include <stdio.h>

int main(){
	long long n, x0, a; 
	scanf("%lld %lld", &n, &x0);
	scanf("%lld", &a); 
	long long otv1 = a;
	long long otv2 = a*(n--);
	
	for (int i = n; i>=0; i--) {
		long long a; scanf("%lld", &a);
		otv1 = (otv1*x0 + a);
		if(i>0)
			otv2 = (otv2*x0 + a * i);
	}
	printf("%lld %lld", otv1, otv2);
}
