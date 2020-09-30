#include "Gauss_method.h"

static	void	subtract_rows(vector<vector<VALUE_TYPE>> &slae, int k, int size)
{
	for (int i = k + 1; i < size; i++)
	{
		VALUE_TYPE a = slae[i][k];
		for (int j = k; j <= size; j++)
			slae[i][j] -= a * slae[k][j];
	}
}

void	permutation(vector<vector<VALUE_TYPE>> &slae, cell max, int k, int size)
{
	if (k != max.i)
		swap(slae[max.i], slae[k]);

	if (k != max.j)
	{
		for (int i = 0; i <= size; i++)
			swap(slae[i][k], slae[i][max.j]);
	}
}

cell	search_leading_element(vector<vector<VALUE_TYPE>> &slae, int k, int size)
{
	cell	max;
	
	max.value = slae[k][k];
	max.i = k;
	max.j = k;
	for (int i = k; i < size; i++)
	{
		for (int j = k; j < size; j++)
		{
			if (abs(slae[i][j]) > abs(max.value))
			{
				max.value = slae[i][j];
				max.i = i;
				max.j = j;
			}
		}
	}

	if (abs(max.value) < PREC_ZERO)
	{
		cout << RED << "[ERROR] Матрица вырождена!" << RESET << endl;
		max.value = 0;
	}
	
	return (max);
}

bool	direct_traverse(vector<vector<VALUE_TYPE>> &slae, int size)
{
	for (int i = 0; i < size; i++)
	{
		cell max = search_leading_element(slae, i, size);
		if (max.value == 0) return false;

		permutation(slae, max, i, size);
		
		for (int j = i; j <= size; j++)
			slae[i][j] /= max.value;

		subtract_rows(slae, i, size);
	}

	return true;
}