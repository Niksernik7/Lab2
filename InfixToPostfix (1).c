#include "InfixToPostfix.h"
int priority(char elem)
{
    if (elem == '+')
        return 1;
    if (elem =='-')
        return 1;
    if (elem == '*')
        return 2;
    if (elem =='/')
        return 2;
    if (elem == '^')
        return 3;
    return 0;
}
char *convert(char *infix)
{
    if (infix == NULL)
        return NULL;
    int i = 0, k = 0, len = strlen(infix) + 1;
    char* postfix = (char*) calloc(len, sizeof(char));
    Stack *s = newStackL();
    while (infix[i] != '\0')
    {
        // if operand add to the postfix expression
        if (infix[i] >= 'a' && infix[i] <= 'z'|| infix[i] >= 'A'&& infix[i] <= 'Z')
        {
            postfix[k] = infix[i];
            i++;
            k++;
        }
            // if opening bracket then push the stack
        else if (infix[i] == '(')
        {
            Push(s, infix[i]);
            i++;
        }
            // if closing bracket encounted then keep popping from stack until
            // closing a pair opening bracket is not encountered
        else if (infix[i] == ')') {
            while(Top(s) != '(') {
                postfix[k] = Top(s);
                Pop(s);
                k++;
            }
            Pop(s);
            i++;
        }
        else
        {
            while (!CheckEmpty(s) && priority(infix[i]) <= priority(Top(s))) {
                postfix[k] = Top(s);
                Pop(s);
                k++;
            }
            Push(s, infix[i]);
            i++;
        }
    }
    while (!CheckEmpty(s)) {
        postfix[k] = Top(s);
        Pop(s);
        k++;
    }
    FreeStack(s);
    return postfix;
}


