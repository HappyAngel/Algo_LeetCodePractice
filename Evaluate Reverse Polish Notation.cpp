/*
title:
**********************************************************
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
**********************************************************	

ideas: just the simple usage of stack
*/

class Solution {
public:
    int evalRPN(vector<string> &tokens) 
	{
		stack s(100000);

		for(int i=0; i < tokens.size(); i++)
		{
			int operand;

			if(tryGetOperand(tokens[i], &operand))
			{
				s.push(operand);
			}
			else if(isOperator(tokens[i]))
			{
				int op1;
				int op2;

				if(!s.isEmpty())
				{
					op1 = s.pop();
					if(!s.isEmpty())
					{
						op2 = s.pop();
					}
				}
				else
				{
					return INT_MIN;
				}

				s.push(eval(op2,op1,tokens[i]));
			}
			else
			{
				return INT_MIN;
			}
		}

		if(s.isEmpty())
		{
			return INT_MIN;
		}
		
		int result = s.pop();

		if(!s.isEmpty())
		{
			return INT_MIN;
		}

		return result;

    }

private:

	bool tryGetOperand(string s, int* output)
	{
		*output = atol(s.c_str());

		if(*output == 0 && s != "0")
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	bool isOperator(string s)
	{
		if(s=="+" || 
			s=="-" ||
			s=="*" ||
			s=="/")
		{
			return true;
		}
		else
		{
			false;
		}
	}

	int eval(int op1, int op2, string optor)
	{
		int result = 0;

		if(optor == "+")
		{
			result = op1+op2;	
		}
		else if(optor == "-")
		{
			result = op1 - op2;
		}
		else if(optor == "*")
		{
			result = op1 * op2;
		}
		else if(optor == "/")
		{
			if(op2 != 0)
			{
				result = op1 / op2;
			}
			else
			{
				result = INT_MIN;
			}
		}
		else
		{
			result = INT_MIN;
		}

		return result;
	}

	// simple implementation of Stack
	class stack
	{
		int* p;
		int index;
		int stackSize;

	public:
		stack(int size)
		{
			p = new int[size];
			index = size-1;
			stackSize = size;
		}

		bool isEmpty()
		{
			if(index+1 >= stackSize)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		void push(int s)
		{
			if(index >= 0)
			{
				p[index--] = s;
			}
		}

		int pop()
		{
			int s = INT_MIN;

			if(index-1 < stackSize)
			{
				s = p[++index];	
			}

			return s;
		}

		~stack()
		{
			if(p!=NULL)
			{
				delete [] p;
			}
		}
	};
};