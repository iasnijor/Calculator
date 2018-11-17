#ifndef _TOKENIZER_H_
#define _TOKENIZER_H_

#include <queue>
#include <iostream>
#include "token.h"

namespace csis3700 {

    class tokenizer {
    public:
        std::queue<token> tokenize(std::istream&);

    };
}


#endif /* _TOKENIZER_H_ */

