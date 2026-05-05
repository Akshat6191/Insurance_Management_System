#ifndef HEALTHINSURANCEPOLICY_H
#define HEALTHINSURANCEPOLICY_H

#include "InsurancePolicy.h"
#include <string>





enum class PlanType { Basic, Standard , Premium};

class HealthInsurancePolicy final: public InsurancePolicy{
    public:
    HealthInsurancePolicy(std::string polno,
    std::string holder_name ,
     int holder_age,
      double sum_assured, 
      bool hasPreExisting,
      PlanType plan );
    double calculatePremium() const override;
    std::string getPolicyType() const override;
    void        displayDetails() const override;
    std::ostream& print(std::ostream& os) const override;
    PlanType    getPlanType()    const noexcept;
    bool       hasPreExistingCond()  const noexcept;
    static std::string planTypeToString(PlanType plan);
    private:
    bool    hasPreExisting_;
    PlanType plan_;
    double planMultiplier() const noexcept;
};
#endif