#include <iostream>
#include <fstream>

int main(int argc, char** arg) {
	std::ifstream pipe{arg[1]};
	std::string entry;
	int index = 0;
	while (std::getline(pipe, entry, '\n')) {
		index++;
		if(entry.compare("Operation failed.") == 0) {
			std::cout<<"Program failed on Operation " << index << std::endl;
			break;
		}
	}
	return 0;
}
