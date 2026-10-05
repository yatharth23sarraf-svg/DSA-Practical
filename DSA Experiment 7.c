#include <stdio.h>
#include <string.h>
#include <math.h>

#define SIZE 80

struct stack
{
    double s[SIZE];
    int top;
} st;

void push(double);
double pop(void);
double post(char[]);

int main()
{
    char expr[SIZE];
    int len;
    double result;

    printf("\nEnter a postfix expression: ");
    scanf("%79s", expr);

    len = strlen(expr);

    if (len >= SIZE - 1)
    {
        printf("\nExpression is too long.\n");
        return 1;
    }

    expr[len] = '$';
    expr[len + 1] = '\0';

    result = post(expr);

    printf("\nThe value of the expression is %f\n", result);

    return 0;
}

double post(char expr[])
{
    char ch;
    double result = 0, val, op1, op2;
    int i = 0;

    st.top = -1;

    ch = expr[i];

    while (ch != '$')
    {
        if (ch >= '0' && ch <= '9')
        {
            val = ch - '0';
            push(val);
        }
        else if (ch == '+' || ch == '-' || ch == '*' ||
                 ch == '/' || ch == '^')
        {
            op2 = pop();
            op1 = pop();

            switch (ch)
            {
                case '+':
                    result = op1 + op2;
                    break;

                case '-':
                    result = op1 - op2;
                    break;

                case '*':
                    result = op1 * op2;
                    break;

                case '/':
                    if (op2 == 0)
                    {
                        printf("\nError: Division by zero.\n");
                        return 0;
                    }
                    result = op1 / op2;
                    break;

                case '^':
                    result = pow(op1, op2);
                    break;
            }

            push(result);
        }
        else
        {
            printf("\nInvalid character in expression.\n");
            return 0;
        }

        i++;
        ch = expr[i];
    }

    if (st.top != 0)
    {
        printf("\nInvalid postfix expression.\n");
        return 0;
    }

    result = pop();

    return result;
}

void push(double val)
{
    if (st.top >= SIZE - 1)
    {
        printf("\nStack full.");
        return;
    }

    st.top++;
    st.s[st.top] = val;
}

double pop(void)
{
    double val;

    if (st.top == -1)
    {
        printf("\nStack is empty.");
        return 0;
    }

    val = st.s[st.top];
    st.top--;

    return val;
}
