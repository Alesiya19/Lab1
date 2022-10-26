#include <iostream>
#include <string>
#include <clocale>
#include <algorithm>
using namespace std;

// Эта функция генерирует ключ циклическим образом до тех пор, пока его длина не станет равной длине исходного текста
string generateKey(string str, string key)
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
//Эта функция возвращает зашифрованный текст
string cipherText(string str, string key)
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
// Эта функция расшифровывает зашифрованный текст и возвращает исходный текст
string originalText(string cipher_text, string key)
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

bool check(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
		{
			cout << "Нужно вводить только на англ.!" << endl;
			return false;
		}
	}
	return true;
}

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
	if (!(check(str) && check(keyword)))
		goto askTheUser;
	if (keyword.size() > str.size())
	{
		cout << "Ключ должен быть меньше, чем вводимое сообщение" << endl;
		goto askTheKey;
	}
	else
	{
		string key = generateKey(str, keyword);
		string cipher_text = cipherText(str, key);
		cout << "Зашифрованный текст : "
			<< cipher_text << " " << endl;;
		char ans;
		cout << "Показать расшифрованный текст? y/n ";
		cin >> ans;
		if (ans == 'y')
			cout << "\nРасшифрованный текст : " << originalText(cipher_text, key);
	}
	

	return 0;
}