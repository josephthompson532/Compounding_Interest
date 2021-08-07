 #include <iostream>
// import header files
#include "Investment.h"

// use the std namespace
using namespace std;

// function prototype for getInput
void getInput(double* initial_amt, double* monthly_deposit, double* annual_interest, int* num_years);

int main( ) {
    
    // create 7 pointers to hold values
    double* initial_amt = new double;

	double* monthly_deposit = new double;

	double* annual_interest = new double;

	int* num_years = new int;
    
    double* total_interest_yearly = new double;
    
    double* earned_interest_per_month = new double;
    
    double* total_per_month = new double;
    
    // call the getInput function to gather input from the user
    getInput(initial_amt, monthly_deposit, annual_interest, num_years);
    
    // creating a pointer avoiding raw memory access
    auto myInvestment = unique_ptr<Investment>(new Investment(initial_amt, monthly_deposit, annual_interest, num_years, 
                                                total_interest_yearly, earned_interest_per_month, total_per_month));
    // calling a method on my Investment object to calculate total balance and interest
    // accrued and print the values to screen by year.
    myInvestment->calculateBalanceInterest();
    
    // deleting all memory dynamically allocated on the heap.
    delete initial_amt;
	delete monthly_deposit;
	delete annual_interest;
	delete num_years;
    delete total_interest_yearly;
    delete earned_interest_per_month;
    delete total_per_month;
    
    return 0;
}

// get input function takes in 4 pointers and reads values into them from user.
void getInput(double* initial_amt, double* monthly_deposit, double* annual_interest, int* num_years) {
    cout << "**********************************" << endl;
	cout << "********** Data Input ************" << endl;
	cout << "Initial Investment Amount: ";
	// type checking the input values to make sure they are of valid type.
    while(!(cin >> *initial_amt)){
        // if the type is invalid, print out warning
        cout << "Incorrect input type! Please enter again: ";
        // clear input
        cin.clear();
        // ignore the rest of the line.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    // do the same for the other pointer variables.
    
	cout << "Monthly Deposit: ";
    while(!(cin >> *monthly_deposit)){
        cout << "Incorrect input type! Please enter again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
	cout << "Annual Interest: ";
    while(!(cin >> *annual_interest)){
        cout << "Incorrect input type! Please enter again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
	cout << "Number of years: ";
    while(!(cin >> *num_years)){
        cout << "Incorrect input type! Please enter again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}