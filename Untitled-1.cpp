#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

struct Person {
    std::string name;
    double amount;
    std::string date;
};

int main() {
    std::ifstream file("payings.txt");
    if (!file.is_open()) {
        std::cerr << "Cannot open" << std::endl;
        return 1;
    }

    std::string line;
    double totalAmount = 0;
    Person personWithMaxAmount;
    double maxAmount = 0;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Person person;
        iss >> person.name >> person.amount >> person.date;

        totalAmount += person.amount;

        if (person.amount > maxAmount) {
            maxAmount = person.amount;
            personWithMaxAmount = person;
        }
    }

    file.close();

    std::cout << "Whole paid sum: " << totalAmount << std::endl;
    std::cout << "Must paid person:" << personWithMaxAmount.name << std::endl;
}