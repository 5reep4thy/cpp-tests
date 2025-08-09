#include <bits/stdc++.h>
using namespace std;
template <typename... Types>
class typelist {};

using short_bool_string_type = typelist<short, bool, std::string>;

// class template for the first element
template <typename List>
struct front;

// partial specialization for the front type
template <typename Head, typename... Tail>
struct front<typelist<Head, Tail...>> {
    using Type = Head;
};

// front_t alias which accesses the front type from the given list
template <typename List>
using front_t = typename front<List>::Type;

// if the first time is not short we'll get a compile error
static_assert(std::is_same<short, front_t<short_bool_string_type>>());
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// class template for pop front
template <typename List>
struct pop_front;

// partial specialization for pop front
template <typename Head, typename... Tail>
struct pop_front<typelist<Head, Tail...>> {
    using Type = typelist<Tail...>; // we create a new typelist without Head
};

// pop_front_t alias to access the type of pop_front
template <typename List>
using pop_front_t = typename pop_front<List>::Type;

// the type short_bool_string_type without short leaves a typelist with bool and string
static_assert(std::is_same<typelist<bool, std::string>, pop_front_t<short_bool_string_type>>());
int main() {

    return 0;
}