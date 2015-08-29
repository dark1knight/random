# Comparison between different technologies when it comes to binding C++ with Python

Found several great links on Stack Overflow in this regard. SWIG seems to be the winner so far with regards to extensibility and needing to muck around in the source too much.

CTypes is great for small projects (as done here) but the need to write C wrappers for everything becomes a bit of a chore.

Boost.Python also seems great but it requires the use of bjam, which is awful.
