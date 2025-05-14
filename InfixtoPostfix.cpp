#include<iostream>
#include<string>

using namespace std;

class Stack {
private:
	int top;
	int size;
	char arr[100];
public:
	Stack() {
		top = -1;
		size = 100;
	}
	bool isEmpty() {
		if (top==-1)
		{
			return true;
		}
		else {
			return false;
		}
	}

	bool isFull() {
		if (top == size - 1) {
			return true;
		}
		else {
			return false;
		}
	}
	void push(char c) {
		if (isFull()) {
			cout << "Stack is overflow";
			return;
		}
		else {
			top++;
			arr[top] = c;
		}

	}
	char Top() {
		if (isEmpty()) {
			return '\0';
		}
		else {
			return arr[top];
		}
	}

	char pop() {
		if (isEmpty())
		{
			cout << "Stack is underflow";
			return'\0';
		}
		else {
			char c = arr[top];
			top--;
			return c;
		}
	}
};

int prec(char op) {
	if (op == '^') {
		return 3;
	}
	else if (op == '*' || op=='/') {
		return 2;
	}
	else if (op == '-' || op == '+'){
		return 1;
	}
	else
		return 0;

}
bool isOperator(char c) {
	return(c == '-' || c == '+' || c == '*' || c == '/');
}

string InfixtoPostfix(string infix) {
	Stack s;
	string pstfix = "";
	for (int i = 0; i < infix.length(); i++) {
		char c = infix[i];
		if (isalnum(c)) {
			pstfix += c;
		}
		else if (c == '(') {
			s.push(c);
		}
		else if (c == ')') {
			while (!s.isEmpty() && s.Top() != '(') {
				s.pop();
			}
			s.pop();
		}
		else if (isOperator(c)) {
			while (!s.isEmpty() && prec(s.Top()) >= prec(c)) {
				pstfix += s.pop();
			}
			s.push(c);
		}

	}

	while (!s.isEmpty()) {   
		pstfix += s.pop();
	}
	return pstfix;
} 
int main() {
	string infix;
	cout << "Enter a Expression" << endl;
	cin >> infix;
	string pstfix = InfixtoPostfix(infix);
	cout << "PostFix expression : " << pstfix << endl;
	return 0;
}
