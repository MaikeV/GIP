#include "catch.h"
#include "suchen.h"

TEST_CASE("Zeichenkette suchen, Text mit Laenge groesser 1, Zeichenkette mit Laenge groesser 1") {
	REQUIRE(suchen("abcdabcde", "cda") == 2);
	REQUIRE(suchen("abcdabcde", "de") == 7);
	REQUIRE(suchen("abcdabcde", "dex") == -1);
	REQUIRE(suchen("abcdabcde", "xyz") == -1);
	REQUIRE(suchen("abcdabcde", "abcdabcd") == 0);
	REQUIRE(suchen("abcdabcde", "abcdabcdx") == -1);
}
TEST_CASE("Zeichenkette suchen, Text mit Laenge groesser 1, Zeichenkette mit Laenge 1") {
	REQUIRE(suchen("abcdabcde", "a") == 0);
	REQUIRE(suchen("abcdabcde", "c") == 2);
	REQUIRE(suchen("abcdabcde", "e") == 8);
	REQUIRE(suchen("abcdabcde", "x") == -1);
}
TEST_CASE("Zeichenkette suchen, Text mit Laenge 1") {
	REQUIRE(suchen("a", "a") == 0);
	REQUIRE(suchen("a", "c") == -1);
	REQUIRE(suchen("a", "xy") == -1);
	REQUIRE(suchen("a", "aa") == -1);
}
TEST_CASE("Zeichenkette suchen, leerer Text") {
	REQUIRE(suchen("", "") == -1);
	REQUIRE(suchen("", "a") == -1);
	REQUIRE(suchen("", "abc") == -1);
}
TEST_CASE("Testfaelle aus Aufgabenstellung") {
	REQUIRE(suchen("abcdefg", "bcd99") == -1);
	REQUIRE(suchen("abcdefg", "efg") == 4);
	REQUIRE(suchen("abc", "abcde") == -1);
	REQUIRE(suchen("012 abc abc 89", "abc") == 4);
	REQUIRE(suchen("xy abc abcdefgh", "abcde") == 7);
	REQUIRE(suchen("xyz 123 456 abc", "123 4") == 4);
	REQUIRE(suchen("abc defg", "abc d") == 0);
}