#include <iostream>
#include<cstring>

using namespace std;


class String {
	size_t sz;
	char* str;

	friend ostream& operator<< (ostream& out, const String& str);
	friend istream& operator>> (istream& out, const String& str);

public:

	String(): sz{0}, str{nullptr} {}

	String(const char* str) : sz{ strlen(str) + 1 }, str{new char [sz]} {
		
		for (int i{}; i < sz; ++i) {
			this->str[i] = str[i];
		}
		this->str[strlen(str)] = '\0';
	}

	String(const String& str): String(str.str) {}

	String& operator= (const String& str){

		if (this == &str)
			return *this;
		sz = str.sz;
		delete[] this->str;
		this->str = new char[strlen(str.str) + 1];
		for (int i{}; i < sz; ++i) {
			this->str[i] = str.str[i];
		}
		this->str[strlen(str.str)] = '\0';

	}
	~String() { delete[] str;}

	String& operator+=(const String& str) {
		sz = (strlen(this->str) + strlen(str.str)) + 1;
		char* new_str = new char[sz];
		int i = 0;
		for (; i < strlen(this->str); ++i) {
			new_str[i] = this->str[i];
		}
		for (int j = 0; j < strlen(str.str); ++j, ++i) {
			new_str[i] = str.str[j];
		}
		new_str[i] = '\0';
		delete[] this->str;
		this->str = new_str;
		
		return *this;
	}

	String operator+(const String& str2) {
		String temp;
		temp.sz= (strlen(str) + strlen(str2.str)) + 1;
		temp.str = new char[temp.sz];
		int i = 0;
		for (; i < strlen(str); ++i) {
			temp.str[i] = str[i];
		}
		for (int j = 0; j < strlen(str2.str); ++j, ++i) {
			temp.str[i] = str2.str[j];
		}
		temp.str[i] = '\0';

		return temp;
	}

	size_t size() const {
		
		return sz;
	}

};

ostream& operator<< (ostream& out, const String& str) {
	out << str.str;
	return out;
}

istream& operator>> (istream& in, const String& str) {
	in >> str.str;

	return in;
}


int main() {

	

	return 0;

}
