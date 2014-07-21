#ifndef _GCRYPTPP_HASH_
#define _GCRYPTPP_HASH_

#include <iostream>

namespace Gcrypp {

  class Hash {
  private:
    bool _uppercase;
  public:
    Hash();
    ~Hash() {}

    std::string sha256_to_hex(std::string input);

  };

} // namespace Gcrypp

#endif // _GCRYPTPP_HASH_
