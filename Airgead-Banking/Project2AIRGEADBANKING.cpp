#include "Investment.h"

#include <iostream>
#include <limits>

using namespace std;

int main()
{
    char runAgain = 'y';

    cout << "Welcome to Airgead Banking Investment Calculator" << endl;
    cout << endl;

    while (runAgain == 'y' || runAgain == 'Y')
    {
        // Create a new investment scenario
        Investment investment;

        // Gather user investment information
        investment.getUserInput();

        // Display the values entered by the user
        investment.displayInputSummary();

        cout << "Press Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();

        // Display both investment reports
        investment.displayReportWithoutDeposits();
        investment.displayReportWithDeposits();

        cout << endl;
        cout << "Would you like to test another investment scenario? (y/n): ";
        cin >> runAgain;
        cout << endl;
    }

    cout << "Thank you for using the Airgead Banking Investment Calculator." << endl;

    return 0;
}