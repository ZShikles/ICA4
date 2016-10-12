
#include <iostream>
#include <cstring>
using namespace std;
class Stock{
	private:
		char company[30];
		int shares;
		double share_val;
		double total_val;
		void set_tot(){total_val = shares * share_val; }
		void acquire(const char * co);
	public:
		void buy(int num, double price);
		void sell(int num, double price);
		void update(double price);
		void display();
		Stock();
};

Stock::Stock(){
	company[0] = '\n';
	shares = 0;
	share_val = 0;
	set_tot();
}

void Stock::acquire(const char * co){
	std::strncpy(company, co, 29);
	company[29] = '\0';
	shares = 0;
	std::cout << "Initialized stock." << std::endl;
	share_val = 0;
	set_tot();
}

void Stock::buy(int n, double pr) //purchases stocks
{	
	using std::cout;
	using std::endl;
	char name[30];
	if(company[0]=='\n')
	{
		cout << "Enter company name: ";
		std::cin >> name;
		acquire(name); 
	}
	int i=0;
	for(i=0; i<n; i++) //adds shares and total value depending on how many objects purchased
	{
		shares++;
		total_val+=pr;
	}	
	std::cout << "Purchased " << n << " shares." << std::endl; //prints out number purchased
}

void Stock::sell(int n, double pr) //sells stocks
{
	using std::cout;
	using std::endl;
	int i=0;
	for(i=0; i<n; i++) //subtracts shares and total value depending on how many objects purchased
	{
		shares--;
		total_val=total_val-pr;
	}	
	std::cout << "Sold " << n << " shares." << std::endl; //prints out number sold
}

void Stock::update(double pr) //updates stock price
{
	using std::cout;
	using std::endl;
	if(pr < 0){
		std::cerr << "price can't be negative; "
				  << company << " price set to 0.\n";
		share_val = 0;
	}
	else
		share_val=pr;
	cout << "Price updated\n";
}

void Stock::display() //displays stock data
{
	//using std::cout;
	using std::endl;
	std::cout << company << endl;
	std::cout << "Shares: " << shares << endl;
	std::cout << "Share value: " << share_val << endl;
	std::cout << "Total value: " << total_val << endl;
}

int main(){
	using std::cout;
	using std::endl;

	int numbuy, numsell, choice, option;
	double price1, price2;
	price1=0;
	price2=0;
	choice=0;
	Stock stock1, stock2;
	
	while(choice!=5){
		
		cout << "\nChoose function:" << endl << "1: buy" << endl << "2: sell" << endl << "3: update" << endl << "4: display" 			<< endl << "5: quit" << endl;
		cin >> choice;
		while(choice<1 || choice>5) //asks user for function to run
		{
			cout << "Choose function:" << endl << "1: buy" << endl << "2: sell" << endl << "3: update" << endl << "4: 				display" << endl;
			cin >> choice;
		}
		cout<< "Choose stock (1 or 2): ";
		cin >> option;
		while(option!=1 && option!=2) //asks user for stock to act on
		{
			cout<< "Choose stock (1 or 2): ";
			cin >> option;
		}
		

		if(choice==1)
		{
			cout << "\nEnter stocks to buy: "; //asks user input for shares to buy
			cin >> numbuy;
			if(option==1){ //buys shares of selected stock
				stock1.buy(numbuy, price1);
			}
			else
				stock2.buy(numbuy, price2);
		}
		else if(choice==2){
			cout << "\nEnter stocks to sell: "; //asks user for shares to sell
			cin >> numsell;
			if(option==1){ //sells shares depending on selected stock
				stock1.sell(numsell, price1);
			}
			else
				stock2.sell(numsell, price2);
		}
		else if(choice==3)
		{
			cout << "\nEnter price to update to: ";
			if(option==1){ //updates price of selected stock
				cin >> price1;
				stock1.update(price1);
			}
			else{
				cin >> price2;	
				stock2.update(price2);
			}
		}
		else if(choice==4){
			if(option==1){ //displays values of selected stock
				stock1.display();
			}
			else{
				stock2.display();
			}
		}
	}
	return 0;
}
