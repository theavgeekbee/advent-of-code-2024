#define N_ROWS 140 
#define N_COLS 140

#include <iostream>
#include <cstdlib>
#include <string>

bool search(char data[N_ROWS][N_COLS], int x, int y, int xDiff, int yDiff, char c) {
	if (x >= N_ROWS || y >= N_COLS || x < 0 || y < 0)
		return false;
	if (data[x][y] != c)
		return false;

	char next;
	if (c == 'M')
		next = 'A';
	if (c == 'A')
		next = 'S';
	if (c == 'S')
		return true;

	return search(data, x + xDiff, y + yDiff, xDiff, yDiff, next);
}

int matched(char data[N_ROWS][N_COLS], int x, int y, char c) {
	if (data[x][y] != c)
		return 0;
	int count = 0;
	if (search(data, x - 1, y, -1, 0, 'M'))
		count++;
	if(search(data, x + 1, y, 1, 0, 'M'))
	       count++;
	if(search(data, x, y - 1, 0, -1, 'M'))
		count++;
	if(search(data, x, y + 1, 0, 1, 'M'))
		count++;
	if(search(data, x - 1, y + 1, -1, 1, 'M'))
		count++;
	if(search(data, x + 1, y + 1, 1, 1, 'M'))
		count++;
	if(search(data, x - 1, y - 1, -1, -1, 'M'))
		count++;
	if(search(data, x + 1, y -1, 1, -1, 'M'))
		count++;
	return count;
}

bool is_cross_mas(char data[N_ROWS][N_COLS], int x, int y) { 
	if (x < 1 || x >= N_ROWS - 1 || y < 1 || y >= N_COLS - 1)
		return 0;
	if (data[x][y] != 'A')
		return 0;

	// M on left
	if (data[x - 1][y - 1] == 'M' && data[x + 1][y - 1] == 'M' &&
		data[x - 1][y + 1] == 'S' && data[x + 1][y + 1] == 'S')
		return true;
	// M on right	
	if (data[x - 1][y + 1] == 'M' && data[x + 1][y + 1] == 'M' &&
		data[x - 1][y - 1] == 'S' && data[x + 1][y - 1] == 'S')
		return true;
	// M on top
	if (data[x - 1][y + 1] == 'M' && data[x - 1][y - 1] == 'M' &&
		data[x + 1][y + 1] == 'S' && data[x + 1][y - 1] == 'S')
		return true;
	// M on bottom
	if (data[x + 1][y + 1] == 'M' && data[x + 1][y - 1] == 'M' &&
		data[x - 1][y + 1] == 'S' && data[x - 1][y - 1] == 'S')
		return true;
	return false;
}

void print_surroundings(char data[N_ROWS][N_COLS], int x, int y) {
	std::cout << "found cross at " << x << " " << y << std::endl;
	std::cout << data[x - 1][y - 1] << " " << data[x - 1][y + 1] << std::endl;
	std::cout << " " << data[x][y] << " " << std::endl;
	std::cout << data[x + 1][y - 1] << " " << data[x + 1][y + 1] << std::endl;
}

int main() {
	char data[N_ROWS][N_COLS];

	std::string line;
	for (int i = 0; i < N_ROWS; i++) {
		std::getline(std::cin, line);
		for (int ii = 0; ii < N_COLS; ii++) {
			data[i][ii] = line.at(ii);
		}
	}
	std::cout << "done parsing input" << std::endl;
	int count = 0;
	int part2 = 0;
	for (int i = 0; i < N_ROWS; i++) {
		for (int j = 0; j < N_COLS; j++) {
			if (is_cross_mas(data, i, j)) {
				part2++;	
				print_surroundings(data, i, j);
			}
		}
	}

	std::cout << "part 1 solution: " << count << std::endl;
	std::cout << "part 2 solution: " << part2 << std::endl;
}
