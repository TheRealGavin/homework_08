// Author: Gavin R Lafferty
// Github: https://github.com/TheRealGavin/homework_08
// December 05, 2020
// CSIS 113A

#include <iostream>
#include <random>

int random_number_generator(int min, int max);
void fill_array(int array[][5], int size);
void print_array(int array[][5], int size);
int count_numbers(int array[][5], int size, int search);

int main() {

  int array[5][5];

  fill_array(array, 5);
  print_array(array, 5);

  std::cout << "\nWhat number do you want to search for? " << std::endl;
  int number;
  std::cin >> number;
  int count = count_numbers(array,5,number);
  std::cout << "Your number appears " << count
            << " times in the array" << std::endl;

}


void fill_array(int array[][5], int size){

  for(int row = 0; row < 5; ++row){
    for(int column = 0; column < 5; ++column){
        array[row][column] = random_number_generator(1,10);
    }
  }
}


void print_array(int array[][5], int size){

  for(int row = 0; row < 5; ++row){
    for(int column = 0; column < 5; ++column){
      std::cout << array[row][column] << "\t";
    }
    std::cout << std::endl;
  }
}


int count_numbers(int array[][5], int size, int search){
  int count = 0;

  for(int row = 0; row < 5; ++row){
    for(int column = 0; column < 5; ++column){
      if(array[row][column] == search){
        ++count;
        std::cout << "Your number appears at: ("
                  << row + 1 << "," << column + 1 << ")\n";
      }
    }
  }
  return count;
}


int random_number_generator(int min, int max){

  static std::mt19937 rng(std::random_device{}());
  std::uniform_int_distribution<int> distribution(min, max);

  return distribution(rng);
}