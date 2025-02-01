#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv) {
	if (argc != 4) {
		printf("Usage: frame <height> <width> <text>");
		return 0;
	}
	int h=atoi(argv[1]);
	int w = atoi(argv[2]);
	int len = strlen(argv[3]);
	if (len > w - 2 || h<3)
		printf("Error");
	else {
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (i == 0 || i == h - 1)
					printf("*");
				else if (j == 0 || j == w - 1)
					printf("*");
				else if (i == (h-1)/ 2 && j == 1 + (w - 2 - len) / 2) {
					for (int q = 0; q < len; q++) {
						printf("%c", argv[3][q]);
					}
					j += len-1;
				}
				else
					printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}
