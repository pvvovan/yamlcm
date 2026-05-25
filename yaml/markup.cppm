module;

#include <string>

export module yaml.markup;

export namespace yaml
{

template<typename T>
concept DC = std::default_initializable<T>;

template<DC T>
class markup
{
public:
    static std::string serialize(T data) {
        return std::string{"yaml data"};
    }

    static T deserialize(std::string text) {
        return T{};
    }
};

}
