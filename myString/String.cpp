#define _CRT_SECURE_NO_WARNINGS

#include "String.hh"

#include <iomanip>
#include <cstring>

using std::endl;
using std::cout;

//为字符串至少保留一个空字符，则可以避免判断字符串是否为空

String::String() {
	cout << "String::String()" << endl;

	_pstr = new char('\0');
}

String::String(const char* s) {
	cout << "String::String(const char*)" << endl;

	int len = strlen(s);
	_pstr = new char[len + 1]();
	strcpy(_pstr, s);
}

String::String(const String& s) {
	cout << "String::String(const String&)" << endl;

	int len = s.size();
	_pstr = new char[len + 1]();
	strcpy(_pstr, s._pstr);
}

String::~String() {
	cout << "String::~String()" << endl;

	delete[] _pstr;
}

String& String::operator+=(const String& s) {
	char* arr = new char[this->size() + s.size() + 1]();
	sprintf(arr, "%s%s", _pstr, s._pstr);
	delete[] _pstr;
	_pstr = arr;
	return *this;
}

String& String::operator+=(const char* s) {
	char* arr = new char[this->size() + strlen(s) + 1]();
	sprintf(arr, "%s%s", _pstr, s);
	delete[] _pstr;
	_pstr = arr;
	return *this;
}

char& String::operator[](std::size_t index) {
	if (this->size() <= index || index < 0) {
		std::cerr << "Invalid index" << endl;
		exit(-1);
	}
	return _pstr[index];
}

const char& String::operator[](std::size_t index) const {
	if (this->size() <= index || index < 0) {
		std::cerr << "Invalid index" << endl;
		exit(-1);
	}
	return _pstr[index];
}

std::size_t String::size() const {
	return strlen(_pstr);
}

const char* String::c_str() const {
	return _pstr;
}

String& String::operator=(const String& s) {
	cout << "tring& String::operator=(const String&)" << endl;

	if (this != &s) {
		delete[] _pstr;
		_pstr = new char[s.size() + 1]();
		strcpy(_pstr, s._pstr);
	}
	return *this;
}

String& String::operator=(const char* s) {
	cout << "String& String::operator=(const char*)" << endl;

	delete[] _pstr;
	
	if (nullptr != s) {
		_pstr = new char[strlen(s) + 1]();
		strcpy(_pstr, s);
	}
	else {
		_pstr = new char('\0');
	}

	return *this;
}

String operator+(const String& s1, const String& s2) {
	cout << "String operator+(const String&, const String&)" << endl;

	int len = s1.size() + s2.size() + 1;
	char* pstr = new char[len]();
	sprintf(pstr, "%s%s", s1.c_str(), s2.c_str());
	return String(pstr);
}

String operator+(const String& s1, const char* s2) {
	cout << "String operator+(const String&, const char*)" << endl;

	if (s2) {
		int len = s1.size() + strlen(s2) + 1;
		char* pstr = new char[len]();
		sprintf(pstr, "%s%s", s1.c_str(), s2);
		return String(pstr);
	}
	return s1;
}

String operator+(const char* s1, const String& s2) {
	cout << "String operator+(const char*, const String&)" << endl;

	if (s1) {
		int len = s2.size() + strlen(s1) + 1;
		char* pstr = new char[len]();
		sprintf(pstr, "%s%s", s1, s2.c_str());
		return String(pstr);
	}
	return s2;
}

bool operator==(const String& s1, const String& s2) {
	return 0 == strcmp(s1._pstr, s2._pstr);
}

bool operator!=(const String& s1, const String& s2) {
	return strcmp(s1._pstr, s2._pstr);
}

bool operator<(const String& s1, const String& s2) {
	return strcmp(s1._pstr, s2._pstr) < 0;
}

bool operator>(const String& s1, const String& s2) {
	return strcmp(s1._pstr, s2._pstr) > 0;
}

bool operator<=(const String& s1, const String& s2) {
	return strcmp(s1._pstr, s2._pstr) <= 0;
}

bool operator>=(const String& s1, const String& s2) {
	return strcmp(s1._pstr, s2._pstr) >= 0;
}


std::ostream& operator<<(std::ostream& os, const String& s) {
	//cout << "std::ostream& operator<<(std::ostream&, const String&)" << endl;

	if (s.size()) {
		os << s._pstr;
	}
	
	return os;
}

std::istream& operator>>(std::istream& is, String& s) {
	//cout << "std::istream& operator>>(std::istream&, String&)" << endl;
	delete[] s._pstr;
	s._pstr = new char[256]();
	is >> std::setw(255) >> s._pstr;
	
	return is;
}