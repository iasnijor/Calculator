/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   infix_evaluator.h
 * Author: Rojen
 *
 * Created on March 24, 2018, 6:01 PM
 */

#ifndef INFIX_EVALUATOR_H
#define INFIX_EVALUATOR_H
#include <queue>
#include "token.h"
namespace csis3700 {

    class infix_evaluator {
    public:
        double evaluate(std::queue<token>);

    };

}

#endif /* INFIX_EVALUATOR_H */





