
#include"Sales_data.h"



/*
*	Sales_data��
*
*
*
*
*
*/

//���캯��
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

std::string Sales_data::isbn() const { return bookNo; }  //����bookNo 

//������������ 
//Sales_data::Sales_data(std::istream &istr){
//	istr >> this->bookNo >> this->units_sold >> this->revenue; //_______@_______ԭ����is >> *this,����ô���룿���� 
//}
//combine
Sales_data& Sales_data::combine(const Sales_data &sameIsbn) {      //Sales_data.combine()�沢
	units_sold += sameIsbn.units_sold;
	revenue += sameIsbn.revenue;
	return *this;              //���ص��øú����Ķ��� p233������һ����ֵ(λ��)���������� 
}
//ƽ���ۼ� 
double Sales_data::avg_price() const    //Sales_data.avg_price()ƽ���ۼ�
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

//�������� 
std::istream &read(std::istream &is, Sales_data &item) {  //_______@________read���ʲôconst�����ǻ���ĵģ����� 
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price;
	return is;
}
//������� 
std::ostream &print(std::ostream &os, const Sales_data &item) {
	os << item.bookNo << "\t" << item.units_sold << "\t" << item.revenue << "\t" << item.avg_price() << "\n";
	return os;
}
Sales_data add(const Sales_data &item1, const Sales_data &item2) {
	Sales_data sum = item1;
	sum.combine(item2);
	return sum;
}




