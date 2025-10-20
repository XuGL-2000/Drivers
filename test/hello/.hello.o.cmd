savedcmd_/usr/xgl/test/hello/hello.o := ld -m elf_x86_64 -z noexecstack   -r -o /usr/xgl/test/hello/hello.o @/usr/xgl/test/hello/hello.mod  ; ./tools/objtool/objtool --hacks=jump_label --hacks=noinstr --hacks=skylake --ibt --retpoline --rethunk --sls --stackval --static-call --uaccess --prefix=16  --link  --module /usr/xgl/test/hello/hello.o

/usr/xgl/test/hello/hello.o: $(wildcard ./tools/objtool/objtool)
