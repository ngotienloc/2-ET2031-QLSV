#include "lecturer.h"
#include <string.h>
#include <set>
#include <fstream>
#include <vector>


string capitalizeName(const string& name) {
    string result = name;
    bool capitalizeNext = true;

    for (size_t i = 0; i < result.length(); ++i) {
        if (isspace(result[i])) {
            capitalizeNext = true; 
        } else if (capitalizeNext && isalpha(result[i])) {
            result[i] = toupper(result[i]); 
            capitalizeNext = false;
        } else {
            result[i] = tolower(result[i]); 
        }
    }

    return result;
}

lecturer::lecturer():user() {};
lecturer::lecturer(string id, string name, string username, string password):user(id,name,username,password) {};
string lecturer::getid() {
	return id;
}
string lecturer::getname() {
	return name;
}
string lecturer::getusername() {
	return username;
}
string lecturer::getpassword() {
	return password;
}
void lecturer::setpassword(string pass) {
	password = pass;
}
void lecturer::setid(string i) {
	id = i;
}
void lecturer::setname(string name) {
	this->name = name;
}
void lecturer::setusername(string user) {
	username = user;
}


void lecturer::ltMenu(PNODEST temp10) {
	system("cls");
	string rp0, rp1, rp2;
	string thongBao = "";
	while (temp10 != NULL) {
		rp0 = temp10->data.getID();
		rp1 = temp10->data.getName();

		if (temp10->data.getdiemqt() >= 100 && temp10->data.getdiemck() >= 100) {
			rp2 = "Phuc tra ca diem qua trinh va cuoi ky";
			thongBao += "Sinh vien: " + rp0 + " - " + rp1 + " - " + rp2 + "\n";
		} else if (temp10->data.getdiemqt() >= 100) {
			rp2 = "Phuc tra diem qua trinh";
			thongBao += "Sinh vien: " + rp0 + " - " + rp1 + " - " + rp2 + "\n";
		} else if (temp10->data.getdiemck() >= 100) {
			rp2 = "Phuc tra diem cuoi ky";
			thongBao += "Sinh vien: " + rp0 + " - " + rp1 + " - " + rp2 + "\n";
		}

		temp10 = temp10->next;
	}


	cout << "              ======================================" << endl;
	cout << "              |              Giang Vien            |" << endl;
	cout << "              ======================================" << endl;
	cout << "              | 1. Them sinh vien                  |" << endl;
	cout << "              | 2. Tra cuu sinh vien               |" << endl;
	cout << "              | 3. Diem danh                       |" << endl;
	cout << "              | 4. Nhap diem                       |" << endl;
	cout << "              | 5. Hien thi toan bo danh sach      |" << endl;
	cout << "              | 6. Xep theo thu tu diem cao xuong  |" << endl;
	cout << "              | 7. Xoa sinh vien                   |" << endl;
	cout << "              | 8. Cap nhat thong tin sinh vien    |" << endl;
	cout << "              | 9. Cap nhat diem phuc tra          |" << endl;
	cout << "              | 0. Tro lai                         |" << endl;
	cout << "              ======================================\n" << endl;

	if (!thongBao.empty()) {
		cout << "Thong bao:\n" << thongBao << endl;
	}
	cout << "              Nhap lua chon: ";
}


void lecturer::addST(ListNodeST &ST) {
	string id, name, username, password;
	fflush(stdin);
	while (true) {
		cout << "id: ";
		getline(cin, id);
		PNODEST current = ST;
		PNODEST current1 = ST;
		bool idExists = false;
		if(id.empty())
			continue; 
		while (current != NULL) {
			if (current->data.getID() == id) {
				idExists = true;
				break;
			}
			current = current->next;
		}

		if (idExists) {
			cout << "ID da ton tai. Vui long nhap ID khac" << endl;
			continue;
		}
		name_:
		cout << "name: ";
		getline(cin, name);
		if(name.empty())
			goto name_;
		username_:
		cout << "username: ";
		getline(cin, username);
		if(username.empty())
			goto username_;
		bool usernameExists = false;
		while (current1 != NULL) {
			if (current1->data.getusername() == username) {
				usernameExists = true;
				break;
			}
			current1 = current1->next;
		}

		if (usernameExists) {
			cout << "username da ton tai! Vui long nhap username khac." << endl;
			continue;
		}
		password_:
		cout << "password: ";
		getline(cin, password);
		if(password.empty())
			goto password_;
	
		student newst(id,capitalizeName(name), username, password);
		PNODEST P = new NodeST(newst);
		if (ST == NULL) {
			P->next = NULL;
			ST = P;
		} else {
			P->next = ST;
			ST = P;
		}
		cout << "Sinh vien da duoc them!" << endl;
		break;
	}

}

