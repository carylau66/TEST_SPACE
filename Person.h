#ifndef PERSON_H
#define PERSON_H

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
	Person() = default;
	Person(const std::string name, const std::string address):strName(name),strAddress(address){ }
	Person(const std::string name){
		strName = name;
		strAddress = "";
	} 
	
	//��Ա 
private:
	std::string strName;    //���� 
	std::string strAddress; //��ַ 
	
public:
	std::string getName() const { return strName; } //��������
	std::string getAddress() const { return strAddress; } //���ص�ַ 
	void setName(std::istream &name) {name >> strName;}	
	void setAddress(std::istream &addr){addr >> strAddress;}
	
};

//�� 
std::istream &read_Person(std::istream &is, Person &item){   //�˴�������const����ΪҪ����ֵ 
//	is >> item.strName >> item.strAddress;
//	std::string str;
//	item.setName(std::cin >> str);
	item.setName(is);
	item.setAddress(is);
	return is;
}
//д 
std::ostream &print_Person(std::ostream &os, const Person &item){ 
	os << item.getName() << item.getName();
	return os;
}

class Screen;
//Window_mgr��
class Window_mgr{
public: 
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex);
private:
	std::vector<Screen> Screens{Screen(24,80,' ')};
}; 

//Screen��
class Screen{
	friend void Window_mgr::clear(ScreenIndex);
public:
	//using pos = std::string::size_type;
	typedef std::string::size_type pos; //���ͱ������������ͳ�Ա 
	//���캯�� 
	Screen() = default;
	Screen(pos ht, pos wd, char c):height(ht), width(wd), 
	contents(ht * wd, c){ }
	//��Ա����
	char get () const							//��ȡ��괦���ַ� 
		{ return contents[cursor]; }  			//��ʽ���� 
	inline char get(pos ht, pos wd) const;		//��ʽ���� 
	Screen &move(pos r, pos c);					//����֮����Ϊ���� 
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
//��Ա�������ⶨ��
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
