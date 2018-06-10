#include<iostream>
#include"Sales_data.h"


int main(){
	
	Sales_data data1;
	Sales_data data2("stupid second");
	Sales_data data3("third", 0, 5.0);
	Sales_data data4(std::cin);
	
	

	/*print(std::cout,data1);
	print(std::cout,data2);
	print(std::cout,data3);
	print(std::cout,data4);*/
	
//	std::cout << data1 << "\n" 
//			  << data2 << "\n"
//			  << data3 << "\n"
//			  << data4 << std::endl;
//	
	
	return 0;
}