void lecturer::showST(PNODEST ST) {

	cout << left << setw(10) << "ID"
	     << setw(20) << "Name"
	     << setw(10) << "Diem QT"
	     << setw(10) << "Vang"
	     << setw(10) << "Diem CK"
	     << setw(10) << "Diem KTHP" << endl;

	cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;

	cout << left << setw(10) << ST->data.getID()
	     << setw(20) << ST->data.getName();
	if(ST->data.getdiemqt()>=100)
		cout << setw(10) << "PT";
	else
		cout << setw(10) << ST->data.getdiemqt();
	cout << setw(10) << ST->data.getdiemdanh();
	if(ST->data.getdiemck()>=100)
		cout << setw(10) << "PT";
	else
		cout << setw(10) << ST->data.getdiemck();
	if(ST->data.getdiemkthp()>=100)
		cout << setw(10) << "PT";
	else
		cout << setw(10) << ST->data.getdiemkthp() << endl;
}

void lecturer::searchST(ListNodeST ST) {
	string id;
	cout<<"id sinh vien can tim: ";
	getchar();
	getline(cin,id);
	PNODEST P = ST;
	while(P!=NULL) {
		if(P->data.getID()==id) {

			showST(P);
			break;
		}
		else {
			P = P->next;
		}
	}
	if(P==NULL)
		cout << "Khong co thong tin sinh vien nay!"<<endl;
	getch();
};

void lecturer::DDST(ListNodeST &ST) {
begin:
	while(1) {
		system("cls");
		PNODEST P = ST;
		PNODEST Q = ST;
		cout << left << setw(5) << "STT"
		     << setw(20) << "Name"
		     << setw(10) << "Vang" << endl;

		cout << setfill('-') << setw(5) << ""
		     << setw(20) << ""
		     << setw(10) << "" << setfill(' ')
		     << endl;
		int i = 0;
		while (P != NULL) {
			i++;
			cout << left << setw(5) << i;
			cout << left << setw(20) << P->data.getName();
			cout << setw(10) << P->data.getdiemdanh();
			cout << endl;
			P = P->next;
		}
		cout << setfill('-') << setw(5) << ""
		     << setw(20) << ""
		     << setw(10) << "" << setfill(' ')
		     << endl;

		cout << "\n" << "1. Diem danh tu dau" << endl
		     << "2. Diem danh lua chon" << endl
		     << "3. Diem danh bu" << endl
		     << "0. Thoat" << endl
		     << "Lua chon: ";
		int z;
		cin >> z;
		if(z==1) {
			int e = 0;
			while(Q!=NULL) {
				e++;
				cout << e << "." << "Sinh Vien: " << Q->data.getName() << "\t";
				int diemdanh;
				cout << "Diem danh: (1->Co & 0->Vang ): ";
				cin >> diemdanh;
				if(diemdanh==0)
					Q->data.VangDiemDanh();
				Q  = Q->next;
			}
		}
		else if(z==2) {
next:
			string o;
			cout << "Ten:  (Nhap 0 de thoat)";
			fflush(stdin);
			getline(cin,o);
			o =  capitalizeName(o);
			PNODEST K = ST;
			while(K!=NULL) {
				if(K->data.getName() == o) {
					int h;
					cout << "Diem danh: (1->Co & 0->Vang ): ";
					cin >> h;
					if(h==0) {
						K->data.VangDiemDanh();
						goto next;
					}
					else if(h==1)
						goto next;
				}
				else {
					K = K->next;
				}
			}
			if(K==NULL) {
				cout<<"Khong co thong tin sinh vien";
				goto begin;
			}

		}
		else if(z==3) {
			PNODEST T = ST;
			string o;
			cout << "Ten: ";
			fflush(stdin);
			getline(cin,o);
			o = capitalizeName(o);
			while(T!=NULL) {
				if(T->data.getName()==o) {
					if(T->data.getdiemdanh()==0) {
						cout << "Sinh vien di hoc day du";
						break;
					}
					else {
						T->data.setDiemdanh(T->data.getdiemdanh()-1);
						cout << "Cap nhat thanh cong" << endl;
						break;
					}
				}
				else T = T->next;
			}
		}
		else if(z==0)
			break;
		getch();
	}
}

