#ifndef ZTALK_STDIO_H
#define ZTALK_STDIO_H

#include <ztalk/types.h>
#include <vegan/stack.h>

namespace ztalk {

  extern ref stdin;
  extern ref stdout;
  extern ref stderr;

  extern vegan::stack<ref> _input_ports;
  extern vegan::stack<ref> _output_ports;

  inline ref current_input_port() { return _input_ports.top(); }
  inline ref current_output_port() { return _output_ports.top(); }

  struct current_input_port_guard {
    explicit current_input_port_guard(ref input_port) { _input_ports.push(input_port); }
    ~current_input_port_guard() { _input_ports.pop(); }
  };

  struct current_output_port_guard {
    explicit current_output_port_guard(ref output_port) { _output_ports.push(output_port); }
    ~current_output_port_guard() { _output_ports.pop(); }
  };

  template<typename F>
    void with_input_from(ref input_port, F &f) { current_input_port_guard g{input_port}; f(); }

  template<typename F>
    void with_output_from(ref output_port, F &f) { current_output_port_guard g{output_port}; f(); }

  ref fgetc(ref input_port);
  inline ref getc() { return fgetc(current_input_port()); }

  void fungetc(ref input_port);
  inline void ungetc() { fungetc(current_input_port()); }

  void fprint(ref output_port, ref x);
  inline void print(ref x) { fprint(current_output_port(), x); }

  inline void fprintln(ref output_port) { fprint(output_port, '\n'); }
  inline void fprintln(ref output_port, ref x) { fprint(output_port, x); fprintln(output_port); }

  inline void println() { fprintln(current_output_port()); }
  inline void println(ref x) { fprintln(current_output_port(), x); }

}

#endif
