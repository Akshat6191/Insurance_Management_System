#include "utils.h"
#include<iomanip>
#include<limits>
#include<string>
#include<stdexcept>
#include<iostream>

namespace Utils{
    void clear_Screen(){
        #if defined(_WIN32) || defined(_WIN64)
        std::system("cls");
        #else
        std::system("clear");
        #endif
    }
    void pause_Screen(){
        std::cout<<"\n Press Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max() , "\n");
        std::cin.get();

        void print_Header(const std::string& title){
            clear_Screen();
            print_Line("=");
            int padding = static_cast<int>((60 - static_cast<int<(title.size()))/2);
            stD::cout<<" "  << std::string(padding , " ") <<title<<"\n";
            print_Line("=");
            std::cout<<"\n";
        }
    }
}


