#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

using std::cout;
using std::endl;
using std::cin;

typedef struct _Account {
	char name[30];
	char id[12];
	int money;

	_Account* link;
} Account;

// 수정할 점: 계좌번호 겹칠 가능성 없게하기
void make_account(Account** head, Account** tail)
{
	Account *new_ac = (Account*)malloc(sizeof(Account));

	cout << "아래에 본인의 정보를 입력해주세요." << endl;
	cout << "이    름: ";
	cin >> new_ac->name;
	
	cout << "계좌를 생성하는 중입니다..." << endl;

	new_ac->money = 0;
	
	srand(time(NULL));
	for (int i=0; i<11; i++) {   // 계좌 번호 생성
		if(i == 5) {
			new_ac->id[i] = '-';
			continue;
		}

		new_ac->id[i] = rand()%10 + '0';	
	}
	new_ac->id[11] = '\0';
	new_ac->link = NULL;

	if (*head == NULL) {   // 아무도 없으면
		*head = *tail = new_ac;
	} else {
		(*tail)->link = new_ac;
		*tail = new_ac;
	}

	system("clear");
	cout << "계좌가 성공적으로 생성되었습니다." << endl;
	cout << "이    름: " << new_ac->name << endl;
	cout << "계좌번호: " << new_ac->id << endl;
	cout << "잔    액: " << new_ac->money << "원\n" << endl;

	sleep(5);
	system("clear");
}

Account* identify(Account* head)
{
	char name[30];
        char id[12];

        cout << "계좌 정보를 입력해주세요" << endl;
        cout << "이    름: ";
        cin >> name;

        cout << "계좌번호: ";
        cin >> id;

        system("clear");

        while (head) {
                if (!strcmp(head->name, name) && !strcmp(head->id, id)) {
                        break;
                }

                head = head->link;
        }

	return head;
}

void deposit(Account *head)
{
	unsigned int input;

	head = identify(head);
	if (head == NULL) {
		cout << "없는 정보입니다." << endl;
		sleep(3);
		system("clear");
		
		return;
	}

	cout << "입금하실 금액을 입력해주세요." << endl;
	cout << "입    력: ";
	
	cin >> input;
	system("clear");

	head->money += input;

	cout << "해당 거래가 성공적으로 처리되었습니다." << endl;
	cout << "잔    액: " << head->money << endl;

	sleep(5);
	system("clear");
}

void withdraw(Account *head)
{
	unsigned int output;

	head = identify(head);
	if (head == NULL) {
		cout << "없는 정보입니다." << endl;
		sleep(3);
		system("clear");

		return;
	}

	cout << "출금하실 금액을 입력해주세요." << endl;
	cout << "입    력: ";

	cin >> output;

	system("clear");
	if (head->money < output) {
		cout << "잔액을 확인해 주세요." << endl;
		cout << "잔    액: " << head->money << endl;

		sleep(3);
		system("clear");
		
		return;
	}
	
	head->money -= output;

	cout << "해당 거래가 성공적으로 처리되었습니다. " << endl;
	cout << "잔    액: " << head->money << endl;

	sleep(5);
	system("clear");
}

void showAll(Account *head)
{
	char id[12];

	if (head == NULL) {
		cout << "가입한 고객이 없습니다." << endl;
	}

	cout << "모든 고객의 잔액을 출력합니다." << endl;
	while(head) {
		strcpy(id, head->id);
		for (int i=6; i<11; i++) {   // 계좌 번호 보호
			id[i] = '*';
		}
	
		cout << "이    름: " << head->name << endl;
		cout << "계좌번호: " << id << endl; 
		cout << "잔    액: " << head->money << endl;		

		head = head->link;
	}

	sleep(5);
	system("clear");
}

void menu()
{
	cout << "=== 준영 은행입니다~~~ === " << endl;
	cout << "1. 계좌 개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 전체 고객 잔액 조회" << endl;
	cout << "5. 종료 " << endl;

	cout << "\n입력: ";
}

int main(void)
{
	Account *head, *tail;
	int sel;

	head = tail = NULL;

	while (1) {
		menu();

		cin >> sel;
		system("clear");
		if (sel < 1 || sel > 5) {
			cout << "잘못된 입력입니다!!!" << endl;
			continue;
		} else if (sel == 5) {
			cout << "이용해 주셔서 감사합니다." << endl;
			break;
		}

		switch (sel) {
		case 1:
			make_account(&head, &tail);
			break;
		case 2:
			deposit(head);
			break;
		case 3:
			withdraw(head);
			break;
		case 4:
			showAll(head);
			break;
		}
	}

	return 0;
}
