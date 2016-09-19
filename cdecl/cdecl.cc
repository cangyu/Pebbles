#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

enum{ IDENTIFIER = 0, QUALIFIER, TYPE };

class token
{
public:
	char type;
	string content;

	void classify(void)
	{
		if (content == "const")
		{ 
			content = "read-only"; 
			type = QUALIFIER;
		}
		else if (content == "volatile")
			type = QUALIFIER;
		else if (content == "void")
			type = TYPE;
		else if (content == "char")
			type = TYPE;
		else if (content == "signed")
			type = TYPE;
		else if (content == "unsigned")
			type = TYPE;
		else if (content == "short")
			type = TYPE;
		else if (content == "int")
			type = TYPE;
		else if (content == "long")
			type = TYPE;
		else if (content == "float")
			type = TYPE;
		else if (content == "double")
			type = TYPE;
		else if (content == "struct")
			type = TYPE;
		else if (content == "union")
			type = TYPE;
		else if (content == "enum")
			type = TYPE;
		else
			type = IDENTIFIER;
	}
};

static void get_token(token &t);
static void decl(void);
static void handle_arrays(void);
static void handle_function_args(void);
static void handle_pointers(void);

stack<token> st;
token cur;

int main(int argc, char** argv)
{
	//read to first
	get_token(cur);
	while (cur.type != IDENTIFIER)
	{
		st.push(cur);
		get_token(cur);
	}
	cout << cur.content << " : ";
	get_token(cur);

	//decl
	decl();

	cout << endl;
	return 0;
}

void get_token(token &t)
{
	char c = 0;
	t.content.clear();

	while ((c = getchar()) == ' ');

	//Checks whether c is either a decimal digit or an uppercase or lowercase letter.
	if (isalnum(c))
	{
		t.content.push_back(c);
		while (isalnum(c = getchar()))
			t.content.push_back(c);
		ungetc(c, stdin);
		t.classify();
		return;
	}

	//Pointer
	if (c == '*')
	{
		t.content = "pointer to";
		t.type = c;
		return;
	}

	//(,),[,],{,}
	t.content.push_back(c);
	t.type = c;
	return;
}

void decl(void)
{
	switch (cur.type)
	{
	case '[':
		handle_arrays();
		break;
	case '(':
		handle_function_args();
		break;
	}

	handle_pointers();

	while (!st.empty())
	{
		if (st.top().type == '(')
		{
			st.pop();
			get_token(cur);
			decl();//already forming an object, recursively decl outer
		}
		else
		{
			cout << st.top().content;
			st.pop();
		}
	}
}

void handle_arrays(void)
{
	while (cur.type == '[')
	{
		cout << "array ";
		get_token(cur);
		if (isdigit(cur.content[0]))
		{
			cout << "0.." << atoi(cur.content.c_str()) - 1<<' ';
			get_token(cur);
		}
		get_token(cur);
		cout << "of ";
	}
}

void handle_function_args(void)
{
	while (cur.type != ')')
		get_token(cur);
	get_token(cur);
	cout << "function returning ";
}

void handle_pointers(void)
{
	while (st.top().type == '*')
	{
		cout << st.top().content << ' ';
		st.pop();
	}
}
