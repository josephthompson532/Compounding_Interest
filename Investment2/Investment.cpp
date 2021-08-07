#include "Investment.h"
#include <iostream>

// the Constructor which sets all member variables
Investment::Investment(double* t_initial_amt, double* t_monthly_deposit, double* t_annual_interest, int* t_num_years, 
                                                double* t_total_interest_yearly, double* t_earned_interest_per_month, double* t_total_per_month)
{
    this->m_initial_amt = t_initial_amt;
    this->m_monthly_deposit = t_monthly_deposit;
    this->m_annual_interest = t_annual_interest;
    this->m_num_years = t_num_years;
    this->m_total_interest_yearly = t_total_interest_yearly;
    this->m_earned_interest_per_month = t_earned_interest_per_month;
    this->m_total_per_month = t_total_per_month;
}

// Destructor
Investment::~Investment()
{
}

// method to reset variable values inbetween calculating balances with and without 
// monthly installments
void Investment::resetVars() {
    // dereference the pointers and assigned them with initial values of zero
    *m_total_interest_yearly = 0;
    *m_earned_interest_per_month = 0;
    *m_total_per_month = 0;
    *m_initial_amt = 0;
}

// method for calculating overall balance and total accrued interest WITHOUT monthly
// payments
void Investment::calcWithoutAdditionalDeposits() {
    // loop through all 60 months that will accure
    for (int x = 1; x < (*m_num_years * 12) + 1; x++) {
        *m_earned_interest_per_month = (*m_initial_amt) * ((*m_annual_interest / 100)/12);
        *m_total_per_month = *m_initial_amt + *m_earned_interest_per_month;
        *m_initial_amt = *m_total_per_month;
        *m_total_interest_yearly += *m_earned_interest_per_month;
        
        if (x%12 == 0) {
            std::cout << "  " << x << "                     " << *m_initial_amt << "             " << *m_total_interest_yearly << "        "<< std::endl;
            *m_total_interest_yearly = 0;
        }
    }
}

// method for calculating overall balance and total accrued interest WITH monthly
// payments
void Investment::calcWithAdditionalDeposits() {
    for (int x = 1; x < (*m_num_years * 12) + 1; x++) {
        *m_earned_interest_per_month = (*m_initial_amt + *m_monthly_deposit) * ((*m_annual_interest / 100)/12);
        *m_total_per_month = *m_initial_amt + *m_monthly_deposit + *m_earned_interest_per_month;
        *m_initial_amt = *m_total_per_month;
        *m_total_interest_yearly += *m_earned_interest_per_month;
        
        if (x%12 == 0) {
            std::cout << "  " << x << "                     " << *m_initial_amt << "           " << *m_total_interest_yearly << "        "<< std::endl;
            *m_total_interest_yearly = 0;
        }
    }
}

// method for calling both functions for balance and accrued interest WITH and WITHOUT
// monthly payments and printing the results to the console.
void Investment::calculateBalanceInterest() {
    std::cout << "     Balance and Interest Without Additional Monthly Deposits     " << std::endl;
    std::cout << "==================================================================" << std::endl;
    std::cout << "  Year          Year End Balance       Year End Earned Interest   " << std::endl;
    
    calcWithoutAdditionalDeposits();
    
    resetVars();

    std::cout << "     Balance and Interest With Additional Monthly Deposits     " << std::endl;
    std::cout << "==================================================================" << std::endl;
    std::cout << "  Year          Year End Balance       Year End Earned Interest   " << std::endl;
    
    calcWithAdditionalDeposits();
}

