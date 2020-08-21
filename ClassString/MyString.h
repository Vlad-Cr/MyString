#pragma once

class MyString {
private:
	char *str;
public:
	MyString();
	MyString(const char str[]);
	MyString(const MyString&);
	MyString(MyString&&);
	~MyString();

	MyString operator +(const MyString&);
	MyString &operator +=(const MyString&);
	friend MyString operator +(const char str[], const MyString&);
	MyString &operator =(MyString&&);
	MyString &operator =(const MyString&);
	bool operator ==(const MyString&);
	bool operator !=(const MyString&);
	bool operator <(const MyString&);
	bool operator >(const MyString&);
	bool operator <=(const MyString&);
	bool operator >=(const MyString&);
	char &operator [](const unsigned int index);
	friend ostream & operator <<(ostream &, const MyString&);
	friend istream & operator >>(istream &, MyString&);
	unsigned int length();
	void copy(const MyString&);
	char & at(const unsigned int index);
	void clear();
	void swap(MyString&);
};