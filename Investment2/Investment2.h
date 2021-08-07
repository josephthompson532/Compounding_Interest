#ifndef INVESTMENT_INVESTMENT_H
#define INVESTMENT_INVESTMENT_H
// using define guards

class Investment
{
public:
    // Defining a single constructor to instantiate the class
    Investment(double* t_initial_amt, double* t_monthly_deposit, double* t_annual_interest, int* t_num_years, 
                double* t_total_interest_yearly, double* t_earned_interest_per_month, double* t_total_per_month);
    ~Investment();
    // defining methods in header file.
    void calculateBalanceInterest();
    void resetVars();
    void calcWithAdditionalDeposits();
    void calcWithoutAdditionalDeposits();

private:
    // setting all variables to private 
    double* m_initial_amt;
	double* m_monthly_deposit;
	double* m_annual_interest;
	int* m_num_years;
    double* m_total_interest_yearly;
    double* m_earned_interest_per_month;
    double* m_total_per_month;

};

#endif // INVESTMENT_INVESTMENT_H
