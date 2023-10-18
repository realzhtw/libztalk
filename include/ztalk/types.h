#ifndef ZTALK_TYPES_H
#define ZTALK_TYPES_H

#include <vegan/types.h>

namespace ztalk {

  using vegan::uintptr_t;

  // immediate:
  //   x.....xxx00 - fixnum
  //   x.....x0010 - char
  //   x.....x0110 - ?
  //   x.....x1010 - ?
  //   0..00001110 - false
  //   0..00011110 - true
  //   0..00101110 - none
  //   0..00111110 - eof
  //   0..01001110 - nil
  // ptr:
  //   xxxxxxxxyy1 - ptr of type yy

  const uintptr_t boolean_mask = (1 << 4);

  struct ref {
    ref() {}
    ref(char c): rep{uintptr_t(c) << 4 | 2} {}
    uintptr_t rep = 0x2e;
  };

  const ref none;

  inline bool immediate(ref x) { return (x.rep & 1) == 0; }
  inline bool fixnum(ref x)    { return (x.rep & 3) == 0; }

  ref cons(ref, ref);
  bool pair(ref);
  ref car(ref);
  ref cdr(ref);

  

}

#endif
