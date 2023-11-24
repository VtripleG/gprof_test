#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <time.h>

std::string ReadFileByGetLine(std::string filePath)
{
    clock_t start = clock();
    std::ifstream file(filePath);
    std::string fileString;
    if(file.is_open())
    {
        std::string line("");
        std::cout<<"File is open"<<std::endl;
        while(!file.eof())
        {
            std::getline(file, line, ' ');
            fileString+=line;
        }
        file.close();
        std::cout<<"Reading complite by ReadFileByGetLine"<<std::endl;
    }
    else
        std::cout << "File is not open" << std::endl;
    clock_t end = clock();
    double seconds = (double)(end-start)/CLOCKS_PER_SEC;
    std::cout << seconds << " sec\n";
    return fileString;

}

std::string ReadFileByGetLineFunction(std::string filePath)
{
    clock_t start = clock();
    std::ifstream file(filePath);
    std::string fileString;
    if(file.is_open())
    {
        std::string line("");
        std::cout<<"File is open"<<std::endl;
        while(!file.eof())
        {
            std::getline(file, line);
            fileString+=line+"\n";
        }
        file.close();
        std::cout<<"Reading complite by ReadFileByGetLineFunction"<<std::endl;
    }
    else
        std::cout << "File is not open" << std::endl;
    clock_t end = clock();
    double seconds = (double)(end-start)/CLOCKS_PER_SEC;
    std::cout << seconds << " sec\n";
    return fileString;

}

std::string ReadFileByRead(std::string filePath)
{
    clock_t start = clock();
    std::ifstream file(filePath);
    std::string fileString;
    if(file.is_open())
    {
        int n = 1;
        char* line  = new char [n+1];
        line[n] = 0;
        std::cout<<"File is open"<<std::endl;
        while(!file.eof())
        {
            file.read(line, n);
            fileString+=line;
        }
        file.close();
        delete [] line;
        std::cout<<"Reading complite by ReadFileByRead"<<std::endl;
    }
    else
        std::cout << "File is not open" << std::endl;
    clock_t end = clock();
    double seconds = (double)(end-start)/CLOCKS_PER_SEC;
    std::cout << seconds << " sec\n";
    return fileString;
}

std::string ReadFile(std::string filePath)
{
    clock_t start = clock();
    std::ifstream file(filePath);
    std::string fileString;
    if(file.is_open())
    {
        std::string buffer;
        std::cout<<"File is open"<<std::endl;
        for (file>>buffer; !file.eof(); file >> buffer)
            fileString+=buffer+" ";
        file.close();
        std::cout<<"Reading complite by ReadFile"<<std::endl;
    }
    else
        std::cout << "File is not open" << std::endl;
    clock_t end = clock();
    double seconds = (double)(end-start)/CLOCKS_PER_SEC;
    std::cout << seconds << " sec\n";
    return fileString;
}

std::string ReplaceByMethod(std::string text, std::string oldStr, std::string newStr)
{
    clock_t start_clock = clock();
    std::cout<<"Start replace"<<std::endl;
    size_t start {text.find(oldStr)};
    while (start != std::string::npos)
    {
        text.replace(start, oldStr.length(), newStr);
        start = text.find(oldStr, start + newStr.length());
    }
    std::cout<<"End replace"<<std::endl;
    clock_t end = clock();
    double seconds = (double)(end-start_clock)/CLOCKS_PER_SEC;
    std::cout << seconds << " sec\n";
    return text;
}

std::string ReplaceManual()
{

}

void SaveFile(std::string text)
{
    clock_t start_clock = clock();
    std::cout<<"Start save"<<std::endl;
    std::ofstream file("./text_.txt");
    if(file.is_open())
    {
        std::cout << "File is open fo writing" << std::endl;
        file.write(text.c_str(), text.length());
        file.close();
    }
    std::cout<<"End save"<<std::endl;
    clock_t end = clock();
    double seconds = (double)(end-start_clock)/CLOCKS_PER_SEC;
    std::cout << seconds << " sec\n";
}

int main()
{
    std::string text1 = ReadFile("./text.txt");
    std::string text2 = ReadFileByGetLine("./text.txt");
    std::string text3 = ReadFileByRead("./text.txt");
    std::string text4 = ReadFileByGetLineFunction("./text.txt");

    text4 = ReplaceByMethod(text4, "optimization", "iiiii");

    SaveFile(text4);
    return 0;
}

