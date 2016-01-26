#include "Container.h"

#define MAX_USER	30

typedef enum {
	DEPOSIT=1, WITHDRAW
} mode;

class AccManager
{
private:
	Container ctr;
public:
	AccManager() { }
	~AccManager();

	void makeAccount();
	void inOut(mode sel);   // 입출금
	void remit(); 		// 송금
	void showAllUsers();
	void menu();
	
	bool identify(const Account* src, const Account& dest);
};
