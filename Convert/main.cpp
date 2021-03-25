#include <iostream>
#include <string>
#include <vector>

#include "Convert.hpp"

int main()
{
    std::ios::sync_with_stdio(false);

    const std::string u8{ "哈摟" };
    std::cout << "UTF8: " << u8 << std::endl;

    std::wstring wstr = Convert::utf8ToWchar(u8);
    std::wcout << L"wstr: " << wstr << std::endl;

    std::vector<char> strBuf;
    strBuf = Convert::wcharToUtf8<std::wstring, std::vector<char>>(wstr);
    wstr = Convert::utf8ToWchar<std::vector<char>>(strBuf);
    std::wcout << L"from UTF8 vector to wstring: " << wstr << std::endl;

    std::cin.ignore();
    return 0;
}
