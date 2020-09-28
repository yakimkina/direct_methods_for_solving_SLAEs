#include "main.h"

vector<vector<VALUE_TYPE>>	subtraction(vector<vector<VALUE_TYPE>> &a, vector<vector<VALUE_TYPE>> &b, int m, int n)
{
	vector<vector<VALUE_TYPE>>	slae;

	for (int i = 0; i < m; i++)
	{
		vector<VALUE_TYPE>	tmp;

		for (int j = 0; j < n; j++)
			tmp.push_back(a[i][j] - b[i][j]);

		slae.push_back(tmp);
	}

	return (slae);
}


