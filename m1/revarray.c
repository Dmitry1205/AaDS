#include <stdio.h>
void revarray(void* base, size_t nel, size_t width) {
	int left = 0;
	int right = (nel - 1) * width;
	char* uk = (char*)base;
	while(left<right) {
		for (int i = 0; i < width; i++) {
			char* a = (uk + left + i);
			char* b = (uk + right + i);
			*a = *a + *b;
			*b = *a - *b;
			*a = *a - *b;
		}
		left += width;
		right -= width;
	}
}
