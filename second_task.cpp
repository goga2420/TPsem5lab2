
#include "second_task.hpp"

void Task2()
{
    std::ifstream fin("/Users/georgijzukov/Desktop/ГУАП/Tp52/Tp52/second_task.txt", std::ios::in);
    try {
        if (!fin.is_open()) {
            
            throw std::invalid_argument("Файл не открылся");
        }
        if (fin.peek() == EOF) {
            throw std::invalid_argument("Файл пустой");
        }
        std::ostringstream os;
        std::string line;
        std::string quote;
        
        
        while (!fin.eof()) {
            std::getline(fin, line, '\n');
            std::string word;
            
            
            bool inQuote = false;
            
            
            for (char c : line) {
                
                if (c == '\"') {
                    
                    inQuote = !inQuote;
                    
                    
                    if (!inQuote) {
                        os << quote << std::endl;
                        
                        quote.clear();
                    }
                } else if (inQuote) {
                    
                    quote += c;
                }
            }
            
            
            
        }
        std::cout << os.str();
    }
    catch (std::exception& error)
    {
        std::cout << error.what() << std::endl;
        fin.close();
    }
}
