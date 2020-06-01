#include "exchange.h"

bool repeat(true);

class ledger
{
	vector <string>Transaction;
	public:
	void record(string s)
	{
		Transaction.push_back(s);
	}
	void print_ledger()
	{
		for (unsigned int i = 0; i < Transaction.size(); i++)
		{
			cout << Transaction.at(i);
		}
	}
};
ledger l;

void show_value_of_btc(t_values *values)
{
	printf("Current value of Bitcoin is at: %lf\n", values->valuebtc);
}

void show_balance(t_values *values)
{
	printf("Your Balance of BTC is: %lf\n", values->numberofbtc);
	printf("Your Balance of USD is: %lf\n", values->cash_balance);
}

int check_amount(t_values *values)
{
	if (values->user_choice == 3 || values->user_choice == 2)
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

class The_Date
{
	public:
		string trans_time;
		string Record_Time(t_values *values)
		{
			time_t now = time(0);
			trans_time = ctime(&now);
			return (trans_time);
		}
};
The_Date time_of_transaction;

class wallet
{
	public: 
		void buy_bitcoin(t_values *values)
		{
			double ogcashmoneys = 0;
			printf("How many BTC's would you like to buy?\n");
			scanf("%lf", &values->numberofbtc);
			values->final_cash_balance = values->numberofbtc * values->valuebtc;
			if (check_amount(values) == 1)
				printf("You do not have enough credits to complete transaction! Try again\n");
			else
			{
				ogcashmoneys = values->cash_balance;
				string s = "You bought " + to_string(values->numberofbtc) + 
					" of BTC on " + time_of_transaction.Record_Time(values);
				l.record(s);
				//purchase_time.Record_Time(values);
				values->cash_balance = ogcashmoneys - values->final_cash_balance;

			}
			printf("Your current balance is: %lf dollars\n", values->cash_balance);
		}
		void sell_bitcoin(t_values *values)
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
				string s = "You sold " + to_string(values->sellingbtc) + 
					" of BTC on " + time_of_transaction.Record_Time(values);
				l.record(s);
				values->final_cash_balance = values->sellingbtc * values->valuebtc;
				values->cash_balance += values->final_cash_balance;
			}
			printf("%lf is the btc in your wallet\n", values->numberofbtc);
			printf("%lf is your balance\n", values->cash_balance);
		}

};

void choice(t_values *values)
{
	wallet  walletclass;

	if (values->user_choice == 1)
		show_value_of_btc(values);
	else if (values->user_choice == 2)
		walletclass.buy_bitcoin(values);
	else if (values->user_choice == 3)
		walletclass.sell_bitcoin(values);
	else if (values->user_choice == 4)
		show_balance(values);
	else if (values->user_choice == 5)
		l.print_ledger();
}

int main()
{
	t_values values;
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
		if (values.user_choice >= 1 && values.user_choice<= 5)
			choice(&values);
		else
			printf("Pick again that is not an option\n");
	}
	while (repeat == true);
}

