#include "Gauss_method.h"

static	vector<VALUE_TYPE>	get_solution(vector<vector<VALUE_TYPE>> &slae, int size)
{
	vector<VALUE_TYPE> x(size);

	for (int i = 0; i < size; i++)
	{
		int pos = (int)slae[size][i];
		x[pos - 1] = slae[i][size];
	}

	return x;
}

void	exit_with_message(vector<vector<VALUE_TYPE>> &slae, string message)
{
	cout << endl << RED << message << RESET << endl;
	print_slae(slae);
	exit(0);
}

void	solution_exists(vector<vector<VALUE_TYPE>> &slae)
{
	if (slae.size() != slae[0].size())
		exit_with_message(slae, "[ERROR] Матрица не квадратная:");

	for (int i = 0; i < slae.size() - 1; i++)
	{
		if (slae[i].size() != slae[i + 1].size())
			exit_with_message(slae, "[ERROR] Матрица не квадратная:");
	}
}

vector<VALUE_TYPE>	Gauss_method(vector<vector<VALUE_TYPE>> slae)
{
	int size = slae.size() - 1;

	if (PRINT_STEPS)
		cout << endl << GREEN << "[МЕТОД ГАУССА]" << RESET << endl;

	solution_exists(slae);

	bool exec = direct_traverse(slae, size);
	if (!exec) return vector<VALUE_TYPE>(0);

	if (PRINT_STEPS)
	{
		cout << endl << MAGENTA << "[МЕТОД ГАУССА] CЛАУ после прямого хода:" << RESET << endl;
		print_slae(slae);
	}

	reverse_traverse(slae, size);

	if (PRINT_STEPS)
	{
		cout << endl << MAGENTA << "[МЕТОД ГАУССА] CЛАУ после обратного хода:" << RESET << endl;
		print_slae(slae);
	}

	return get_solution(slae, size);
}

