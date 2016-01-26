bank1.cpp is independant file.   // 2015-12-31


Account.h, Account.cpp, main2.cpp is one.   // 2016-01-01

Account.h, Account.cpp, AccManager.h, AccManager.cpp, bank3.0.cpp is one.
gcc -o bank3.0 Account.cpp AccManager.cpp bank3.0.cpp
// 2016-01-22

gcc -o bank4.0 Account.cpp AccManager.cpp Container.cpp bank4.0.cpp
// 2015-01-26

수정할 점 : 계좌 정보 중복, 음수 입력, 가독성, 연산자 오버로딩, 돈이 뿔어나는 현상
