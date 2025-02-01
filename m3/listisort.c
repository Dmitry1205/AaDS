#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Elem {
	struct Elem* prev, * next;
	int v;
} Elem;
void InitDoubleLinkedList(Elem* l) {
	l->prev = l;
	l->next = l;
}

bool ListEmpty(Elem* l) {
	return (l->next == l);
}

void InsertAfter(Elem* x, Elem* y) {
	Elem* z = x->next;
	x->next = y;
	y->prev = x;
	y->next = z;
	z->prev = y;
}
void InsertBefore(Elem* x, Elem* y) {
	Elem* z = x->prev;
	x->prev->next = y;
	x->prev = y;
	y->next = x;
	y->prev = z;
	z->next = y;
}
void vstavka(Elem* l, Elem* x) {
	if (ListEmpty(l)) {
		InsertAfter(l, x);
		return;
	}
	Elem* p =l->next;
	do {
		if (x->v < p->v) {
			InsertBefore(p, x);
			return;
		}
		p = p->next;
	} while (p!= l);
	InsertAfter(p->prev, x);
}
typedef struct Elem Elem;
int main() {
	int n;
	scanf("%d", &n);
	Elem* l = (Elem*)malloc(sizeof(Elem));
	l->v = -123456789;
	InitDoubleLinkedList(l);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		Elem* x = (Elem*)malloc(sizeof(Elem));
		x->v = a;
		//Сортируем втавками по ходу считывания
		vstavka(l, x);
	}
	Elem* p=l->next;
	for (int i = 0; i < n; i++) {
		printf("%d ", p->v);
		p = p->next;
	}
	p = l->next;
	while (p != l) {
		p = p->next;
		free(p->prev);
	}
	free(l);
}
