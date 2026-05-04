#include "Menu.h"
#include "Utils.h"
#include "Life_Insurance_Policy.h"
#include "Health_Insurance_Policy.h"

#include <iostream>
#include <iomanip>
#include <memory>
#include <stdexcept>

// Menu - UI Layer Implementation
namespace Menu 

//Add Life Insurance Policy 
void addLifePolicy(PolicyVault<InsurancePolicy>& vault, int& counter) {

  Utils::printHeader("ADD LIFE INSURANCE POLICY");

  const std::string name = Utils::getStringInput("Holder Name :");
  const int age = Utils::getIntInput("Age : ",1,70);
  const double sum = Utils::getDoubleInput("Sum Assured :",10000.0);
  const int term = Utils::getIntInput("Policy Term : ",1,40);
  const std::string nominee = Utils::getStringInput("Nominee Name : ");

  const std::string polNo = Utils::generatePolicyNumber("LIFE", ++counter);

  try {
    auto policy = std::make_unique<Life_Insurance_Policy(
        pollNo,name,age,sum,term,nominee);

    vault.addPolicy(std::move(policy));

    std::cout << "\nPolicy Added Successfully\n";
    std::cout << "Policy Number : " << polNo << std::endl ;


  }
  catch(const std :: invalid_arguement& e){

    std::cout << "Error : " << e.what() << std::endl;
    counter--;
  }

  Utils::pauseScreen();
}

//-------------------------------------------------------------------------------------------------------------------------------
// View All Policies (Using Operator Overloading <<)
//-------------------------------------------------------------------------------------------------------------------------------
void viewAllPolicies(const PolicyVault<InsurancePolicy>& vault ){

    Utils::printHeader("ALL POLICIES ");

    std::cout << "Total Policies :" << vault.count() << std::endl;
    std::cout << "Total Annual Premium :" << vault.totalAnnualPremiums() << std::endl;
    
    std::cout << "\n----POLICY LIST ----\n";
    for (const auto& policy : vault>getPolicies())
    {
        std::cout << *policy << std::endl; // Operator Overloading Used here 
    }

    Utils::pauseScreen();
}

//---------------------------------------------------------------------------------------------------------------------------------
// Search Policy 
//---------------------------------------------------------------------------------------------------------------------------------
void searchPolicy(const PolicyVault<InsurancePolicy>& vault ){

    Utils::printHeader(" SEARCH POLICY ");
    
}

    std::cout << "  1. Search by Policy Number\n";
    std::cout << "  2. Search by Holder Name\n";
    const int choice = Utils::getIntInput("\n  Enter choice : ", 1, 2);
    std::cout << '\n';

    if (choice == 1) {
        const std::string polNo = Utils::getStringInput("  Policy Number : ");
        const InsurancePolicy* result = vault.findByPolicyNumber(polNo);
        if (result)
            result->displayDetails();
        else
            std::cout << "\n  [!] No policy found: " << polNo << '\n';
    } else {
        const std::string name = Utils::getStringInput("  Holder Name   : ");
        vault.findByHolderName(name);
    }

    Utils::pauseScreen();
}

