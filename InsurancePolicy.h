#ifndef INSURANCEPOLICY_H
#define INSURANCEPOLICY_H

#include <string>

class InsurancePolicy{
    protected:
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
    virtual std::string  getpolicy_type()    const=0;
    virtual void         displayDetails()   const=0;
    const std::string&   getpolicy_number_()  const noexcept;
    const std::string&   getholder_name_()  const noexcept;
    int                  getholder_age_()   const noexcept;
    double               getsum_assured_()  const noexcept;
    protected:
    void displayCommon() const;
    private:
    std::string policy_number_;
    std::string holder_name_;
    int         holder_age_;
    double      sum_assured_;
};

std::ostream& operator<<(std::ostream& os,const InsurancePolicy& pol);

#endif