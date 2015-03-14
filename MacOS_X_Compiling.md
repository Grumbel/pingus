If you are on a 32-bit system (i386), change the x86\_64-apple-darwin10.6.0 accordingly.

This is how I am building Pingus-0.7.6 om MacOS 10.6.

This is completely independent of the Install.macosx file in the pingus source directory and does not use MacPorts

Getting Started

Alt: Install RUDIX http://code.google.com/p/rudix/

All: Install developer tools, either from the OS X Install DVD or from Apple's website
All: symlink include folder of OpenGL framework to /usr/local/include/GL (Unix programs have an easier time finding it this way)
> % sudo ln -s /System/Library/Frameworks/OpenGL.framework/Versions/A/Headers/ /usr/local/include/GL
(you might need to create /usr/local/include/ first if you never built and installed anything from source! sudo mkdir -p /usr/local/include/)

All: iTerm2
This is completely unnecessary, the stock Terminal.app will do just fine; it is just a matter of taste
http://www.iterm2.com/

All: Environment
Add /usr/local/bin to your PATH, **before** /usr/bin so that the new versions of stuff you install are picked over the older ones installed by default (this might not be necessary if you don't install autotools below)
In a terminal : sudo nano /etc/profile (enter your password as prompted)
add the line export PATH=/usr/local/bin:$PATH at the bottom of the file
Hit Ctrl+O then press enter to save changes.
Hit Ctrl-X to exit.

Alt: sudo rudix install pkg-config

Orig: Download pkg-config sources from http://pkgconfig.freedesktop.org/releases/ and build it:
> % cd /path/to/pkg-config-0.22
> % ./configure
> % make
> % sudo make install

Alt: sudo rudix install m4; sudo rudix install automake; sudo rudix install autoconf

Orig: get M4 from http://ftp.gnu.org/gnu/m4/ and install it
symlink m4 to gm4 since that's how some programs refer to it.
> % sudo ln -s /usr/local/bin/m4 /usr/local/bin/gm4
Then, build and install autoconf and automake from GNU the same way as described above
http://www.gnu.org/software/autoconf/
http://www.gnu.org/software/automake/

SCONS
Alt: sudo rudix install scons

Orig: http://www.scons.org/

BOOST
Alr: sudo rudix install boost

Orig: {http://www.boost.org/}  Needs apple's gcc to build

DYLIBBUNDLER
All: http://macdylibbundler.sourceforge.net/  need apple's gcc to build

LIBXML2
All: ./configure && make && sudo make install

SDL
Alt: sudo rudix install sdl

Orig: ./configure CC=/usr/bin/gcc CXX=/usr/bin/g++ && make && sudo make install

LIBOGG
Alt: sudo rudix install static-libogg

Orig: ./configure && make && sudo make install

LIBVORBIS
Alt: sudo rudix install static-libvorbis

Orig: ./configure && make && sudo make install

LIBMAD
All: ./configure x86\_64-apple-darwin10.6.0 CC=/usr/bin/gcc CXX=/usr/bin/g++ && make && sudo make install

FLAC
All: ./configure x86\_64-apple-darwin10.6.0 && make && sudo make install

MIKMOD
All: #We must us a patched version of libmikmod

cd ~; curl -o libmikmod.tbz dl.dropbox.com/u/3252883/Libs/libmikmod-3.2.0-beta2.tbz -#; tar -xjf libmikmod.tbz; cd ~/libmikmod-3.2.0-beta2; ./configure; make; sudo make install

SDL\_MIXER
All: ./configure -enable-music-mp3-shared=false --enable-music-ogg-shared=false --enable-music-flac-shared=false --enable-music-mod-shared=false --enable-music-mp3-mad-gpl && make && sudo make install

LIB\_PNG
Alt: sudo rudix install static-libpng

Orig: ./configure x86\_64-apple-darwin10.6.0 && make && sudo make install

LIB\_JPEG
Alt: sudo rudix install static-libjpeg

Orig: ./configure x86\_64-apple-darwin10.6.0 && make && sudo make install'

You may need to manually copy libjpeg.a to /usr/local/lib/
You may need to manually copy all the **.h files to /usr/local/include/**

LIB\_TIFF
All: ./configure x86\_64-apple-darwin10.6.0 --with-apple-opengl-framework && make && sudo make install


SDL\_IMAGE
All: ./configure -enable-jpg-shared=false --enable-png-shared=false --enable-tif-shared=false && make && sudo make install

GCC-4.6+
All: Pingus uses functions not present in Apples version of GCC (4.2.1)  Luckily GCC compiles cleanly on MacOS X.  Remember to intall the dependencies: gmp, mpc & mpfr.
There is nothing special needed to compile GCC or its dependencies, just

./configure && make && make install

PINGUS

Change nessecary for mac are still in GIT

git clone https://code.google.com/p/pingus/

scons

MAKING AN APP BUNDLE

./bundle\_mac.sh