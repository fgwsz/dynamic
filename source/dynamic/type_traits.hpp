#pragma once
#include<type_traits>

namespace dynamic{

template<typename Type__>
static constexpr bool is_value_type_v=
    ::std::is_same_v<Type__,::std::decay_t<Type__>>;

template<typename Type__>
static constexpr bool is_big_type_v=
    sizeof(Type__)>sizeof(void*);

template<typename Type__>
static constexpr bool is_small_type_v=
    !::dynamic::is_big_type_v<Type__>;

}//namespace dynamic
