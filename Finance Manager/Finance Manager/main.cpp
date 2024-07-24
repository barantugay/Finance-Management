#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

void showMenu() {
	cout << endl << endl;
	cout << "**********************************\n";
	cout << "*                                *\n";
	cout << "*       Finance Management       *\n";
	cout << "*                                *\n";
	cout << "**********************************\n\n";

	cout << "Update income/expense = 1" << endl;
	cout << "Show all income/expense = 2" << endl;
	cout << "Log out = 3 " << endl;
}

void update(int& totalIncome, int& rent, int& bills, int& kitchen, int& fun, int& others, int& totalMoney) {
	string cho;
	cout << "Please type 'Total Income', 'Rent', 'Bills', 'Kitchen', 'Fun', 'Others', 'Total Money': ";
	cin.ignore();
	getline(cin, cho);
	transform(cho.begin(), cho.end(), cho.begin(), [](unsigned char c) { return tolower(c); });

	if (cho == "total income") {
		cout << "Enter new total income: ";
		cin >> totalIncome;
	}
	else if (cho == "rent") {
		cout << "Enter new rent: ";
		cin >> rent;
	}
	else if (cho == "bills") {
		cout << "Enter new bills: ";
		cin >> bills;
	}
	else if (cho == "kitchen") {
		cout << "Enter new kitchen expenses: ";
		cin >> kitchen;
	}
	else if (cho == "fun") {
		cout << "Enter new fun expenses: ";
		cin >> fun;
	}
	else if (cho == "others") {
		cout << "Enter new other expenses: ";
		cin >> others;
	}
	else if (cho == "total money") {
		cout << "Enter new total money: ";
		cin >> totalMoney;
	}
	else {
		cout << "Invalid choice." << endl;
	}
	 
	totalMoney = totalIncome - rent - bills - kitchen - fun - others;
}

void showAll(int totalIncome, int rent, int bills, int kitchen, int fun, int others, int totalMoney) {
	cout << "Total Income: " << totalIncome << endl;
	cout << "Rent: " << rent << endl;
	cout << "Bills: " << bills << endl;
	cout << "Kitchen: " << kitchen << endl;
	cout << "Fun: " << fun << endl;
	cout << "Others: " << others << endl;
	cout << "Total Money: " << totalMoney << endl;
}


int main() {

	static int totalIncome, rent, bills, kitchen, fun, others, totalMoney;
	cout << "Type your total income: ";
	cin >> totalIncome;
	cout << "Type your house rent(if house is your own house type 0): ";
	cin >> rent;
	cout << "Type your bills: ";
	cin >> bills;
	cout << "Type your kitchen expenses: ";
	cin >> kitchen;
	cout << "Type your fun expanses: ";
	cin >> fun;
	cout << "Type your other expenses: ";
	cin >> others;
	totalMoney = totalIncome - rent - bills - fun - others;
	cout << "Congratulations, You typed all informations about incomes and expenses...";
	int choice = 0;
	do {
		
		showMenu();
		cout << "Your choice: ";
		cin >> choice;
		cout << endl << endl;

		switch (choice)
		{
		case 1:
			update(totalIncome, rent, bills, kitchen, fun, others, totalMoney);
			break;
		case 2:
			showAll(totalIncome, rent, bills, kitchen, fun, others, totalMoney);
			break;
		case 3:
			cout << "You logged out";
			break;
		
		default:
			cout << "Wrong choice" << endl;
		}

	} while (choice != 3);



	cout << endl;
	return 0;
}