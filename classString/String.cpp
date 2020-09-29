#include "String.h"
#include<cassert>
#include <iomanip>

String::String(const char* s)
	:lenght(strlen(s))
{
	setString(s);
}

String::String(const String &copy)
	:lenght(copy.lenght)
{
	setString(copy.sptr);
}

String::~String()
{
	delete[] sptr;
	sptr = nullptr;
}

const String& String::operator=(const String &right)
{
	if (&right != this) {
		delete[] sptr;
		lenght = right.lenght;
		setString(right.sptr);
	}

	return *this;
	
}

const String& String::operator+=(const String&right)
{
	char* tempptr = sptr;
	lenght += right.lenght;
	sptr = new char[lenght + 1];
	strcpy(sptr, tempptr);
	strcat(sptr, right.sptr);
	delete[] tempptr;
	tempptr = 0;

	return *this;

}

bool String::operator!() const
{
	return lenght == 0;
}

bool String::operator==(const String &right) const
{
	return (strcmp(sptr,right.sptr) == 0);
}

bool String::operator<(const String &right) const
{
	return (strcmp(sptr, right.sptr) < 0);
}

char& String::operator[](int index)
{
	assert(index >= 0 && index < lenght);
	return sptr[index];
}
const char& String::operator[](int index)const
{
	assert(index >= 0 && index < lenght);
	return sptr[index];
}

String String::operator()(int index, int sublenght)
{
	assert(index >= 0 && index < lenght && sublenght >= 0);

	int len;

	if ((sublenght == 0) || index + sublenght > lenght)
		len = lenght - index;
	else
		len = sublenght;

	char* tempptr = new char[len + 1];
	assert(tempptr != 0);

	strncpy(tempptr, &sptr[index], len);

	tempptr[len] = '\0';

	String tempString(tempptr);
	delete[] tempptr;

	return tempString;
}

int String::getLenght() const
{
	return lenght;
}

void String::setString(const char *s)
{
	sptr = new char[lenght + 1];
	assert(sptr != 0);
	strcpy(sptr, s);
}

ostream& operator<<(ostream& output, const String &str)
{
	output << str;

	return output;
}

istream& operator>>(istream &input, String &str)
{
	char temp[100];

	input >> std::setw(100) >> temp;

	str = temp;

	return input;
}
