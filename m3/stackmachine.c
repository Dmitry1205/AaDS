#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Stack {
	long long cap;
	long long top;
	long long* data;
};
typedef struct Stack Stack;

long long max(long long a, long long b) {
	return (a > b) ? a : b;
}
long long min(long long a, long long b) {
	return (a < b) ? a : b;
}
void InitStack(Stack* s, int n) {
	s->data = (long long*)malloc(n*sizeof(long long));
	s->cap = n;
	s->top = 0;
}
int StackEmpty(Stack* s) {
	return s->top == 0;
}
void Push(Stack* s, long long x) {
	if (s->top == s->cap) {
		printf("ERROR");
		return;
	}
	s->data[s->top] = x;
	s->top = s->top + 1;
}
long long Pop(Stack* s) {
	if (StackEmpty(s)) {
		printf("ERROR");
		return -123456789;
	}
	s->top -= 1;
	return s->data[s->top];
}
int main() {
	Stack St;
	InitStack(&St, 1000000);
	char op[6];
	scanf("%s", op);
	while (op[0] != 'E') {
		if (op[0] == 'C') {
			long long x; scanf("%lld", &x);
			Push(&St, x);
		}
		else if (op[0] == 'A') {
			Push(&St, Pop(&St) + Pop(&St));
		}
		else if (op[0] == 'S' && op[1] == 'U') {
			Push(&St, Pop(&St) - Pop(&St));
		}
		else if (op[0] == 'M' && op[1] == 'U') {
			Push(&St, Pop(&St) * Pop(&St));
		}
		else if (op[0] == 'D' && op[1] == 'I') {
			Push(&St, Pop(&St) / Pop(&St));
		}
		else if (op[0] == 'M' && op[1] == 'A') {
			Push(&St, max(Pop(&St), Pop(&St)));
		}
		else if (op[0] == 'M' && op[1] == 'I') {
			Push(&St, min(Pop(&St), Pop(&St)));
		}
		else if (op[0] == 'N') {
			Push(&St, -Pop(&St));
		}
		else if (op[0] == 'D') {
			Push(&St, St.data[St.top - 1]);
		}
		else if (op[0] == 'S' && op[1] == 'W') {
			long long a = Pop(&St);
			long long b = Pop(&St);
			Push(&St, a);
			Push(&St, b);
		}
		scanf("%s", op);
	}
	printf("%lld", St.data[St.top - 1]);
	free(St.data);
}
