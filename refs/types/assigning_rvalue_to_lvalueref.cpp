struct T { // substituent for std::tuple<int>
    int x;
};

struct Tr { // substituent for std::tuple<int&>
    int& xr;

    auto operator=(const T& other)
    {
       // std::get<I>(*this) = std::get<I>(other);
       xr = other.x;
    }
};

int main() {
    int a;
    Tr{a} = T{24};
};