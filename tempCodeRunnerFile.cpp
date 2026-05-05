#include "Menu.h"
#include "utils.h"

int main () {
    PolicyVault<InsurancePolicy> vault;
    int counter  = 0;
    int choice = 0;


    

    try {
        while (true) {
            Utils :: clear_Screen();
            Menu ::showMainMenu ();
            choice = Utils :: get_Int_Input( " Enter your choice : " , 0 , 7);
