#ifndef _GCRYPTPP_HASH_
#define _GCRYPTPP_HASH_

#include <iostream>

namespace Gcrypp {

  class Hash {
  public:
    Hash();
    ~Hash() {}

    std::string sha256_to_hex(std::string input);

  };

} // namespace GCRYPTPP

#endif // _GCRYPTPP_HASH_
