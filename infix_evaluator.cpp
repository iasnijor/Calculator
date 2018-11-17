/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "infix_converter.h"
#include "postfix_evaluator.h"
#include "token.h"
#include "infix_evaluator.h"

#include <stack>
#include <string>
#include "tokenizer.h"
namespace csis3700 {

    double infix_evaluator::evaluate(std::queue<token> infix) {
        infix_converter i1;
        std::queue<token> answer_queue = i1.convert_to_postfix(infix);
        postfix_evaluator evaluated_answer;
        double answer = evaluated_answer.evaluate(answer_queue);
        return answer;
    }
}









