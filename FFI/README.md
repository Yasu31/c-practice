# Foreign Function Interface

based on k-okada's printout「外部関数インターフェース」for the cource ロボットシステム

## Shared object library
create with:
`$ gcc -shared -fPIC -o ffi-c.so ffi-c.c -lm`

The ctypes Python module can utilize the shared object library.
