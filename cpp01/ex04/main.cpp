#include "sed.hpp"

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    if (argv[1][0] == '\0' || argv[2][0] == '\0') {
        std::cerr << "Error: Empty string argument(s) provided." << std::endl;
        return 1;
    }
    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << argv[1] << std::endl;
        return 1;
    }
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();
    std::string result;
    size_t pos = 0;
    size_t found;

    while ((found = content.find(s1,pos)) != std::string::npos) {
        result.append(content, pos, found - pos);
        result += s2;
        pos = found + s1.length();
    }
    result.append(content, pos, content.length() - pos);
    std::ofstream outfile((std::string(argv[1]) + ".replace").c_str());
    if (!outfile.is_open()) {
        std::cerr << "Error: Could not create the output file." << std::endl;
        return 1;
    }
    outfile << result;
    outfile.close();
    return 0;
}