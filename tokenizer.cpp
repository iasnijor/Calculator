#include <queue>
#include <string>
#include "token.h"
#include "tokenizer.h"
using namespace std;

namespace csis3700 {

    queue<token> tokenizer::tokenize(istream& ins) {
        queue<token> result;
        while (ins && ins.peek() != '\n') {
            string word;
            ins >> word;
            if (word != "")
                result.push(token(word));
        }
        return result;
    }
}
