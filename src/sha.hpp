// hashes and returns a string using SHA256
#pragma once
#include <iostream>
#include <string>
#include "picosha2.hpp"

inline std::string hash_sha256(std::string src_str)
{
    std::string hash_hex_str = picosha2::hash256_hex_string(src_str);
    return hash_hex_str;
}