require "criu/version"
require "criu/criu"

module CRIU
  class Error < StandardError; end
  # Your code goes here...

  class << self
    def images_dir=(path)
      @images_dir = File.open(path, 'r')
      self._set_images_dir_fd(@images_dir.fileno)
      return path
    end
  end
end
