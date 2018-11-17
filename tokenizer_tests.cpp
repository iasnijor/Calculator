#include "tokenizer.h"
#include <queue>
#include <sstream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
using namespace std;
using namespace csis3700;

TEST_CASE("construct", "tokenizer") {
    tokenizer t;
}

TEST_CASE("given_stream_of_numbers_produces_tokens", "tokenizer") {
    tokenizer t;
    stringstream ss("3 5 7");
    queue<token> result = t.tokenize(ss);
    REQUIRE(result.size() == 3);
}

TEST_CASE("given_stream_of_numbers_produces_number_tokens", "tokenizer") {
    tokenizer t;
    stringstream ss("10 34 5");
    queue<token> result = t.tokenize(ss);
    while (!result.empty()) {
        REQUIRE(result.front().is_numeric());
        result.pop();
    }
}

TEST_CASE("given_stream_of_mixed_produces_correct_numbers", "tokenizer") {
    tokenizer t;
    stringstream ss("10 + 3");
    queue<token> result = t.tokenize(ss);
    REQUIRE(result.front().is_numeric());
    result.pop();
    REQUIRE(!result.front().is_numeric());
    result.pop();
    REQUIRE(result.front().is_numeric());
}

TEST_CASE("given_stream_of_mixed_produces_correct_numbers2", "tokenizer") {
    tokenizer t;
    stringstream ss("10 + .3");
    queue<token> result = t.tokenize(ss);
    REQUIRE(result.front().is_numeric());
    result.pop();
    REQUIRE(!result.front().is_numeric());
    result.pop();
    REQUIRE(result.front().is_numeric());
}

TEST_CASE("given_stream_of_mixed_produces_correct_numbers3", "tokenizer") {
    tokenizer t;
    stringstream ss("10 + -3");
    queue<token> result = t.tokenize(ss);
    REQUIRE(result.front().is_numeric());
    result.pop();
    REQUIRE(!result.front().is_numeric());
    result.pop();
    REQUIRE(result.front().is_numeric());
}
