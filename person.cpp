#include"person.h"


/*
*	Person��
*
*	std::string Person::getName() const				��������
*	std::string Person::getAddress() const			���ص�ַ
*	void Person::setName(std::istream &name)		��������
*	void Person::setAddress(std::istream &addr)		���õ�ַ
*
*/

//���캯�� 
Person::Person() = default;
Person::Person(const std::string name, const std::string address) :strName(name), strAddress(address) { }
Person::Person(const std::string name) {
	strName = name;
	strAddress = "";
}
//��Ա����
std::string Person::getName() const { return strName; } //��������
std::string Person::getAddress() const { return strAddress; } //���ص�ַ 
void Person::setName(std::istream &name) { name >> strName; }
void Person::setAddress(std::istream &addr) { addr >> strAddress; }

//�� 
std::istream &read_Person(std::istream &is, Person &item) {   //�˴�������const����ΪҪ����ֵ 
															  //	is >> item.strName >> item.strAddress;
															  //	std::string str;
															  //	item.setName(std::cin >> str);
	item.setName(is);
	item.setAddress(is);
	return is;
}
//д 
std::ostream &print_Person(std::ostream &os, const Person &item) {
	os << item.getName() << item.getName();
	return os;
}