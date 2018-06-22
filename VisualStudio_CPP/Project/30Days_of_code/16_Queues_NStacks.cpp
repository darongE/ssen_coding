
#include <iostream>
#include <string>

using namespace std;

//Two instance variables : one for your stack, and one for your queue.
//A void pushCharacter(char ch) method that pushes a character onto a stack.
//A void enqueueCharacter(char ch) method that enqueues a character in the queue  instance variable.
//A char popCharacter() method that pops and returns the character at the top of the stack instance variable.
//A char dequeueCharacter() method that dequeues and returns the first character in the queue instance variable.


//Sample Input
//racecar
//Sample Output
//The word, racecar, is a palindrome.


class Solution {
	


public:

	Solution()
	{
	}

	void pushCharacter(char ch) {

		stack.push_back(ch);
	}


	void enqueueCharacter(char ch) {

		queue.push_back(ch);
	}


	char popCharacter()
	{
		return stack.back();
	}

	char dequeueCharacter()
	{
		return queue[0];
	}


private:
	std::string stack, queue;
	

};





int main() {
	// read the string s.
	string s ="yes";
	//getline(cin, s);

	// create the Solution class object p.
	Solution obj;

	// push/enqueue all the characters of string s to stack.
	for (int i = 0; i < s.length(); i++) {
		obj.pushCharacter(s[i]);
		obj.enqueueCharacter(s[i]);
	}

	bool isPalindrome = true;

	// pop the top character from stack.
	// dequeue the first character from queue.
	// compare both the characters.
	for (int i = 0; i < s.length() / 2; i++) {
		if (obj.popCharacter() != obj.dequeueCharacter()) {
			isPalindrome = false;

			break;
		}
	}

	// finally print whether string s is palindrome or not.
	if (isPalindrome) {
		cout << "The word, " << s << ", is a palindrome.";
	}
	else {
		cout << "The word, " << s << ", is not a palindrome.";
	}

	return 0;
}