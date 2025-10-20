savedcmd_/usr/xgl/test/hello/hello.mod := printf '%s\n'   src/hello_intf.o | awk '!x[$$0]++ { print("/usr/xgl/test/hello/"$$0) }' > /usr/xgl/test/hello/hello.mod
