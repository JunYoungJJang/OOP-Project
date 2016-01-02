class Account
{
	const char* name;
	const char* id;
	unsigned int money;
public:
	Account();
	Account(const char* _name);
	Account(const Account& temp);   // 복사 생성자
	~Account();

	void Deposit(unsigned int _money);
	void Withdraw(unsigned int _money);

	static int identify(Account* arr[]);

	static void ShowInfo(Account* arr[]);
	static void ShowMenu();	
};