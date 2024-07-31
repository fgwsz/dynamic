#pragma once
#include<string>//::std::string
#include<utility>//::std::move
#include<type_traits>//::std::is_same_v

#include"test/test.hpp"
#include"dynamic/box.hpp"

//[o]Box(Type__ const& value);
//[o]Box(Box<Type__> const& rhs);
//[o]Box(Type__&& value={});
//[o]Box(Box<Type__>&& rhs);
//[o]Box<Type__>& operator=(Type__ const& value);
//[o]Box<Type__>& operator=(Box<Type__> const& rhs);
//[o]Box<Type__>& operator=(Type__&& value);
//[o]Box<Type__>& operator=(Box<Type__>&& rhs);
//[o]~Box();
//[o]Type__ const& get()const;
//[o]using value_type=Type__;

TEST_GROUP(dynamic_box){
    TEST_GROUP_ELEMENT(dynamic_box_copy_ctor_by_value);
    TEST_GROUP_ELEMENT(dynamic_box_copy_ctor_by_box);
    TEST_GROUP_ELEMENT(dynamic_box_move_ctor_by_value);
    TEST_GROUP_ELEMENT(dynamic_box_move_ctor_by_box);
    TEST_GROUP_ELEMENT(dynamic_box_copy_assign_by_value);
    TEST_GROUP_ELEMENT(dynamic_box_copy_assign_by_box);
    TEST_GROUP_ELEMENT(dynamic_box_move_assign_by_value);
    TEST_GROUP_ELEMENT(dynamic_box_move_assign_by_box);
    TEST_GROUP_ELEMENT(dynamic_box_dtor);
    TEST_GROUP_ELEMENT(dynamic_box_get);
    TEST_GROUP_ELEMENT(dynamic_box_value_type);
}

//[o]Box(Type__ const& value);
TEST_CASE(dynamic_box_copy_ctor_by_value){
    using small_type=int;
    small_type small_object={100};
    ::dynamic::Box<small_type> small_box(small_object);
    TEST_CHECK_EQ(small_box.get(),small_object);

    using big_type=::std::string;
    big_type big_object={"hello"};
    ::dynamic::Box<big_type> big_box(big_object);
    TEST_CHECK_EQ(big_box.get(),big_object);
}

//[o]Box(Box<Type__> const& rhs);
TEST_CASE(dynamic_box_copy_ctor_by_box){
    using small_type=int;
    small_type small_object={100};
    ::dynamic::Box<small_type> small_box_1(small_object);
    ::dynamic::Box<small_type> small_box_2(small_box_1);
    TEST_CHECK_EQ(small_box_2.get(),small_object);

    using big_type=::std::string;
    big_type big_object={"hello"};
    ::dynamic::Box<big_type> big_box_1(big_object);
    ::dynamic::Box<big_type> big_box_2(big_box_1);
    TEST_CHECK_EQ(big_box_2.get(),big_object);
}

//[o]Box(Type__&& value={});
TEST_CASE(dynamic_box_move_ctor_by_value){
    using small_type=int;
    small_type small_object={100};
    ::dynamic::Box<small_type> small_box_1(::std::move(small_object));
    TEST_CHECK_EQ(small_box_1.get(),100);
    ::dynamic::Box<small_type> small_box_2;
    TEST_CHECK_EQ(small_box_2.get(),0);

    using big_type=::std::string;
    big_type big_object={"hello"};
    ::dynamic::Box<big_type> big_box_1(::std::move(big_object));
    TEST_CHECK_EQ(big_box_1.get(),"hello");
    ::dynamic::Box<big_type> big_box_2;
    TEST_CHECK_EQ(big_box_2.get(),"");
}

//[o]Box(Box<Type__>&& rhs);
TEST_CASE(dynamic_box_move_ctor_by_box){
    using small_type=int;
    small_type small_object={100};
    ::dynamic::Box<small_type> small_box_1(small_object);
    ::dynamic::Box<small_type> small_box_2(::std::move(small_box_1));
    TEST_CHECK_EQ(small_box_2.get(),small_object);

    using big_type=::std::string;
    big_type big_object={"hello"};
    ::dynamic::Box<big_type> big_box_1(big_object);
    ::dynamic::Box<big_type> big_box_2(::std::move(big_box_1));
    TEST_CHECK_EQ(big_box_2.get(),big_object);
}

