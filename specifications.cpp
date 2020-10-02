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

	/* norm_1 */
	cond_with_cell cond_1 = evaluate_condition_number(slae, size, solution, method, vector_norm_1);
	cout << endl << MAGENTA << "cond_1 A >= " << RESET << cond_1.max_cond << endl;
	cout << MAGENTA << "b[" << cond_1.b.i << "] = " << RESET << cond_1.b.value << " ";
	(cond_1.dist > 0) ? cout << "+ " : cout << "- ";
	cout << abs(cond_1.dist) << endl;

	/* norm_inf */
	cond_with_cell cond_inf = evaluate_condition_number(slae, size, solution, method, vector_norm_inf);
	cout << endl << MAGENTA << "cond_inf A >= " << RESET << cond_inf.max_cond << endl;
	cout << MAGENTA << "b[" << cond_inf.b.i << "] = " << RESET << cond_inf.b.value << " ";
	(cond_inf.dist > 0) ? cout << "+ " : cout << "- ";
	cout << abs(cond_inf.dist) << endl;
}

