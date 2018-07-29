#ifndef __PERSON__
#define __PERSON__

#include<string>
#include<iostream>
#include<vector>

////Person�� 
//struct Person{
//	std::string strName;    //���� 
//	std::string strAddress; //��ַ 
//	
//	std::string name() const {return strName;} //��������                  ------C��struct�ǲ��ܶ��庯���ģ�����C++����չ 
//	std::string address() const {return strAddress;} //���ص�ַ 
//};

//Person�� 
class Person{
public:	
	//���캯�� 
	Person();
	Person(const std::string name, const std::string address);
	Person(const std::string name);
	std::string getName() const; //�������� 
	std::string getAddress() const; //���ص�ַ 
	void setName(std::istream &name);
	void setAddress(std::istream &addr);
	//��Ա 
private:
	std::string strName;    //����
	std::string strAddress; //��ַ
};

//�� 
std::istream &read_Person(std::istream &is, Person &item);
//д 
std::ostream &print_Person(std::ostream &os, const Person &item);


#endif
