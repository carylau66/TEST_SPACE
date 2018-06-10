#ifndef PERSON_H
#define PERSON_H

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
	Person() = default;
	Person(const std::string name, const std::string address):strName(name),strAddress(address){ }
	Person(const std::string name){
		strName = name;
		strAddress = "";
	} 
	
	//成员 
private:
	std::string strName;    //姓名 
	std::string strAddress; //地址 
	
public:
	std::string getName() const { return strName; } //返回姓名
	std::string getAddress() const { return strAddress; } //返回地址 
	void setName(std::istream &name) {name >> strName;}	
	void setAddress(std::istream &addr){addr >> strAddress;}
	
};

//读 
std::istream &read_Person(std::istream &is, Person &item){   //此处不能是const。因为要更改值 
//	is >> item.strName >> item.strAddress;
//	std::string str;
//	item.setName(std::cin >> str);
	item.setName(is);
	item.setAddress(is);
	return is;
}
//写 
std::ostream &print_Person(std::ostream &os, const Person &item){ 
	os << item.getName() << item.getName();
	return os;
}

class Screen;
//Window_mgr类
class Window_mgr{
public: 
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex);
private:
	std::vector<Screen> Screens{Screen(24,80,' ')};
}; 

//Screen类
class Screen{
	friend void Window_mgr::clear(ScreenIndex);
public:
	//using pos = std::string::size_type;
	typedef std::string::size_type pos; //类型别名，类内类型成员 
	//构造函数 
	Screen() = default;
	Screen(pos ht, pos wd, char c):height(ht), width(wd), 
	contents(ht * wd, c){ }
	//成员函数
	char get () const							//读取光标处的字符 
		{ return contents[cursor]; }  			//隐式内联 
	inline char get(pos ht, pos wd) const;		//显式内联 
	Screen &move(pos r, pos c);					//能在之后被设为内联 
	Screen &set(char);
	Screen &set(pos r, pos , char); 
	Screen &display(std::ostream &os);//{ do_display(os); return *this; }
	const Screen &display(std::ostream &os) const;// { do_display(os); return *this; }
	
	 
private:
//public:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	void do_display(std::ostream &os) const{ os << contents; }
		
}; 
//成员函数类外定义
inline 
Screen &Screen::move(pos r, pos c){
	pos row = r * width;
	cursor = row + c;
	return *this;
}
char Screen::get(pos ht, pos wd) const{
	pos row = ht * width;
	return contents[row + wd];
}

Screen &Screen::set(char c){
	contents[cursor] = c;
	return *this;
}
Screen &Screen::set(pos r, pos col, char ch){
	pos row = r * width;
	contents[row + col] = ch;
	return *this; 
}
Screen &Screen::display(std::ostream &os){
	do_display(os);
	return *this;
}
const Screen &Screen::display(std::ostream &os) const{
	do_display(os);
	return *this;
}


void Window_mgr::clear(ScreenIndex i)
{
	Screen &s = Screens[i];
	s.contents = std::string(s.height * s.width,' ');
}














#endif
