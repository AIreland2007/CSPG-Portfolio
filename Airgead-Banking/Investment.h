#ifndef AIRGEAD_BANKING_INVESTMENT_H_
#define AIRGEAD_BANKING_INVESTMENT_H_

// Class used to store investment information
// and generate compound interest reports
class Investment
{
public:
    Investment();

    // Collect user input
    void getUserInput();

    // Display entered values
    void displayInputSummary() const;

    // Display report without monthly deposits
    void displayReportWithoutDeposits() const;

    // Display report with monthly deposits
    void displayReportWithDeposits() const;

private:
    // Investment data members
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterest;
    int m_numberYears;

    // Input validation functions
    double getValidatedDouble(const char* t_prompt, bool t_allowZero) const;
    int getValidatedInteger(const char* t_prompt) const;

    // Helper function used to generate reports
    void displayReport(double t_monthlyDeposit) const;
};

#endif