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

 switch (choice) {
                case 1:
                    Menu::addLifePolicy (vault , counter);
                    break;
                case 2:
                    Menu::addHealthPolicy (vault , counter);
                    break;
                case 3:
                    Menu::viewAllPolicies (vault);
                    break;
                case 4:
                    Menu::searchPolicy (vault);
                    break;
                case 5:
                    Menu::premiumCalculator (vault);
                    break;
                    
                    case 6:
                    Menu::summaryReport (vault);
                    break;
                case 7:
                    Menu::showAbout();
                    break;
                case 0:
                    Utils :: clear_Screen();
                    break;
            }
            if (choice == 0) {
                std::cout << " !THANK YOU!  HAVE A GREAT DAY!!\n";
                Utils::print_Line('=');
                break;
            }
        }
    } catch (const std::runtime_error& err) {
        std::cerr << "!Unexpected Fatal Error:" << err.what() << '\n';
        std::cerr << " Exiting program...\n";
        return 1;
    } catch(...) {
        std::cerr << "!Unexpected error occurred. Exiting.\n";
        return 1;
    }
    return 0;
}
