#include "AccManager.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(void)
{
	AccManager hana;
	int choice;

	while(1) {
		hana.menu();
		cin >> choice;
		if(choice < 0 || choice >5) {
			cout << "잘못된 입력입니다." << endl<<endl;
			continue;
		}
	
		switch(choice) {
		case 1:
			hana.makeAccount();
			break;
		case 2:
			hana.inOut(DEPOSIT);
			break;
		case 3:
			hana.inOut(WITHDRAW);
			break;
		case 4:
			hana.remit();
			break;
		case 5:
			hana.showAllUsers();
			break;
		}

		if(choice == 0) {
			break;
		}
	}
	cout << "이용해주셔서 감사합니다." << endl;

	return 0;
}
