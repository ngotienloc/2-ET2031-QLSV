#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "lecturer.h"
#include <fstream>
#include <sstream>
using namespace std;
template <typename T>
void change_password(T* &a) {
	string currentpassword,newpassword;
	cout << "Enter current password: ";
	cin.ignore();
	getline(cin,currentpassword);
	if(a->data.getpassword()==currentpassword) {
		cout << "Enter new password: ";
		getch();
		getline(cin,newpassword);
		a->data.setpassword(newpassword) ;
		cout << "Cap nhat mat khau thanh cong" << endl;
		cin.ignore();
	}
	else
		cout << "Mat khau khong dung!"<<endl;
}


void updata(ListNodeST &ST,lecturer &lecturer1) {
	ifstream inFile("quanlysinhvien.txt");
	string line;
	getline(inFile, line);
	stringstream aa(line);
	string username, password, id, name;
	getline(aa, username, ',');
	getline(aa, password, ',');
	getline(aa, id, ',');
	getline(aa, name, ',');

	lecturer1.setid(id);
	lecturer1.setname(name);
	lecturer1.setusername(username);
	lecturer1.setpassword(password);

	while(getline(inFile,line)) {
		stringstream ss(line);
		string username, password, id, name;
		int diemdanh;
		float diemqt, diemck, diemkthp;
		getline(ss, username, ',');
		getline(ss, password, ',');
		getline(ss, id, ',');
		getline(ss, name, ',');
		ss >> diemdanh;
		ss.ignore();
		ss >> diemqt;
		ss.ignore();
		ss >> diemck;
		ss.ignore();
		ss >> diemkthp;
		PNODEST save = new NodeST;
		save->data.setusername(username);
		save->data.setpassword(password);
		save->data.setID(id);
		save->data.setname(name);
		save->data.setDiemdanh(diemdanh);
		save->data.setdiemqt(diemqt);
		save->data.setdiemck(diemck);
		save->data.setdiemkthp(diemkthp);
		save->next = ST;
		ST = save;
	}
	inFile.close();
}


int main() {
	int choice;
	lecturer lecturer1;
	ListNodeST ST = NULL;
	updata(ST,lecturer1);
	PNODEST temp10 = ST;
	PNODEST tempi = ST;
	while(1) {
MAIN:
		system("cls");
		cout << "              ======================================" << endl;
		cout << "              |      He thong quan ly sinh vien    |" << endl;
		cout << "              ======================================" << endl;
		cout << "              | 1. Giang vien                      |" << endl;
		cout << "              | 2. Sinh vien                       |" << endl;
		cout << "              ======================================\n" << endl;
		cout << "              Nhap lua chon: ";
		cin >> choice;
		//Lua chon:
		if(choice==1) {
RE:
			int t = lecturer1.login();
			if(t==3)
				goto MAIN;
			if(t==0)
				goto RE;

			while(1) {
				lecturer1.ltMenu(temp10);
				int a;
				cin>>a;
				if(a==1) {
					lecturer1.addST(ST);
				}
				else if(a==2) {
					lecturer1.searchST(ST);
				}
				else if(a==3) {
					lecturer1.DDST(ST);
				}
				else if(a==4) {
					lecturer1.NhapDiem(ST);
				}
				else if(a==5) {
					lecturer1.DisplayListStudent(ST);
				}
				else if(a==6) {
					lecturer1.arrange(ST);
				}
				else if(a==7) {
					lecturer1.deleteST(ST);
				}
				else if(a==8) {
					savedata(ST,lecturer1);
					cout << "Luu thong tin sinh vien thanh cong!";
					getch();
				}
				else if(a==9) {
					lecturer1.check(tempi);
					savedata(ST,lecturer1);
				}
				else if(a==0) {
					savedata(ST,lecturer1);
					goto MAIN;
				}
			}
		}
		else if (choice == 2) {
			PNODEST head= ST;
			string name, pass;
			cout << "username: ";
			cin.ignore();
			getline(cin, name);
			cout << "password: ";
			while (true) {
				char ch = getch();
				if (ch == 13) {
					break;
				} else if (ch == '\b') {
					if (!pass.empty()) {
						pass.erase(pass.length() - 1);
						cout << "\b \b";
					}
				}
				else {
					pass += ch;
					cout << '*';
				}
			}
			PNODEST S = ST;
			while (S != NULL) {
				int a = S->data.login(name, pass);
				if (a == 1) {
					break;
				} else if (a == 0) {
					S = S->next;
				}
			}

			if (S == NULL) {
				cout << "Khong co thong tin sinh vien!" << endl;
				getch();
				continue;
			}
			while(true) {
				S->data.stMenu();
				int b;
				cin>>b;
				if(b==0){
					goto MAIN;
					savedata(ST,lecturer1); 
				}
				else if(b==1)
					showdata(head);
				else if(b==2)
					S->data.DT(lecturer1.getname());
				else if(b==3) {
					S->data.re(S);
					savedata(ST,lecturer1);
				}
				else if(b==4) {
					change_password(S);
					savedata(ST,lecturer1);
				}
			}

		}

		else {
			cout<<"Lua chon khong hop le. Vui long nhap lai!"<<endl;
		}
		cout<<"Nhan phim bat ky de tiep tuc.....";
		getch();

	}

	return 0;
}


