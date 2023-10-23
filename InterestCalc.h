#ifndef Project_Two_Header_Files_InterestCalc_H_
#define Project_Two_Header_Files_InterestCalc_H_
#pragma once  //Similar to #ifndef, bur prevents header file from being included more than once

class InterestCalc {

public:
	// Default constructor declaration
	InterestCalc(); 
	  
	// Setters and Getters
	void setInitialDeposit(double t_initialDeposit);
	void setMonthlyDeposit(double t_monthlyDeposit);
	void setPercentInterest(double t_percentInterest);
	void setNumberYears(int t_numberYears);
	double getInitialDeposit();
	double getMonthlyDeposit();
	double getPercentInterest();
	int getNumberYears();

	//Function to calculate monthly balance
	double monthlyBalance(int t_months, double t_monthDeposit);
	//Function to calculate monthly interest
	double monthlyInterest(int t_months, double t_monthDeposit);
	//Function to calculate annual balance
	double annualBalance(int t_numYears, double t_depositAmount);
	//Function to calculate annual interest
	double annualInterest(int t_numYears, double t_depositAmount);
	//Function to display data
	void showReport(double t_monthlyDep);

//Private objects of class - objects cannot be manipulated from outside the class
private:
	double initialDeposit;
	double monthlyDeposit;
	double percentInterest;
	int numberYears;
};
#endif