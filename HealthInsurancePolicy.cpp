#include "HealthInsurancePolicy.h"
#include "utils.h"

#include <iostream>
#include <iomanip>
#include <utility>

//USED INITIALIZER LIST-------------------------------------------------------------------------
HealthInsurancePolicy::HealthInsurancePolicy(std::string polno,std::string holder_name,int  holder_age,double sumAssured,bool hasPreexisting , Plantype plan) : 
    InsurancePolicy(std::move(polNo),std::move(holder_name),
    holder Age,sumAssured)
    , hasPreExisting_(hasPreExisting), 
    plan_(plan)
{}
//------------------------------------------------------------------------------------------------

double HealthInsurancePolicy::planMultiplier() const noexcept {
    switch (plan_){
        case PlanType::Standard: return 1.2;
        case PlanType::Premium:  return 1.5;
        default:                 return 1.0;
    }
}                                                              
double HealthInsurancePolicy::calculatePremium() const {
    const double base           = getSumAssured() * 0.02;
    const int    ageLoad        = (getHolder() > 30) ? ((getHolderAge() -30/5)): 0;
    const double ageSurcharge   = getSumAssured() * ageLoad * 0.005;
    const double preSurcharge   = hasPreExisting_ ? (base * 0.25): 0.0;
    return (base + ageSurcharge + preSurcharge) * planMultiplier();                        
}                                            
                                                
std::string HealthInsurancePolicy::getPolicyType() const {
return "Health Insurance";
}               
void HealthInsurancePolicy::displayDetails() const
{
    Utils::print_Line();

    
    displayCommon();

    
    double annualPremium  = calculatePremium();
    double monthlyPremium = annualPremium / 12.0;

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "\nPolicy Information\n";
    std::cout << "------------------------------\n";
    std::cout << "Plan Type        : " 
              << planTypeToString(plan_) << std::endl;

    std::cout << "Pre-Existing     : " << (hasPreExisting_ ? "Yes" : "No") << std::endl;

    std::cout << "Annual Premium   : Rs. " << annualPremium << std::endl;

    std::cout << "Monthly Premium  : Rs. " << monthlyPremium << std::endl;

    utils::print_Line();
}
std::string HealthInsurancePolicy::planTypeToString(PlanType plan) {
    switch (plan) {
        case PlanType::Standard: return "Standard";
        case PlanType::Premium:  return "Premium";
        default:                 return "Basic";
    }
}
PlanType HealthInsurancePolicy::getPlanType() const noexcept {
    return plan_;
}
bool HealthInsurancePolicy::hasPreExistingCond() const noexcept {
    return hasPreExisting_;
}