#include <gcrypt.h>

#include <gcrypt++/Hash.hpp>
#include <gcrypt++/Utils.hpp>


Gcrypp::Hash::Hash()
{
  _uppercase = false;
}

std::string Gcrypp::Hash::sha256_to_hex(std::string input)
{
  int hash_length = gcry_md_get_algo_dlen(GCRY_MD_SHA256);
  unsigned char digest[hash_length];

  gcry_md_hash_buffer(GCRY_MD_SHA256, digest, input.c_str(), input.size());

  std::string output(digest, digest + hash_length);

  return Gcrypp::Utils::string_to_hex(output, _uppercase);
}
