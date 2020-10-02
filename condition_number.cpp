#include "main.h"

void	put_vector(vector<vector<VALUE_TYPE>> &slae, int size, VALUE_TYPE dist, int row)
{
	for (int i = 0; i < size; i++)
		slae[i][size] = (i == row) ? dist : 0;
}

vector<VALUE_TYPE>	get_vector(vector<vector<VALUE_TYPE>> slae, int size, int col)
{
	vector<VALUE_TYPE>	tmp;

	for (int i = 0; i < size; i++)
		tmp.push_back(slae[i][col]);

	return tmp;
}

VALUE_TYPE	errors_ratio(vector<vector<VALUE_TYPE>> slae, int size, VALUE_TYPE dist, int pos, VALUE_TYPE norm_x, VALUE_TYPE norm_b, \
		vector<VALUE_TYPE> (*method)(vector<vector<VALUE_TYPE>>), VALUE_TYPE (*norm)(vector<VALUE_TYPE>, int))
{
	put_vector(slae, size, dist, pos);
	vector<VALUE_TYPE> delta_solution = method(slae);
	VALUE_TYPE	norm_delta_x = norm(delta_solution, size);
	VALUE_TYPE	norm_delta_b = DELTA_B;

//	cout << YELLOW << "norm delta x = " << norm_delta_x << endl;
//	cout << "norm x = " << norm_x << endl;
//	cout << "norm delta b = " << norm_delta_b << endl;
//	cout << "norm b = " << norm_b << endl;
//
//	cout << RED << "delta_x = " << (norm_delta_x / norm_x) << endl;
//	cout << RED << "delta_b = " << (norm_delta_b / norm_b) << endl;
//	cout << RED << "cond = " << (norm_delta_x / norm_x) / (norm_delta_b / norm_b) << endl << endl;

	return ((norm_delta_x / norm_x) / (norm_delta_b / norm_b));
}

cond_with_cell	evaluate_condition_number(vector<vector<VALUE_TYPE>> slae, int size, vector<VALUE_TYPE> solution, \
vector<VALUE_TYPE> (*method)(vector<vector<VALUE_TYPE>>), VALUE_TYPE (*norm)(vector<VALUE_TYPE>, int))
{
	VALUE_TYPE	norm_x = norm(solution, size);
	VALUE_TYPE	norm_b = norm(get_vector(slae, size, size), size);

	cond_with_cell	tmp;
	tmp.max_cond = 0;
	for (int i = 0; i < size; i++)
	{
		for (int k = -1; k < 2; k += 2)
		{
			VALUE_TYPE	cond = errors_ratio(slae, size, DELTA_B * k, i, norm_x, norm_b, method, norm);
			if (cond > tmp.max_cond)
			{
				tmp.max_cond = cond;
				tmp.dist = DELTA_B * k;
				tmp.b.value = slae[i][size];
				tmp.b.i = i;
//				tmp.b.j = size;
			}
		}
	}

	return tmp;
}

VALUE_TYPE	get_condition_number(vector<vector<VALUE_TYPE>> slae, vector<vector<VALUE_TYPE>> inverse_slae, int size, VALUE_TYPE (*norm)(vector<vector<VALUE_TYPE>>, int))
{
	VALUE_TYPE	norm_slae = norm(slae, size);
	VALUE_TYPE	norm_inverse_slae = norm(inverse_slae, size);
	
	return (norm_slae * norm_inverse_slae);
}
