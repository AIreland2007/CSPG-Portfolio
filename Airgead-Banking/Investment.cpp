#include "Investment.h"

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

// Default constructor
Investment::Investment()
{
    m_initialInvestment = 0.0;
    m_monthlyDeposit = 0.0;
    m_annualInterest = 0.0;
    m_numberYears = 0;
}

// Get validated double input
double Investment::getValidatedDouble(const char* t_prompt, bool t_allowZero) const
{
    double value;

    while (true)
    {
        cout << t_prompt;
        cin >> value;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
        }
        else if ((!t_allowZero && value <= 0) || (t_allowZero && value < 0))
        {
            cout << "Please enter a valid positive number." << endl;
        }
        else
        {
            return value;
        }
    }
}

// Get validated integer input
int Investment::getValidatedInteger(const char* t_prompt) const
{
    int value;

    while (true)
    {
        cout << t_prompt;
        cin >> value;

        if (cin.fail() || value <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid whole number greater than zero." << endl;
        }
        else
        {
            return value;
        }
    }
}

// Collect user input
void Investment::getUserInput()
{
    cout << "**********************************" << endl;
    cout << "********** Data Input ************" << endl;

    m_initialInvestment =
        getValidatedDouble("Initial Investment Amount: $", false);

    m_monthlyDeposit =
        getValidatedDouble("Monthly Deposit: $", true);

    m_annualInterest =
        getValidatedDouble("Annual Interest (%): ", false);

    m_numberYears =
        getValidatedInteger("Number of Years: ");
}

// Display input summary
void Investment::displayInputSummary() const
{
    cout << endl;
    cout << "Initial Investment Amount: $" << fixed << setprecision(2)
        << m_initialInvestment << endl;

    cout << "Monthly Deposit: $" << m_monthlyDeposit << endl;

    cout << "Annual Interest: "
        << m_annualInterest << "%" << endl;

    cout << "Number of Years: "
        << m_numberYears << endl;

    cout << endl;
}

// Generic report function
void Investment::displayReport(double t_monthlyDeposit) const
{
    double balance = m_initialInvestment;

    cout << fixed << setprecision(2);

    cout << left
        << setw(10) << "Year"
        << setw(25) << "Year End Balance"
        << setw(25) << "Year End Earned Interest"
        << endl;

    cout << "-----------------------------------------------------------"
        << endl;

    for (int year = 1; year <= m_numberYears; year++)
    {
        double yearlyInterest = 0.0;

        for (int month = 1; month <= 12; month++)
        {
            double interest =
                (balance + t_monthlyDeposit) *
                ((m_annualInterest / 100) / 12);

            yearlyInterest += interest;

            balance += t_monthlyDeposit + interest;
        }

        cout << left
            << setw(10) << year
            << setw(25) << balance
            << setw(25) << yearlyInterest
            << endl;
    }
}

// Report without deposits
void Investment::displayReportWithoutDeposits() const
{
    cout << endl;
    cout << "Balance and Interest Without Additional Monthly Deposits"
        << endl;
    cout << endl;

    displayReport(0.0);
}

// Report with deposits
void Investment::displayReportWithDeposits() const
{
    cout << endl;
    cout << "Balance and Interest With Additional Monthly Deposits"
        << endl;
    cout << endl;

    displayReport(m_monthlyDeposit);
}