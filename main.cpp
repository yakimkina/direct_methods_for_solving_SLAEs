#include "main.h"

// хранить матрицу по столбцам, а не строкам

// TO DO in both methods:
// if abs(slae[i][j]) < PREC
//     slae[i][j] = 0;

// read about how is it better to pass vector: using & or not

// QR - how to check if matrix is degenerate

// if make class think about passing arg size or not - возможно, нужно использовать полиформизм

// add in which method was an error & not exit the program

// в местах создания матрицы/вектора изменить на создание через конструктор с подачей туда аргумента
// vector<vector<mytype» init_matrix(matrix.size(), vector<mytype> (matrix[0].size() - 1));
// или
// vector<vector<mytype» init_matrix(matrix.size()(matrix[0].size() - 1));
// переписать комментарии и вывод на русский
void	print_info()
{
	cout << endl << MAGENTA << "Программа решения СЛАУ методом Гаусса(с полным выбором главного элемента) и методом QR разложения." << endl;
	cout << "Работу выполнили " << GREEN << "Мыльникова Е." << MAGENTA << " и " << GREEN << "Якимкина П." << MAGENTA <<", группа " \
	<< GREEN << "ФН12-51Б" << MAGENTA << ", варианты: 19 и 30." << endl;

	string file_name = FILE_NAME;
	cout << endl << "Файл: " << file_name.substr(file_name.rfind("/") + 1) << endl;
}

int		main()
{
	print_info();
	vector<vector<VALUE_TYPE>> slae = parsing_file();

	cout << endl << MAGENTA << "СЛАУ:" << RESET << endl;
	print_slae(slae);

	vector<VALUE_TYPE> Gauss_solution = Gauss_method(slae);
	if (!Gauss_solution.empty())
	{
		cout << endl << GREEN << "[МЕТОД ГАУССА] " << MAGENTA << "РЕШЕНИЕ:" << RESET << endl;
		print_vector(Gauss_solution);
		cout << endl << GREEN << "[МЕТОД ГАУССА] " << RESET;
		method_specification(slae, slae.size() - 1, Gauss_solution, Gauss_method);
	}

	vector<VALUE_TYPE> QR_solution = QR_method(slae);
	if (!QR_solution.empty())
	{
		cout << endl << GREEN << "[МЕТОД QR] " << MAGENTA << "РЕШЕНИЕ:" << RESET << endl;
		print_vector(QR_solution);
		cout << endl << GREEN << "[МЕТОД QR] " << RESET;
		method_specification(slae, slae.size() - 1, QR_solution, QR_method);
	}

	cout << endl;
	if (!Gauss_solution.empty() && !QR_solution.empty())
		matrix_specification(slae, slae.size() - 1);

	cout << endl;
	return 0;
}
