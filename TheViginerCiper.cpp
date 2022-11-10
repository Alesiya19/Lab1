#include "TheViginerCiper.h"
#include <iostream>
#include <string>
#include <clocale>
#include <algorithm>
using namespace std;

TheViginerCiper::TheViginerCiper()
{

}
TheViginerCiper::~TheViginerCiper()
{

}
// ��� ������� ���������� ���� ����������� ������� �� ��� ���, ���� ��� ����� �� ������ ������ ����� ��������� ������
string TheViginerCiper::generateKey(string str, string key)
{
	int x = str.size();
	for (int i = 0; ; i++)
	{
		if (x == i)
			i = 0;
		if (key.size() == str.size())
			break;
		key.push_back(key[i]);
	}
	return key;
}
//��� ������� ���������� ������������� �����
string TheViginerCiper::cipherText(string str, string key)
{
	string cipher_text;
	for (int i = 0; i < str.size(); i++)
	{
		char x = (str[i] + key[i]) % 26;
		x += 'A';
		cipher_text.push_back(x);
	}
	return cipher_text;
}
// ��� ������� �������������� ������������� ����� � ���������� �������� �����
string TheViginerCiper::originalText(string cipher_text, string key)
{
	string orig_text;
	for (int i = 0; i < cipher_text.size(); i++)
	{
		char x = (cipher_text[i] - key[i] + 26) % 26;
		x += 'A';
		orig_text.push_back(x);
	}
	return orig_text;
}

bool TheViginerCiper::checks(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
		{
			cout << "����� ������� ������ �� ����.!" << endl;
			return false;
		}
	}
	return true;
}

