#include "main.h"

// TO DO in both methods:
// if abs(slae[i][j]) < PREC
//     slae[i][j] = 0;

// read about how is it better to pass vector: using & or not

// QR - how to check if matrix is degenerate

// if make class think about passing arg size or not - возможно, нужно использовать полиформизм

// add in which metod was an error & not exit the program

int		main()
{
	vector<vector<VALUE_TYPE>> slae = parsing_file();

	cout << endl << BLUE << "SLAE given:" << RESET << endl;
	print_slae(slae);

	vector<VALUE_TYPE> Gauss_solution = Gauss_method(slae);
	if (!Gauss_solution.empty())
	{
		cout << endl << BLUE << "VECTOR X [GAUSS solution]:" << RESET << endl;
		print_vector(Gauss_solution);
	}

	vector<VALUE_TYPE> QR_solution = QR_method(slae);
	if (!QR_solution.empty())
	{
		cout << endl << BLUE << "VECTOR X [QR solution]:" << RESET << endl;
		print_vector(QR_solution);
	}

	return 0;
}
