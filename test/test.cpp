#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "srec/srec.hpp"

// Test the ASCIIToHexString function
TEST_CASE( "ASCIIToHexString", "[ASCIIToHexString]" ) {
	std::string buffer = "Hello, World!";
	std::string expected = "48656C6C6F2C20576F726C6421";
	REQUIRE(ASCIIToHexString(buffer) == expected);
	// Test with an empty buffer
	REQUIRE(ASCIIToHexString("") == "");
	// Test with a single character
	REQUIRE(ASCIIToHexString("A") == "41");
	// Test with a buffer of 0x00
	REQUIRE(ASCIIToHexString(std::string("\0\0\0\0\0", 5)) == "0000000000");
	// Test with a buffer of 0xFF
	REQUIRE(ASCIIToHexString("\xFF\xFF\xFF\xFF\xFF") == "FFFFFFFFFF");
	// Test with a buffer of A, B, C, D, E
	REQUIRE(ASCIIToHexString("ABCDE") == "4142434445");
}

TEST_CASE( "SrecFile", "[SrecFile]") {
	SrecFile sf("test.srec", SrecFile::AddressSize::BITS32);
	REQUIRE(sf.is_open());
	std::vector<uint8_t> buffer = {0x7F, 0x45, 0x4C, 0x46, 0x01, 0x01, 0x01, 0x03};
	sf.write_record_payload(buffer);
	sf.close();
	std::ifstream f;
	f.open("test.srec");
	REQUIRE(f.is_open());
	std::string line1;
	std::getline(f, line1);
	REQUIRE(line1 == "S30D000000007F454C460101010396");
	f.close();
}
