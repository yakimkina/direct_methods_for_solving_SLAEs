#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define FILE_NAME	"../_Lab1,2/TEST/D4.TXT"
//#define FILE_NAME	"../_Lab1,2/SYS2/P_DAT30.TXT"
//#define FILE_NAME	"../_Lab1,2/SYS1/DATA30.TXT"
#define PRINT_STEPS	false
#define PRINT_CHECK	false
#define WIDTH	8
#define PREC	4
#define PREC_ZERO	0.000001
#define WITHOUT_IDS	1

/* multiplication */
#define A__ID_COLUMN	0
#define A__B_COLUMN		0
#define B__ID_COLUMN	1
#define B__B_COLUMN		1

/* colorful output */
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

using namespace std;

typedef double VALUE_TYPE;

struct	cell
{
	VALUE_TYPE	value;
	int			i;
	int			j;
};

struct cond_with_cell
{
	VALUE_TYPE	max_cond;
	VALUE_TYPE	dist;
	cell		b;
};

void	print_vector(vector<VALUE_TYPE> x);
void	print_slae(vector<vector<VALUE_TYPE>> slae); /* print SLAE with b vector */
void	print_slae(vector<vector<VALUE_TYPE>> slae, int size); /* print SLAE without b vector */

void	exit_with_message(vector<vector<VALUE_TYPE>> &slae, string message);

void	matrix_specification(vector<vector<VALUE_TYPE>> slae, int size);
void	method_specification(vector<vector<VALUE_TYPE>> slae, int size, vector<VALUE_TYPE> solution, vector<VALUE_TYPE> (*method)(vector<vector<VALUE_TYPE>>));

vector<vector<VALUE_TYPE>> 	parsing_file();

vector<VALUE_TYPE>	Gauss_method(vector<vector<VALUE_TYPE>> slae);
vector<VALUE_TYPE>	QR_method(vector<vector<VALUE_TYPE>> slae);

vector<vector<VALUE_TYPE>>	transpose(vector<vector<VALUE_TYPE>> &slae);
vector<vector<VALUE_TYPE>>	multiply(vector<vector<VALUE_TYPE>> &a, vector<vector<VALUE_TYPE>> &b);
vector<vector<VALUE_TYPE>>	inverse(vector<vector<VALUE_TYPE>> slae, int size, vector<VALUE_TYPE> (*method)(vector<vector<VALUE_TYPE>>));
vector<vector<VALUE_TYPE>>	subtract_matrices(vector<vector<VALUE_TYPE>> a, vector<vector<VALUE_TYPE>> b, int m, int n);

VALUE_TYPE		get_condition_number(vector<vector<VALUE_TYPE>> slae, vector<vector<VALUE_TYPE>> inverse_slae, int size, VALUE_TYPE (*norm)(vector<vector<VALUE_TYPE>>, int));
cond_with_cell	evaluate_condition_number(vector<vector<VALUE_TYPE>> slae, int size, vector<VALUE_TYPE> solution, vector<VALUE_TYPE> (*method)(vector<vector<VALUE_TYPE>>));

vector<VALUE_TYPE>	subtract_vectors(vector<VALUE_TYPE> a, vector<VALUE_TYPE> b, int n);
vector<VALUE_TYPE>	put_solution(vector<vector<VALUE_TYPE>> slae, int size, vector<VALUE_TYPE> x);

VALUE_TYPE	vector_norm(vector<VALUE_TYPE> x, int size);
VALUE_TYPE	norm_1(vector<vector<VALUE_TYPE>> slae, int size);
VALUE_TYPE	norm_inf(vector<vector<VALUE_TYPE>> slae, int size);

bool	is_degenerate(vector<vector<VALUE_TYPE>> &slae, int size);

void	reverse_traverse(vector<vector<VALUE_TYPE>> &slae, int size);

#endif
