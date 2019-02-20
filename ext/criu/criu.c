#include "ruby-criu.h"
#include <criu/criu.h>

static VALUE
rb_criu_init_options (VALUE klass) {
  if(criu_init_opts() < 0) {
    rb_raise(rb_eRuntimeError, "criu_init_opts failed");
  }
  return Qtrue;
}

static VALUE
rb_criu_set_log_level (VALUE klass, VALUE level) {
  criu_set_log_level(NUM2INT(level));
  return level;
}

static VALUE
rb_criu_set_log_file (VALUE klass, VALUE path) {
  criu_set_log_file(RSTRING_PTR(path));
  return path;
}

void
Init_criu(void)
{
  VALUE rb_mCriu;

  rb_mCriu = rb_define_module("CRIU");
  rb_define_module_function(rb_mCriu, "_init_options", rb_criu_init_options, 0);
  rb_define_module_function(rb_mCriu, "log_level=", rb_criu_set_log_level, 1);
  rb_define_module_function(rb_mCriu, "log_file=", rb_criu_set_log_file, 1);
}
