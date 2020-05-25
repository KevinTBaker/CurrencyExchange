#include "exchange.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <vector>
#include <iostream>

using namespace std;

bool repeat(true);

void	show_value_of_btc(t_values *values)
{
	printf("Current value of Bitcoin is at: %d\n", values->valuebtc);
	//values->user_choice = 0;
}

void	show_balance(t_values *values)
{
	printf("Your Balance of BTC is: %lf\n", values->numberofbtc);
	printf("Your Balance of USD is: %lf\n", values->cash_balance);
}

int	check_amount(t_values *values)
{
	if (values->user_choice == 3)
	{
		if (values->sellingbtc > values->numberofbtc)
			return (1);
		else
			return (0);
	}
	else if (values->final_cash_balance > values->cash_balance)
		return (1);
	else
		return (0);
}

class ledger
{
	public :
		vector <string> Transaction;
		vector <float> Value;
		string symbol = "BTC";
		vector <string> Time;		
		void record()
		{
			for (unsigned int i = 0; i < Transaction.size(); i++) 
			{
				cout << Time.at(i) << "   ";
				cout << Transaction.at(i) << ' ';
				cout << Value.at(i) << ' ';
				cout << symbol << endl << endl;
			}
		}
};

class	The_Date
{
	string trans_time;
	void Record_Time ()
	{
		time_t now = time(0);
		trans_time = ctime(&now);
	}
}

class	wallet
{
	public: 
		void	buy_bitcoin(t_values *values)
		{
			double ogcashmoneys = 0;
			printf("How many BTC's would you like to buy?\n");
			scanf("%lf", &values->numberofbtc);
			values->final_cash_balance = values->numberofbtc * values->valuebtc;
			if (check_amount(values) == 1)
				printf("You do not have enough credits to complete transaction! Try again\n");
			else
			{
				//ledger ledgerclass;
				ogcashmoneys = values->cash_balance;
				//ledgerclass.record();
				values->cash_balance = ogcashmoneys - values->final_cash_balance;

			}
			printf("Your current balance is: %lf dollars\n", values->cash_balance);
			
			//ledgerclass.record;
		}
		void	sell_bitcoin(t_values *values)
		{
			printf("How many BTC's would you like to sell?\n");
			scanf("%lf", &values->sellingbtc);
			if (check_amount(values) == 1)
				printf("You do not have that much BTC boyo\n");
			if (check_amount(values) == 1 && values->numberofbtc == 0)
				printf("You don't have any BTC. Buy some before you can sell\n");
			else
			{
				values->numberofbtc -= values->sellingbtc;
				values->final_cash_balance = values->sellingbtc * values->valuebtc;
				values->cash_balance += values->final_cash_balance;
			}
			printf("%lf is the btc in your wallet\n", values->numberofbtc);
			printf("%lf is you balance\n", values->cash_balance);
		}

};

void	choice(t_values *values)
{
	ledger		show_purchase;
	ledger		show_sell;
	The_date	purchase_time;
	The_date	sell_time;

	if (values->user_choice == 1)
		show_value_of_btc(values);
	else if (values->user_choice == 2)
	{	wallet walletclass;
		//ledger ledgerclass;
		walletclass.buy_bitcoin(values);
		purchase_time.Record_time();
		History_Purchase.Transaction.push_back("You bought ");
		//ledgerclass.record();
	}
	else if (values->user_choice == 3)
	{
		wallet walletclass;
		walletclass.sell_bitcoin(values);
	}
	else if (values->user_choice == 4)
		show_balance(values);
	/*
	   else if (values->user_choice == 5)
	   {
	   ledger ledgerclass;
	//ledger
	}
	 */
}

int	main()
{
	t_values	values;
	bzero(&values, sizeof(t_values));
	values.valuebtc = 10000;
	values.numberofbtc = 0;
	values.user_choice = 0;
	values.cash_balance = 20000;
	do
	{
		printf("Enter the option you would like:\n");
		printf("1: Ask for value of BTC\n");
		printf("2: Buy Bitcoin\n");
		printf("3: Sell Bitcoin\n");
		printf("4: Show balance\n");
		printf("5: Print history\n");
		scanf("%d", &values.user_choice);
		choice(&values);
	}
	while (repeat == true);
}
