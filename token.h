#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <string>
#include <stack>

namespace csis3700 {

    class token {
    public:
        token(const std::string& contents);
        std::string as_string() const;
        bool is_numeric() const;
        double as_number() const;
        int arity() const;
        int precdence() const;
    private:
        std::string value;
    };
}

#endif /* _TOKEN_H_ */

