#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
#include <execution>
#include <chrono>
#include <cstdlib>  // where atoi() is located
#include <unistd.h> // where getopt() is located
#include <cstring>
#include "sets.h"
//#include "catch_section.hpp"
//#include "catch_user_config.hpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#define SIZE 100000

using namespace std;

TEST_CASE("The four data structures can be initialized")

{
    int numbers[] = {1, 2, 3, 4};
    arraySet arrayset(numbers, 4);
    ListSet listSet(numbers, 4);
    treeSet treeSet(numbers, 4);
    hashSet hashSet(numbers, 4);

    REQUIRE(arrayset.size() == 4);
    REQUIRE(listSet.size() == 4);
    REQUIRE(treeSet.size() == 4);
    REQUIRE(hashSet.size() == 4);
}

TEST_CASE("Array SET"){
    SECTION("Intialization"){
        int numbers[] = {1, 2, 3, 4}; 
        arraySet arrayset(numbers, 4);  
        REQUIRE(arrayset.size() == 4); 
    } 
    SECTION("Find: successful"){
        int numbers[] = {1, 2, 3, 4}; 
        arraySet arrayset(numbers, 4);  
        REQUIRE(arrayset.find(3) == true); 
    }  
    SECTION("Find: unsuccessful"){
        int numbers[] = {1, 2, 3, 4}; 
        arraySet arrayset(numbers, 4);  
        REQUIRE(arrayset.find(10) == false);  
    } 
    SECTION("Insert: unsuccessful"){
        int numbers[] = {1, 2, 3, 4}; 
        arraySet arrayset(numbers, 4);  
        REQUIRE(arrayset.insert(2) == false);  
    } 
    SECTION("Insert: successful"){
        int numbers[] = {1, 2, 3, 4}; 
        arraySet arrayset(numbers, 4);  
        REQUIRE(arrayset.insert(5) == true);  
    } 
    SECTION("Remove: unsuccessful"){
        int numbers[] = {1, 2, 3, 4}; 
        arraySet arrayset(numbers, 4);  
        REQUIRE(arrayset.remove(5) == false);  
    } 
    SECTION("Remove: successful"){
        int numbers[] = {1, 2, 3, 4}; 
        arraySet arrayset(numbers, 4);  
        REQUIRE(arrayset.remove(2) == true);  
    } 
}

TEST_CASE("List SET"){
    SECTION("Intialization"){
        int numbers[] = {1, 2, 3, 4}; 
        ListSet listSet(numbers, 4);  
        REQUIRE(listSet.size() == 4); 
    } 
    SECTION("Find: successful"){
        int numbers[] = {1, 2, 3, 4}; 
        ListSet listSet(numbers, 4);  
        REQUIRE(listSet.find(2) == true); 
    }  
    SECTION("Find: unsuccessful"){
        int numbers[] = {1, 2, 3, 4}; 
        ListSet listSet(numbers, 4);  
        REQUIRE(listSet.find(9) == false);  
    } 
    SECTION("Insert: unsuccessful"){
        int numbers[] = {1, 2, 3, 4}; 
        ListSet listSet(numbers, 4);  
        REQUIRE(listSet.insert(4) == false);  
    } 
    SECTION("Insert: successful"){
        int numbers[] = {1, 2, 3, 4}; 
        ListSet listSet(numbers, 4);  
        REQUIRE(listSet.insert(7) == true);  
    } 
    SECTION("Remove: unsuccessful"){
        int numbers[] = {1, 2, 3, 4}; 
        ListSet listSet(numbers, 4);  
        REQUIRE(listSet.remove(7) == false);  
    } 
    SECTION("Remove: successful"){
        int numbers[] = {1, 2, 3, 4}; 
        ListSet listSet(numbers, 4);  
        REQUIRE(listSet.remove(1) == true);  
    } 
}

TEST_CASE("Tree SET"){
    SECTION("Intialization"){
        int numbers[] = {1, 2, 3, 4}; 
        treeSet treeSet(numbers, 4);  
        REQUIRE(treeSet.size() == 4); 
    } 
    SECTION("Find: successful"){
        int numbers[] = {1, 2, 3, 4}; 
        treeSet treeSet(numbers, 4);  
        REQUIRE(treeSet.find(2) == true); 
    }  
    SECTION("Find: unsuccessful"){
        int numbers[] = {1, 2, 3, 4}; 
        treeSet treeSet(numbers, 4);  
        REQUIRE(treeSet.find(8) == false);  
    } 
    SECTION("Insert: unsuccessful"){
        int numbers[] = {1, 2, 3, 4}; 
        treeSet treeSet(numbers, 4);  
        REQUIRE(treeSet.insert(4) == false);  
    } 
    SECTION("Insert: successful"){
        int numbers[] = {1, 2, 3, 4}; 
        treeSet treeSet(numbers, 4);  
        REQUIRE(treeSet.insert(6) == true);  
    } 
    SECTION("Remove: unsuccessful"){
        int numbers[] = {1, 2, 3, 4}; 
        treeSet treeSet(numbers, 4);  
        REQUIRE(treeSet.remove(7) == false);  
    } 
    SECTION("Remove: successful"){
        int numbers[] = {1, 2, 3, 4}; 
        treeSet treeSet(numbers, 2);  
        REQUIRE(treeSet.remove(2) == true);  
    } 
}

TEST_CASE("Hash SET"){
    SECTION("Intialization"){
        int numbers[] = {1, 2, 3, 4}; 
        hashSet hashSet(numbers, 4);  
        REQUIRE(hashSet.size() == 4); 
    } 
    SECTION("Find: successful"){
        int numbers[] = {1, 2, 3, 4}; 
        hashSet hashSet(numbers, 4);  
        REQUIRE(hashSet.find(1) == true); 
    }  
    SECTION("Find: unsuccessful"){
        int numbers[] = {1, 2, 3, 4}; 
        hashSet hashSet(numbers, 4);  
        REQUIRE(hashSet.find(10) == false);  
    } 
    SECTION("Insert: unsuccessful"){
        int numbers[] = {1, 2, 3, 4}; 
        hashSet hashSet(numbers, 4);  
        REQUIRE(hashSet.insert(1) == false);  
    } 
    SECTION("Insert: successful"){
        int numbers[] = {1, 2, 3, 4}; 
        hashSet hashSet(numbers, 4);  
        REQUIRE(hashSet.insert(9) == true);  
    } 
    SECTION("Remove: unsuccessful"){
        int numbers[] = {1, 2, 3, 4}; 
        hashSet hashSet(numbers, 4);  
        REQUIRE(hashSet.remove(10) == false);  
    } 
    SECTION("Remove: successful"){
        int numbers[] = {1, 2, 3, 4}; 
        hashSet hashSet(numbers, 4);  
        REQUIRE(hashSet.remove(4) == true);  
    } 
}





