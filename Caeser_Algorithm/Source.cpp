using namespace std;
#include <stdio.h>
#include <string.h>
#include <iostream>
void encryption(int, int[], char[]);
void decryption(int, int[], char[]);
void main()
{
	int key;
	int ed;
	int a[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 };
	char b[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	cout << "enter the encryption key:" << endl;
	cin >> key;
	cout << "enter 0 for encryption or 1 for decryption:" << endl;
	cin >> ed;
	if (ed == 0) encryption(key, a, b);
	if (ed == 1) decryption(key, a, b);
}
void encryption(int key, int a[], char b[])
{
	char PT[200];
	char CT[200];
	puts("enter the original (plaintext) message");
	cin>>PT;
	cout << "The encrypted (ciphertext) message is:";
	for (int i = 0; i < strlen(PT); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (PT[i] == b[j])
			{
				int n = (a[j] + key) % (26);
				CT[i] = b[n];
				cout << CT[i];
				break;
			}
		}
	}
	cout << " " << endl;
}
void decryption(int key, int a[], char b[])
{
	char PT[200];
	char CT[200];
	puts("enter the encrypted (ciphertext) message");
	cin>>CT;
	cout << "The original (plaintext) message is:";
	for (int i = 0; i < strlen(CT); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (CT[i] == b[j])
			{
				int n = (a[j] - key) % (26);
				if(n < 0)
				{
					n = n + 26;
				}
				PT[i] = b[n];
				cout << PT[i];
				break;
			}
		}
	}
	cout << " " << endl;
}
