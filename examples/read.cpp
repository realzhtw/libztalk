#include <ztalk/read.h>
#include <ztalk/stdio.h>

using namespace ztalk;

int main()
{
  ref x = read();
  println(x);
}
