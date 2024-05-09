#include<iostream>
#include<string>
#include <fstream>
#include <locale>
#include <codecvt>
#include "BruteForce.h"
#include "RabinKarp.h"
#include "kmp.h"
#include "sunday.h"
#include<fstream>

#include <iostream>
#include <fstream>
#include <string>
#include <locale>

int main() {
    // 假设这是你的文件路径
    std::string file_path ="PDG.txt";  // 替换为实际文件路径

    // 创建宽字符的输入文件流
    std::wifstream file(file_path);

    // 如果要处理 UTF-8 或其他编码，设置合适的 locale
    std::locale loc("");  // 让系统决定使用什么 locale
    file.imbue(loc);

    if (!file.is_open()) {
        std::cerr << L"无法打开文件：" << file_path << std::endl;
        return 1;
    }

    std::wstring line;
    std::wcout << L"文件内容：" << std::endl;

    // 循环读取每一行
    while (std::getline(file, line)) {
        // 如果行内容为空，跳过
        if (line.empty() || line.find_first_not_of(L" \t\r\n") == std::wstring::npos) {
            continue;  // 跳过空行或仅含空白字符的行
        }

        // 如果不是空行，输出行内容
        std::wcout << line << std::endl;
    }

    // 关闭文件
    file.close();

    return 0;
}