void lecturer::inputGrades1(PNODEST &ST,float grates1) {
	ST->data.setdiemqt(grates1);
}

void lecturer::inputGrades2(PNODEST &ST,float grates2) {
	ST->data.setdiemck(grates2);
}


void lecturer::NhapDiem(ListNodeST &ST) {
	while(1) {
		system("cls");
		cout << "              ======================================" << endl;
		cout << "              |              Nhap Diem            |" << endl;
		cout << "              ======================================" << endl;
		cout << "              | 1. Diem qua trinh                  |" << endl;
		cout << "              | 2. Diem cuoi ky                    |" << endl;
		cout << "              | 3. Sua diem qt                     |" << endl;
		cout << "              | 4. Sua diem cuoi ky                |" << endl;
		cout << "              | 5. Tinh diem kthp                  |" << endl;
		cout << "              | 0. Tro lai                         |" << endl;
		cout << "              ======================================" << endl;
		cout << "              Nhap lua chon: ";

		int a;
		cin >> a ;

		PNODEST P = ST;
		PNODEST Q = ST;
		PNODEST H = ST;
		PNODEST Q1 = ST;
		PNODEST Q2 = ST;
		PNODEST Q3 = ST;
		PNODEST Q4 = ST;
		if(a==1) {
			while (P != NULL) {
				if(P->data.getdiemqt()!=-1)
					goto next;
				cout << "Sinh vien: " << P->data.getName() << endl;
				float diemQT;
				cout << "Nhap diem QT: ";
				cin >> diemQT;


				while (diemQT < 0 || diemQT > 10) {
					cout << "Diem khong hop le! Vui long nhap lai (0 <= Diem QT <= 10): ";
					cin >> diemQT;
				}
				P->data.setdiemqt(diemQT);
next:
				P = P->next;
			}

			cout << "Diem qua trinh cua tat ca sinh vien da duoc cap nhat!" << endl;
		}
		else if(a==2) {
			while (Q!= NULL) {
				if(Q->data.getdiemck()!=-1)
					goto next_1;
				cout << "Sinh vien: " << Q->data.getName() << endl;
				float diemCK;
				cout << "Nhap diem CK: ";
				cin >> diemCK;


				while (diemCK < 0 || diemCK > 10) {
					cout << "Diem khong hop le! Vui long nhap lai (0 <= Diem CK <= 10): ";
					cin >> diemCK;
				}

				Q->data.setdiemck(diemCK);
next_1:
				Q = Q->next;
			}

			cout << "Diem cuoi ky cua tat ca sinh vien da duoc cap nhat!" << endl;
		}
		else if(a==3) {
			string name;
			while (Q1 != NULL) {
				cout << "Sinh vien: " << Q1->data.getName() << ", Diem GK: " << Q1->data.getdiemqt() << endl;
				Q1 = Q1->next;
			}
			fflush(stdin);
			cout << "Nhap ten sinh vien can sua diem: ";
			getline(cin,name);
			while(Q2!=NULL) {
				if(Q2->data.getName()==capitalizeName(name)) {
					float diemQT;
					cout << "Nhap diem QT: ";

					cin >> diemQT;
					while (diemQT < 0 || diemQT > 10) {
						cout << "Diem khong hop le! Vui long nhap lai (0 <= Diem QT <= 10): ";
						cin >> diemQT;
					}
					Q2->data.setdiemqt(diemQT);
					break;
				}
				else
					Q2 = Q2->next;
			}
		}
		else if(a==4) {
			string name;
			while (Q3 != NULL) {
				cout << "Sinh vien: " << Q3->data.getName() << ", Diem GK: " << Q3->data.getdiemqt() << endl;
				Q3 = Q3->next;
			}
			cout << "Nhap ten sinh vien can sua diem: ";
			fflush(stdin);
			getline(cin,name);
			while(Q4!=NULL) {
				if(Q4->data.getName()==capitalizeName(name)) {
					float diemCK;
					cout << "Nhap diem CK: ";
					cin >> diemCK;
					while (diemCK < 0 || diemCK > 10) {
						cout << "Diem khong hop le! Vui long nhap lai (0 <= Diem CK <= 10): ";
						cin >> diemCK;
					}
					Q4->data.setdiemck(diemCK);
					break;
				}
				else
					Q4 = Q4->next;
			}
		}
		else if(a==5) {
			while(H!=NULL) {
				float diemkthp;
				if (H->data.getdiemdanh() >= 2) {
					diemkthp = (((H->data.getdiemqt() - 1) > 10) ? 10 : (H->data.getdiemqt() - 1)) * 0.3 + H->data.getdiemck() * 0.7;
				}
				else if (H->data.getdiemdanh() == 0) {
					diemkthp = ((H->data.getdiemqt() > 10) ? 10 : H->data.getdiemqt()) * 0.3 + H->data.getdiemck() * 0.7;
				}
				else {
					diemkthp = (((H->data.getdiemqt() + 1) > 10) ? 10 : (H->data.getdiemqt() + 1)) * 0.3 + H->data.getdiemck() * 0.7;
				}

				if(diemkthp>10)
					diemkthp = 10;
				H->data.setdiemkthp(diemkthp);
				H = H->next;
			}
			cout << "Hoanh thanh tinh toan!";
		}

		else if(a==0) {
			break;
		}
		getch();
	}
}

