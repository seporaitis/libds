# Must init the autoconf setup
# The first parameter is project name
# second is version number
# third is bug report address
AC_INIT([libds], [1.0])

# Safety checks in case user overwritten --srcdir
AC_CONFIG_SRCDIR([src/heap.c])

# Put M4 macros in the m4/ subdirectory
AC_CONFIG_MACRO_DIR([m4])

# Store the auxiliary build tools (e.g., install-sh, config.sub, config.guess)
# in this dir (build-aux)
AC_CONFIG_AUX_DIR([build-aux])

# Init automake, and specify this program use relaxed structures.
# i.e. this program doesn't follow the gnu coding standards, and doesn't have
# ChangeLog, COPYING, AUTHORS, INSTALL, README etc. files.
AM_INIT_AUTOMAKE([foreign])

AM_PATH_CHECK([0.9.0],[],[AC_MSG_ERROR([check is missing])])

# Check for C compiler
AC_PROG_CC

# We can add more checks in this section
AC_PROG_LIBTOOL

# Tells automake to create a Makefile
# See https://www.gnu.org/software/automake/manual/html_node/Requirements.html
AC_CONFIG_FILES([src/Makefile
                 tests/Makefile
                 Makefile])

# Generate the output
AC_OUTPUT
