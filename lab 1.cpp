#include <iostream>
#include <string>

int main() {
	// Variable declarations
	std::string studentName;
	std::string favoriteTopic;

	// Prompt user for input
	std::cout << "==========================================" << std::endl;
	std::cout << "  Welcome to CS101: C++ & Git Lab 1!     " << std::endl;
	std::cout << "==========================================" << std::endl;
    
	std::cout << "Enter your name: ";
	std::getline(std::cin, studentName);

	std::cout << "What C++ or IT topic are you most excited to learn? ";
	std::getline(std::cin, favoriteTopic);

	// Personalized Output
	std::cout << "\n------------------------------------------" << std::endl;
	std::cout << "Hello, " << studentName << "!" << std::endl;
	std::cout << "Great choice! Learning " << favoriteTopic 
			  << " will build a solid programming foundation." << std::endl;
	std::cout << "Your environment is fully configured and ready!" << std::endl;
	std::cout << "------------------------------------------" << std::endl;

	return 0;
}
