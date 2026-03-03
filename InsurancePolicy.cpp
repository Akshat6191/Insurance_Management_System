#include<iostream>
#include "utils.h"
#include "InsurancePolicy.h"
#include<iomanip>
#include<stdexcept>
#include<utility>
// 

InsurancePolicy::InsurancePolicy(std::string pol_no , std::string holder_name , int holder_age , double sum_assured) : 
                                policy_number_(std::move(pol_no)) ,
                                holder_name_(std::move(holder_name)) ,
                                holder_age_(holder_age) , 
                                sum_assured_(sum_assured) {
                                    if(holder_age_ <= 0 || holder_age_ >120) {
                                        throw std :: invalid_argument("Age must be between 1 and 120.");
                                    }

                                    if(sum_assured_ <= 0.0){
                                        throw std:: invalid_argument("Sum assured must be positive value.");
                                    }
                                }

const std::string& InsurancePolicy::getpolicy_number_() const noexcept{return policy_number_;}
const std::string& InsurancePolicy::getholder_name_() const noexcept{return holder_name_;}
int                InsurancePolicy::getholder_age_() const noexcept{return holder_age_;}
double             InsurancePolicy::getsum_assured_() const noexcept{return sum_assured_;}


void InsurancePolicy::setpolicy_number_(const std::string& pol_no){
    if(pol_no.empty()){
        throw std::invalid_argument("Policy number cannot be empty,");
    }
    policy_number_ = pol_no;
}
void InsurancePolicy::setholder_name_(const std::string& holder_name) {
    if(holder_name.empty()){
        throw std::invalid_argument("Holder holder_ cannot be empty.");
    }
            holder_name_ = holder_name;
}
void InsurancePolicy::setholder_age_(const int holder_age){
    if(holder_age<=0 || holder_age>120){
        throw std::invalid_argument("Age must be between 1 and 120");
    }
            holder_age_ = holder_age;
}
void InsurancePolicy :: setsum_assured_(const double holder_sum) {
    if(holder_sum<=0.0){
        throw std::invalid_argument("Sum assured must be positive.");
    }
            sum_assured_ = holder_sum;

}

bool InsurancePolicy :: operator == (const InsurancePolicy& pln)const noexcept{
    return policy_number_ == pln.policy_number_;
}
// bool InsurancePolicy :: operator < (const InsurancePolicy& sa)const noexcept {
//     return sum_assured_ < sa.sum_assured_;
// }
// bool InsurancePolicy ::operator > (const InsurancePolicy& sa) const noexcept {
//     return sum_assured_ > sa.sum_assured_;
// }

std::partial_ordering InsurancePolicy::operator<=>(const InsurancePolicy& pln) const noexcept{
    return sum_assured_ <=> pln.sum_assured_ ;
}

        // auto InsurancePolicy::operator<=>(const InsurancePolicy& pin)const noexcept{
        //     return sum_assured_ <=> pin.sum_assured_;
        // }


std::istream& operator >> (std:: istream& ip , InsurancePolicy& policy){
    std::string pol_no , holder_name;
    int holder_age{};
    double sum_assured;
    std::cout<<"Policy number:- ";
    std::getline(ip , pol_no);
    std::cout<<"Holder name:- ";
    std::getline(ip , holder_name);
    std::cout<<"Holder age:- ";
    ip>>holder_age;
    ip.ignore();
    std::cout<<"Sum Assured:- ";
    ip>>sum_assured;

    policy.setpolicy_number_(pol_no);
    policy.setholder_name_(holder_name);
    policy.setholder_age_(holder_age);
    policy.setsum_assured_(sum_assured);
    
    return ip;
}


std::ostream& operator << (std::ostream& os , const InsurancePolicy& pol) {
    os << std::fixed << std::setprecision(2);
    os << "[" << pol.getpolicy_number_() <<"]" << pol.getpolicy_type_()<< " | " << pol.getholder_name_() << " | " << "Age:- "<< pol.getholder_age_()<< " | "<< " Sum: Rs "<<pol.getsum_assured_();

    return os;
}

void InsurancePolicy::displayCommon() const {
    std::cout<<std::fixed << std::setprecision(2);
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "  Policy Number   : " << policy_number_   << '\n';
    std::cout << "  Policy Type     : " << getpolicy_type_() << '\n';
    std::cout << "  Holder Name     : " << holder_name_     << '\n';
    std::cout << "  Holder Age      : " << holder_age_ << " years\n";
    std::cout << "  Sum Assured     : Rs. " << sum_assured_ << '\n';
}
