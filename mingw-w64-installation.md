# Install Notes

1. Go to <http://mingw-w64.org/doku.php/download> and choose the **MingW-W64-builds** option.
2. An executable installer will be downloaded in which the following options are to be given:
   1. 64-bit systems: x86_64
   2. 32-bit systems: i686
3. Once the installation is done, Set the Path in the System Environment Variable Settings as `<minGW-install-directory>/bin`.
4. Once the path is set, check whether the installation was successful or not by running `g++ --version` and `gdb --version` in cmd/powershell/terminal. If the output is some kind of an error, then the installation process aforementioned, was followed incorrectly.
