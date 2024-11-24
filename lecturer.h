#ifndef lecturer_h
#define lecturer_h
#include"user.h"
#include "student.h"
#include <fstream>
#include<string>


using namespace std;

class lecturer:public user {
public:
	lecturer();
	lecturer(string id, string name, string username, string password);
	string getid();
	string getname();
	string getusername();
	string getpassword();

	void setid(string i);
	void setname(string name);
	void setusername(string user);
	void setpassword(string pass);

	void ltMenu(PNODEST temp10);
	void addST(ListNodeST &ST);
	void searchST(ListNodeST ST);
	void showST(PNODEST ST);
	void DDST(ListNodeST &ST);
	void inputGrades1(PNODEST &ST,float grades1);
	void inputGrades2(PNODEST &ST,float grades2);
	void NhapDiem(ListNodeST &ST);
	void DisplayListStudent(ListNodeST ST);
	void deleteST(ListNodeST &ST);
	PNODEST searchnotest(ListNodeST ST,string id);
	PNODEST searchnotebeforest(ListNodeST ST,string id);
	void arrange(ListNodeST &ST);
	struct arr {
		float a;
		string id;
	};
	void insertsort(arr a[], int n);
	void check(PNODEST temp);
};
void savedata(ListNodeST ST,lecturer lecturer1);
string capitalizeName(const string& name);
#endif