void lecturer::DisplayListStudent(ListNodeST ST) {
    PNODEST P = ST;
    int stt = 1; 

    cout << left << setw(5) << "STT" 
         << setw(10) << "ID"
         << setw(25) << "Name"
         << setw(10) << "Diem QT"
         << setw(10) << "Vang"
         << setw(10) << "Diem CK"
         << setw(10) << "Diem KTHP" << endl;
    cout << setfill('-') << setw(80) << "-" << setfill(' ') << endl;

    while (P != NULL) {
        cout << left << setw(5) << stt++ 
             << setw(10) << P->data.getID()
             << setw(25) << P->data.getName();
        if (P->data.getdiemqt() >= 100)
            cout << setw(10) << "PT";
        else
            cout << setw(10) << P->data.getdiemqt();
        cout << setw(10) << P->data.getdiemdanh();
        if (P->data.getdiemck() >= 100)
            cout << setw(10) << "PT";
        else
            cout << setw(10) << P->data.getdiemck();
        if (P->data.getdiemkthp() >= 100)
            cout << setw(10) << "PT";
        else
            cout << setw(10) << P->data.getdiemkthp();

        cout << endl;
        P = P->next;
    }

    getch();
}


PNODEST lecturer::searchnotest(ListNodeST ST,string id) {
	if(ST==NULL)
		return NULL;
	else {
		while(ST!=NULL) {
			if(ST->data.getID()==id)
				return ST;
			else
				ST = ST->next;
		}
		return NULL;
	}
}

PNODEST lecturer::searchnotebeforest(ListNodeST ST,string id) {
	if(ST==NULL)
		return NULL;
	else {
		while(ST!=NULL) {
			if(ST->next->data.getID()==id)
				return ST;
			else
				ST = ST->next;
		}
		if(ST==NULL)
			return NULL;
	}
	return NULL; 
}

void lecturer::deleteST(ListNodeST &ST) {
	if (ST == NULL) {
		cout << "Danh sach trong!" << endl;
		return;
	}

	string id;
	DisplayListStudent(ST);

	cout << "Nhap ID sinh vien can xoa: ";
	fflush(stdin);
	getline(cin, id);

	PNODEST P = ST;
	PNODEST prev = NULL;

	if (P != NULL && P->data.getID() == id) {
		ST = P->next;
		delete P;
		cout << "Sinh vien da duoc xoa!" << endl;
		return;
	}

	while (P != NULL && P->data.getID() != id) {
		prev = P;
		P = P->next;
	}

	if (P == NULL) {
		cout << "Khong tim thay sinh vien voi ID: " << id << endl;
		return;
	}

	prev->next = P->next;
	delete P;

	cout << "Sinh vien da duoc xoa!" << endl;
	DisplayListStudent(ST);
	getch();
}