//[o]Box<Type__>& operator=(Type__ const& value);
TEST_CASE(dynamic_box_copy_assign_by_value){
    using small_type=int;
    small_type small_object={100};
    ::dynamic::Box<small_type> small_box;
    small_box=small_object;
    TEST_CHECK_EQ(small_box.get(),small_object);

    small_box=small_box.get();
    TEST_CHECK_EQ(small_box.get(),small_object);

    using big_type=::std::string;
    big_type big_object={"hello"};
    ::dynamic::Box<big_type> big_box;
    big_box=big_object;
    TEST_CHECK_EQ(big_box.get(),big_object);

    big_box=big_box.get();
    TEST_CHECK_EQ(big_box.get(),big_object);
}

//[o]Box<Type__>& operator=(Box<Type__> const& rhs);
TEST_CASE(dynamic_box_copy_assign_by_box){
    using small_type=int;
    small_type small_object={100};
    ::dynamic::Box<small_type> small_box_1(small_object);
    ::dynamic::Box<small_type> small_box_2;
    small_box_2=small_box_1;
    TEST_CHECK_EQ(small_box_2.get(),small_object);

    small_box_2=small_box_2;
    TEST_CHECK_EQ(small_box_2.get(),small_object);

    using big_type=::std::string;
    big_type big_object={"hello"};
    ::dynamic::Box<big_type> big_box_1(big_object);
    ::dynamic::Box<big_type> big_box_2;
    big_box_2=big_box_1;
    TEST_CHECK_EQ(big_box_2.get(),big_object);

    big_box_2=big_box_2;
    TEST_CHECK_EQ(big_box_2.get(),big_object);
}

//[o]Box<Type__>& operator=(Type__&& value);
TEST_CASE(dynamic_box_move_assign_by_value){
    using small_type=int;
    small_type small_object={100};
    ::dynamic::Box<small_type> small_box;
    small_box=::std::move(small_object);
    TEST_CHECK_EQ(small_box.get(),100);

    using big_type=::std::string;
    big_type big_object={"hello"};
    ::dynamic::Box<big_type> big_box;
    big_box=::std::move(big_object);
    TEST_CHECK_EQ(big_box.get(),"hello");
}

//[o]Box<Type__>& operator=(Box<Type__>&& rhs);
TEST_CASE(dynamic_box_move_assign_by_box){
    using small_type=int;
    small_type small_object={100};
    ::dynamic::Box<small_type> small_box_1(small_object);
    ::dynamic::Box<small_type> small_box_2;
    small_box_2=::std::move(small_box_1);
    TEST_CHECK_EQ(small_box_2.get(),small_object);

    small_box_2=::std::move(small_box_2);
    TEST_CHECK_EQ(small_box_2.get(),small_object);

    using big_type=::std::string;
    big_type big_object={"hello"};
    ::dynamic::Box<big_type> big_box_1(big_object);
    ::dynamic::Box<big_type> big_box_2;
    big_box_2=::std::move(big_box_1);
    TEST_CHECK_EQ(big_box_2.get(),big_object);

    big_box_2=::std::move(big_box_2);
    TEST_CHECK_EQ(big_box_2.get(),big_object);
}

//[o]~Box();
TEST_CASE(dynamic_box_dtor){
    struct SmallType{
        SmallType():data_(true){}
        ~SmallType(){this->data_=false;}
        bool data_;
    };
    using small_type=SmallType;
    ::dynamic::Box<small_type> small_box;
    small_box.~Box();
    TEST_CHECK_EQ(small_box.get().data_,false);

    using big_type=::std::string;
    big_type big_object={"hello"};
    ::dynamic::Box<big_type> big_box(big_object);
    big_box.~Box();
    TEST_CHECK_EQ(&(big_box.get()),nullptr);
}

//[o]Type__ const& get()const;
TEST_CASE(dynamic_box_get){
    using small_type=int;
    small_type small_object={100};
    ::dynamic::Box<small_type> small_box(small_object);
    TEST_CHECK_EQ(small_box.get(),small_object);
    TEST_CHECK_EQ(*(small_type*)(&small_box),small_object);

    using big_type=::std::string;
    big_type big_object={"hello"};
    ::dynamic::Box<big_type> big_box(big_object);
    TEST_CHECK_EQ(big_box.get(),big_object);
}

//[o]using value_type=Type__;
TEST_CASE(dynamic_box_value_type){
    using small_type=int;
    TEST_STATIC_CHECK(::std::is_same_v<
        typename ::dynamic::Box<small_type>::value_type
        ,small_type
    >);

    using big_type=::std::string;
    TEST_STATIC_CHECK(::std::is_same_v<
        typename ::dynamic::Box<big_type>::value_type
        ,big_type
    >);
}
