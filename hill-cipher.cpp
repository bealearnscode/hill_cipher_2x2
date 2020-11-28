// John Cilli - jcilli@live.esu.edu
// Beatrix House - evanputten@live.esu.edu
// CPSC 370 - Introduction to Cryptology, 12pm
// Final Project: 2x2 Hill Cipher Implementation
// December 3, 2020

#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

void encryption(char plaintext[], char *ciphertext[], int key[2][2]);
void decryption(char ciphertext[], char *plaintext[], int key[2][2]);

void inverse(int y[2][2], int (&z)[2][2]);
int inversemodulo(int x, int z);



