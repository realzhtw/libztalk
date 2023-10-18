#ifndef ZTALK_READ_H
#define ZTALK_READ_H

#include <ztalk/stdio.h>

namespace ztalk {

  ref read(ref input_port);
  inline ref read() { return read(current_input_port()); }

}

#endif
