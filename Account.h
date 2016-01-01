class Account
{
	char* name;
	char* id;
	unsigned int money;
public:
	Account();
	Account(const char* _name);
	~Account();

	void Deposit(unsigned int _money);
	void Withdraw(unsigned int _money);

	int identify(Account* arr[]);

	void ShowInfo();
	void ShowMenu();	
};

