#include "main.h"

void	matrix_specification(vector<vector<VALUE_TYPE>> slae, int size)
{
	cout << GREEN << "ХАРАКТЕРИСТИКИ МАТРИЦЫ" << RESET << endl;

	vector<vector<VALUE_TYPE>> inverse_slae = inverse(slae, size, QR_method);

	/* check if A * A^(-1) == E */
	cout << endl << MAGENTA << "A * A^(-1) = " << RESET << endl;
	print_slae(multiply(inverse_slae, slae), size);

	/* condition number */
	cout << endl << GREEN << "cond_1 A = " << RESET << get_condition_number(slae, inverse_slae, size, norm_1);
	cout << endl << GREEN << "cond_inf A = " << RESET << get_condition_number(slae, inverse_slae, size, norm_inf);
}


void	method_specification(vector<vector<VALUE_TYPE>> slae, int size, vector<VALUE_TYPE> solution, vector<VALUE_TYPE> (*method)(vector<vector<VALUE_TYPE>>))
{
	cout << MAGENTA << "ХАРАКТЕРИСТИКИ МЕТОДА" << RESET << endl;

	vector<VALUE_TYPE>	b1 = put_solution(slae, size, solution);

	vector<VALUE_TYPE>	b;
	for (int i = 0; i < size; i++)
		b.push_back(slae[i][size]);

	/* residual vector norm */
	VALUE_TYPE n = vector_norm(subtract_vectors(b, b1, size), size);
	cout.precision(PREC * 4);
	cout << endl << MAGENTA << "|| b - b1 || = " << RESET << n << endl;

	/* condition number evaluation */
	cout.precision(PREC);
	cond_with_cell cond = evaluate_condition_number(slae, size, solution, method);
	cout << endl << MAGENTA << "cond A >= " << RESET << cond.max_cond << endl;
	cout << MAGENTA << "b[" << cond.b.i << "][" << cond.b.j << "] = " << RESET << cond.b.value << " ";
	(cond.dist > 0) ? cout << "+ " : cout << "- ";
	cout << abs(cond.dist) << endl;
}

