all:
	g++ -g main.cpp App.h App.cpp euler_solver.cpp print_to_file.cpp pr_print.cpp rk4_solver.cpp heun_solver.cpp Matrix.cpp Matrix.h analytical_solver.cpp -o main


