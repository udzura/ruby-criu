#include "ruby-criu.h"
#include <criu/criu.h>
#include <stdio.h>

static VALUE
rb_criu_init_options (VALUE klass) {
  if(criu_init_opts() < 0) {
    rb_raise(rb_eRuntimeError, "criu_init_opts failed");
  }
  return Qtrue;
}

static VALUE
rb_criu_set_service_address (VALUE klass, VALUE path) {
  criu_set_service_address(RSTRING_PTR(path));
  return path;
}

static VALUE
rb_criu_set_images_dir_fd (VALUE klass, VALUE fd) {
  criu_set_images_dir_fd(NUM2INT(fd));
  return fd;
}

static VALUE
rb_criu_set_pid (VALUE klass, VALUE pid) {
  criu_set_pid(NUM2INT(pid));
  return pid;
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

static VALUE
rb_criu_dump (VALUE klass) {
  if(criu_dump() < 0) {
    perror("ruby-criu"); /* FIXME: debug... */
    rb_raise(rb_eRuntimeError, "criu_dump failed");
  }
  return Qtrue;
}

void
Init_criu(void)
{
  VALUE rb_mCriu;

  rb_mCriu = rb_define_module("CRIU");
  rb_define_module_function(rb_mCriu, "_init_options", rb_criu_init_options, 0);
  rb_define_module_function(rb_mCriu, "service_address=", rb_criu_set_service_address, 1);
  rb_define_module_function(rb_mCriu, "_set_images_dir_fd", rb_criu_set_images_dir_fd, 1);
  rb_define_module_function(rb_mCriu, "pid=", rb_criu_set_pid, 1);
  rb_define_module_function(rb_mCriu, "log_level=", rb_criu_set_log_level, 1);
  rb_define_module_function(rb_mCriu, "log_file=", rb_criu_set_log_file, 1);

  rb_define_module_function(rb_mCriu, "dump", rb_criu_dump, 0);
}
