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

int inversemodulo(int c, int d);
void inverse(int f[2][2], int (&d)[2][2]);


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

int inversemodulo(int c, int d)
{
    int c0, d0, g, h, temp;

    int l0 = 0;
    int l = 1;
    c0 = c;
    d0 = d;
    g = floor(c0 / d0);
    h = c0 - g * d0;

    while (h > 0)
    {
        temp = l0 - g * l;
        if (temp >= 0)
        {
            temp = temp % c;
        }
        else
        {
            temp = c - ((-temp) % c);
            l0 = l;
            l = temp;
            c0 = d0;
            d0 = h;
            g = floor(c0 / d0);
            h = c0 - g * d0;
        }
    }
    return l;
}


// void inverse(int f[2][2], int(&d)[2][2])
// {
//     int dK = ((f[0][0] * f[1][1]) - (f[0][1] * f[1][0]));
// }

int main()
{
    int key[2][2];
    int inversearray[2][2];
    int determinantkey;
    int inversedeterminant;

    char plaintext[99];
    char ciphertext[99];

    bool isInvertible = false;
    bool gcd1 = false;

    // ask user to create a 2x2 matrix
    cout << "Create a 2x2 key by typing four numbers separated by a space." << endl;
    for (int index = 0; index < 2; index++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> key[index][j];
        }
        cout << endl;
    }

    // print the matrix created by the user
    cout << "Your matrix key is: " << endl;
    for (int index = 0; index < 2; index++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << key[index][j] << "\t";
        }
        cout << endl << endl;
    }

    // check if matrix is invertible
    determinantkey = ((key[0][0] * key[1][1]) - (key[0][1] * key[1][0]));
    if (determinantkey != 0)
    {
        isInvertible = true;
    }
    cout << "The matrix is invertible and the determinant is " << determinantkey << "." << endl;

    // check if gcd = 1
    if(__gcd(determinantkey, 26) == 1)
    {
        gcd1 = true;
    }

    return 0;
}