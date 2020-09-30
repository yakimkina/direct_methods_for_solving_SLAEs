#include "main.h"

vector<VALUE_TYPE>	put_solution(vector<vector<VALUE_TYPE>> slae, int size, vector<VALUE_TYPE> x)
{
	vector<VALUE_TYPE>	b;

	for (int i = 0; i < size; i++)
	{
		VALUE_TYPE sum = 0;
		for (int j = 0; j < size; j++)
			sum += slae[i][j] * x[j];

		b.push_back(sum);
	}

	return b;
}

