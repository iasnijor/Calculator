#include "tokenizer.h"
#include <queue>
#include <string>
#include "postfix_evaluator.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
using namespace std;
using namespace csis3700;

TEST_CASE("construct", "postfix_evaluator") {
    postfix_evaluator e;
}

TEST_CASE("empty_evaluates_to_zero", "postfix_evaluator") {
    postfix_evaluator e;
    queue<token> queue;
    REQUIRE(e.evaluate(queue) == 0);
}

TEST_CASE("number_evaluates_to_number", "postfix_evaluator") {
    postfix_evaluator e;
    queue<token> q;
    q.push(token("1"));
    REQUIRE(e.evaluate(q) == 1.0);
}

TEST_CASE("can_add", "postfix_evaluator") {
    postfix_evaluator e;
    queue<token> q;
    q.push(token("9"));
    q.push(token("13"));
    q.push(token("+"));
    REQUIRE(e.evaluate(q) == 22.0);
}

TEST_CASE("can_subtract", "postfix_evaluator") {
    postfix_evaluator e;
    queue<token> q;
    q.push(token("9"));
    q.push(token("13"));
    q.push(token("-"));
    REQUIRE(e.evaluate(q) == -4.0);
}

TEST_CASE("can_multiply", "postfix_evaluator") {
    postfix_evaluator e;
    queue<token> q;
    q.push(token("2"));
    q.push(token("13"));
    q.push(token("*"));
    REQUIRE(e.evaluate(q) == 26.0);
}

TEST_CASE("can_divide", "postfix_evaluator") {
    postfix_evaluator e;
    queue<token> q;
    q.push(token("26"));
    q.push(token("13"));
    q.push(token("/"));
    REQUIRE(e.evaluate(q) == 2.0);
}

TEST_CASE("can_expontiate", "postfix_evaluator") {
    postfix_evaluator e;
    queue<token> q;
    q.push(token("2"));
    q.push(token("3"));
    q.push(token("^"));
    REQUIRE(e.evaluate(q) == 8.0);
}

TEST_CASE("can_negate", "postfix_evaluator") {
    postfix_evaluator e;
    queue<token> q;
    q.push(token("2"));
    q.push(token("n"));
    REQUIRE(e.evaluate(q) == -2.0);
}

TEST_CASE("factorial", "postfix_evaluator") {
    postfix_evaluator e;
    queue<token> q;
    q.push(token("3"));
    q.push(token("!"));
    REQUIRE(e.evaluate(q) == 6.0);
}

TEST_CASE("can_give_remainder", "postfix_evaluator") {
    postfix_evaluator e;
    queue<token> q;
    q.push(token("5"));
    q.push(token("2"));
    q.push(token("%"));
    REQUIRE(e.evaluate(q) == 1.0);
}

TEST_CASE("complex", "postfix_evaluator") {
    postfix_evaluator e;
    queue<token> q;
    q.push(token("5"));
    q.push(token("3"));
    q.push(token("!"));
    q.push(token("-"));
    REQUIRE(e.evaluate(q) == -1.0);
}
