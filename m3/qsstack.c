#include <stdio.h>
#include <stdlib.h>

typedef struct Task {
	int low, high;
} Task;
typedef struct Stack {
	int cap;
	int top;
	Task* data;
} Stack;
void InitStack(Stack* s, int n) {
	s->data = (Task*)malloc(n * sizeof(Task));
	s->cap = n;
	s->top = 0;
}
int StackEmpty(Stack* s) {
	return s->top == 0;
}
void Push(Stack* s, Task x) {
	if (s->top == s->cap) {
		return;
	}
	s->data[s->top] = x;
	s->top = s->top + 1;
}
Task Pop(Stack* s) {
	if (StackEmpty(s)) {
		printf("ERROR");
		Task error;
		error.low = -1;
		error.high = -1;
		return error;
	}
	s->top -= 1;
	return s->data[s->top];
}
int Partion(int low, int high, int p[]) {
	int i = low;
	int  j = low;
	while (j < high) {
		if (p[j] < p[high]) {
			int dop = p[i];
			p[i] = p[j];
			p[j] = dop;
			i++;
		}
		j++;
	}
	int dop2 = p[i];
	p[i] = p[high];
	p[high] = dop2;
	return i;
}
int main() {
	int n; scanf("%d", &n);
	int* l = (int*)malloc((n+1)*sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &l[i]);
	}
	Stack St;
	InitStack(&St, n+2);
	Task start;
	start.low = 0;
	start.high = n-1;
	Push(&St, start);
	while (!StackEmpty(&St)) {
		Task cur = Pop(&St);
		if (cur.low < cur.high) {
			int boarder=Partion(cur.low, cur.high, l);
			Task first;
			first.low = cur.low;
			first.high = boarder-1;
			Task second;
			second.low = boarder+1;
			second.high = cur.high;
			Push(&St, first);
			Push(&St, second);
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", l[i]);
	}
	free(St.data);
	free(l);
}
