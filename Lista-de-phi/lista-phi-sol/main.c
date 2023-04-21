#include "TLinkedList.h"
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

/*#define ll long long

// Exponenciação modular
ll mod_pow(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp > 0) {
        if (exp & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

// Teste de primalidade de Miller-Rabin
bool miller_rabin(ll n, int k) {
    if (n == 2 || n == 3)
        return true;
    if (n <= 1 || n % 2 == 0)
        return false;

    ll d = n - 1;
    int r = 0;
    while (d % 2 == 0) {
        d /= 2;
        r++;
    }

    for (int i = 0; i < k; i++) {
        ll a = rand() % (n - 3) + 2;
        ll x = mod_pow(a, d, n);

        if (x == 1 || x == n - 1)
            continue;

        bool flag = false;
        for (int j = 0; j < r - 1; j++) {
            x = mod_pow(x, 2, n);
            if (x == n - 1) {
                flag = true;
                break;
            }
        }

        if (!flag)
            return false;
    }

    return true;
}

// Teste de primalidade de Lucas
bool lucas(ll n) {
    if (n == 2)
        return true;
    if (n <= 1 || n % 2 == 0)
        return false;

    ll d = 5;
    while (true) {
        ll q = (1 - d) / 4;
        if (mod_pow(d, n - 1, n) == 1 && (q == 0 || mod_pow(q, n - 1, n) == 1))
            return true;
        if (miller_rabin(n, 10))
            return false;
        d = (d + 2) % n;
    }
}*/

/**
 * @brief Calcula o mdc de um número pelo Algoritmo de Euler
 * 
 * @param n 
 * @param m 
 * @return int 
 */
int mdc(int n, int m){
  if (!m) return n;
  return mdc(m, n%m);
}

int isPrime(int number) {
  if (number <= 1) return 0;
  if ((number % 2 == 0 && number != 2 )|| (number % 3 == 0 && number != 3)) 
      return 0;
  int i = 5;
  while(i * i <= number) {
    if (number % i == 0 || number % (i + 2) == 0) {
      return 0;
    }
    i = i + 6;
  }
  return 1;
}
    
int Phi_function(int number) {
  if (isPrime(number)) 
    return number - 1;
  else {
    int coprime = 0;
    if(number % 2 == 0) {
      for (int i = 1; i < number; i+=2) {
        mdc(number, i) == 1 ? coprime++ : coprime;
      }
      return coprime;
    }
    for (int i = 1; i < number; i++) {
      mdc(number, i) == 1 ? coprime++ : coprime;
    }
    return coprime;
  }
}

TLinkedList* Phi_List(int number){
  TLinkedList* list = TLinkedList_create();
  while(number != 1){
    TLinkedList_insert_end(list, number);
    number = Phi_function(number);
  }
  TLinkedList_insert_end(list, number);
  return list;
}

int main(){
  int input;
  scanf("%d",&input);
  TLinkedList* solution = Phi_List(input);
  int size = TLinkedList_print(solution);
  printf("%d\n", size);
  return 0;
}