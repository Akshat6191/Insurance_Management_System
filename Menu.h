#ifndef MENU_H
#define MENU_H

#include "PolicyVault.h"
#include "InsurancePolicy.h"

// ============================================================================================
// Menu - UI Layer Declaration 
// Keeps main.cpp clean and separates concerns 
// ============================================================================================

namespace Menu {

    void addLifePolicy   (PolicyVault<InsurancePolicy>& vault, int& counter ) ;
    void addHealthPolicy (PolicyVault<InsurancePolicy>& vault , int& counter) ;
    void viewAllPolicies (const PolicyVault<InsurancePolicy>& vault) ;
    void searchPolicy    (const PolicyVault<InsurancePolicy>& vault) ;
    void premiumCalculator(const PolicyVault<InsurancePolicy>& vault);
    void summaryReport   (const PolicyVault<InsurancePolicy>& vault) ;
    void showAbout();
    void showMainMenu();

} // namespace Menu 

#endif // MENU_H