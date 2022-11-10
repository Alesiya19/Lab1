#include <iostream>
#include <string>
#include <clocale>
#include <algorithm>
#include "TheViginerCiper.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	string str;
	string keyword;
    askTheUser:
	cout << "Введите слово: ";
	cin >> str;
	transform(str.begin(), str.end(), str.begin(), toupper);
    askTheKey:
	cout << "Введите ключ: ";
	cin >> keyword;
	transform(keyword.begin(), keyword.end(), keyword.begin(), toupper);
	TheViginerCiper ciper;
	if (!(ciper.checks(str) && ciper.checks(keyword)))
		goto askTheUser;
	if (keyword.size() > str.size())
	{
		cout << "Ключ должен быть меньше, чем вводимое сообщение" << endl;
		goto askTheKey;
	}
	else
	{
		string key = ciper.generateKey(str, keyword);
		string cipher_text = ciper.cipherText(str, key);
		cout << "Зашифрованный текст : "
			<< cipher_text << " " << endl;;
		char ans;
		cout << "Показать расшифрованный текст? y/n ";
		cin >> ans;
		if (ans == 'y')
			cout << "\nРасшифрованный текст : " << ciper.originalText(cipher_text, key);
	}
	

	return 0;
}