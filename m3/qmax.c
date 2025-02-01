#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct DoubleStack {
	long long cap;
	long long top1;
	long long top2;
	long long* max;
	long long uk1;
	long long uk2;
	long long* data;
} DoubleStack;

void InitDoubleStack(DoubleStack* s, long long n) {
	s->data = (long long*)malloc(n * sizeof(long long));
	s->max = (long long*)malloc(n * sizeof(long long));
	s->uk1 = 0;
	s->uk2 = 0;
	s->cap = n;
	s->top1 = 0;
	s->top2 = n - 1;
}
bool StackEmpty1(DoubleStack* s) {
	return (s->top1 == 0);
}
bool StackEmpty2(DoubleStack* s) {
	return (s->top2 == s->cap - 1);
}
void Push1(DoubleStack* s,long long x) {
	if (s->top2 < s->top1) {
		return;
	}
	s->data[s->top1] = x;
	s->top1++;
}
void Push2(DoubleStack* s,long long x) {
	if (s->top2 < s->top1) {
		return;
	}
	s->data[s->top2] = x;
	s->top2--;
}
long long Pop1(DoubleStack* s) {
	if (StackEmpty1(s)) {
		return -12345678;
	}
	s->top1--;
	return s->data[s->top1];
}
long long Pop2(DoubleStack* s) {
	if (StackEmpty2(s)) {
		return -12345678;
	}
	s->top2++;
	return s->data[s->top2];
}
void InitQueueOnStack(DoubleStack* St,long long n) {
	InitDoubleStack(St, n);
}
bool QueueEmpty(DoubleStack* St) {
	return (StackEmpty1(St) && StackEmpty2(St));
}
void Enqueue(DoubleStack* s, long long x) {
	Push1(s, x);
	if (s->uk1 == s->uk2) {
		s->max[s->uk1] = x;
		s->uk2++;
		return;
	}
	for (long long i = s->uk2-1; i >= s->uk1; i--) {
		if (x > s->max[i]) {
			s->uk2--;
		}
		else {
			s->max[i + 1] = x;
			s->uk2++;
			return;
		}
	}
	s->max[s->uk1] = x;
	s->uk2++;
}
long long Dequeue(DoubleStack* s) {
	if (StackEmpty2(s)) {
		while (!StackEmpty1(s))
			Push2(s, Pop1(s));
	}
	long long poper = Pop2(s);
	if (s->max[s->uk1] == poper) {
		s->uk1++;
	}
	return poper;
}
long long Maximum(DoubleStack* s) {
	return s->max[s->uk1];
}
int main() {
	DoubleStack St;
	InitQueueOnStack(&St, 10000000);
	char op[6];
	scanf("%s", op);
	while (op[0] != 'E' || op[2] != 'D') {
		if (op[0] == 'E' && op[2] == 'Q') {
			long long x; scanf("%lld", &x);
			Enqueue(&St, x);
		}
		else if (op[0] == 'D') {
			printf("%lld\n", Dequeue(&St));
		}
		else if (op[0] == 'E' && op[1] == 'M') {
			printf(QueueEmpty(&St) ? "true\n" : "false\n");
		}
		else if (op[0] == 'M') {
			printf("%lld\n", Maximum(&St));
		}
		scanf("%s", op);
	}
	free(St.data);
	free(St.max);
}
