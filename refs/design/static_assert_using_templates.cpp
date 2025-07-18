template<bool>
struct CompileTimeError;

template<>
struct CompileTimeError<true> {};

#define STATIC_CHECK(expr) \
(CompileTimeError<(expr) != 0>())


template<bool> struct CompileTimeChecker
{
CompileTimeChecker(...);
};
template<> struct CompileTimeChecker<false> { };
#define STATIC_CHECK_WITH_MSG(expr, msg) \
{\
class ERROR_##msg {}; \
(void)sizeof(CompileTimeChecker<(expr) != 0>((ERROR_##msg())));\
}

int main() {
    STATIC_CHECK(1 == 1); // No Compile error
    // STATIC_CHECK(0 == 1); // Compile error
    int b = 0;
    STATIC_CHECK_WITH_MSG(1 == 0, CHECK_FAILED);
    return 0;
}