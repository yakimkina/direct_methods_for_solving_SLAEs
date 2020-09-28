#include "main.h"

VALUE_TYPE	sum(vector<VALUE_TYPE> a_i, vector<vector<VALUE_TYPE>> &b, int j, int size)
{
	VALUE_TYPE s = 0;

	for (int i = 0; i < size; i++)
		s += a_i[i] * b[i][j];

	return s;
}

vector<vector<VALUE_TYPE>>	multiplication(vector<vector<VALUE_TYPE>> &a, vector<vector<VALUE_TYPE>> &b)
{
	vector<vector<VALUE_TYPE>> slae;

	/* a is [m x n] size, b is [n x k] size */
	int		m = a.size() - A__ID_COLUMN;
	int		n = a[0].size() - A__B_COLUMN;
	int		k = b[0].size() - B__B_COLUMN;
	
	if (n != b.size() - B__ID_COLUMN)
	{
		cerr << "[ERROR] Multiplication stopped. Wrong dimensions." << endl;
		exit(0);
	}

	for (int i = 0; i < m; i++)
	{
		vector<VALUE_TYPE> tmp;
		for (int j = 0; j < k; j++)
			tmp.push_back(sum(a[i], b, j, n));

		slae.push_back(tmp);
	}

	return slae;
}

