#include <iostream>
#include <fstream>
#include <string>

std::string myReplace(std::string text, const std::string &s1, const std::string &s2)
{
    std::string result;
    size_t pos = 0;
    size_t found;

    while ((found = text.find(s1, pos)) != std::string::npos)
    {
        result += text.substr(pos, found - pos);
        result += s2;
        pos = found + s1.length();
    }
    result += text.substr(pos);
    return result;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>\n";
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty())
    {
        std::cerr << "Error: s1 must not be empty.\n";
        return 1;
    }

    std::ifstream inFile(filename);
    if (!inFile)
    {
        std::cerr << "Error: Cannot open file " << filename << "\n";
        return 1;
    }

    std::ofstream outFile(filename + ".replace");
    if (!outFile)
    {
        std::cerr << "Error: Cannot creat output file.\n";
        inFile.close();
        return 1;
    }

    std::string line;
    while (std::getline(inFile, line))
    {
        outFile << myReplace(line, s1, s2) << "\n";
    }

    inFile.close();
    outFile.close();

    return 0;
}
