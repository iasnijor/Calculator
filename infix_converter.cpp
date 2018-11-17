/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "infix_converter.h"
#include "token.h"
#include <stack>
#include <cassert>
#include <iostream>
#include <cmath>
using namespace std;
namespace csis3700 {

    std::queue<token> infix_converter::convert_to_postfix(std::queue<token> infix) {
        stack<token> s;
        queue<token> post_fix;
        s.push(token("("));
        infix.push(token(")"));
        while (!infix.empty()) {
            token current_token = infix.front();
            infix.pop();
            if (current_token.is_numeric()) post_fix.push(current_token);
            else if (current_token.as_string()[0] == '(') {
                s.push(current_token);
            } else if (current_token.as_string()[0] == ')') {
                while (s.top().as_string()[0] != '(') {
                    token signs = s.top();
                    post_fix.push(signs);
                    s.pop();
                }
                s.pop();
            }
            else {
                
               
                while (s.top().as_string()[0] != '(' && s.top().precdence() >= current_token.precdence()) {
                    post_fix.push(s.top());
                    s.pop();
                }
                s.push(current_token);
            }

        }
        return post_fix;
    }
}






















































