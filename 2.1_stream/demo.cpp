#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int stringToInteger(const string& s);
void printStateBits(const istream& iss);
void stringToIntegerTest();
int main() {
    
    /*
    ostringstream oss("Ito-En Green Tea", ostringstream::ate); //buffer
    cout << oss.str() << endl; //convert to string

    oss << 16.9 <<  " Ounces";//overwrite buffer, number convert to characters
    cout << oss.str() << endl; 

    istringstream iss("16.9 Ounces");
    double amount; //what if amount is a integer?
    string unit;

    iss >> amount >> unit;
    cout << amount / 2  << " " << unit << endl;
    */
    // Call function below
    stringToIntegerTest();
    return 0;
}

int stringToInteger(const string& s) {
    istringstream iss(s);
    // printStateBits(iss);

    int result;
    iss >> result;
    if (iss.fail()) throw std::domain_error("no value int at the beginning!");

    char remain;
    iss >> remain;
    if (!iss.eof()) throw std::domain_error("more than a single valid int!");

    // printStateBits(iss);

    return result;
}

void stringToIntegerTest() {
    while (true) {
        cout << "Type in an integer: ";
        string s;
        if (!getline(cin, s))
            throw std::domain_error("getline failed");
        cout << "You typed in: " << s << "\n";
        int result = stringToInteger(s);
        cout << "As an integer, this is: " << result << "\n";
        cout << "Half of that is: " << result/2 << "\n";
    }
}

void printStateBits(const istream& iss) {
    cout << "State bits: ";

    cout << (iss.good() ? "G" : "-");
    cout << (iss.fail() ? "F" : "-");
    cout << (iss.eof() ? "E" : "-");
    cout << (iss.bad() ? "B" : "-");
    cout << endl;
    //automatically flushed!
}