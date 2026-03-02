#include<iostream>
#include "utils.h"
#include "InsurancePolicy.h"
#include<iomanip>
#include<stdexcept>
#include<utility>
class InsurancePolicy{
    protected:
        std::string policy_number_;
        std::string holder_name_;
        int holder_age_;
        double sum_assured_;
}

InsurancePolicy::InsurancePolicy(std::string pol_no , std::string holder_name , int holder_age , double sum_assured) : 
                                policy_number_(std::move(pol_no)) ,
                                holder_name_(std::move(holder_name)) ,
                                holder_age_(holder_age) , 
                                sum_assured_(sum_assured) {
                                    if(holder_age_ <= 0 || holder_age_ >120) {
                                        throw std :: invalid_argument("Agw must be between 1 and 120.");
                                    }

                                    if(sum_assured_ <= 0.0){
                                        throw std:: invalid_argument("Sum assured must be positive value.");
                                    }
                                }

const std::string& InsurancePolicy::getpolicy_number_() const noexcept{return policy_number_;}
const std::string& InsurancePolicy::getholder_name_() const noexcept{return holder_name;}
int                InsurancePolicy::getholder_age_() const noexcept{return holder_age_;}
double             InsurancePolicy::getsum_assured_() const noexcept{return sum_assured_;}



