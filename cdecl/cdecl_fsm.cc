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
static void init(void);
static void get_array(void);
static void get_params(void);
static void get_lparen(void);
static void get_single_ptr(void);
static void get_type(void);

stack<token> st;
token cur;
void(*next_state)(void) = init;

int main(int argc, char** argv)
{
	while (next_state != nullptr)
		(*next_state)();

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
		t.type = c;
		return;
	}

	//(,),[,],{,}
	t.content.push_back(c);
	t.type = c;
	return;
}

void init(void)
{
	get_token(cur);
	while (cur.type != IDENTIFIER)
	{
		st.push(cur);
		get_token(cur);
	}
	cout << cur.content << " : ";
	get_token(cur);
	next_state = get_array;
}

void get_array(void)
{
	next_state = get_params;
	while (cur.type == '[')
	{
		cout << "array ";
		get_token(cur);
		if (isdigit(cur.content[0]))
		{
			cout << "0.." << atoi(cur.content.c_str()) - 1 << ' ';
			get_token(cur);
		}
		get_token(cur);
		cout << "of ";
		next_state = get_lparen;
	}
}

void get_params(void)
{
	while (cur.type != ')')
		get_token(cur);
	get_token(cur);
	cout << "function returning ";
	
	next_state = get_lparen;
}

void get_lparen(void)
{
	next_state = get_single_ptr;
	if (!st.empty())
	{
		if (st.top().type == '(')
		{
			st.pop();
			get_token(cur);
			next_state = get_array;
		}
	}
}

void get_single_ptr(void)
{
	if (st.top().type == '*')
	{
		cout << "pointer to ";
		st.pop();
		next_state = get_lparen;
	}
	else if (st.top().type==QUALIFIER)
	{
		cout << st.top().content << ' ';
		st.pop();
		next_state = get_lparen;
	}
	else
		next_state = get_type;
}

void get_type(void)
{
	while (!st.empty())
	{
		cout << st.top().content<<' ';
		st.pop();
	}
	next_state = nullptr;
}
