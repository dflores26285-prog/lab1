#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


// ==========================================
// FUNCTION 1: GET ACCOUNT NUMBER
// ==========================================
string getAccountNumber()
{
    string acc;

    cout << "Enter Customer Account number: ";
    cin >> acc;

    return acc;
}


// ==========================================
// FUNCTION 2: GET CUSTOMER NAME
// ==========================================
string getCustomerName()
{
    string name;

    cout << "Enter customer Full Name: ";

    cin.ignore();
    getline(cin, name);

    return name;
}


// ==========================================
// FUNCTION 3: GET METER READINGS
// ==========================================
void getReadings(double &pre, double &cur)
{
    cout << "Enter Previous reading (kWh): ";
    cin >> pre;

    cout << "Enter current Reading (kWh): ";
    cin >> cur;
}


// ==========================================
// FUNCTION 4: CALCULATE CONSUMPTION
// ==========================================
double calculateConsumption(double pre, double cur)
{
    return cur - pre;
}


// ==========================================
// FUNCTION 5: CALCULATE TIER CHARGES
// ==========================================
void calculateTierCharges(double consumption,
                          double &fus,
                          double &sus,
                          double &tus)
{
    double rate1 = 0.08;
    double rate2 = 0.12;
    double rate3 = 0.16;

    fus = 0;
    sus = 0;
    tus = 0;

    if (consumption <= 500)
    {
        fus = consumption * rate1;
    }
    else if (consumption <= 1000)
    {
        fus = 500 * rate1;
        sus = (consumption - 500) * rate2;
    }
    else
    {
        fus = 500 * rate1;
        sus = 500 * rate2;
        tus = (consumption - 1000) * rate3;
    }
}


// ==========================================
// FUNCTION 6: CALCULATE TOTALS
// ==========================================
void calculateTotals(double charge,
                     double fus,
                     double sus,
                     double tus,
                     double &subtotal,
                     double &surcharge,
                     double &totalBalance)
{
    subtotal = charge + fus + sus + tus;

    surcharge = subtotal * 0.055;

    totalBalance = subtotal + surcharge;
}


// ==========================================
// FUNCTION 7: DISPLAY INVOICE
// ==========================================
void displayInvoice(string acc,
                    string name,
                    double consumption,
                    double charge,
                    double fus,
                    double sus,
                    double tus,
                    double subtotal,
                    double surcharge,
                    double totalBalance)
{
    cout << fixed << setprecision(2);

    cout << "\n=======================================================\n";
    cout << "\n                ITEMIZED UTILITY INVOICE\n";
    cout << "\n=======================================================\n";

    cout << left << setw(20) << "Account Number"
         << ": " << acc << "\n";

    cout << left << setw(20) << "Customer Name"
         << ": " << name << "\n";

    cout << left << setw(20) << "Total Consumption"
         << ": " << consumption << " kWh\n";

    cout << "--------------------------------------------------------\n";

    cout << left << setw(38) << "Line Item Breakdown"
         << "Amount ($)\n";

    cout << "--------------------------------------------------------\n";

    cout << left << setw(35) << "Base Customer Charge"
         << "$" << right << setw(10) << charge << "\n";

    cout << left << setw(35) << "Tier 1 Usage (First 500.00 kWh)"
         << "$" << right << setw(10) << fus << "\n";

    cout << left << setw(35) << "Tier 2 Usage (Next 500.00 kWh)"
         << "$" << right << setw(10) << sus << "\n";


    double excessKwh;

    if (consumption > 1000)
    {
        excessKwh = consumption - 1000;
    }
    else
    {
        excessKwh = 0.0;
    }

    cout << left << "Tier 3 Usage (Excess "
         << excessKwh << " kWh)"
         << right << setw(35)
         << "$" << right << setw(10)
         << tus << "\n";

    cout << "--------------------------------------------------------\n";

    cout << left << setw(35) << "Total Consumption Subtotal"
         << "$" << right << setw(10) << subtotal << "\n";

    cout << left << setw(35)
         << "Municipal Clean Energy Surcharge (5.5%)"
         << "$" << right << setw(10) << surcharge << "\n";

    cout << "========================================================\n";

    cout << left << setw(35) << "TOTAL BALANCE DUE"
         << "$" << right << setw(10) << totalBalance << "\n";

    cout << "========================================================\n";

    cout << "Payment Due Date: 21 Days From Statement Generation.\n";
    cout << "Thank you for being a valued customer!\n";
}


// ==========================================
// MAIN FUNCTION
// ==========================================
int main()
{
    double pre, cur;
    double consumption;

    double charge = 18.50;

    double fus = 0;
    double sus = 0;
    double tus = 0;

    double subtotal;
    double surcharge;
    double totalBalance;


    cout << "\n======================================================\n";
    cout << "\n               Orange Walk BEL Agency\n";
    cout << "\n             MONTHLY BILLING CALCULATOR\n";
    cout << "\n======================================================\n";


    // Get customer information
    string acc = getAccountNumber();

    string name = getCustomerName();

    // Get meter readings
    getReadings(pre, cur);

    cout << "\nComputing charges... Done.\n\n";


    // Calculate consumption
    consumption = calculateConsumption(pre, cur);


    // Calculate tier charges
    calculateTierCharges(consumption, fus, sus, tus);


    // Calculate subtotal, surcharge and total
    calculateTotals(charge, fus, sus, tus,
                    subtotal, surcharge, totalBalance);


    // Display final invoice
    displayInvoice(acc, name, consumption,
                   charge, fus, sus, tus,
                   subtotal, surcharge, totalBalance);


    return 0;
}
