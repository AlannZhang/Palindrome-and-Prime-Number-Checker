/*
   The values that I used to test this program included values less then 2, which did not work since I implemented
   error checking for any value less then 2. I tested values by multiples of 10, ex: 10, 100, 1000, 100000, and 1000000, which
   worked as well. Hence, my program will work for any inputted value that is greater then 2.
 */

#include <iostream>
#include <string>
using namespace std;

//function declaration
void input_value (int &in_value);
bool is_prime (int num);
bool is_palindromic (string num1);
bool is_odd_sum (int num);
void output_all_prime_num (int in_value, string num1);
void execute_prime_num_finder ();

//checks for correct user input
void input_value (int &in_value) {
    do {
        cout <<"Please input an integer that is greater then 0, and not 1 or 0: ";
        cin >> in_value;
    }
    while(in_value < 2);
}

//checks for prime numbers
bool is_prime (int num) {
    bool is_prime = true;
    
    for (int pos = 2; pos < num; pos++) {
        if (num % pos == 0) {
            is_prime = false;
            break;
        }
    }
    return is_prime;
}

//checks for palindromic numbers
bool is_palindromic (string num1) {
    int pos_start = 0;
    int pos_last = num1.length() - 1;
    bool is_palin = true;
    
    while (pos_start != pos_last && pos_start < pos_last) {
        if (num1[pos_start] != num1[pos_last]) {
            is_palin = false;
            break;
        }
        pos_start++;
        pos_last--;
    }
    return is_palin;
}

//checks if the sum of the digits is odd
bool is_odd_sum (int num) {
    int temp;
    int sum = 0;
    bool is_odd = true;
    
    while (num != 0) {
        temp = num%10;
        sum += temp;
        num = num/10;
    }
    
    if (sum % 2 == 0) {
        is_odd = false;
    }
    
    return is_odd;
}

//loops for the numbers less then the outputted value
void output_all_prime_num (int in_value, string num1) {
    for (int num = 2; num <= in_value; num++) {
        num1 = to_string(num);
        
        //calls the prime, palindromic, and odd sum checker to pass values to check whether they are of those types
        if (is_prime(num) == true) {
            if (is_palindromic(num1) == true && num < 10000 && num1.length() > 1) {
                if (is_odd_sum(num) == false){
                    printf("%i is palindromic \n", num);
                }
                else {
                    printf("%i is palindromic and has an odd sum \n", num);
                }
            }
            
            if (is_odd_sum(num) == true && num < 100000 && num1.length() > 1 && is_palindromic(num1) == false) {
                printf("%i has an odd sum \n", num);
            }
            else {
                printf("%i \n", num);
            }
        }
    }
}

//wraps the other functions into one function
void execute_prime_num_finder() {
    int in_value;
    string num1;
    
    input_value(in_value);
    output_all_prime_num(in_value, num1);
}

//calls the final function
int main() {
    execute_prime_num_finder();
} 
