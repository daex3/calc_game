int calc(int x, char op, int y) {
	switch (op) {
		case '+':
			return x + y;

		case '-':
			return x - y;

		case '*':
			return x * y;

		case '/':
			return x / y;

		case '%':
			return x % y;
	}

	return -1;
}
