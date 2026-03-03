#include "utils.h"

#include<iomanip>
#include<limits>
#include<string>
#include<stdexcept>
#include<iostream>

namespace utils{
//----------------------------------------------------------------------------------------------------
    void clear_Screen(){
        #if defined(_WIN32) || defined(_WIN64)
        std::system("cls");
        #else
        std::system("clear");
        #endif
    }
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
    void pause_Screen(){
        std::cout<<"\n Press Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max() , '\n' );
        std::cin.get();
    }
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
    void print_Line(char ch , char len){
        std::cout<<" "<<std::string(len , ch)<< '\n';
    }
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
    void print_Header(const std::string& title){
        clear_Screen();
        print_Line('=');
        int padding = static_cast<int>((60 - static_cast<int>(title.size()))/2);
        std::cout<<" "  << std::string(padding , ' ') << title <<"\n";
        print_Line('-');
        std::cout<<"\n";
    }
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
    int get_Int_Input(const std::string& labels , int min_val , int max_val){
        int val{};
        while(true) {
            std::cout<< labels;
            if(std::cin>>val && val>= min_val && val<= max_val){
                std::cin.ignore(std::numeric_limits<std::streamsize>::max() , '\n');
                return val;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>:: max() , '\n');
            std::cout<<" [!] Enter a number between "<< min_val << " and " << max_val << ",\n";
        }
    }
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------

    double get_Double_Input(const std::string& labels , double min_val){
        double val{};
        while(true) {
            std::cout << labels;
            if(std::cin >> val && val >= min_val){
                std::cin.ignore(std::numeric_limits <std::streamsize> :: max() , '\n');
                return val;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits <std::streamsize> :: max() , '\n' );
            std::cout<<" [!] Enter a value " << min_val << ".\n";
        }
    }
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
    std::string get_String_Input(const std::string& labels){
        std::string val;
        std::cout << labels;
        std::getline(std::cin >> std::ws , val);
        return val;
    }
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
    std::string generate_policy_number_(const std::string& prefix , int id){
        return prefix + "-" + std::to_string(2026000 + id);
    }
//----------------------------------------------------------------------------------------------------

}   
    

