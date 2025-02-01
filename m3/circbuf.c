#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Queue {
	long long* data;
	long long cap;
	long long count;
	long long head;
	long long tail;
};
typedef struct Queue Queue;
void InitQueue(Queue* q, int n) {
	q->data = (long long*)malloc(n * sizeof(long long));
	q->cap = n;
	q->count = 0;
	q->head = 0;
	q->tail = 0;
}
bool QueueEmpty(Queue* q) {
	return (q->count == 0);
}
void up_size(Queue* q){
	long long* new_data = (long long*)malloc(q->cap * 2 * sizeof(long long));
	long long i = q->head, new_i = 0;
	new_data[new_i] = q->data[i];
	new_i++;
	i = (i + 1) % q->cap;
	while (i != q->tail) {
		new_data[new_i] = q->data[i];
		new_i++;
		i = (i + 1) % q->cap;
	}
	q->head = 0;
	q->tail = q->cap;
	q->cap *= 2;
	free(q->data);
	q->data = new_data;
}
void Enqueue(Queue* q, long long x) {
	if (q->count == q->cap) {
		up_size(q);
	}
	q->data[q->tail] = x;
	q->tail++;
	if (q->tail == q->cap)
		q->tail = 0;
	q->count++;
}
long long Dequeue(Queue* q) {
	if (QueueEmpty(q)) {
		printf("ERROR");
		return -123456789;
	}
	long long x = q->data[q->head];
	q->head++;
	if (q->head == q->cap)
		q->head = 0;
	q->count--;
	return x;
}
int main() {
	Queue q;
	InitQueue(&q, 4);
	char op[6];
	scanf("%s", op);
	while (op[0]!='E' || op[2]!='D') {
		if (op[0] == 'E' && op[1] == 'N') {
			long long x; scanf("%lld", &x);
			Enqueue(&q, x);
		}
		else if (op[0] == 'D') {
			printf("%lld\n", Dequeue(&q));
		}
		else if (op[0] == 'E') {
			printf("%s\n", (QueueEmpty(&q))?"true" : "false");
		}
		scanf("%s", op);
	}
	free(q.data);
}
