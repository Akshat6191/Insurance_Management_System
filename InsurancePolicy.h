#ifndef INSURANCEPOLICY_H
#define INSURANCEPOLICY_H

#include <string>

class InsurancePolicy{
    private:
        std::string policy_number_;
        std::string holder_name_;
        int         holder_age_;
        double      sum_assured_;
    protected:
        void displayCommon() const;
    public:
        InsurancePolicy(std::string pol_no, std::string holder_name, int holder_age,double sum_assured);
        InsurancePolicy(const InsurancePolicy&)             =delete;
        InsurancePolicy& operator=(const InsurancePolicy&)  =delete;
        InsurancePolicy(InsurancePolicy&&)                  =default;
        InsurancePolicy& operator=(InsurancePolicy&&)       =default;
        virtual ~InsurancePolicy()                          =default;
        virtual double       calculatePremium()     const=0;
        virtual std::string  getpolicy_type_()       const=0;
        virtual void         displayDetails()       const=0;


        const std::string&   getpolicy_number_()    const noexcept;
        const std::string&   getholder_name_()      const noexcept;
        int                  getholder_age_()       const noexcept;
        double               getsum_assured_()      const noexcept;


        void setpolicy_number_(const std::string& pol_no);
        void setholder_name_(const std::string& holder_name);
        void setholder_age_(const int holder_age);
        void setsum_assured_(const double sum_assured);
    
    
};
std::ostream& operator<<(std::ostream& os,const InsurancePolicy& pol);

#endif