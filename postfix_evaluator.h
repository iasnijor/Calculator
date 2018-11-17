#ifndef _POSTFIX_EVALUATOR_H_
#define _POSTFIX_EVALUATOR_H_

#include <queue>
#include "token.h"

namespace csis3700 {

    class postfix_evaluator {
    public:
        double evaluate(std::queue<token>);
    private:
        void evaluate(const token&, std::stack<double>&);
    };
}

#endif /* _POSTFIX_EVALUATOR_H_ */
