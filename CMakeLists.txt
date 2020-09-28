cmake_minimum_required(VERSION 3.17)
project(direct_methods_for_solving_SLAEs)

set(CMAKE_CXX_STANDARD 14)

add_executable(direct_methods_for_solving_SLAEs
		main.cpp main.h
		parser/parser.cpp parser/parser.h
		print_slae.cpp
		Gauss_method/Gauss_method.h Gauss_method/Gauss_method.cpp
		Gauss_method/direct_traverse.cpp Gauss_method/reverse_traverse.cpp QR_method/QR_method.cpp QR_method/QR_method.h QR_method/create_matrix.cpp transpose.cpp multiplication.cpp is_degenerate.cpp subtraction.cpp)