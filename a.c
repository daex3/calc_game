#include <stdio.h>
#include <stdlib.h>
#include "calc.c"

int r_to_op(int r) {
	switch (r) {
		case 0:
			return '+';

		case 1:
			return '-';

		case 2:
			return '*';

		case 3:
			return '/';

		case 4:
			return '%';
	}

	return ' ';
}

int get_input_num() {
	char	*input	= NULL;
	size_t	 n	= 1024;

	getline(&input, &n, stdin);

	int r = atoi(input);

	free(input);

	return r;
}

int main(int argc, char **argv) {
	int	m	= argc > 1 ? atoi(argv[1]) : 3000,
		m_op	= 5;

	for(;;) {
		int	x  = arc4random_uniform(m),
			op = r_to_op(arc4random_uniform(m_op)),
			y  = 1 + arc4random_uniform(m);

		printf("%d %c %d = ", x, op, y),
		fflush(stdout);

		int	a = calc(x, op, y),
			b = get_input_num();

		if (a == b)
			puts("\nYes");
		else
			puts("\nWHAT");
	}
}
