#ifndef LIFEINSURANCEPOLICY_H
#define LIFEINSURANCEPOLICY_H

#include "InsurancePolicy.h"
#include <string>

class LifeInsurancePolicy final : public InsurancePolicy{

    private:
        int           termYears_;
        std::string   nomineeName_;

    public:
    LifeInsurancePolicy(std::string pol_no_,
                        std::string holder_name_,
                        int         holder_age_,
                        double      sum_assured_,
                        int         term_years_,
                        std::string nomineeName);

    void settermYears_(int termYears);
    void setnomineeName_(std::string nomineeName);

double       calculatePremium() const override;
std::string  getpolicy_type_() const override;
void         displayDetails()   const override;

int                 getTermYears()   const noexcept;
const std::string&  getNomineeName() const noexcept;

bool operator == (const LifeInsurancePolicy& lic)const;
std::partial_ordering operator <=>(const LifeInsurancePolicy& lic) const;
std::ostream& print(std::ostream& os) const;
};

inline std::ostream& operator << (std::ostream& os , const LifeInsurancePolicy& lic) {return lic.print(os);}
#endif
