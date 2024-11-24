#include"student.h"
#include <stdlib.h>
student::student():user() {};
student::student(string id, string name, string username, string password):user(id,name,username,password),diemqt(-1),diemck(-1),diemkthp(-1),diemdanh(0) {};
//getter
string student::getID() {
	return id;
}
string student::getusername() {
	return username;
}
string student::getpassword() {
	return password;
}
string student::getName() {
	return name;
}
float student::getdiemqt() {
	return diemqt;
}
float student::getdiemck() {
	return diemck;
}
float student::getdiemkthp() {
	return diemkthp;
}
int student::getdiemdanh() {
	return diemdanh;
}
void student::setDiemdanh(int diemdanh) {
	this->diemdanh = diemdanh;
}
void student::setdiemqt(float qt) {
	diemqt = qt;
}
void student::setdiemck(float ck) {
	diemck = ck;
}
void student::setdiemkthp(float kthp) {
	diemkthp = kthp;
}
void student::VangDiemDanh() {
	diemdanh++;
}
void student::setname(string name) {
	this->name = name;
}
void student::setusername(string name) {
	username = name;
}
void student::setID(string ID) {
	id = ID;
}
void student::setpassword(string password) {
	this->password =password;
}
void student::stMenu() {
	system("cls");
	cout << "              ======================================" << endl;
	cout << "              |              Sinh Vien             |" << endl;
	cout << "              ======================================" << endl;
	cout << "              | 1. Xem danh sach lop               |" << endl;
	cout << "              | 2. Thong tin mon hoc               |" << endl;
	cout << "              | 3. Phuc tra diem                   |" << endl;
	cout << "              | 4. Doi mat khau                    |" << endl;
	cout << "              | 0. Tro lai                         |" << endl;
	cout << "              ======================================\n" << endl;
	cout << "              Nhap lua chon: ";
}
void student::DT(string namelt) {
	cout << left << setw(10) << "ID"
	     << setw(20) << "Name"
	     << setw(10) << "Diem QT"
	     << setw(6) << "Vang"
	     << setw(9) << "Diem CK"
	     << setw(9) << "Diem KTHP"
	     << setw(22) << "Teacher" << endl;
	cout << setfill('-') << setw(80) << "-" << setfill(' ') << endl;
	cout << left << setw(10) << id
	     << setw(20) << name;
	if(diemqt>100)
		cout << setw(10) <<"PT";
	else
		cout << setw(10) << diemqt;
	cout << setw(6) << diemdanh;
	if(diemck>100)
		cout  << setw(9) << "PT";
	else
		cout << setw(9) << diemck;
	if(diemkthp>100)
		cout << setw(9) << "PT";
	else
		cout << setw(9) << diemkthp;
	cout << setw(22) << namelt << endl;
	getch();
}
void showdata(ListNodeST ST) {
	cout << left << setw(10) << "ID"
	     << setw(20) << "Name" << endl;
	cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;

	while (ST != NULL) {
		cout << left << setw(10) << ST->data.getID()
		     << setw(20) << ST->data.getName() << endl;
		ST = ST->next;
	}

	getch();
}
void student::re(PNODEST &S) {
	int choice;
	while(1) {
		system("cls");
		cout <<"          	==================="<<endl;
		cout <<"          	|    Phuc tra     |"<<endl;
		cout <<"          	==================="<<endl;
		cout <<"          	|1. Diem qua trinh|"<<endl;
		cout <<"          	|2. Diem cuoi ky  |"<<endl;
		cout <<"          	|0. Thoat         |"<<endl;
		cout <<" 		==================="<<endl;
		cout << endl << "Nhap lua chon: ";
		cin >> choice;
		if(choice == 0)
			break;
		else if(choice==1) {
			int choice_1;
			if(S->data.getdiemqt()>=100) {
				cout << "Diem dang duoc phuc tra!";
				getch();
				break;
			}
			while(1) {
				system("cls");
				cout <<"		==================================="<<endl;
				cout <<"		|    Phuc tra diem qua trinh      |"<<endl;
				cout <<"		==================================="<<endl;
				cout <<"		|Diem qua trinh ban dau: "<< S->data.getdiemqt() <<endl;
				cout <<"\n"<<"		|1. Phuc tra                      |"<<endl;
				cout <<"		|0. Thoat                         |"<<endl;
				cout << endl << "Nhap lua chon: ";
				cin >> choice_1;
				if(choice_1==1) {
					S->data.setdiemqt(S->data.getdiemqt()+101);
					S->data.setdiemkthp(S->data.getdiemkthp()+101);
					cout << "Phuc tra thanh cong" << endl;
					getch();
					break;
				}
				else if(choice_1==0)
					break;
				else
					cout << "Lua chon khong hop le. Nhap lai."<<endl;
			}
		}
		else if(choice==2) {
			if(S->data.getdiemck()>=100) {
				cout << "Diem dang duoc phuc tra!";
				getch();
				break;
			}
			int choice_1;
			while(1) {
				system("cls");
				cout <<"		==================================="<<endl;
				cout <<"		|    Phuc tra diem cuoi ky        |"<<endl;
				cout <<"		==================================="<<endl;
				cout <<"		Diem cuoi ky ban dau:"<< S->data.getdiemqt() <<endl;
				cout <<"\n"<<"		|1. Phuc tra                      |"<<endl;
				cout <<"		|0. Thoat                         |"<<endl;
				cout << endl << "Nhap lua chon: ";
				cin >> choice_1;
				if(choice_1==1) {
					S->data.setdiemck(S->data.getdiemck()+101);
					S->data.setdiemkthp(S->data.getdiemkthp()+101);
					cout << "Phuc tra thanh cong" << endl;
					getch();
					break;
				}
				else if(choice_1==0)
					break;
				else
					cout << "Lua chon khong hop le. Nhap lai."<<endl;
			}
		}
		else {
			cout << "Lua chon khong hop le. Nhap lai."<<endl;
		}

	}
}
