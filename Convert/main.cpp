#include <iostream>
#include <string>
#include <vector>

#include "Convert.hpp"

int main()
{
    try {
        std::locale::global(std::locale("en_US.UTF-8"));
        std::ios::sync_with_stdio(false);

        std::wstring wstr = L"哈摟";
        std::wcout << L"wstr: " << wstr << std::endl;

        const std::string str = Convert::wcharToUtf8(wstr);
        std::cout << "str: " << str << std::endl;

        std::vector<char> strBuf;
        strBuf = Convert::wcharToUtf8<std::wstring, std::vector<char>>(wstr);
        wstr = Convert::utf8ToWchar<std::vector<char>>(strBuf);
        std::wcout << L"from UTF8 vector to wstring: " << wstr << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cin.ignore();
    return 0;
}
