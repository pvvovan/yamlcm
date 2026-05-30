#include <ostream>

namespace yaml
{

class indent {
public:
    virtual ~indent() = default;

    indent(int nesting) {
        this->nesting = nesting;
    }

    friend std::ostream& operator<<(std::ostream& stream, const indent& ind);

private:
    int nesting;
};

inline std::ostream& operator<<(std::ostream& stream, const indent& ind) {
    for (int i = 0; i < ind.nesting; i++) {
        stream << "  ";
    }
    return stream;
}

}
