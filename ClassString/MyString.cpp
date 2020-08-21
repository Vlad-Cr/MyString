#include <iostream>
using namespace std;
#include "MyString.h"

MyString::MyString() {
	str = new char[1];
	str[0] = '\0';
}

MyString::MyString(const char str[]) {
	this->str = new char[strlen(str) + 1];
	strcpy_s(this->str, strlen(str) + 1, str);
}

MyString::MyString(const MyString &other) {
	str = new char[strlen(other.str) + 1];
	strcpy_s(str, strlen(other.str) + 1, other.str);
}

MyString::MyString(MyString &&other) {
	this->str = other.str;
	other.str = nullptr;
}

MyString::~MyString() {
	delete[] str;
}


unsigned int MyString::length() {
	return strlen(str);
}

void MyString::copy(const MyString &other) {
	if (*this == other) {
		return;
	}

	delete[] str;
	str = new char[strlen(other.str) + 1];
	strcpy_s(str, strlen(other.str) + 1, other.str);
}

char & MyString::at(const unsigned int index) {
	if (index > strlen(str)) {
		throw exception("Error, incorrect index value");
	}
	return str[index];
}

void MyString::clear() {
	delete[] str;
	str = new char[1];
	str[0] = '\0';
}

void MyString::swap(MyString &other) {
	if (*this == other) {
		return;
	}
	MyString temp(*this);
	*this = other;
	other = temp;
}

MyString &MyString::operator =(MyString &&other) {
	this->str = other.str;
	other.str = nullptr;
	return *this;
}

MyString MyString::operator +(const MyString &other) {
	MyString newStr;

	delete[] newStr.str;
	newStr.str = new char[strlen(this->str) + strlen(other.str) + 1];

	int i = 0;
	for (; i < strlen(this->str); i++) {
		newStr.str[i] = this->str[i];
	}

	for (int j = 0; j < strlen(other.str) + 1; i++, j++) {
		newStr.str[i] = other.str[j];
	}
	return newStr;
}

MyString &MyString::operator +=(const MyString &other) {
	MyString temp(*this);

	delete[] this->str;

	this->str = new char[strlen(temp.str) + strlen(other.str) + 1];

	int i = 0;
	for (; i < strlen(temp.str); i++) {
		this->str[i] = temp.str[i];
	}

	for (int j = 0; j < strlen(other.str) + 1; i++, j++) {
		this->str[i] = other.str[j];
	}

	return *this;
}

MyString operator +(const char str[], const MyString &other) {
	MyString newStr;

	delete[] newStr.str;
	newStr.str = new char[strlen(other.str) + strlen(str) + 1];

	int i = 0;
	for (; i < strlen(other.str); i++) {
		newStr.str[i] = other.str[i];
	}

	for (int j = 0; j < strlen(str) + 1; i++, j++) {
		newStr.str[i] = str[j];
	}
	return newStr;
}

bool MyString::operator ==(const MyString &other) {
	if (strcmp(str, other.str) == 0) {
		return true;
	}
	return false;
}

bool MyString::operator !=(const MyString &other) {
	return !(this->operator==(other));
}

bool MyString::operator <(const MyString &other) {
	if (strcmp(str, other.str) == -1) {
		return true;
	}
	return false;
}

bool MyString::operator >(const MyString &other) {
	if (strcmp(str, other.str) == 1) {
		return true;
	}
	return false;
}

bool MyString::operator <=(const MyString &other) {
	if (strcmp(str, other.str) <= 0) {
		return true;
	}
	return false;
}

bool MyString::operator >=(const MyString &other) {
	if (strcmp(str, other.str) >= 0) {
		return true;
	}
	return false;
}

MyString &MyString::operator =(const MyString &other) {
	if (*this == other) {
		return *this;
	}

	delete[] str;
	str = new char[strlen(other.str) + 1];
	strcpy_s(str, strlen(other.str) + 1, other.str);

	return *this;
}

char &MyString::operator [](const unsigned int index) {
	return str[index];
}

ostream & operator <<(ostream &stream, const MyString &obj) {
	stream << obj.str;
	return stream;
}

istream & operator >>(istream &stream, MyString &obj) {
	char str[256];
	stream >> str;
	delete[] obj.str;
	obj.str = new char[strlen(str) + 1];
	strcpy_s(obj.str, strlen(str) + 1, str);
	return stream;
}