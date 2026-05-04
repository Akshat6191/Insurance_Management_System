#ifndef POLICYVAULT_H
#define POLICYVAULT_H

#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>

// ============================================================
//  PolicyVault<T> — Generic Policy Container
//
//  OOP Demonstrated:
//    Templates     : Works with any type derived from InsurancePolicy
//
//  Design:
//    Uses std::unique_ptr — no manual new/delete, no memory leaks.
//    T must be a polymorphic type with:
//      getPolicyNumber(), getHolderName(), calculatePremium(),
//      displayDetails()
// ============================================================

template <typename T>
class PolicyVault {
public:
    PolicyVault()                              = default;
    ~PolicyVault()                             = default;

    // Non-copyable (unique_ptr ownership)
    PolicyVault(const PolicyVault&)            = delete;
    PolicyVault& operator=(const PolicyVault&) = delete;

    // Movable
    PolicyVault(PolicyVault&&)                 = default;
    PolicyVault& operator=(PolicyVault&&)      = default;

    // ---- Mutators ----------------------------------------------

    void addPolicy(std::unique_ptr<T> policy) {
        policies_.push_back(std::move(policy));
    }

    // ---- Queries -----------------------------------------------

    std::size_t count() const noexcept {
        return policies_.size();
    }

    bool isEmpty() const noexcept {
        return policies_.empty();
    }

    double totalAnnualPremiums() const {
        double total = 0.0;
        for (const auto& p : policies_)
            total += p->calculatePremium();
        return total;
    }

    // Returns raw observer pointer — caller does NOT own it
    T* findByPolicyNumber(const std::string& polNo) const {
        auto it = std::find_if(policies_.begin(), policies_.end(),
            [&polNo](const std::unique_ptr<T>& p) {
                return p->getPolicyNumber() == polNo;
            });
        return (it != policies_.end()) ? it->get() : nullptr;
    }

    void findByHolderName(const std::string& name) const {
        bool found = false;
        for (const auto& p : policies_) {
            if (p->getHolderName() == name) {
                p->displayDetails();
                found = true;
            }
        }
        if (!found)
            std::cout << "\n  No policy found for holder: " << name << '\n';
    }

    void displayAll() const {
        if (policies_.empty()) {
            std::cout << "\n  Vault is empty. No policies registered.\n";
            return;
        }
        int serial = 1;
        for (const auto& p : policies_) {
            std::cout << "\n  [" << serial++ << "]";
            p->displayDetails();
        }
    }

private:
    std::vector<std::unique_ptr<T>> policies_;
};

#endif // POLICYVAULT_H
