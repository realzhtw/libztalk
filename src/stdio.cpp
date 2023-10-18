#include <ztalk/stdio.h>
#include "not_implemented.h"

namespace ztalk {

  ref stdin;
  ref stdout;
  ref stderr;

  vegan::stack<ref> _input_ports{vegan::const_vector_ref{stdin}};
  vegan::stack<ref> _output_ports{vegan::const_vector_ref{stdout}};

  void fprint(ref output_port, ref x)
  {
    if (fixnum(x)) {
    }
    not_implemented("fprint");
  }

}

