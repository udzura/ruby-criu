require "bundler/gem_tasks"
require "rake/extensiontask"

task :build => :compile

Rake::ExtensionTask.new("criu") do |ext|
  ext.lib_dir = "lib/criu"
end

task :default => [:clobber, :compile, :spec]
