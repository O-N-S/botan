/*
* ARC4
* (C) 1999-2008 Jack Lloyd
*
* Distributed under the terms of the Botan license
*/

#ifndef BOTAN_ARC4_H__
#define BOTAN_ARC4_H__

#include <botan/stream_cipher.h>
#include <botan/types.h>

namespace Botan {

/**
* Alleged RC4
*/
class BOTAN_DLL ARC4 : public StreamCipher
   {
   public:
      void cipher(const byte in[], byte out[], u32bit length);

      void clear();
      std::string name() const;

      StreamCipher* clone() const { return new ARC4(SKIP); }

      ARC4(u32bit = 0);
      ~ARC4() { clear(); }
   private:
      void key_schedule(const byte[], u32bit);
      void generate();

      const u32bit SKIP;

      SecureVector<byte, DEFAULT_BUFFERSIZE> buffer;
      SecureVector<u32bit, 256> state;
      u32bit X, Y, position;
   };

}

#endif
