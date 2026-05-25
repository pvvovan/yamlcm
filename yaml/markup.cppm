module;

import std;

export module yaml.markup;

export namespace yaml
{

template<typename T>
concept DC = std::default_initializable<T>;

template<DC T>
class markup
{
public:
    static std::string serialize(T obj) {
        std::ostringstream oss;
        constexpr std::meta::info ns_refl = ^^T;
        constexpr std::meta::access_context ctx = std::meta::access_context::unchecked();
        constexpr auto members = std::define_static_array(std::meta::members_of(ns_refl, ctx));

        template for (constexpr auto& member : auto(members)) {
            if constexpr (std::meta::has_identifier(member)) {
                oss << std::meta::identifier_of(member) << ": " << obj.[:member:] << '\n';
            }
        }
        return oss.str();
    }

    static T deserialize(std::string text) {
        return T{};
    }
};

}
