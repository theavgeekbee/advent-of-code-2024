#define INPUT_LINES 1000
#define PART2 true

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector> 

bool valid(std::vector<int> nums, bool increasing) {
	for (int i = 1; i < nums.size(); i++) {
		if (increasing && nums[i] - nums[i - 1] < 0) {
			return false;
		}
		if (!increasing && nums[i] - nums[i - 1] > 0) {
			return false;
		}
		int diff = abs(nums[i] - nums[i - 1]);
		if (diff < 1 || diff > 3)
			return false;
	}

	return true;
}

bool listMostlyIncreasing(std::vector<int> nums) {
	int increasing = 0;
	int decreasing = 0;
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] - nums[i - 1] > 0) increasing++;
		if (nums[i] - nums[i - 1] < 0) decreasing++;
	}
	return increasing > decreasing;
}

bool valid_without_element(std::vector<int> nums, int index) {
	std::vector<int> removed;
	for (int i = 0; i < nums.size(); i++) {
		if (i != index)
			removed.push_back(nums[i]);
	}
	return valid(removed, listMostlyIncreasing(removed));
}

int main() {
	int nLines = INPUT_LINES;

	int count = 0;
	for (int i = 0; i < nLines; i++) {
		std::string line;
		std::getline(std::cin, line);

		std::istringstream stream(line);
		std::vector<int> nums;		

		for (std::string token; std::getline(stream, token, ' ');) {
			int num = std::stoi(token);
			nums.push_back(num);
		}

		bool isValid = valid(nums, listMostlyIncreasing(nums));

		if (isValid)
			count++;
		else if (PART2) {
			for (int ii = 0; ii < nums.size(); ii++) {
				isValid = valid_without_element(nums, ii);
				if (isValid) {
					count++;
					break;
				}
			}
		}
	}
	std::cout << count << std::endl;

	return 0;	
}
