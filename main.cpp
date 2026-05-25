import std;
import yaml.markup;

class my_class {
public:
    int val{1};
    virtual ~my_class() = default;
};

int main()
{
    std::cout << yaml::markup<my_class>::serialize(my_class());

    my_class m = yaml::markup<my_class>::deserialize("val: 2");
    std::cout << m.val << "\n";

    return 0;
}
