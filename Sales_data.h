#ifndef __SALESDATA__
#define __SALESDATA__
 
#include<iostream>
#include<string>



//Sales_data�� 
class Sales_data{
	//��Ԫ 
	friend Sales_data add(const Sales_data&, const Sales_data&);      //�� 
	friend std::ostream &print(std::ostream&, const Sales_data&);     //��� 
	friend std::istream &read(std::istream&, Sales_data&);      //����						 //���崦constȥ����Ҫ�ǵ��޸�����������Ԫ����������

public: 
	//���캯�� 
	Sales_data();
	Sales_data(const std::string &s);
	Sales_data(const std::string &s, unsigned , double );
	Sales_data(std::istream &istr);
	std::string isbn() const;  //����bookNo 
	Sales_data& combine(const Sales_data&);

//��Ա	 
private:
	
	double avg_price() const;
	std::string bookNo; //��� 
	unsigned units_sold = 0;//���ۼ� 
	double revenue = 0.0; //���۶� 
	
};
//��غ������� 
Sales_data add(const Sales_data&, const Sales_data&);      //�� 
std::ostream &print(std::ostream&, const Sales_data&);     //��� 
std::istream &read(std::istream&, const Sales_data&);      //���� 

//ƽ���ۼ� 
Sales_data add(const Sales_data &item1, const Sales_data &item2);












#endif
