#include <iostream>

#include <gcrypt++/Hash.hpp>


int main(int argc, char **argv)
{
  Gcrypp::Hash hash;

  std::string hash_str = hash.sha256_to_hex("hello");

  std::cout << hash_str << std::endl;

  return 0;
}
