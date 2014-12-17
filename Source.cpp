#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	// input string
	string input("Hello \n World \n bob \n sam");

	// what delineates lines in the original
	const string original = "\n";

	// what we want the lines to start with in the reply
	const string reply = "\n>";

	// Start at the beginning of the string, use register for speed. using size_t for type as this won't be negative and to avoid casting when comparing with npos.
	register size_t cursor = 0;

	// make sure we start with the reply symbol.
	input.insert(0, "> ");

	// start looking for the newline character, unless we get to the end, assuming that the entire message is less than the max value of size_t (npos)
	while ((cursor = input.find(original, cursor)) != string::npos)
	{
		// replace what is where we are plus one space with what we want the reply to be
		input.replace(cursor, original.length(), reply);

		// continue iterating through the string, but start after what we replaced already.
		cursor += reply.length(); 
	}

	cout << input;
	return (0);
}