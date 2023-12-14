# -*- sh -*-

AC_MSG_CHECKING([for sdl2 display support])

AC_ARG_WITH(vm-display-sdl2,
[  --with-vm-display-sdl2   enable sdl2 window support [default=disabled]],
  [with_vm_display_sdl2="$withval"],
  [with_vm_display_sdl2="no"])
if test "$with_vm_display_sdl2" = "yes"; then
  # check for libraries, headers, etc., here...
  AC_MSG_RESULT([yes])
else
  AC_MSG_RESULT([no])
  AC_PLUGIN_DISABLE
fi
