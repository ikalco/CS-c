#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	if (argc != 3) exit(1);

	char *first = argv[1];
	char *second = argv[2];

	int first_len = strlen(first);
	int second_len = strlen(second);

	int count = 0;

	int i = 0;
	int j = 0;

	while (i < first_len && j < second_len) {
		if (first[i] != second[j]) {
			i++;
			continue;
		}

		count++;
		i++;
		j++;
	}

	printf("Count: %d\n", count);

	return 0;
}
