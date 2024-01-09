#include <iostream>
#include <string>
#include <fstream>

using std::string;

void DumpFile(const string);

int main(int argc, char* argv[]) {

    const string program_version = {
        "0.1-dev"
    };

    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>\n";
        return -1;
    }

    if (string(argv[1]) == "--v" || string(argv[1]) == "--version") {
        std::cout << "Cat - Dump your files |" << program_version << '\n';
        std::cout << "Programmer: Ravi Gabriel Valentim da Silva\n";

        return 0;
    }
    else if (string(argv[1]) == "--h" || string(argv[1]) == "--help") {
        std::cerr << "Usage: " << argv[0] << " <filename>\n";

        return 0;
    }
    else {
        DumpFile(static_cast<string>(argv[1]));
    }
    return 0;
}

void DumpFile(const string file_path) {
    std::ifstream file;
    file.open(file_path);

    if (!file.is_open()) {
        std::cerr << "Error: unable to open \""
            << file_path << "\"\n";
        return;
    }

    string line;
    int line_number = { 1 };

    while (std::getline(file, line)) {
        std::cout << line_number << " - " << line << '\n';
        ++line_number;
    }
}
