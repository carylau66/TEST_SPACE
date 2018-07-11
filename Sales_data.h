#ifndef SALESDATA_H
#define SALESDATA_H
 
#include<iostream>
#include<string>



class Sales_data;
//Sales_data类 
//class Sales_data{
//	//友元 
//	friend Sales_data add(const Sales_data&, const Sales_data&);      //加 
//	friend std::ostream &print(std::ostream&, const Sales_data&);     //输出 
//	friend std::istream &read(std::istream&, Sales_data&);      //输入						 //定义处const去掉后，要记得修改声明处、友元声明处！！
//
//public: 
//	//构造函数 
//	Sales_data() = default;
//	Sales_data(const std::string &s);
//	Sales_data(const std::string &s, unsigned , double );
//	Sales_data(std::istream &istr);
//	std::string isbn() const;  //返回bookNo 
//	Sales_data& combine(const Sales_data&);
//
////成员	 
//private:
//	
//	double avg_price() const;
//	std::string bookNo; //书号 
//	unsigned units_sold;//零售价 
//	double revenue; //销售额 
//	
//};
////相关函数声明 
//Sales_data add(const Sales_data&, const Sales_data&);      //加 
//std::ostream &print(std::ostream&, const Sales_data&);     //输出 
//std::istream &read(std::istream&, const Sales_data&);      //输入 
//
////平均售价 
//Sales_data add(const Sales_data &item1, const Sales_data &item2);












#endif
