#pragma once
#include"test/test.hpp"
#include"dynamic/box.hpp"

//[]Box(Type__ const& value);
//[]Box(Box<Type__> const& rhs);
//[]Box(Type__&& value={});
//[]Box(Box<Type__>&& rhs);
//[]Box<Type__>& operator=(Type__ const& value);
//[]Box<Type__>& operator=(Box<Type__> const& rhs);
//[]Box<Type__>& operator=(Type__&& value);
//[]Box<Type__>& operator=(Box<Type__>&& rhs);
//[]~Box();
//[]Type__ const& get()const;
//[]using value_type=Type__;

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

TEST_CASE(dynamic_box_copy_ctor_by_value){
    //TODO
}

TEST_CASE(dynamic_box_copy_ctor_by_box){
    //TODO
}

TEST_CASE(dynamic_box_move_ctor_by_value){
    //TODO
}

TEST_CASE(dynamic_box_move_ctor_by_box){
    //TODO
}

TEST_CASE(dynamic_box_copy_assign_by_value){
    //TODO
}

TEST_CASE(dynamic_box_copy_assign_by_box){
    //TODO
}

TEST_CASE(dynamic_box_move_assign_by_value){
    //TODO
}

TEST_CASE(dynamic_box_move_assign_by_box){
    //TODO
}

TEST_CASE(dynamic_box_dtor){
    //TODO
}

TEST_CASE(dynamic_box_get){
    //TODO
}

TEST_CASE(dynamic_box_value_type){
    //TODO
}
