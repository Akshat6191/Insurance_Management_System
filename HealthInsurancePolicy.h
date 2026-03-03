#ifndef HEALTHINSURANCEPOLICY_H
#define HEALTHINSURANCEPOLICY_H

#include "InsurancePolicy.h"
#include <string>

<<<<<<< HEAD
=======




>>>>>>> 8453b9a (Edited LifeInsurancePolicy.h)
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
    std::string getpolicy_type_() const override;
    void        displayDetails() const override;
    PLanType    getplan_type_()    const noexcept;
    bool       hasPreExistingCond()  const noexcept;
    static std::string planTypeToString(PlanType plan);
    private:
    bool    HasPreExisting_;
    PlanType plan_;
    double planmultiplier() const noexcept;
};
<<<<<<< HEAD
=======

>>>>>>> 8453b9a (Edited LifeInsurancePolicy.h)
#endif