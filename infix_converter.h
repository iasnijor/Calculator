/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   infix_converter.h
 * Author: Rojen
 *
 * Created on March 23, 2018, 2:03 PM
 */

#ifndef INFIX_CONVERTER_H
#define INFIX_CONVERTER_H
#include <queue>
#include "token.h"

namespace csis3700 {

    class infix_converter {
    public:
        std::queue<token> convert_to_postfix(std::queue<token>);

    };
}


#endif /* INFIX_CONVERTER_H */






