default:
	clang++ -fsanitize=address -std=c++17 -g -O0 -Wall main.cpp -o main