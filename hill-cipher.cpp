// John Cilli - jcilli@live.esu.edu
// Beatrix House - evanputten@live.esu.edu
// CPSC 370 - Introduction to Cryptology, 12pm
// Final Project: 2x2 Hill Cipher Implementation
// December 3, 2020

#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <string.h>

using namespace std;


void encryption(char plaintext[], char *ciphertext, int keymatrix[2][2]);
void decryption(char ciphertext[], char *plaintext, int inversematrix[2][2]);

void inversefunction(int c[2][2], int (&d)[2][2]);
int inversemodulo(int f, int d);

void encryption(char plaintext[], char *ciphertext, int keymatrix[2][2])
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
	for (int index = 0; index <= stringlength-1; index++)
  {
		ciphertext[index] = ( (plaintext[index] * keymatrix[0][0]) + (plaintext[index + 1] * keymatrix[1][0]) ) % 26;
		ciphertext[index + 1] = ( (plaintext[index] * keymatrix[0][1]) + (plaintext[index + 1] * keymatrix[1][1]) ) % 26;
		index++;
	}

	for (int index = 0; index <= stringlength; index++)
  {
		ciphertext[index] = toupper(ciphertext[index] + 97);
	}
}

void decryption(char ciphertext[], char *plaintext, int inversematrix[2][2]){
	int stringlength = strlen(ciphertext);
	for (int index = 0; index <= stringlength; index++)
  {
		ciphertext[index] = tolower(ciphertext[index]);
		ciphertext[index] = ciphertext[index]-97;
	}

	for (int index = 0; index <= stringlength-1; index++)
  {
		plaintext[index] = (ciphertext[index]*inversematrix[0][0]+ciphertext[index+1]*inversematrix[1][0])%26;
		plaintext[index+1] = (ciphertext[index]*inversematrix[0][1]+ciphertext[index+1]*inversematrix[1][1])%26;
		index++;
	}
	for (int index = 0; index <= stringlength; index++){
		plaintext[index] = plaintext[index] + 97;
	}
}

void inversefunction(int c[2][2], int (&d)[2][2]){
	
	int dK = (c[0][0]*c[1][1]) - (c[0][1]*c[1][0]);	
	
	d[0][0] = ((inversemodulo(26,dK)) * c[1][1]);
	d[0][1] = ((inversemodulo(26,dK)) * c[0][1]*(-1));
	d[1][0] = ((inversemodulo(26,dK)) * c[1][0]*(-1));
	d[1][1] = ((inversemodulo(26,dK)) * c[0][0]);
	
	for(int index = 0; index<2; index++)
  {
		for(int j = 0; j < 2; j++)
    {
			if(d[index][j] >= 0)
      {
        d[index][j] = d[index][j] % 26;
      }
			else
      {
        d[index][j] = 26 - ((-d[index][j]) % 26);
      }
		}
	}
}

int inversemodulo(int f, int d)
{
	int f0,d0,l,m,temp;
	
	int s0 = 0;
	int s = 1;
	f0 = f;
	d0 = d;
	l = floor(f0/d0);
	m = f0 - l * d0;
	
	while (m > 0){
		temp = s0 - l * s;
		if(temp >= 0) temp = temp % f;
		else temp = f - ((-temp) % f);
		s0 = s;
		s = temp;
		f0 = d0;
		d0 = m;
		l = floor(f0/d0);
		m = f0 - l * d0;
	}
	
	return s;
}

// void inversefunction(int c[2][2], int (&d)[2][2]){
	
// 	int dK = (c[0][0]*c[1][1]) - (c[0][1]*c[1][0]);	
	
// 	d[0][0] = ((inversemodulo(26,dK)) * c[1][1]);
// 	d[0][1] = ((inversemodulo(26,dK)) * c[0][1]*(-1));
// 	d[1][0] = ((inversemodulo(26,dK)) * c[1][0]*(-1));
// 	d[1][1] = ((inversemodulo(26,dK)) * c[0][0]);
	
// 	for(int index = 0; index<2; index++)
//   {
// 		for(int j = 0; j < 2; j++)
//     {
// 			if(d[index][j] >= 0)
//       {
//         d[index][j] = d[index][j] % 26;
//       }
// 			else
//       {
//         d[index][j] = 26 - ((-d[index][j]) % 26);
//       }
// 		}
// 	}
// }

// void encryption(char plaintext[], char *ciphertext, int keymatrix[2][2])
// {
// 	int stringlength = strlen(plaintext);

