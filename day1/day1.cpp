#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>

int part1(int len, std::vector<int> left, std::vector<int> right) {
	int acc = 0;
	for (int i = 0; i < len; i++) {
		acc += abs(left[i] - right[i]); 
	}

	return acc;
}
int part2(std::vector<int> left, std::vector<int> right) {
	int sim = 0;

	for (int i : left) {
		int count = 0;
		for (int ii : right) {
			if (ii == i)
				count++;
		}
		sim += i * count;
	}	

	return sim;
}

int main() {
	std::vector<int> left;
	std::vector<int> right;

	std::string num;
	std::getline(std::cin, num);
	int len = stoi(num);

	for (int i = 0; i < len; i++) {
		int n1, n2;
		std::cin >> n1 >> n2;
		left.push_back(n1);
		right.push_back(n2);
	}

	std::sort(left.begin(), left.end());
	std::sort(right.begin(), right.end());

	std::cout << "part 1 solution: " << part1(len, left, right) << std::endl;
	std::cout << "part 2 solution: " << part2(left, right) << std::endl;

        return 0;
}
