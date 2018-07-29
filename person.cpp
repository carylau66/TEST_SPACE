#include"person.h"


/*
*	Person类
*
*	std::string Person::getName() const				返回姓名
*	std::string Person::getAddress() const			返回地址
*	void Person::setName(std::istream &name)		设置姓名
*	void Person::setAddress(std::istream &addr)		设置地址
*
*/

//构造函数 
Person::Person() = default;
Person::Person(const std::string name, const std::string address) :strName(name), strAddress(address) { }
Person::Person(const std::string name) {
	strName = name;
	strAddress = "";
}
//成员函数
std::string Person::getName() const { return strName; } //返回姓名
std::string Person::getAddress() const { return strAddress; } //返回地址 
void Person::setName(std::istream &name) { name >> strName; }
void Person::setAddress(std::istream &addr) { addr >> strAddress; }

//读 
std::istream &read_Person(std::istream &is, Person &item) {   //此处不能是const。因为要更改值 
															  //	is >> item.strName >> item.strAddress;
															  //	std::string str;
															  //	item.setName(std::cin >> str);
	item.setName(is);
	item.setAddress(is);
	return is;
}
//写 
std::ostream &print_Person(std::ostream &os, const Person &item) {
	os << item.getName() << item.getName();
	return os;
}