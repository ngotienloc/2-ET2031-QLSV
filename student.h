#ifndef student_h
#define student_h
#include"user.h"
#include<string>
#include <iomanip>
using namespace std;
class NodeST;
typedef NodeST* PNODEST;

class student:public user {
private:
	float diemqt,diemck,diemkthp;
	int diemdanh;
public:
	student(string id, string name, string username, string password);
	void VangDiemDanh();
	//getter:
	string getID();
	string getName();
	float getdiemqt();
	float getdiemck();
	float getdiemkthp();
	int getdiemdanh();

	//setter:
	void setDiemdanh(int diemdanh);
	void setdiemqt(float qt);
	void setdiemck(float ck);
	void setdiemkthp(float kthp);
	void setname(string name);
	void setusername(string username);
	void setpassword(string password);
	void setID(string ID);
	//getter:
	string getusername();
	student();
	string getpassword();
	void stMenu();
	void DT(string name);
	void re(PNODEST &S);
};
class NodeST {
public:
	student data;
	NodeST* next;

	NodeST() {
		next = NULL;
	}
	NodeST(const student& st) : data(st), next(NULL) {};
};
typedef NodeST* PNODEST;
typedef NodeST* ListNodeST;
void showdata(ListNodeST ST);
#endif


