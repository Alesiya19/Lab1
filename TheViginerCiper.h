#pragma once
#include <iostream>
#include <string>
#include <clocale>
#include <algorithm>
using namespace std;

class TheViginerCiper
{
public:
	string generateKey (string str, string key);
	string cipherText (string str, string key);
	string originalText (string cipher_text, string key);
	bool checks (string str);
	TheViginerCiper();
	~TheViginerCiper();
};