//   // using ASCII codes to en/decrypt,
//   // so it's easier to put everything
//   // in a single lettercase
// 	for (int index = 0; index <= stringlength; index++)
//   {
// 		plaintext[index] = tolower(plaintext[index] - 97);
// 	}

//   // the key looks like a 2 x 2 block.
//   // this means two columns and two rows.
//   // the rows of the first matrix are
//   // multiplied by the columns of the second
// 	for (int index = 0; index <= stringlength-1; index++)
//   {
// 		ciphertext[index] = ( (plaintext[index] * keymatrix[0][0]) + (plaintext[index + 1] * keymatrix[1][0]) ) % 26;
// 		ciphertext[index + 1] = ( (plaintext[index] * keymatrix[0][1]) + (plaintext[index + 1] * keymatrix[1][1]) ) % 26;
// 		index++;
// 	}

// 	for (int index = 0; index <= stringlength; index++)
//   {
// 		ciphertext[index] = toupper(ciphertext[index] + 97);
// 	}
// }

// void decryption(char ciphertext[], char *plaintext, int inversematrix[2][2]){
// 	int stringlength = strlen(ciphertext);
// 	for (int index = 0; index <= stringlength; index++)
//   {
// 		ciphertext[index] = tolower(ciphertext[index]);
// 		ciphertext[index] = ciphertext[index]-97;
// 	}

// 	for (int index = 0; index <= stringlength-1; index++)
//   {
// 		plaintext[index] = (ciphertext[index]*inversematrix[0][0]+ciphertext[index+1]*inversematrix[1][0])%26;
// 		plaintext[index+1] = (ciphertext[index]*inversematrix[0][1]+ciphertext[index+1]*inversematrix[1][1])%26;
// 		index++;
// 	}
// 	for (int index = 0; index <= stringlength; index++){
// 		plaintext[index] = plaintext[index] + 97;
// 	}
// }


// BEGIN MAIN FUNCTION
int main()
{
	int keymatrix[2][2];
	int inversematrix[2][2];
	int determinantkey, determinantinverse;

	char plaintext[99];
	char ciphertext[99];

	bool isInvertible = false;
	bool gcd1 = false;
	bool kinversemod1 = false;

  // ask user to create a 2x2 matrix
	cout << "Create a 2x2 key by typing four numbers separated by a space." << endl;
	for(int index = 0; index < 2; index++)
  {
		for(int j = 0; j < 2; j++)
    {
			cin >> keymatrix[index][j];
		}
    cout << endl;
	}
	
  // print the matrix created by the user
  cout << "Your matrix key is: " << endl;
    for (int index = 0; index < 2; index++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << keymatrix[index][j] << "\t";
        }
        cout << endl << endl;
    }
	
	// check if matrix is invertible. if so, calculate and display determinant
	determinantkey = (keymatrix[0][0] * keymatrix[1][1]) - (keymatrix[0][1] * keymatrix[1][0]);	
	if(determinantkey != 0)
  {
    isInvertible = true;
  }
	cout << "The matrix is invertible and the determinant is " << determinantkey << "." << endl << endl;
	
	// check if gcd = 1
	if(__gcd(determinantkey, 26) == 1)
  {
      gcd1 = true;
  }
	
	inversefunction(keymatrix, inversematrix);
	
	cout << "Your inverse matrix key is: " << endl;
	for(int index = 0; index < 2; index++)
  {
		for(int j = 0; j < 2; j++)
    {
			cout << inversematrix[index][j] << "\t";
		}
    cout << endl << endl;
	}

	determinantinverse = (inversematrix[0][0]*inversematrix[1][1]) - (inversematrix[0][1]*inversematrix[1][0]);
	
	if (determinantkey >= 0)
  {
    determinantkey %= 26;
  }
  else
  {
    determinantkey = 26  - ((-determinantkey) % 26);
  }

  if((determinantkey * determinantinverse) % 26 == 1)
  {
    kinversemod1 = true;
  }
	
	
  cout << "Enter the phrase (without spaces!) that you want to encrypt: " << endl;
  cin >> plaintext;
  encryption(plaintext, ciphertext, keymatrix);
  int stringlength = strlen(ciphertext);
  
  cout << "Encryption: ";
  for(int index = 0; index <= stringlength - 1; index++)
  {
    cout << ciphertext[index];
  }
  cout << endl;

  decryption(ciphertext, plaintext, inversematrix);
  cout << "Decryption: ";
  
  for(int index = 0; index < stringlength - 1; index++)
  {
    cout << plaintext[index];
  }
  cout << endl;

}
// END MAIN FUNCTION