void lecturer::insertsort(arr a[], int n) {
	for (int i = 1; i < n; i++) {
		arr key = a[i];
		int j = i - 1;


		while (j >= 0 && a[j].a > key.a) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

void lecturer::arrange(ListNodeST &ST) {
	arr a[100];
	ListNodeST temp = ST;
	ListNodeST temp1 = ST;
	int i = 0;
	set<string> addedIDs;
	while (temp != NULL && i < 100) {
		a[i].a = temp->data.getdiemkthp();
		a[i].id = temp->data.getID();
		temp = temp->next;
		i++;
	}
	insertsort(a, i);

	ST = NULL;
	PNODEST last = NULL;

	for (int j = 0; j < i; j++) {
		PNODEST P1 = searchnotest(temp1, a[j].id);

		if (P1 != NULL && addedIDs.find(P1->data.getID()) == addedIDs.end()) {
			PNODEST newNode = new NodeST(P1->data);

			if (ST == NULL) {
				ST = newNode;
			} else {
				newNode->next = ST;
			}
			ST = newNode;
			addedIDs.insert(P1->data.getID());
		}
	}
	cout << "Sap xep thanh cong";
	getch();
}

void savedata(ListNodeST ST,lecturer lecturer1) {
	ofstream outFile("quanlysinhvien.txt",ios::out);
	PNODEST current = ST;
	outFile << lecturer1.getusername() << ","
	        << lecturer1.getpassword() << ","
	        << lecturer1.getid() << ","
	        << lecturer1.getname() << "," << endl;

	while(current!=NULL) {
		outFile << current->data.getusername() << ","
		        << current->data.getpassword() << ","
		        << current->data.getID() << ","
		        << current->data.getName() << ","
		        << current->data.getdiemdanh() << ","
		        << current->data.getdiemqt() << ","
		        << current->data.getdiemck() << ","
		        << current->data.getdiemkthp() << endl;
		current = current->next;
	}
	outFile.close();
}

struct SinhVienPhucTra {
	int stt;
	string id;
	string ten;
	float diemqt;
	float diemck;
	string trangThai;
};

void lecturer::check(PNODEST temp0) {
	PNODEST head = temp0;

	while(1) {
		vector<SinhVienPhucTra> danhSachPhucTra;
		int stt = 1;
		system("cls");
		cout << setw(5) << left << "STT"
		     << setw(10) << left << "ID"
		     << setw(20) << left << "Ten"
		     << setw(20) << left << "Mon Phuc Tra"
		     << setw(10) << left << "Diem "
		     << setw(15) << left << "Trang Thai" << endl;
		cout << string(75, '-') << endl;

		PNODEST temp = head;
		while(temp!=NULL) {
			if (temp->data.getdiemqt() >= 100) {
				danhSachPhucTra.push_back({stt, temp->data.getID(), temp->data.getName(), temp->data.getdiemqt() - 101,0,(temp->data.getdiemqt() <= 10) ? "Da cap nhat" : "Chua xu ly"});
				cout << setw(5) << left << stt++
				     << setw(10) << left << temp->data.getID()
				     << setw(20) << left << temp->data.getName()
				     << setw(20) << left << "Diem Qua Trinh"
				     << setw(10) << left << temp->data.getdiemqt()-101
				     << setw(15) << left << ((temp->data.getdiemqt()<=10) ? "Da cap nhat" : "Chua xu ly") << endl;
			}

			if (temp->data.getdiemck() >= 100) {
				danhSachPhucTra.push_back({stt, temp->data.getID(), temp->data.getName(),0, temp->data.getdiemck() - 101, (temp->data.getdiemck() <= 10) ? "Da cap nhat" : "Chua xu ly"});
				cout << setw(5) << left << stt++
				     << setw(10) << left << temp->data.getID()
				     << setw(20) << left << temp->data.getName()
				     << setw(20) << left << "Diem Cuoi Ky"
				     << setw(10) << left << temp->data.getdiemck()-101
				     << setw(15) << left << ((temp->data.getdiemck()<=10) ? "Da cap nhat" : "Chua xu ly") << endl;
			}
			temp = temp->next;
		}
		cout << string(75, '-') << endl;
		if(danhSachPhucTra.empty()) {
			cout << "\n" << "Khong co sinh vien phuc tra" << endl;
		}
		cout << "Nhap ma so sinh vien can xu ly diem: (Nhap 0 de thoat) ";
		string mssv;
		fflush(stdin);
		getline(cin,mssv);
		if(mssv == "0")
			break;
		for (size_t i = 0; i < danhSachPhucTra.size(); ++i) {
			const SinhVienPhucTra& sv = danhSachPhucTra[i];
			if(sv.id==mssv) {
				if(sv.diemck==0)
				{
					while(1) {
						int choice;
						cout <<"          	========================"<<endl;
						cout <<"          	| Xu ly phuc tra       |"<<endl;
						cout <<"          	========================"<<endl;
						cout <<"          	|1. Diem qua trinh moi |"<<endl;
						cout <<"          	|0. Khong thay doi     |"<<endl;
						cout <<" 		========================"<<endl;
						cout << endl << "Nhap lua chon: ";
						cin >> choice;
						if(choice == 1) {
							temp = head;
							float dqt;
							cout << "Nhap diem qua trinh moi: ";
							cin >> dqt;
							PNODEST P = searchnotest(temp,sv.id);
							P->data.setdiemqt(dqt);
							float diemkthp;
							if (P->data.getdiemdanh() >= 2) {
								diemkthp = (((P->data.getdiemqt() - 1) > 10) ? 10 : (P->data.getdiemqt() - 1)) * 0.3 + P->data.getdiemck() * 0.7;
							}
							else if (P->data.getdiemdanh() == 0) {
								diemkthp = ((P->data.getdiemqt() > 10) ? 10 : P->data.getdiemqt()) * 0.3 + P->data.getdiemck() * 0.7;
							}
							else {
								diemkthp = (((P->data.getdiemqt() + 1) > 10) ? 10 : (P->data.getdiemqt() + 1)) * 0.3 + P->data.getdiemck() * 0.7;
							}

							if(diemkthp>10)
								diemkthp = 10;
							P->data.setdiemkthp(diemkthp);
							cout << "Cap nhat thanh cong";
							getch();
							break;
						}
						else if(choice == 0) {
							temp = head;
							PNODEST P = searchnotest(temp,sv.id);
							P->data.setdiemqt(P->data.getdiemqt()-101);
							P->data.setdiemkthp(P->data.getdiemkthp()-101);
							cout << "Hoan thanh!";
							getch();
							break;
						}
					}
				}
				else
					while(1) {
						int choice;
						cout <<"          	========================"<<endl;
						cout <<"          	| Xu ly phuc tra       |"<<endl;
						cout <<"          	========================"<<endl;
						cout <<"          	|1. Diem cuoi ky moi   |"<<endl;
						cout <<"          	|0. Khong thay doi     |"<<endl;
						cout <<" 		========================"<<endl;
						cout << endl << "Nhap lua chon: ";
						cin >> choice;
						if(choice == 1) {
							temp = head;
							float dck;
							cout << "Nhap diem cuoi ky moi: ";
							cin >> dck;
							PNODEST P = searchnotest(temp,sv.id);
							P->data.setdiemck(dck);
							float diemkthp;
							if (P->data.getdiemdanh() >= 2) {
								diemkthp = (((P->data.getdiemqt() - 1) > 10) ? 10 : (P->data.getdiemqt() - 1)) * 0.3 + P->data.getdiemck() * 0.7;
							}
							else if (P->data.getdiemdanh() == 0) {
								diemkthp = ((P->data.getdiemqt() > 10) ? 10 : P->data.getdiemqt()) * 0.3 + P->data.getdiemck() * 0.7;
							}
							else {
								diemkthp = (((P->data.getdiemqt() + 1) > 10) ? 10 : (P->data.getdiemqt() + 1)) * 0.3 + P->data.getdiemck() * 0.7;
							}

							if(diemkthp>10)
								diemkthp = 10;
							P->data.setdiemkthp(diemkthp);
							cout << "Cap nhat thanh cong";
							getch();
							break;
						}
						else if(choice == 0) {
							temp = head;
							PNODEST P = searchnotest(temp,sv.id);
							P->data.setdiemck(P->data.getdiemck()-101);
							P->data.setdiemkthp(P->data.getdiemkthp()-101);
							cout << "Hoan thanh!";
							getch();
							break;
						}
					}
			}
		}
		danhSachPhucTra.clear();
	}
}
