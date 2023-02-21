# Implementation of the RSA cryptosystem in C with openSSL

CoraLib is the name of the project, after pubcrypt, an RSA implementation in python, I'm starting a C implementation of RSA.
In this library I'm using Bignum structure with openSSL and some arithmetic operation like Montgomery multiplication will be implemented in C++.
New feature are also in-coming like the possibility of generating keypair with your GPU.

I'm using C/C++ and later for the GPU computing I'll use CUDA.


## Actual stat

Actually the project is under developpement. I'm practising with the Bignum structure and I'll start soon to implemente the necessary arithmetic operation.
This repo is the very first version of the program. It is only a demo to show how I proceed, the version I'm updating more often is on another branch.


## Sources

[1] https://www.openssl.org/docs/man1.0.2/man3/bn.html
[2] https://en.algorithmica.org/hpc/
[3] https://nvlpubs.nist.gov/nistpubs/fips/nist.fips.186-4.pdf
[4] https://nvlpubs.nist.gov/nistpubs/SpecialPublications/NIST.SP.800-56Br2.pdf