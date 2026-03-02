#ifndef HEALTHINSURANCEPOLICY_H
#define HEALTHINSURANCEPOLICY_H

#include "InsurancePolicy.h"
#include <string>

enum class PlanType { Basic, Standard ,Premium};

class HealthInsurancePolicy final: public InsurancePolicy{
    public:
    HealthInsurancePolicy(std::string polno,
    std::string holdername ,
     int holderAge,
      double sumAssured, 
      bool hasPreExisting,
      PlanType plan );
    double calculatePremium() const override;
    std::string getPolicyType() const override;
    void        displayDetails() const override;
    Plantype    getPlantype()    const noexcept;
    bool       hasPreExistingCond()  const noexcept;
    static std::string planTypeToString(PlanType plan);
    private:
    bool    HasPreExisting_;
    PlanType plan_;
    double planmultiplier() const noexcept;
};
#endif