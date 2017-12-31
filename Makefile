all: trapez romberg

trapez: trapez.c
  gcc trapez.c -lm -o trapez

romberg: romberg.c
  gcc romberg.c -lm -o romberg