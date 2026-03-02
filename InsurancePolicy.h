#ifndef INSURANCEPOLICY_H
#define INSURANCEPOLICY_H

#include <string>
#include<ostream>
class InsurancePolicy{
    public:
    InsurancePolicy(std::string pol_no_,
                    std::string holder_name_,
                    int         holder_age_,
                    double      sum_assured_
    );
    InsurancePolicy(const InsurancePolicy&)         =delete;
    InsurancePolicy& operator=(const InsurancePolicy&)=delete;
    InsurancePolicy(InsurancePolicy&&)            =default;
    InsurancePolicy& operator=(InsurancePolicy&&)=default;
    virtual ~InsurancePolicy() = default;
    virtual double       calculatePremium() const=0;
    virtual std::string  getPolicyType()    const=0;
    virtual void         displayDetails()   const=0;
    const std::string&   getPolicyNumber()  const noexcept;
    const std::string&   getHolderName()  const noexcept;
    int                  getHolderAge()   const noexcept;
    double               getSumAssured()  const noexcept;
    protected:
    void displayCommon() const;
    private:
    std::string policy_number_;
    std::string holder_name_;
    int         holder_age_;
    double      sum_assured_;
}

std::ostream& operator<<(std::ostream& os,const InsurancePolicy& policy);

#endif