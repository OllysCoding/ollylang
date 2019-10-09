#include <iostream>
#include "../token/token.hpp"
#include "../TokenType/TokenType.hpp"
#include "../InputStream/InputStream.hpp"

using namespace std;

class TokenStream {
  InputStream input;

  public: 
    TokenStream(InputStream stream) : input(stream) {};

    

};
