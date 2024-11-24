#ifndef user_h
#define user_h
#include<iostream>
#include<string>
#include "conio.h"
using namespace std; 
class user{
	protected: 
		string id; 
		string name; 
		string username ; 
		string password ; 
	public: 
 
		user();
		user(string id, string name, string username, string password);	
		bool checklogin(string input_username,string input_password);
		int login();
		int login(string username,string password);
};
#endif


