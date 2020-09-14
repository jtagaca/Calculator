#include<iostream>

using namespace std;

double get_money(string prompt);

double get_money(string prompt, double &minimum);

void calc_change(double change, int &quarters, int &dimes, int &nickels, int &pennies);

int main() {
    double total = 0, num1, tendered = 0, change;
    int quarters = 0, dimes = 0, nickels = 0, pennies = 0;


    total = get_money("Enter total: ");


    tendered = get_money("Enter amount tendered: ", total);
    change = tendered - total;
    cout << endl;
    cout << "Your change is " << change << endl << endl;
    calc_change(change, quarters, dimes, nickels, pennies);
    cout << "You should now have " << quarters << " quartes(s)," << dimes << " dimes," << nickels << " nickels,"
         << pennies << " pennies" << endl;


    return 0;
}

double get_money(string prompt) {
    double num1;
    do {
        cout << prompt << endl;
        cin >> num1;

    } while (num1 < 0);
    return num1;
}

double get_money(string prompt, double &minimum) {
    double tendered;
    do {
        cout << prompt << endl;
        cin >> tendered;

        if (tendered <= minimum) {
            cout << "*** Amount must be at least " << minimum << endl;

        }


    } while (tendered < minimum);
    return tendered;
}

void calc_change(double change, int &quarters, int &dimes, int &nickels, int &pennies) {
    double newvalue;
    //int se_change=change;
    if(change>=1)
   { 
       int intPart=change;
       change=change-intPart;

    }
    
    quarters = change / .25;
    newvalue = (change - (quarters * .25));
    dimes = newvalue / .10;
    newvalue = (change - (quarters * .25) - (dimes * .10));
    nickels = newvalue / .05;
    newvalue = (change - (quarters * .25) - (dimes * .10) - nickels * .05);
    pennies = newvalue / .01;

}








