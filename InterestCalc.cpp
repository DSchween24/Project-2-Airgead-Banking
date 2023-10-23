#include "InterestCalc.h"
#include <iostream>
#include <iomanip>
using namespace std;

//Default constructor - Parameters initalized to zero
InterestCalc::InterestCalc() {
	initialDeposit = 0.00;
	monthlyDeposit = 0.00;
	percentInterest = 0.00;
	numberYears = 0;
}

//Setters and Getters
void InterestCalc::setInitialDeposit(double t_initialDeposit) { 
	initialDeposit = t_initialDeposit;
}
void InterestCalc::setMonthlyDeposit(double t_monthlyDeposit) { 
	monthlyDeposit = t_monthlyDeposit;
}
void InterestCalc::setPercentInterest(double t_percentInterest) {
	percentInterest = t_percentInterest;
}
void InterestCalc::setNumberYears(int t_numberYears) {
	numberYears = t_numberYears;
}
double InterestCalc::getInitialDeposit() { 
	return initialDeposit;
}
double InterestCalc::getMonthlyDeposit() {
	return monthlyDeposit;
}
double InterestCalc::getPercentInterest() { 
	return percentInterest;
}
int InterestCalc::getNumberYears() {
	return numberYears;
}

//function to calculate monthly balance
double InterestCalc::monthlyBalance(int t_months, double t_monthDeposit) {
	double balAmount = getInitialDeposit();
	for (int i = 0; i < t_months; i++) {
		balAmount = balAmount + t_monthDeposit;
		balAmount = balAmount + ((balAmount * getPercentInterest() / 100) / 12);
	}
	return balAmount;
}

//function to calculate monthly interest -- calculate single month interest only
double InterestCalc::monthlyInterest(int t_months, double t_monthDeposit) {
	double intAmount;double monthlyInterestRate = (getPercentInterest() / 100) / 12;
	intAmount = (monthlyBalance(t_months - 1, t_monthDeposit) + t_monthDeposit) * monthlyInterestRate;
		return intAmount;
}

//function to calculate annual balance - running total year over year 
double InterestCalc::annualBalance(int t_numYears, double t_depositAmount) {
	int numMonths;
	double annualBal = 0.00;
	numMonths = t_numYears * 12;
	 
	for (int i = 0; i < t_numYears; i++) { 
		annualBal = monthlyBalance(numMonths, t_depositAmount);
	}
	return annualBal;
}

//function to calculate annual interest
double InterestCalc::annualInterest(int t_numYears, double t_depositAmount) {
	int numMonths;
	double annualInt = 0.00;
	double priorYears = 0.00;
	numMonths = t_numYears * 12;

	for (int i = 0; i < numMonths; i++) {
		annualInt = annualInt + monthlyInterest(i + 1, t_depositAmount);
	}
	for (int j = 0; j < numMonths - 12; j++) {
		priorYears = priorYears - monthlyInterest(j + 1, t_depositAmount);
	}
	annualInt = annualInt + priorYears;
		return annualInt;
}

//Function to display data - Pass in 0 for without deposit
void InterestCalc::showReport(double t_monthlyDep) {
	cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "     " << "Year" << "          " << "Year End Balance" << "           " << "Year End EarnedInterest" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << setprecision(2) << fixed << endl; //Round to nearest hundredth decimal
	for (int i = 0; i < getNumberYears(); i++) {
		cout << "     " << i + 1 << "              " << annualBalance(i + 1,t_monthlyDep) << "                       " << annualInterest(i + 1,t_monthlyDep) << endl;
	}
		return;


}