#include "QR_method.h"

static	vector<VALUE_TYPE>	get_solution(vector<vector<VALUE_TYPE>> &slae, int size)
{
	vector<VALUE_TYPE> x;

	for (int i = 0; i < size; i++)
		x.push_back(slae[i][size] / slae[i][i]);

	return x;
}

vector<VALUE_TYPE>	QR_method(vector<vector<VALUE_TYPE>> slae)
{
	int size = slae.size() - 1;
	
	cout << endl << GREEN << "[QR METHOD]" << RESET << endl;

	vector<vector<VALUE_TYPE>> matR = slae;
	vector<vector<VALUE_TYPE>> matT = create_T(size);
	build_R(matR, matT, size);

	/* check if matrix is degenerate */
	if (is_degenerate(matR, size))
	{
		cout << RED << "[ERROR] Matrix is degenerate!" << RESET << endl;
		return vector<VALUE_TYPE>(0);
	}

	cout << endl << MAGENTA << "R matrix:" << RESET << endl;
	print_slae(matR);

	vector<vector<VALUE_TYPE>>	matQ = transpose(matT);

	cout << endl << MAGENTA << "Q matrix:" << RESET << endl;
	print_slae(matQ, matQ.size());

	/* check if QR == A */

//	make in class: if (A == multiplication(matQ, matR))

	cout << endl << YELLOW << "[check] A - QR:" << endl << "A:" << RESET << endl;
	vector<vector<VALUE_TYPE>>	matA = multiplication(matQ, matR);
	vector<vector<VALUE_TYPE>>	delta = subtraction(slae, matA, size, size);
	print_slae(delta, delta.size());

	reverse_traverse(matR, size);

	return get_solution(matR, size);
}

