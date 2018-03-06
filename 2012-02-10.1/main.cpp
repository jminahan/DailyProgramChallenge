#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name, age, username;
	cout << "What is your name?\n";
	cin >> name;
	cout << "How old are you?\n";
	cin >> age;
	cout << "What is your reddit username?\n";
	cin >> username;

	cout << "Your name is " + name + ", you are " + age + " years old and your reddit username is " + username + "\n";
}