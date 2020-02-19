//
// Client that tests the ArrayList
//


#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_FAST_COMPILE
#include <iostream>
#include "ArrayList.h"
#include "catch.hpp"

using namespace std;


TEST_CASE("ArrayList", "[ArrayList01]") {

    SECTION("Appending") {
        ArrayList L;
        REQUIRE(L.getLength() == 0);

        L.append(4);
        // expected: 4
        REQUIRE(L.at(0) == 4);
        REQUIRE(L.getLength() == 1);

        L.append(7);
        // expected: 4, 7
        REQUIRE(L.at(0) == 4);
        REQUIRE(L.at(1) == 7);
        REQUIRE(L.getLength() == 2);

        L.append(10);
        L.append(2);
        L.append(8);
        // expected: 4, 7, 10, 2, 8
        REQUIRE(L.at(4) == 8);
        REQUIRE(L.at(3) == 2);
        REQUIRE(L.getLength() == 5);
    }

    SECTION("Insert after") {
        ArrayList M;

        M.append(9);
        M.insertAfter(0, 11);
        // expected: 9, 11
        REQUIRE(M.at(1) == 11);

        M.insertAfter(0, 14);
        // expected: 9, 14, 11
        REQUIRE(M.at(2) == 11);
        REQUIRE(M.at(1) == 14);
        REQUIRE(M.at(0) == 9);

        M.insertAfter(2, 42);
        // expected: 9, 14, 11, 42
        REQUIRE(M.at(2) == 11);
        REQUIRE(M.at(3) == 42);
    }

    SECTION("Prepend") {
        ArrayList P;

        P.prepend(3);
        // expected: 3
        REQUIRE(P.at(0) == 3);

        P.prepend(6);
        // expected: 6, 3
        REQUIRE(P.at(0) == 6);
        REQUIRE(P.at(1) == 3);
    }

    SECTION("Search") {
        ArrayList L;
        vector<int> tmp = {9, 1, 42, 33, 89, 55};
        for (auto e: tmp) L.append(e);

        REQUIRE(L.search(9) == 0);
        REQUIRE(L.search(42) == 2);
        REQUIRE(L.search(55) == 5);
        REQUIRE(L.search(88) == -1);
    }


    SECTION("Remove At") {
        ArrayList L;
        vector<int> tmp = {9, 1, 42, 33, 89, 55};
        for (auto e: tmp) L.append(e);

        L.removeAt(0);
        // expected: 1, 42, 33, 89, 55
        REQUIRE(L.at(0) == 1);

        L.removeAt(4);
        // expected: 42, 33, 55, 89
        REQUIRE(L.at(3) == 89);
        REQUIRE(L.getLength() == 4);

        L.removeAt(0);
        L.removeAt(0);
        L.removeAt(0);
        // expected: 89
        REQUIRE(L.at(0) == 89);
    }
}

TEST_CASE("Reverse an empty list", "[Reverse]") {
    ArrayList L;
    REQUIRE(L.getLength() == 0);
}

TEST_CASE("Reverse a list", "[Reverse]") {
    ArrayList L;
    vector<int> tmp = { 9, 1, 42, 33, 89, 55, 98};
    for (auto e: tmp) L.append(e);

    L.reverse();
    int len = tmp.size();
    for (int i = 0; i < len; i++)
        REQUIRE(L.at(i) == tmp[len-1-i]);
}

TEST_CASE("Reverse a one element list", "[Reverse]") {
    ArrayList L;
    L.append(33);
    L.reverse();
    REQUIRE(L.at(0)  == 33);
    REQUIRE(L.getLength()  == 1);
}

TEST_CASE("Elim odds of a long list", "[ElimOdds]") {
    ArrayList L;
    vector<int> tmp = { 9, 1, 42, 33, 89, 55, 98};
    for (auto e: tmp) L.append(e);

    L.elimOdds();
    vector<int> expected = { 42, 98};
    REQUIRE(L.getLength() == 2);
    for (int i = 0; i < expected.size(); i++)
        REQUIRE(L.at(i) == expected[i]);
}

TEST_CASE("Elim odds of an odd list", "[ElimOdds]") {
    ArrayList L;
    vector<int> tmp = { 9, 11, 421, 33, 89, 55, 981};
    for (auto e: tmp) L.append(e);

    L.elimOdds();
    REQUIRE(L.getLength() == 0);
}

TEST_CASE("Elim odds of an even list", "[ElimOdds]") {
    ArrayList L;
    vector<int> tmp = { 92, 112, 4212, 334, 892, 556, 9810};
    for (auto e: tmp) L.append(e);

    L.elimOdds();
    REQUIRE(L.getLength() == tmp.size());
    for (int i = 0; i < tmp.size(); i++)
        REQUIRE(L.at(i) == tmp[i]);
}

TEST_CASE("Elim odds of an empty list", "[ElimOdds]") {
    ArrayList L;

    L.elimOdds();
    REQUIRE(L.getLength() == 0);

    L.append(15);
    L.elimOdds();
    REQUIRE(L.getLength() == 0);

    L.append(44);
    L.elimOdds();
    REQUIRE(L.getLength() == 1);


}



TEST_CASE("Mode of a list ", "[Mode]") {
    ArrayList L;
    vector<int> tmp = { 9, 1, 9, 42, 33, 89, 55, 98};
    for (auto e: tmp) L.append(e);

    REQUIRE(L.mode() == 9);

    L.append(42);
    REQUIRE(L.mode() == -1);

    L.append(42);
    REQUIRE(L.mode() == 42);

}

TEST_CASE("Mode is the min element", "[Mode]") {
    ArrayList L;
    vector<int> tmp = { 9, 1, 9, 42, 1, 33, 89, 1, 55, 98};
    for (auto e: tmp) L.append(e);

    REQUIRE(L.mode() == 1);

}

TEST_CASE("Mode is the max element", "[Mode]") {
    ArrayList L;
    vector<int> tmp = { 9, 100, 100, 42, 100, 9, 89, 1, 55, 98};
    for (auto e: tmp) L.append(e);

    REQUIRE(L.mode() == 100);
}

TEST_CASE("Mode in extreme cases", "[Mode]") {
    ArrayList L;
    REQUIRE(L.mode() == -1);

    L.append(8);
    REQUIRE(L.mode() == 8);
}

