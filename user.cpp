#include"user.h"
user::user() {};
user::user(string id, string name, string username, string password) {
	this->id = id;
	this->name = name;
	this->username = username;
	this->password = password;
}
bool user::checklogin(string input_username,string input_password) {
	if(username == input_username && password == input_password) {
		cout<<"\nDang nhap thanh cong! "<<endl;
		return 1;
	}
	else {
		cout<<"\nDang nhap that bai! "<<endl;
		cout<<"Nhap 0 de tro lai! "<<endl;
		return 0;
	}
}
int user::login() {
	fflush(stdin);
	while(1) {
		system("cls");
		cout << "              ======================================" << endl;
		cout << "              |      He thong quan ly sinh vien    |" << endl;
		cout << "              ======================================" << endl;
		cout << "              | 1. Giang vien                      |" << endl;
		cout << "              | 2. Sinh vien                       |" << endl;
		cout << "              ======================================\n" << endl;
		string username;
		string password;
		cout<<"username: ";
		getline(cin,username);
		cout<<"password: ";
		while (true) {
			char ch = getch();
			if (ch == 13) {
				break;
			} else if (ch == '\b') {
				if (!password.empty()) {
					password.erase(password.length() - 1);
					cout << "\b \b";
				}
			}
			else {
				password += ch;
				cout << '*';
			}
		}

		if (username == "0" || password == "0") {
			cout << "Tro ve menu chinh..." << endl;
			return 3;
			getch();

		}
		if(user::checklogin(username,password))
			return 1;
		else
			return 0;
		getch();
	}
}
int user::login(string username,string password) {
	if(this->username == username && this->password == password) {
		return 1;
	}
	else
		return 0;
}
