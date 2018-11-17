/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "tokenizer.h"
#include <queue>
#include <string>
#include "infix_converter.h"
#include "postfix_evaluator.h"
#include "infix_evaluator.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
using namespace std;
using namespace csis3700;

TEST_CASE("+", "infix") {
    infix_converter i;
    queue<token> q;

    q.push(token("1"));
    q.push(token("+"));
    q.push(token("3"));

    queue<token> result = i.convert_to_postfix(q);
    postfix_evaluator e;
    REQUIRE(e.evaluate(result) == 4);
}

TEST_CASE("-", "infix") {
    infix_converter i;
    queue<token> q;

    q.push(token("1"));
    q.push(token("-"));
    q.push(token("3"));

    queue<token> result = i.convert_to_postfix(q);
    postfix_evaluator e;
    REQUIRE(e.evaluate(result) == -2.0);
}

TEST_CASE("*-", "infix") {
    infix_converter i;
    queue<token> q;
    q.push(token("1"));
    q.push(token("*"));
    q.push(token("3"));
    q.push(token("-"));
    q.push(token("3"));

    queue<token> result = i.convert_to_postfix(q);
    postfix_evaluator e;
    REQUIRE(e.evaluate(result) == 0);
}

TEST_CASE("*+*", "infix") {
    infix_converter i;
    queue<token> q;
    q.push(token("1"));
    q.push(token("+"));
    q.push(token("3"));
    q.push(token("*"));
    q.push(token("3"));
    queue<token> result = i.convert_to_postfix(q);
    postfix_evaluator e;
    REQUIRE(e.evaluate(result) == 10);
}

TEST_CASE("++", "infix_evaluator") {
    infix_evaluator i;
    queue<token> q;

    q.push(token("1"));
    q.push(token("+"));
    q.push(token("3"));

    REQUIRE(i.evaluate(q) == 4);
}

TEST_CASE("*+", "infix_evaluator") {
    infix_converter i;
    queue<token> q;

    q.push(token("1"));
    q.push(token("+"));
    q.push(token("3"));
    q.push(token("*"));
    q.push(token("3"));

    infix_evaluator e;
    REQUIRE(e.evaluate(q) == 10);
}

TEST_CASE("^*+", "infix_evaluator") {
    infix_converter i;
    queue<token> q;

    q.push(token("1"));
    q.push(token("+"));
    q.push(token("3"));
    q.push(token("*"));
    q.push(token("3"));
    q.push(token("^"));
    q.push(token("2"));

    infix_evaluator e;
    REQUIRE(e.evaluate(q) == 28);
}

TEST_CASE("^", "infix_evaluator") {
    infix_converter i;
    queue<token> q;

    q.push(token("1"));
    q.push(token("^"));
    q.push(token("3"));
    q.push(token("+"));
    q.push(token("3"));
    q.push(token("^"));
    q.push(token("2"));

    infix_evaluator e;
    REQUIRE(e.evaluate(q) == 10);
}

TEST_CASE("()", "infix_evaluator") {
    infix_converter i;
    queue<token> q;

    q.push(token("1"));
    q.push(token("/"));
    q.push(token("("));
    q.push(token("3"));
    q.push(token("-"));
    q.push(token("2"));
    q.push(token(")"));


    infix_evaluator e;
    REQUIRE(e.evaluate(q) == 1);
}

TEST_CASE("complex", "infix_evaluator") {
    infix_converter i;
    queue<token> q;

    q.push(token("4"));
    q.push(token("+"));
    q.push(token("9"));
    q.push(token("-"));
    q.push(token("6"));
    q.push(token("*"));
    q.push(token("4"));
    q.push(token("!"));
    q.push(token("/"));
    q.push(token("8"));
    infix_evaluator e;
    REQUIRE(e.evaluate(q) == -5);
}




























