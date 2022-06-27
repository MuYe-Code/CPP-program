#include <iostream>

#include "String.hh"

using std::cin;
using std::cout;
using std::endl;

void test01() {
	String s1;
	s1 = "world";
	cout << "s1: " << s1 << endl;

	String s2("hello");
	cout << "s2: " << s2 << endl;

	String s3(s2);
	cout << "s3: " << s3 << endl;

	String s4 = s1 + s2;
	cout << "s4: " << s4 << endl;

	String s5;
	cin >> s5;
	cout << "s5: " << s5 << endl;

	
	for (int i = 0; i < s5.size(); ++i) {
		cout << s5[i] << " ";
	}
	cout << endl;

	if (s1 > s2) {
		cout << s1.c_str() << " > " << s2.c_str() << endl;
	}
	else {
		cout << s1.c_str() << " <= " << s2.c_str() << endl;
	}
}


int main() {
	test01();
	return 0;
}