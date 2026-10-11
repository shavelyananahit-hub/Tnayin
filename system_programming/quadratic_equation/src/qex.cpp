#include <iostream>
#include <string>
#include "qe.h"
#include "path.h"
#include "version.h"

void print_help(const char* name)
{
    std::cout << "Usage: " << name << " [option]\n"
              << "-h, --help     Show help\n"
              << "-p, --path     Show project paths\n"
              << "-v, --version  Show version\n";
}

int main(int argc, char* argv[])
{
    if (argc > 1) {
        std::string option = argv[1];

        if (option == "-h" || option == "--help") {
            print_help(argv[0]);
            return 0;
        }
        if (option == "-p" || option == "--path") {
            std::cout << "Source path: " << SOURCE_PATH << '\n';
            std::cout << "Build path: " << BINARY_PATH << '\n';
            return 0;
        }
        if (option == "-v" || option == "--version") {
            std::cout << "Version: " << VERSION << '\n';
            return 0;
        }
        print_help(argv[0]);
        return 1;
    }

    double a, b, c, x1, x2;

    std::cout << "Enter a, b, c: ";
    if (!(std::cin >> a >> b >> c)) {
        std::cerr << "Invalid input!\n";
        return 1;
    }

    qef(a, b, c, x1, x2);

    std::cout << "x1 = " << x1 << '\n';
    std::cout << "x2 = " << x2 << '\n';
    std::cout << "x1 + x2 = " << x1 + x2 << '\n';
    std::cout << "x1 * x2 = " << x1 * x2 << '\n';

    if (x1 * x2 != 0)
        std::cout << "(x1 + x2) / (x1 * x2) = "
                  << (x1 + x2) / (x1 * x2) << '\n';
    else
        std::cout << "Division by zero!\n";

    return 0;
}
