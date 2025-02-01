#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int strdiff(char* a, char* b) {
	int i = 0;
	while (a[i] != '\0' || b[i] != '\0') {
		int c = a[i];
		int d = b[i];
		if (c == d) {
			i++;
			continue;
		}
		int col = 0;
		for (int j = 1; j <= 8; j++) {
			if ((c & ((int)pow(2, j) - 1)) != (d & ((int)pow(2, j) - 1)))
				break;
			col++;
		}
		return (col + i * 8);

	}
	return -1;
}
