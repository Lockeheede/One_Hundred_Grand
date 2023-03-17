// One_Hundred_Grand.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Simple Program the checks until $100,000
// Input currentAmt, targetAmt, moneyIn, moneyOut

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//Variables
float currentAmt;
float targetAmt;
float moneyIn; //Monthly
float moneyOut; //Monthly
float salary; //Yearly
char choice;
char reverse; //Extra variable



//Functions
float UntilOneGrand(float cA, float tA, float mI, float mO);
void MonthsUntil(float cA, float tA, float mI, float mO);
float UntilOneGrandSalary(float cA, float tA, float sal, float mO);
void MonthsUntilSalary(float cA, float tA, float sal, float mO);
void SavedPerMonth(float tA, float mI, float mO);

int main()
{
    cout << "How Much You'll Save Per Month? (M) \n";
    cout << "Or How Many Months Until A Target? (T): ";
    cin >> reverse;
    toupper(reverse);
    if (reverse == 'T')
    {
        float sum = 0.0f;

        cout << "Enter Target Amount: ";
        cin >> targetAmt;
        cout << "Enter Current Amount: ";
        cin >> currentAmt;

        if (currentAmt == targetAmt)
        {
            cout << "You already have " << targetAmt << "!\n";
            return 0;
        }

        if (currentAmt > targetAmt)
        {
            cout << "You already have more than " << targetAmt << "!\n";
            return 0;
        }

        cout << "Salary? (Y/N) ";
        cin >> choice;
        toupper(choice);
        if (choice == 'Y')
        {
            cout << "Enter Salary: ";
            cin >> salary;
            cout << "Enter Money Out Monthly: ";
            cin >> moneyOut;
            sum = UntilOneGrandSalary(currentAmt, targetAmt, salary, moneyOut);
            MonthsUntilSalary(currentAmt, targetAmt, salary, moneyOut);
        }
        else
        {
            cout << "Enter Money In Monthly: ";
            cin >> moneyIn;
            cout << "Enter Money Out Monthly: ";
            cin >> moneyOut;

            if (moneyOut >= moneyIn)
            {
                cout << "Monthly Out cannot be equal to or greater than Monthly In to make a profit!\n";
                return 0;
            }
            sum = UntilOneGrand(currentAmt, targetAmt, moneyIn, moneyOut);
            MonthsUntil(currentAmt, targetAmt, moneyIn, moneyOut);

        }



        cout << "Sum: " << sum << endl;
    }
    else if (reverse == 'M')
    {
        cout << "Target Amount: ";
        cin >> targetAmt;
        cout << "Money in Monthly: ";
        cin >> moneyIn;
        cout << "Money Out Monthly: ";
        cin >> moneyOut;
        
        SavedPerMonth(targetAmt, moneyIn, moneyOut);
    }
    
}

float UntilOneGrand(float cA, float tA, float mI, float mO)
{
   
    while (cA < tA)
    {
        cA += mI;
        cA -= mO;
        cout << "Current Amount: " << cA << endl;
        cout << "Until Target Amount: " << tA - cA << endl;
    }

    return cA; 
}

void MonthsUntil(float cA, float tA, float mI, float mO)
{
    int months = 0;
    while (cA < tA)
    {
        cA += mI;
        cA -= mO;

        ++months;
    }
    cout << "Months Necessary: " << months << endl;
}

float UntilOneGrandSalary(float cA, float tA, float sal, float mO)
{
    sal /= 12;
    while (cA < tA)
    {
        cA += sal;
        cA -= mO;
        cout << "Current Amount: " << cA << endl;
        cout << "Until Target Amount: " << tA - cA << endl;
    }

    return cA;
}

void MonthsUntilSalary(float cA, float tA, float sal, float mO)
{
    sal /= 12;
    int months = 0;
    while (cA < tA)
    {
        cA += sal;
        cA -= mO;

        ++months;
    }
    cout << "Months Necessary: " << months << endl;
}

void SavedPerMonth(float tA, float mI, float mO)
{
    if (mI < mO)
    {
        cout << "You are spending more than you are making.\n";
    }
    else
    {
        float sum = 0.0f;
        int months = 0;
        while (sum < tA)
        {
            sum += mI;
            sum -= mO;

            months++;
        }

        cout << "You need to save $" << sum / months << " a month for " << months << " months to make $" << tA << endl;
    }
}
