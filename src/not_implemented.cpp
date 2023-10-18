#include "not_implemented.h"
#include <vegan/stdio.h>

namespace ztalk {

  void not_implemented(vegan::string_ref src)
  {
    vegan::fprintln(vegan::stderr, "not implemented: ", src);
    throw 1;
  }

}
