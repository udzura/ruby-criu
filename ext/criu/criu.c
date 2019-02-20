#include "criu.h"

VALUE rb_mCriu;

void
Init_criu(void)
{
  rb_mCriu = rb_define_module("Criu");
}
