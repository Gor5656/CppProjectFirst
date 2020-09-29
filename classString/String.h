#pragma once
#ifndef _STRING_H_
#define _STRING_H_

#include <iostream>

#pragma warning (disable:4996)

using std::cout;
using std::endl;
using std::ostream;
using std::istream;

class String {
	friend ostream& operator<<(ostream&, const String&);
	friend istream& operator>>(istream&, String&);
public:
	String(const char* = "");
	String(const String &);
	~String();

	const String& operator=(const String&);
	const String& operator+=(const String&);

	bool operator!()const;
	bool operator==(const String &)const;
	bool operator<(const String &)const;

	bool operator!=(const String& right) {
		return !(*this == right);
	}

	bool operator>(const String& right) {
		return right < *this;
	}

	bool operator>=(const String& right)const {
		return !(*this < right);
	}
	bool operator<=(const String& right)const {
		return !(right < *this);
	}

	char &operator[](int);
	const char &operator[](int)const;
	String operator()(int, int);



	int getLenght()const;

private:
	int lenght;
	char* sptr;

	void setString(const char *);
};

#endif