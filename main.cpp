#include <iostream>
import yaml.markup;

class my_class {
public:
    int val{1};
    virtual ~my_class() = default;
};

int main()
{
    std::cout << yaml::markup<my_class>::serialize(my_class()) << std::endl;
}
