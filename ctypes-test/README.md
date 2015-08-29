# Comparison between different technologies when it comes to binding C++ with Python

Found several great links on Stack Overflow in this regard (*need to add them here*). SWIG seems to be the winner so far with regards to extensibility. It also doesn't require as heavy a wrapping as CTypes. However, the initial learning curve with the .i files is steep.

CTypes is great for small projects (as done here) but the need to write C wrappers for everything becomes a bit of a chore.

Boost.Python also seems great but it requires the use of bjam, which is awful.

## Other things to remember

- All source files must be compiled with _-fPIC_ so that they generate positionally independent assembly. Without this, they cannot be wrapped into the shared object and that's how you get undefined symbol errors.
- When wrapping a static library, make sure that it's also compiled with -fPIC and then use the following compiler option:

   ```bash
   -Wl,--whole-archive
   # followed by...
-Wl,--no-whole-archive # for the rest of the libraries that don't need to be linked this way
```
