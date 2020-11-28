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

int inversemodulo(int x, int z);
void inverse(int y[2][2], int (&z)[2][2]);


void encryption(char plaintext[], char *ciphertext, int key[2][2])
{
    int stringlength = strlen(plaintext);

    // using ASCII codes to en/decrypt,
    // so it's easier to put everything
    // in a single lettercase
    for (int index = 0; index <= stringlength; index++)
    {
        plaintext[index] = tolower(plaintext[index] - 97);
    }

    // the key looks like a 2 x 2 block.
    // this means two columns and two rows.
    // the rows of the first matrix are
    // multiplied by the columns of the second
    for (int index = 0; index <= stringlength; index++)
    {
        ciphertext[index] = (((plaintext[index] * key[0][0]) + (plaintext[index + 1] * key[1][0])) % 26);
        ciphertext[index + 1] = (((plaintext[index] * key[0][1]) + (plaintext[index + 1] * key[1][1])) % 26);
        index++;
    }

    for (int index = 0; index <= stringlength; index++)
    {
        ciphertext[index] = ciphertext[index] + 97;
    }
}

void decryption(char ciphertext[], char *plaintext, int key[2][2])
{
    int stringlength = strlen(ciphertext);

    for (int index = 0; index <= stringlength; index++)
    {
        ciphertext[index] = tolower(ciphertext[index] - 97);
    }

    for(int index = 0; index <= stringlength - 1; index++)
    {
        plaintext[index] = (((ciphertext[index] * key[0][0]) + (ciphertext[index + 1] * key[1][0])) % 26);
        plaintext[index + 1] = (((plaintext[index] * key[0][1]) + (plaintext[index + 1] * key[1][1])) % 26);
        index++;
    }

    for(int index = 0; index <= stringlength; index++)
    {
        plaintext[index] = plaintext[index] + 97;
    }
}

int inversemodulo(int x, int z)
{
    int x0, z0, p, q, temp;

    int h0 = 0;
    x0 = x;
    z0 = z;
}

void inverse(int y[2][2], int(&z)[2][2])
{
    int dK = ((y[0][0] * y[1][1]) - (y[0][1] * y[1][0]));
}