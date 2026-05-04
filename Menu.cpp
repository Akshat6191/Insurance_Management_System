#include "Menu.h"
#include "Utils.h"
#include "Life_Insurance_Policy.h"
#include "Health_Insurance_Policy.h"

#include <iostream>
#include <iomanip>
#include <memory>
#include <stdexcept>

//============================================================================================
// Menu - UI Layer Implementation
//============================================================================================

namespace Menu 

//--------------------------------------------------------------------------------------------
//Add Life Insurance Policy 
//--------------------------------------------------------------------------------------------
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