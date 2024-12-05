#define N_ROWS 3 
#define N_COLS 3

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

bool check_ms(char data[N_ROWS][N_COLS], int x, int y) {
	return data[x][y] == 'M' || data[x][y] == 'S';
}
bool has_char_surrounding(char data[N_ROWs
bool is_cross_mas(char data[N_ROWS][N_COLS], int x, int y) {
	if (x < 1 || x >= N_ROWS - 1 || y < 1 || y > N_COLS - 1)
		return 0;
	if (data[x][y] != 'A')
		return 0;

	int count = 0;
	
	// Bottom left is M
	if (check_with_bounds(data, x - 1, y - 1, 'M') &&
			check_with_bounds(data, x + 1, y + 1, 'S'))
		count++;
	// Bottom right is M
	if (check_with_bounds(data, x + 1, y - 1, 'M') &&
			check_with_bounds(data, x - 1, y + 1, 'S'))
		count++;
	// Top left is M
	if (check_with_bounds(data, x - 1, y + 1, 'M') &&
			check_with_bounds(data, x + 1, y - 1, 'S'))
		count++;
	// Top right is M
	if (check_with_bounds(data, x + 1, y + 1, 'M') &&
			check_with_bounds(data, x - 1, y - 1, 'S'))
		count++;

	return count;
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
	std::cout << data[7][2] << std::endl;
	std::cout << "done parsing input" << std::endl;
	int count = 0;
	int part2 = 0;
	for (int i = 0; i < N_ROWS; i++) {
		for (int j = 0; j < N_COLS; j++) {
			count += matched(data, i, j, 'X');
			part2 += count_cross_mas(data, i, j);
		}
	}

	std::cout << "part 1 solution: " << count << std::endl;
	std::cout << "part 2 solution: " << part2 << std::endl;
}
