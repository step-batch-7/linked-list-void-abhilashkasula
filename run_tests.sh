rm main *.o
gcc -c linkedlist.c test/*.c && gcc -o main *.o && ./main
