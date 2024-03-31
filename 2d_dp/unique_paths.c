#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc != 3) exit(1);

	unsigned long w, h;
	w = strtoul(argv[1], NULL, 10);
	h = strtoul(argv[2], NULL, 10);

	printf("%ld %ld\n", w, h);

	if (w == 0 || h == 0) exit(1);

	// row, col
	unsigned long arr[h][w];

	for (int row = 0; row < h; row++) {
		for (int col = 0; col < w; col++) {
			arr[row][col] = 0;
		}
	}

	arr[h - 1][w - 1] = 1;

	unsigned long right, down;
	for (int row = h - 1; row >= 0; row--) {
		for (int col = w - 1; col >= 0; col--) {
			right = 0;
			down = 0;

			if (col + 1 < w) right = arr[row][col + 1];
			if (row + 1 < h) down = arr[row + 1][col];

			arr[row][col] = right + down;

			if (col == w - 1 && row == h - 1) arr[row][col] = 1;
		}
	}

	printf("Number: %ld\n", arr[0][0]);

	for (int row = 0; row < h; row++) {
		for (int col = 0; col < w; col++) {
			printf("%ld ", arr[row][col]);
		}
		printf("\n");
	}

	return 0;
}
