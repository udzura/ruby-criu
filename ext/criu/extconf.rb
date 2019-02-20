require "mkmf"

abort "missing libcriu" unless have_library("criu")
abort "missing <criu/criu.h>" unless have_header("criu/criu.h")

create_makefile("criu/criu")
