#ifndef __PERSON__
#define __PERSON__

#include<string>
#include<iostream>
#include<vector>

////Person类 
//struct Person{
//	std::string strName;    //姓名 
//	std::string strAddress; //地址 
//	
//	std::string name() const {return strName;} //返回姓名                  ------C的struct是不能定义函数的，这是C++的扩展 
//	std::string address() const {return strAddress;} //返回地址 
//};

//Person类 
class Person{
public:	
	//构造函数 
	Person();
	Person(const std::string name, const std::string address);
	Person(const std::string name);
	std::string getName() const; //返回姓名 
	std::string getAddress() const; //返回地址 
	void setName(std::istream &name);
	void setAddress(std::istream &addr);
	//成员 
private:
	std::string strName;    //姓名
	std::string strAddress; //地址
};

//读 
std::istream &read_Person(std::istream &is, Person &item);
//写 
std::ostream &print_Person(std::ostream &os, const Person &item);


#endif
