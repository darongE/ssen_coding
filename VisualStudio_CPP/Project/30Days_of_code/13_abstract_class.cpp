#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
//
//Sample Input
//
//The Alchemist
//Paulo Coelho
//248
//
//Sample Output
//
//The following output is printed by your display() method:
//
//Title: The Alchemist
//	Author : Paulo Coelho
//	Price : 248

class Book 
{
protected:
	string title;
	string author;
public:
	Book(string t, string a) {
		title = t;
		author = a;
	}
	virtual void display() = 0;

};

// Write your MyBook class here

//   Class Constructor
//   
//   Parameters:
//   title - The book's title.
//   author - The book's author.
//   price - The book's price.
//
// Write your constructor here

class MyBook : public Book
{
protected:
	int price;

public:
	MyBook(string title, string author, int price) : Book(title, author)
	{
		this->price = price;

	}

	void display()
	{
		cout << "Title: " << this->title << endl;
		cout << "Author: " << this->author << endl;
		cout << "Price: " << this->price << endl;

	}


 };

//   Function Name: display
//   Print the title, author, and price in the specified format.
//
// Write your method here

// End class

int main() {

	string title, author;
	int price;
	getline(cin, title);
	getline(cin, author);
	
	cin >> price;
	MyBook novel(title, author, price);
	novel.display();
	return 0;
}