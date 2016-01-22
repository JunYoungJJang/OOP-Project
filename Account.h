#include <iostream>

class Account
{
private:
	char *name, *id, *pw;
	unsigned int balance;
public:
	Account(const char* _name=NULL, const char* _id=NULL, const char* _pw=NULL);
	Account(const Account& a);
	~Account();
	
	const char* GetName() const;
	const char* GetID() const;
	const char* GetPW() const;
	unsigned int GetBal() const;
	
	void AddMoney(int money);
	void MinMoney(int money);
};