// ------------------------------------------------------------
void premiumCalculator() {
    Utils::printHeader("PREMIUM CALCULATOR");

    std::cout << "  1. Life Insurance Estimate\n";
    std::cout << "  2. Health Insurance Estimate\n";
    const int choice = Utils::getIntInput("\n  Enter choice : ", 1, 2);
    std::cout << '\n';

    if (choice == 1) {
        const int    age  = Utils::getIntInput   ("  Age (years)  : ", 1,     70);
        const double sum  = Utils::getDoubleInput("  Sum Assured  : ",     10000.0);
        const int    term = Utils::getIntInput   ("  Term (years) : ", 1,     40);

        const double annual = sum * (age * 0.0005 + term * 0.001);
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "\n  Annual Premium  : Rs. " << annual        << '\n';
        std::cout << "  Monthly Premium : Rs. " << annual / 12.0  << '\n';

    } else {
        const int    age  = Utils::getIntInput   ("  Age (years)  : ", 1, 80);
        const double sum  = Utils::getDoubleInput("  Sum Assured  : ", 10000.0);

        std::cout << "\n  Plans — 1. Basic   2. Standard   3. Premium\n";
        const int planChoice = Utils::getIntInput("  Select Plan  : ", 1, 3);
        const PlanType plan  = (planChoice == 1) ? PlanType::Basic
                             : (planChoice == 2) ? PlanType::Standard
                                                 : PlanType::Premium;

        const int  preChoice   = Utils::getIntInput("  Pre-Existing? (1=Yes / 2=No) : ", 1, 2);
        const bool preExisting = (preChoice == 1);

        const double base         = sum * 0.02;
        const int    ageLoad      = (age > 30) ? ((age - 30) / 5) : 0;
        const double ageSurcharge = sum * ageLoad * 0.005;
        const double preSurcharge = preExisting ? (base * 0.25) : 0.0;
        const double multiplier   = (plan == PlanType::Basic)    ? 1.0
                                  : (plan == PlanType::Standard) ? 1.2 : 1.5;
        const double annual       = (base + ageSurcharge + preSurcharge) * multiplier;

        std::cout << std::fixed << std::setprecision(2);
        std::cout << "\n  Plan            : " << HealthInsurancePolicy::planTypeToString(plan) << '\n';
        std::cout << "  Annual Premium  : Rs. " << annual        << '\n';
        std::cout << "  Monthly Premium : Rs. " << annual / 12.0 << '\n';
    }

    Utils::pauseScreen();
}

// ------------------------------------------------------------
void summaryReport(const PolicyVault<InsurancePolicy>& vault) {
    Utils::printHeader("SUMMARY REPORT");

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "  Total Policies         : " << vault.count()                    << '\n';
    std::cout << "  Total Annual Premiums  : Rs. " << vault.totalAnnualPremiums()  << '\n';
    std::cout << "  Total Monthly Premiums : Rs. " << vault.totalAnnualPremiums() / 12.0 << '\n';
    Utils::printLine();
    vault.displayAll();

    Utils::pauseScreen();
}

// ------------------------------------------------------------
void showAbout() {
    Utils::printHeader("ABOUT THIS SYSTEM");

    Utils::printLine();
    std::cout << "  Insurance Management System  |  C++17\n";
    Utils::printLine();
    std::cout << '\n';
    std::cout << "  Encapsulation   : Private data in InsurancePolicy;\n"
              << "                    exposed only via const noexcept getters.\n\n";
    std::cout << "  Abstraction     : Pure virtual functions define the contract\n"
              << "                    — no InsurancePolicy object can be created.\n\n";
    std::cout << "  Inheritance     : LifeInsurancePolicy and\n"
              << "                    HealthInsurancePolicy extend the base class.\n\n";
    std::cout << "  Polymorphism    : unique_ptr<InsurancePolicy> holds any subtype;\n"
              << "                    virtual dispatch resolves at runtime.\n\n";
    std::cout << "  Templates       : PolicyVault<T> is a generic, type-safe\n"
              << "                    container using unique_ptr ownership.\n\n";
    std::cout << "  Smart Pointers  : std::unique_ptr — zero manual new/delete.\n\n";
    std::cout << "  Enums           : PlanType is a scoped enum (enum class).\n\n";
    std::cout << "  Namespaces      : Utils:: and Menu:: prevent global pollution.\n\n";
    Utils::printLine();

    Utils::pauseScreen();
}

// ------------------------------------------------------------
void showMainMenu() {
    Utils::printLine('=');
    std::cout << "         INSURANCE MANAGEMENT SYSTEM\n";
    Utils::printLine('=');
    std::cout << "\n"
              << "  1. Add Life Insurance Policy\n"
              << "  2. Add Health Insurance Policy\n"
              << "  3. View All Policies\n"
              << "  4. Search Policy\n"
              << "  5. Premium Calculator\n"
              << "  6. Summary Report\n"
              << "  7. About This System\n"
              << "  0. Exit\n";
    Utils::printLine();
}

} // namespace Menu

