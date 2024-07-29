#pragma once
#include<stdexcept>
#include<string>

#define DYNAMIC_MACRO_STR_IMPL(...) #__VA_ARGS__
#define DYNAMIC_MACRO_STR(...) DYNAMIC_MACRO_STR_IMPL(__VA_ARGS__)

#define DYNAMIC_MACRO_STATIC_ASSERT(...) \
    static_assert( \
        __VA_ARGS__ \
        ,"file:\"" __FILE__ "\" line:" DYNAMIC_MACRO_STR(__LINE__) \
    ) \
//

#define DYNAMIC_MACRO_RUNTIME_ERROR(...) \
    throw ::std::runtime_error( \
        ::std::string{ \
            "file:\"" __FILE__ "\" line:" DYNAMIC_MACRO_STR(__LINE__) \
            " message:\"" \
        }+::std::string{__VA_ARGS__}+"\"" \
    ) \
//
