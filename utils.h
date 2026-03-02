#ifndef UTILS_H
#define UTILS_H 

#include<string>

namespace Utils{

    void clear_Screen();
    void pause_Screen();
    void print_Line(char ch = '-' , int length = 70);
    void print_Header(const std::string& title);
    

    int get_Int_Input(const std::string& labels , int min_val , int max_val);
    double get_Double_Input(const std::string labels , double min_val);
    std::string get_String_Input(const std::string& labels);

    std::string generate_Policy_Number(const std::string& prefix , int id);
    
}


    



#endif