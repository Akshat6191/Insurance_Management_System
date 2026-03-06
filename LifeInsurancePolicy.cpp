#include "LifeInsurancePolicy.h"
#include "Utils.h"

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <utility>


LifeInsurancePolicy::LifeInsurancePolicy(std::string pol_no_,
                                        std::string  holder_name_,
                                        int          holder_age_,
                                        double       sum_assured_,
                                        int          term_years_,
                                        std::string  nomineeName)
 : InsurancePolicy(std::move(pol_no_),
                std::move(holder_name_),
                holder_age_,
                sum_assured_)
, termYears_   (term_years_)
, nomineeName_ (std::move(nomineeName))
{
    if (term_years_ <=0 || term_years_ >40)
    throw std::invalid_argument("Policy terms muat be between 1 and 40 years");
}                
double LifeInsurancePolicy::calculatePremium() const {
    const double ageRate    = getholder_age_() * 0.0005;
    const double termFactor = termYears_       * 0.001;
    return getsum_assured_() * (ageRate + termFactor);
}

std::string LifeInsurancePolicy::getpolicy_type_() const {
    return "Life Insurance";
}

void LifeInsurancePolicy::displayDetails() const {
        utils::print_Line();
        displayCommon();
        std::cout << "Policy Term    : " << termYears_ << " years\n";
        std::cout << "Nominee Name   : " << nomineeName_ << "\n";
        std::cout << std::fixed << std::setprecision(2);
        std::cout << " Annual Premium : Rs. " << calculatePremium()  << '\n';
        std::cout << " Monthly Premium : Rs. " << calculatePremium() / 12  << '\n';
        utils::print_Line();
    }
int LifeInsurancePolicy::getTermYears() const noexcept {
    return termYears_;
}
const std::string& LifeInsurancePolicy::getNomineeName() const noexcept {
    return nomineeName_;
}
