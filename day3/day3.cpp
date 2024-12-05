#include <regex>
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

int main() {
	std::string input;

	for (std::string line; std::getline(std::cin, line);) {
		input.append(line);	
	}

	std::regex regex("(mul\\(\\d+,\\d+\\)|do\\(\\)|don't\\(\\))");
	std::smatch match;

	int sum = 0;
	bool track = true;

	std::string dont("don");
	std::string d0("do");

	while (regex_search(input, match, regex)) {
		std::string call = match.str(0);
		if (call.find(dont) != std::string::npos) {
			track = false;
		} else if (call.find(d0) != std::string::npos) {
			track = true;
		} else if (track) {
			std::string split = call.substr(4);

			std::istringstream stream(split);

			std::string token;
			std::getline(stream, token, ',');

			int acc = stoi(token);

			std::getline(stream, token, ',');

			acc *= stoi(token);
	
			sum += acc;
		}
		input = match.suffix().str();
	}

	std::cout << sum << std::endl;

	return 0;
}
