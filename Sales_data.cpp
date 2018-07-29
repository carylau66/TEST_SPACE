
#include"Sales_data.h"



/*
*	Sales_data类
*
*
*
*
*
*/

//构造函数
Sales_data::Sales_data() = default;
Sales_data::Sales_data(const std::string &s) : bookNo(s) { }
Sales_data::Sales_data(std::istream &istr)
{
	std::cin >> this->bookNo >> this->units_sold >> this->revenue;
}
Sales_data::Sales_data(const std::string &s, const unsigned units_, double revenue_)
{
	bookNo = s;
	units_sold = units_;
	revenue = revenue_;
}

std::string Sales_data::isbn() const { return bookNo; }  //返回bookNo 

//用输入流构造 
//Sales_data::Sales_data(std::istream &istr){
//	istr >> this->bookNo >> this->units_sold >> this->revenue; //_______@_______原答案是is >> *this,这怎么输入？？？ 
//}
//combine
Sales_data& Sales_data::combine(const Sales_data &sameIsbn) {      //Sales_data.combine()兼并
	units_sold += sameIsbn.units_sold;
	revenue += sameIsbn.revenue;
	return *this;              //返回调用该函数的对象 p233，返回一个左值(位置)：引用类型 
}
//平均售价 
double Sales_data::avg_price() const    //Sales_data.avg_price()平均售价
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

//读入数据 
std::istream &read(std::istream &is, Sales_data &item) {  //_______@________read你加什么const啊，是会更改的！！！ 
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price;
	return is;
}
//输出数据 
std::ostream &print(std::ostream &os, const Sales_data &item) {
	os << item.bookNo << "\t" << item.units_sold << "\t" << item.revenue << "\t" << item.avg_price() << "\n";
	return os;
}
Sales_data add(const Sales_data &item1, const Sales_data &item2) {
	Sales_data sum = item1;
	sum.combine(item2);
	return sum;
}




