#include "postfix_evaluator.h"
#include "token.h"
#include <stack>
#include <cassert>
#include <iostream>
#include <cmath>
using namespace std;

namespace csis3700 {

    // foward decls
    void eval_arity_1(const token&, stack<double>&);
    void eval_arity_2(const token&, stack<double>&);

    double postfix_evaluator::evaluate(std::queue<token> postfix) {
        if (postfix.empty()) return 0;
        stack<double> s;
        while (!postfix.empty()) {
            token current_token = postfix.front();
            postfix.pop();
            evaluate(current_token, s);
        }
        return s.top();
    }

    void postfix_evaluator::evaluate(const token& t, stack<double>& s) {
        if (t.is_numeric())
            s.push(t.as_number());
        else {
            if (t.arity() == 1) {
                eval_arity_1(t, s);
            } else {
                eval_arity_2(t, s);
            }
        }
    }

    long long factorial(int n) {
        if (n == 0)
            return 1;
        return n * factorial(n - 1);
    }

    void eval_arity_1(const token& t, stack<double>& s) {
        char op = t.as_string()[0];
        double op1 = s.top();
        s.pop();
        switch (op) {
            case 'n':
                s.push(-op1);
                break;
            case '!':
                s.push(factorial((int) op1));
                break;
            default:
                assert(false);
        }
    }

    void eval_arity_2(const token& t, stack<double>& s) {
        char op = t.as_string()[0];
        double op2 = s.top();
        s.pop();
        double op1 = s.top();
        s.pop();
        switch (op) {
            case '+':
                s.push(op1 + op2);
                break;
            case '-':
                s.push(op1 - op2);
                break;
            case '*':
                s.push(op1 * op2);
                break;
            case '/':
                s.push(op1 / op2);
                break;
            case '^':
                s.push(pow(op1, op2));
                break;
            case '%':
                s.push(fmod(op1, op2));
                break;
            default:
                assert(false);
        }
    }


}

