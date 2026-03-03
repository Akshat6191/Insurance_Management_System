#ifndef LIFEINSURANCEPOLICY_H
#define LIFEINSURANCEPOLICY_H

#include "InsurancePolicy.h"
#include <string>

class LifeInsurancePolicy final : public InsurancePolicy{
    public:
    LifeInsurancePolicy(std::string pol_no_,
                        std::string holder_name_,
                        int         holder_age_,
                        double      sumAssured,
                        std::string nomineeName);

double       calculatePremium() const override;
std::string  getPolicyType()    const override;
void         displayDetails()   const override;

int                 getTermYears()   const noexcept;
const std::string&  getNomineeName() const noexcept;

private:
int           termYears_;
std::string   nomineeName_;
};
#endif
