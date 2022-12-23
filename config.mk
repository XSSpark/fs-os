
# For compiling the bootstrap assembly
ASM=nasm
ASM_FLAGS=-f elf32

# i686 cross-compiler. See https://github.com/fs-os/cross-compiler
CC=/usr/local/cross/bin/i686-elf-gcc

# Global cflags. Other commands use specific ones not yet in the config
CFLAGS=-Wall -Wextra

# Cross-compiled ar for creating the static library (LIBC)
AR=/usr/local/cross/bin/i686-elf-ar

# Kernel binary and iso filenames
KERNEL_BIN=fs-os.bin
ISO=$(KERNEL_BIN:.bin=.iso)

# For replacing "(GITHASH)" with the last commit in the grub entry. Comment these
# lines if you just want the os name.
PERCENT:=%
COMMIT_CMD=git branch -v --format="$(PERCENT)(objectname:short)$(PERCENT)(HEAD)" | grep "*$$" | tr -d "*"
COMMIT_SHA1=($(shell $(COMMIT_CMD)))

# List of object files of our standard library, and the final static library
LIBC_OBJS=obj/libc/string.o obj/libc/stdlib.o
LIBC=obj/libc.a

# sysroot paths
SYSROOT=./sysroot
SYSROOT_INCLUDEDIR=usr/include
SYSROOT_LIBDIR=usr/lib
SYSROOT_BOOTDIR=boot

SYSROOT_KERNEL=$(SYSROOT)/$(SYSROOT_BOOTDIR)/$(KERNEL_BIN)

# Paths for moving the headers to the sysroot. For example:
# (src/libc/include/*.h -> sysroot/usr/include/*.h)
KERNEL_INCLUDES=src/kernel/include
LIBC_INCLUDES=src/libc/include

